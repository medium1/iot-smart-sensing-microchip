/**************************************************************************
  Crypto Framework Library Header

  Company:
    Microchip Technology Inc.

  File Name:
    error.h
  
  Summary:
    Crypto Framework Library header for cryptographic functions.

  Description:
    This header file contains function prototypes and definitions of
    the data types and constants that make up the Cryptographic Framework
    Library for PIC32 families of Microchip microcontrollers.
**************************************************************************/

//DOM-IGNORE-BEGIN
/******************************************************************************
Copyright � 2013 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED �AS IS� WITHOUT WARRANTY OF ANY KIND,
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




#ifndef CRYPT_ERROR_H
#define CRYPT_ERROR_H

#include "crypto/src/types.h"

#ifdef __cplusplus
    extern "C" {
#endif


/* error codes */
enum {
    MAX_CODE_E         = -100,  /* errors -101 - -299 */
    OPEN_RAN_E         = -101,  /* opening random device error */
    READ_RAN_E         = -102,  /* reading random device error */
    WINCRYPT_E         = -103,  /* windows crypt init error */
    CRYPTGEN_E         = -104,  /* windows crypt generation error */
    RAN_BLOCK_E        = -105,  /* reading random device would block */
    BAD_MUTEX_E        = -106,  /* Bad mutex operation */

    MP_INIT_E          = -110,  /* mp_init error state */
    MP_READ_E          = -111,  /* mp_read error state */
    MP_EXPTMOD_E       = -112,  /* mp_exptmod error state */
    MP_TO_E            = -113,  /* mp_to_xxx error state, can't convert */
    MP_SUB_E           = -114,  /* mp_sub error state, can't subtract */
    MP_ADD_E           = -115,  /* mp_add error state, can't add */
    MP_MUL_E           = -116,  /* mp_mul error state, can't multiply */
    MP_MULMOD_E        = -117,  /* mp_mulmod error state, can't multiply mod */
    MP_MOD_E           = -118,  /* mp_mod error state, can't mod */
    MP_INVMOD_E        = -119,  /* mp_invmod error state, can't inv mod */
    MP_CMP_E           = -120,  /* mp_cmp error state */
    MP_ZERO_E          = -121,  /* got a mp zero result, not expected */

    MEMORY_E           = -125,  /* out of memory error */

    RSA_WRONG_TYPE_E   = -130,  /* RSA wrong block type for RSA function */
    RSA_BUFFER_E       = -131,  /* RSA buffer error, output too small or
                                   input too large */
    BUFFER_E           = -132,  /* output buffer too small or input too large */
    ALGO_ID_E          = -133,  /* setting algo id error */
    PUBLIC_KEY_E       = -134,  /* setting public key error */
    DATE_E             = -135,  /* setting date validity error */
    SUBJECT_E          = -136,  /* setting subject name error */
    ISSUER_E           = -137,  /* setting issuer  name error */
    CA_TRUE_E          = -138,  /* setting CA basic constraint true error */
    EXTENSIONS_E       = -139,  /* setting extensions error */

    ASN_PARSE_E        = -140,  /* ASN parsing error, invalid input */
    ASN_VERSION_E      = -141,  /* ASN version error, invalid number */
    ASN_GETINT_E       = -142,  /* ASN get big int error, invalid data */
    ASN_RSA_KEY_E      = -143,  /* ASN key init error, invalid input */
    ASN_OBJECT_ID_E    = -144,  /* ASN object id error, invalid id */
    ASN_TAG_NULL_E     = -145,  /* ASN tag error, not null */
    ASN_EXPECT_0_E     = -146,  /* ASN expect error, not zero */
    ASN_BITSTR_E       = -147,  /* ASN bit string error, wrong id */
    ASN_UNKNOWN_OID_E  = -148,  /* ASN oid error, unknown sum id */
    ASN_DATE_SZ_E      = -149,  /* ASN date error, bad size */
    ASN_BEFORE_DATE_E  = -150,  /* ASN date error, current date before */
    ASN_AFTER_DATE_E   = -151,  /* ASN date error, current date after */
    ASN_SIG_OID_E      = -152,  /* ASN signature error, mismatched oid */
    ASN_TIME_E         = -153,  /* ASN time error, unknown time type */
    ASN_INPUT_E        = -154,  /* ASN input error, not enough data */
    ASN_SIG_CONFIRM_E  = -155,  /* ASN sig error, confirm failure */
    ASN_SIG_HASH_E     = -156,  /* ASN sig error, unsupported hash type */
    ASN_SIG_KEY_E      = -157,  /* ASN sig error, unsupported key type */
    ASN_DH_KEY_E       = -158,  /* ASN key init error, invalid input */
    ASN_NTRU_KEY_E     = -159,  /* ASN ntru key decode error, invalid input */
    ASN_CRIT_EXT_E     = -160,  /* ASN unsupported critical extension */

