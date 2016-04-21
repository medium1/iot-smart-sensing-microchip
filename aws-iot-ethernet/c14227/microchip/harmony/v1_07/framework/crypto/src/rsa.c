/**************************************************************************
  Crypto Framework Library Source

  Company:
    Microchip Technology Inc.

  File Name:
    rsa.c
  
  Summary:
    Crypto Framework Libarary source for cryptographic functions.

  Description:
    This source file contains functions that make up the Cryptographic 
	Framework Library for PIC32 families of Microchip microcontrollers.
**************************************************************************/

//DOM-IGNORE-BEGIN
/******************************************************************************
File Name:  rsa.c
Copyright © 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*******************************************************************************/
//DOM-IGNORE-END




#ifdef HAVE_CONFIG_H
    #include "config.h"
#endif
#include "system_config.h"

#include "crypto/src/settings.h"

#ifndef NO_RSA

#include "crypto/src/rsa.h"
#include "crypto/src/random.h"
#include "crypto/src/error-crypt.h"
#include "crypto/src/logging.h"
#ifdef NO_INLINE
    #include "crypto/src/misc.h"
#else
    #include "crypto/src/misc.c"
#endif

enum {
    RSA_PUBLIC_ENCRYPT  = 0,
    RSA_PUBLIC_DECRYPT  = 1,
    RSA_PRIVATE_ENCRYPT = 2,
    RSA_PRIVATE_DECRYPT = 3,

    RSA_BLOCK_TYPE_1 = 1,
    RSA_BLOCK_TYPE_2 = 2,

    RSA_MIN_SIZE = 512,
    RSA_MAX_SIZE = 4096,

    RSA_MIN_PAD_SZ   = 11      /* seperator + 0 + pad value + 8 pads */
};


int wc_InitRsaKey(RsaKey* key, void* heap)
{
    key->type = -1;  /* haven't decided yet */
    key->heap = heap;

/* TomsFastMath doesn't use memory allocation */
#ifndef USE_FAST_MATH
    key->n.dp = key->e.dp = 0;  /* public  alloc parts */

    key->d.dp = key->p.dp  = 0;  /* private alloc parts */
    key->q.dp = key->dP.dp = 0;  
    key->u.dp = key->dQ.dp = 0;
#else
    mp_init(&key->n);
    mp_init(&key->e);
    mp_init(&key->d);
    mp_init(&key->p);
    mp_init(&key->q);
    mp_init(&key->dP);
    mp_init(&key->dQ);
    mp_init(&key->u);
#endif

    return 0;
}


int wc_FreeRsaKey(RsaKey* key)
{
    (void)key;

/* TomsFastMath doesn't use memory allocation */
#ifndef USE_FAST_MATH
    if (key->type == RSA_PRIVATE) {
        mp_clear(&key->u);
        mp_clear(&key->dQ);
        mp_clear(&key->dP);
        mp_clear(&key->q);
        mp_clear(&key->p);
        mp_clear(&key->d);
    }
    mp_clear(&key->e);
    mp_clear(&key->n);
#endif

    return 0;
}

static int wc_RsaPad(const byte* input, word32 inputLen, byte* pkcsBlock,
                   word32 pkcsBlockLen, byte padValue, WC_RNG* rng)
{
    if (inputLen == 0)
        return 0;

    pkcsBlock[0] = 0x0;       /* set first byte to zero and advance */
    pkcsBlock++; pkcsBlockLen--;
    pkcsBlock[0] = padValue;  /* insert padValue */

    if (padValue == RSA_BLOCK_TYPE_1)
        /* pad with 0xff bytes */
        XMEMSET(&pkcsBlock[1], 0xFF, pkcsBlockLen - inputLen - 2);
    else {
        /* pad with non-zero random bytes */
        word32 padLen = pkcsBlockLen - inputLen - 1, i;
        int    ret    = wc_RNG_GenerateBlock(rng, &pkcsBlock[1], padLen);

        if (ret != 0)
            return ret;

        /* remove zeros */
        for (i = 1; i < padLen; i++)
            if (pkcsBlock[i] == 0) pkcsBlock[i] = 0x01;
    }

    pkcsBlock[pkcsBlockLen-inputLen-1] = 0;     /* separator */
    XMEMCPY(pkcsBlock+pkcsBlockLen-inputLen, input, inputLen);

    return 0;
}


