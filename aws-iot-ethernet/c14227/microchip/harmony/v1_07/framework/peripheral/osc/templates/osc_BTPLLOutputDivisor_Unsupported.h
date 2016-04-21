/*******************************************************************************
  OSC Peripheral Library Template Implementation

  File Name:
    osc_BTPLLOutputDivisor_Unsupported.h

  Summary:
    OSC PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : BTPLLOutputDivisor
    and its Variant : Unsupported
    For following APIs :
        PLIB_OSC_ExistsBTPLLOutputDivisor
        PLIB_OSC_BTPLLOutputDivisorSet
        PLIB_OSC_BTPLLOutputDivisorGet

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
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

#ifndef _OSC_BTPLLOUTPUTDIVISOR_UNSUPPORTED_H
#define _OSC_BTPLLOUTPUTDIVISOR_UNSUPPORTED_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    None.

  MASKs: 
    None.

  POSs: 
    None.

  LENs: 
    None.

*/


//******************************************************************************
/* Function :  OSC_ExistsBTPLLOutputDivisor_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_OSC_ExistsBTPLLOutputDivisor

  Description:
    This template implements the Unsupported variant of the PLIB_OSC_ExistsBTPLLOutputDivisor function.
*/

PLIB_TEMPLATE bool OSC_ExistsBTPLLOutputDivisor_Unsupported( OSC_MODULE_ID index )
{
    return false;
}


//******************************************************************************
/* Function :  OSC_BTPLLOutputDivisorSet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_OSC_BTPLLOutputDivisorSet 

  Description:
    This template implements the Unsupported variant of the PLIB_OSC_BTPLLOutputDivisorSet function.
*/

PLIB_TEMPLATE void OSC_BTPLLOutputDivisorSet_Unsupported( OSC_MODULE_ID index , OSC_BTPLL_OUT_DIV PLLOutDiv )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_OSC_BTPLLOutputDivisorSet");
}


//******************************************************************************
/* Function :  OSC_BTPLLOutputDivisorGet_Unsupported

  Summary:
    Implements Unsupported variant of PLIB_OSC_BTPLLOutputDivisorGet 

  Description:
    This template implements the Unsupported variant of the PLIB_OSC_BTPLLOutputDivisorGet function.
*/

PLIB_TEMPLATE uint16_t OSC_BTPLLOutputDivisorGet_Unsupported( OSC_MODULE_ID index )
{
    PLIB_ASSERT(false, "The device selected does not implement PLIB_OSC_BTPLLOutputDivisorGet");

    return (uint16_t) 0;
}


#endif /*_OSC_BTPLLOUTPUTDIVISOR_UNSUPPORTED_H*/

/******************************************************************************
 End of File
*/