    ECC_BAD_ARG_E      = -170,  /* ECC input argument of wrong type */
    ASN_ECC_KEY_E      = -171,  /* ASN ECC bad input */
    ECC_CURVE_OID_E    = -172,  /* Unsupported ECC OID curve type */
    BAD_FUNC_ARG       = -173,  /* Bad function argument provided */
    NOT_COMPILED_IN    = -174,  /* Feature not compiled in */
    UNICODE_SIZE_E     = -175,  /* Unicode password too big */
    NO_PASSWORD        = -176,  /* no password provided by user */
    ALT_NAME_E         = -177,  /* alt name size problem, too big */

    AES_GCM_AUTH_E     = -180,  /* AES-GCM Authentication check failure */
    AES_CCM_AUTH_E     = -181,  /* AES-CCM Authentication check failure */

    CAVIUM_INIT_E      = -182,  /* Cavium Init type error */

    COMPRESS_INIT_E    = -183,  /* Compress init error */
    COMPRESS_E         = -184,  /* Compress error */
    DECOMPRESS_INIT_E  = -185,  /* DeCompress init error */
    DECOMPRESS_E       = -186,  /* DeCompress error */

    BAD_ALIGN_E         = -187,  /* Bad alignment for operation, no alloc */
    ASN_NO_SIGNER_E     = -188,  /* ASN no signer to confirm failure */
    ASN_CRL_CONFIRM_E   = -189,  /* ASN CRL signature confirm failure */
    ASN_CRL_NO_SIGNER_E = -190,  /* ASN CRL no signer to confirm failure */
    ASN_OCSP_CONFIRM_E  = -191,  /* ASN OCSP signature confirm failure */

    BAD_ENC_STATE_E     = -192,  /* Bad ecc enc state operation */
    BAD_PADDING_E       = -193,  /* Bad padding, msg not correct length  */

    REQ_ATTRIBUTE_E     = -194,  /* setting cert request attributes error */

    PKCS7_OID_E         = -195,  /* PKCS#7, mismatched OID error */
    PKCS7_RECIP_E       = -196,  /* PKCS#7, recipient error */
    FIPS_NOT_ALLOWED_E  = -197,  /* FIPS not allowed error */
    ASN_NAME_INVALID_E  = -198,  /* ASN name constraint error */

    RNG_FAILURE_E       = -199,  /* RNG Failed, Reinitialize */
    HMAC_MIN_KEYLEN_E   = -200,  /* FIPS Mode HMAC Minimum Key Length error */
    RSA_PAD_E           = -201,  /* RSA Padding Error */
    LENGTH_ONLY_E       = -202,  /* Returning output length only */

    IN_CORE_FIPS_E      = -203,  /* In Core Integrity check failure */
    AES_KAT_FIPS_E      = -204,  /* AES KAT failure */
    DES3_KAT_FIPS_E     = -205,  /* DES3 KAT failure */
    HMAC_KAT_FIPS_E     = -206,  /* HMAC KAT failure */
    RSA_KAT_FIPS_E      = -207,  /* RSA KAT failure */
    DRBG_KAT_FIPS_E     = -208,  /* HASH DRBG KAT failure */
    DRBG_CONT_FIPS_E    = -209,  /* HASH DRBG Continious test failure */
    AESGCM_KAT_FIPS_E   = -210,  /* AESGCM KAT failure */
    THREAD_STORE_KEY_E  = -211,  /* Thread local storage key create failure */
    THREAD_STORE_SET_E  = -212,  /* Thread local storage key set failure */

    MAC_CMP_FAILED_E    = -213,  /* MAC comparison failed */
    IS_POINT_E          = -214,  /* ECC is point on curve failed */
    ECC_INF_E           = -215,  /* ECC point infinity error */
    ECC_PRIV_KEY_E      = -216,  /* ECC private key not valid error */

    SRP_CALL_ORDER_E    = -217,  /* SRP function called in the wrong order. */
    SRP_VERIFY_E        = -218,  /* SRP proof verification failed. */
    SRP_BAD_KEY_E       = -219,  /* SRP bad ephemeral values. */

    ASN_NO_SKID         = -220,  /* ASN no Subject Key Identifier found */
    ASN_NO_AKID         = -221,  /* ASN no Authority Key Identifier found */
    ASN_NO_KEYUSAGE     = -223,  /* ASN no Key Usage found */
    SKID_E              = -224,  /* setting Subject Key Identifier error */
    AKID_E              = -225,  /* setting Authority Key Identifier error */
    KEYUSAGE_E          = -226,  /* Bad Key Usage value */
    CERTPOLICIES_E      = -227,  /* setting Certificate Policies error */

    WC_INIT_E           = -228,  /* wolfcrypt failed to initialize */
    SIG_VERIFY_E        = -229,  /* wolfcrypt signature verify error */
    BAD_COND_E          = -230,  /* Bad condition variable operation */

    MIN_CODE_E          = -300   /* errors -101 - -299 */
};


WOLFSSL_API void wc_ErrorString(int err, char* buff);
WOLFSSL_API const char* wc_GetErrorString(int error);


#ifdef __cplusplus
    } /* extern "C" */
#endif
#endif /* CRYPT_ERROR_H */