/* UnPad plaintext, set start to *output, return length of plaintext,
 * < 0 on error */
static int RsaUnPad(const byte *pkcsBlock, unsigned int pkcsBlockLen,
                       byte **output, byte padValue)
{
    word32 maxOutputLen = (pkcsBlockLen > 10) ? (pkcsBlockLen - 10) : 0,
           invalid = 0,
           i = 1,
           outputLen;

    if (pkcsBlock[0] != 0x0) /* skip past zero */
        invalid = 1;
    pkcsBlock++; pkcsBlockLen--;

    /* Require block type padValue */
    invalid = (pkcsBlock[0] != padValue) || invalid;

    /* verify the padding until we find the separator */
    if (padValue == RSA_BLOCK_TYPE_1) {
        while (i<pkcsBlockLen && pkcsBlock[i++] == 0xFF) {/* Null body */}
    }
    else {
        while (i<pkcsBlockLen && pkcsBlock[i++]) {/* Null body */}
    }

    if(!(i==pkcsBlockLen || pkcsBlock[i-1]==0)) {
        WOLFSSL_MSG("RsaUnPad error, bad formatting");
        return RSA_PAD_E;
    }

    outputLen = pkcsBlockLen - i;
    invalid = (outputLen > maxOutputLen) || invalid;

    if (invalid) {
        WOLFSSL_MSG("RsaUnPad error, bad formatting");
        return RSA_PAD_E;
    }

    *output = (byte *)(pkcsBlock + i);
    return outputLen;
}


static int wc_RsaFunction(const byte* in, word32 inLen, byte* out,
                          word32* outLen, int type, RsaKey* key)
{
    #define ERROR_OUT(x) { ret = (x); goto done;}

    mp_int tmp;
    int    ret = 0;
    word32 keyLen, len;

    if (mp_init(&tmp) != MP_OKAY)
        return MP_INIT_E;

    if (mp_read_unsigned_bin(&tmp, (byte*)in, inLen) != MP_OKAY)
        ERROR_OUT(MP_READ_E);

    if (type == RSA_PRIVATE_DECRYPT || type == RSA_PRIVATE_ENCRYPT) {
        #ifdef RSA_LOW_MEM      /* half as much memory but twice as slow */
            if (mp_exptmod(&tmp, &key->d, &key->n, &tmp) != MP_OKAY)
                ERROR_OUT(MP_EXPTMOD_E);
        #else
            #define INNER_ERROR_OUT(x) { ret = (x); goto inner_done; }

            mp_int tmpa, tmpb;

            if (mp_init(&tmpa) != MP_OKAY)
                ERROR_OUT(MP_INIT_E);

            if (mp_init(&tmpb) != MP_OKAY) {
                mp_clear(&tmpa);
                ERROR_OUT(MP_INIT_E);
            }

            /* tmpa = tmp^dP mod p */
            if (mp_exptmod(&tmp, &key->dP, &key->p, &tmpa) != MP_OKAY)
                INNER_ERROR_OUT(MP_EXPTMOD_E);

            /* tmpb = tmp^dQ mod q */
            if (mp_exptmod(&tmp, &key->dQ, &key->q, &tmpb) != MP_OKAY)
                INNER_ERROR_OUT(MP_EXPTMOD_E);

            /* tmp = (tmpa - tmpb) * qInv (mod p) */
            if (mp_sub(&tmpa, &tmpb, &tmp) != MP_OKAY)
                INNER_ERROR_OUT(MP_SUB_E);

            if (mp_mulmod(&tmp, &key->u, &key->p, &tmp) != MP_OKAY)
                INNER_ERROR_OUT(MP_MULMOD_E);

            /* tmp = tmpb + q * tmp */
            if (mp_mul(&tmp, &key->q, &tmp) != MP_OKAY)
                INNER_ERROR_OUT(MP_MUL_E);

            if (mp_add(&tmp, &tmpb, &tmp) != MP_OKAY)
                INNER_ERROR_OUT(MP_ADD_E);

        inner_done:
            mp_clear(&tmpa);
            mp_clear(&tmpb);

            if (ret != 0) return ret;

        #endif   /* RSA_LOW_MEM */
    }
    else if (type == RSA_PUBLIC_ENCRYPT || type == RSA_PUBLIC_DECRYPT) {
        if (mp_exptmod(&tmp, &key->e, &key->n, &tmp) != MP_OKAY)
            ERROR_OUT(MP_EXPTMOD_E);
    }
    else
        ERROR_OUT(RSA_WRONG_TYPE_E);

    keyLen = mp_unsigned_bin_size(&key->n);
    if (keyLen > *outLen)
        ERROR_OUT(RSA_BUFFER_E);

    len = mp_unsigned_bin_size(&tmp);

    /* pad front w/ zeros to match key length */
    while (len < keyLen) {
        *out++ = 0x00;
        len++;
    }

    *outLen = keyLen;

    /* convert */
    if (mp_to_unsigned_bin(&tmp, out) != MP_OKAY)
        ERROR_OUT(MP_TO_E);

done:
    mp_clear(&tmp);
    if (ret == MP_EXPTMOD_E) {
        WOLFSSL_MSG("RSA_FUNCTION MP_EXPTMOD_E: memory/config problem");
    }
    return ret;
}


