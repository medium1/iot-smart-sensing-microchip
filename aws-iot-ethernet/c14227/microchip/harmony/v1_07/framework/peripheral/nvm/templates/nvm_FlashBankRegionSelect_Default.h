/*******************************************************************************
  NVM Peripheral Library Template Implementation

  File Name:
    nvm_FlashBankRegionSelect_Default.h

  Summary:
    NVM PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : FlashBankRegionSelect
    and its Variant : Default
    For following APIs :
        PLIB_NVM_ExistsFlashBankRegionSelect
        PLIB_NVM_ProgramFlashBank1LowerRegion
        PLIB_NVM_ProgramFlashBank2LowerRegion
        PLIB_NVM_ProgramFlashBank2IsLowerRegion

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

#ifndef _NVM_FLASHBANKREGIONSELECT_DEFAULT_H
#define _NVM_FLASHBANKREGIONSELECT_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _NVM_PROGRAM_FLASH_BANK_REGION_SELECT_VREG(index)

  MASKs: 
    _NVM_PROGRAM_FLASH_BANK_REGION_SELECT_MASK(index)

  POSs: 
    _NVM_PROGRAM_FLASH_BANK_REGION_SELECT_POS(index)

  LENs: 
    _NVM_PROGRAM_FLASH_BANK_REGION_SELECT_LEN(index)

*/


//******************************************************************************
/* Function :  NVM_ExistsFlashBankRegionSelect_Default

  Summary:
    Implements Default variant of PLIB_NVM_ExistsFlashBankRegionSelect

  Description:
    This template implements the Default variant of the PLIB_NVM_ExistsFlashBankRegionSelect function.
*/

#define PLIB_NVM_ExistsFlashBankRegionSelect PLIB_NVM_ExistsFlashBankRegionSelect
PLIB_TEMPLATE bool NVM_ExistsFlashBankRegionSelect_Default( NVM_MODULE_ID index )
{
    return true;
}


//******************************************************************************
/* Function :  NVM_ProgramFlashBank1LowerRegion_Default

  Summary:
    Implements Default variant of PLIB_NVM_ProgramFlashBank1LowerRegion 

  Description:
    This template implements the Default variant of the PLIB_NVM_ProgramFlashBank1LowerRegion function.
*/

PLIB_TEMPLATE void NVM_ProgramFlashBank1LowerRegion_Default( NVM_MODULE_ID index )
{
    _SFR_BIT_CLEAR(_NVM_PROGRAM_FLASH_BANK_REGION_SELECT_VREG(index),
                     _NVM_PROGRAM_FLASH_BANK_REGION_SELECT_POS(index) );
}


//******************************************************************************
/* Function :  NVM_ProgramFlashBank2LowerRegion_Default

  Summary:
    Implements Default variant of PLIB_NVM_ProgramFlashBank2LowerRegion 

  Description:
    This template implements the Default variant of the PLIB_NVM_ProgramFlashBank2LowerRegion function.
*/

PLIB_TEMPLATE void NVM_ProgramFlashBank2LowerRegion_Default( NVM_MODULE_ID index )
{
    _SFR_BIT_SET(_NVM_PROGRAM_FLASH_BANK_REGION_SELECT_VREG(index),
                     _NVM_PROGRAM_FLASH_BANK_REGION_SELECT_POS(index) );
}


//******************************************************************************
/* Function :  NVM_ProgramFlashBank2IsLowerRegion_Default

  Summary:
    Implements Default variant of PLIB_NVM_ProgramFlashBank2IsLowerRegion 

  Description:
    This template implements the Default variant of the PLIB_NVM_ProgramFlashBank2IsLowerRegion function.
*/

PLIB_TEMPLATE bool NVM_ProgramFlashBank2IsLowerRegion_Default( NVM_MODULE_ID index )
{
    return (_SFR_BIT_READ(_NVM_PROGRAM_FLASH_BANK_REGION_SELECT_VREG(index), _NVM_PROGRAM_FLASH_BANK_REGION_SELECT_POS(index)));
}


#endif /*_NVM_FLASHBANKREGIONSELECT_DEFAULT_H*/

/******************************************************************************
 End of File
*/