int wc_RsaPublicEncrypt(const byte* in, word32 inLen, byte* out, word32 outLen,
                     RsaKey* key, WC_RNG* rng)
{
    int sz, ret;

#ifdef HAVE_CAVIUM
    if (key->magic == WOLFSSL_RSA_CAVIUM_MAGIC)
        return CaviumRsaPublicEncrypt(in, inLen, out, outLen, key);
#endif

    sz = mp_unsigned_bin_size(&key->n);
    if (sz > (int)outLen)
        return RSA_BUFFER_E;

    if (inLen > (word32)(sz - RSA_MIN_PAD_SZ))
        return RSA_BUFFER_E;

    ret = wc_RsaPad(in, inLen, out, sz, RSA_BLOCK_TYPE_2, rng);
    if (ret != 0)
        return ret;

    if ((ret = wc_RsaFunction(out, sz, out, &outLen,
                              RSA_PUBLIC_ENCRYPT, key)) < 0)
        sz = ret;

    return sz;
}


int wc_RsaPrivateDecryptInline(byte* in, word32 inLen, byte** out, RsaKey* key)
{
    int ret;

#ifdef HAVE_CAVIUM
    if (key->magic == WOLFSSL_RSA_CAVIUM_MAGIC) {
        ret = CaviumRsaPrivateDecrypt(in, inLen, in, inLen, key);
        if (ret > 0)
            *out = in;
        return ret;
    }
#endif

    if ((ret = wc_RsaFunction(in, inLen, in, &inLen, RSA_PRIVATE_DECRYPT, key))
            < 0) {
        return ret;
    }
 
    return RsaUnPad(in, inLen, out, RSA_BLOCK_TYPE_2);
}


int wc_RsaPrivateDecrypt(const byte* in, word32 inLen, byte* out, word32 outLen,
                     RsaKey* key)
{
    int plainLen;
    byte*  tmp;
    byte*  pad = 0;

#ifdef HAVE_CAVIUM
    if (key->magic == WOLFSSL_RSA_CAVIUM_MAGIC)
        return CaviumRsaPrivateDecrypt(in, inLen, out, outLen, key);
#endif

    tmp = (byte*)XMALLOC(inLen, key->heap, DYNAMIC_TYPE_RSA);
    if (tmp == NULL) {
        return MEMORY_E;
    }

    XMEMCPY(tmp, in, inLen);

    if ( (plainLen = wc_RsaPrivateDecryptInline(tmp, inLen, &pad, key) ) < 0) {
        XFREE(tmp, key->heap, DYNAMIC_TYPE_RSA);
        return plainLen;
    }
    if (plainLen > (int)outLen)
        plainLen = BAD_FUNC_ARG;
    else
        XMEMCPY(out, pad, plainLen);

    ForceZero(tmp, inLen);
    XFREE(tmp, key->heap, DYNAMIC_TYPE_RSA);

    return plainLen;
}


/* for Rsa Verify */
int wc_RsaSSL_VerifyInline(byte* in, word32 inLen, byte** out, RsaKey* key)
{
    int ret;


    if ((ret = wc_RsaFunction(in, inLen, in, &inLen, RSA_PUBLIC_DECRYPT, key))
            < 0) {
        return ret;
    }
  
    return RsaUnPad(in, inLen, out, RSA_BLOCK_TYPE_1);
}


int wc_RsaSSL_Verify(const byte* in, word32 inLen, byte* out, word32 outLen,
                     RsaKey* key)
{
    int plainLen;
    byte*  tmp;
    byte*  pad = 0;

    tmp = (byte*)XMALLOC(inLen, key->heap, DYNAMIC_TYPE_RSA);
    if (tmp == NULL) {
        return MEMORY_E;
    }

    XMEMCPY(tmp, in, inLen);

    if ( (plainLen = wc_RsaSSL_VerifyInline(tmp, inLen, &pad, key) ) < 0) {
        XFREE(tmp, key->heap, DYNAMIC_TYPE_RSA);
        return plainLen;
    }

    if (plainLen > (int)outLen)
        plainLen = BAD_FUNC_ARG;
    else
        XMEMCPY(out, pad, plainLen);

    ForceZero(tmp, inLen);
    XFREE(tmp, key->heap, DYNAMIC_TYPE_RSA);

    return plainLen;
}

#include "internal.h"
#include "wolfssl/internal.h"
/* for Rsa Sign */
int wc_RsaSSL_Sign(const byte* in, word32 inLen, byte* out, word32 outLen,
                      RsaKey* key, WC_RNG* rng)
{
    int sz, ret;

#ifdef HAVE_CAVIUM
    if (key->magic == WOLFSSL_RSA_CAVIUM_MAGIC)
        return CaviumRsaSSL_Sign(in, inLen, out, outLen, key);
#endif

    sz = mp_unsigned_bin_size(&key->n);
    if (sz > (int)outLen)
        return RSA_BUFFER_E;

    if (inLen > (word32)(sz - RSA_MIN_PAD_SZ))
        return RSA_BUFFER_E;

    ret = wc_RsaPad(in, inLen, out, sz, RSA_BLOCK_TYPE_1, rng);
    if (ret != 0)
        return ret;

    if ((ret = wc_RsaFunction(out, sz, out, &outLen,
                              RSA_PRIVATE_ENCRYPT,key)) < 0)
        sz = ret;
    
    return sz;
}


int wc_RsaEncryptSize(RsaKey* key)
{
    return mp_unsigned_bin_size(&key->n);
}

/* flatten RsaKey structure into individual elements (e, n) */
int wc_RsaFlattenPublicKey(RsaKey* key, byte* e, word32* eSz, byte* n,
                           word32* nSz)
{
    int sz, ret;

    if (key == NULL || e == NULL || eSz == NULL || n == NULL || nSz == NULL)
       return BAD_FUNC_ARG;

    sz = mp_unsigned_bin_size(&key->e);
    if ((word32)sz > *nSz)
        return RSA_BUFFER_E;
    ret = mp_to_unsigned_bin(&key->e, e);
    if (ret != MP_OKAY)
        return ret;
    *eSz = (word32)sz;

    sz = mp_unsigned_bin_size(&key->n);
    if ((word32)sz > *nSz)
        return RSA_BUFFER_E;
    ret = mp_to_unsigned_bin(&key->n, n);
    if (ret != MP_OKAY)
        return ret;
    *nSz = (word32)sz;

    return 0;
}

#ifdef WOLFSSL_KEY_GEN
/* Make an RSA key for size bits, with e specified, 65537 is a good e */
int wc_MakeRsaKey(RsaKey* key, int size, long e, WC_RNG* rng)
{
    mp_int p, q, tmp1, tmp2, tmp3;
    int    err;

    if (key == NULL || rng == NULL)
        return BAD_FUNC_ARG;

    if (size < RSA_MIN_SIZE || size > RSA_MAX_SIZE)
        return BAD_FUNC_ARG;

    if (e < 3 || (e & 1) == 0)
        return BAD_FUNC_ARG;

    if ((err = mp_init_multi(&p, &q, &tmp1, &tmp2, &tmp3, NULL)) != MP_OKAY)
        return err;

    err = mp_set_int(&tmp3, e);

    /* make p */
    if (err == MP_OKAY) {
        do {
            err = mp_rand_prime(&p, size/16, rng, key->heap); /* size in bytes/2 */

            if (err == MP_OKAY)
                err = mp_sub_d(&p, 1, &tmp1);  /* tmp1 = p-1 */

            if (err == MP_OKAY)
                err = mp_gcd(&tmp1, &tmp3, &tmp2);  /* tmp2 = gcd(p-1, e) */
        } while (err == MP_OKAY && mp_cmp_d(&tmp2, 1) != 0);  /* e divdes p-1 */
    }

    /* make q */
    if (err == MP_OKAY) {
        do {
            err = mp_rand_prime(&q, size/16, rng, key->heap); /* size in bytes/2 */

            if (err == MP_OKAY)
                err = mp_sub_d(&q, 1, &tmp1);  /* tmp1 = q-1 */

            if (err == MP_OKAY)
                err = mp_gcd(&tmp1, &tmp3, &tmp2);  /* tmp2 = gcd(q-1, e) */
        } while (err == MP_OKAY && mp_cmp_d(&tmp2, 1) != 0);  /* e divdes q-1 */
    }

    if (err == MP_OKAY)
        err = mp_init_multi(&key->n, &key->e, &key->d, &key->p, &key->q, NULL);

    if (err == MP_OKAY)
        err = mp_init_multi(&key->dP, &key->dQ, &key->u, NULL, NULL, NULL);

    if (err == MP_OKAY)
        err = mp_sub_d(&p, 1, &tmp2);  /* tmp2 = p-1 */

    if (err == MP_OKAY)
        err = mp_lcm(&tmp1, &tmp2, &tmp1);  /* tmp1 = lcm(p-1, q-1),last loop */

    /* make key */
    if (err == MP_OKAY)
        err = mp_set_int(&key->e, e);  /* key->e = e */

    if (err == MP_OKAY)                /* key->d = 1/e mod lcm(p-1, q-1) */
        err = mp_invmod(&key->e, &tmp1, &key->d);

    if (err == MP_OKAY)
        err = mp_mul(&p, &q, &key->n);  /* key->n = pq */

    if (err == MP_OKAY)
        err = mp_sub_d(&p, 1, &tmp1);

    if (err == MP_OKAY)
        err = mp_sub_d(&q, 1, &tmp2);

    if (err == MP_OKAY)
        err = mp_mod(&key->d, &tmp1, &key->dP);

    if (err == MP_OKAY)
        err = mp_mod(&key->d, &tmp2, &key->dQ);

    if (err == MP_OKAY)
        err = mp_invmod(&q, &p, &key->u);

    if (err == MP_OKAY)
        err = mp_copy(&p, &key->p);

    if (err == MP_OKAY)
        err = mp_copy(&q, &key->q);

    if (err == MP_OKAY)
        key->type = RSA_PRIVATE; 

    mp_clear(&tmp3); 
    mp_clear(&tmp2); 
    mp_clear(&tmp1); 
    mp_clear(&q); 
    mp_clear(&p);

    if (err != MP_OKAY) {
        wc_FreeRsaKey(key);        
        return err;
    }

    return 0;
}


#endif /* WOLFSSL_KEY_GEN */



#endif /* NO_RSA */
