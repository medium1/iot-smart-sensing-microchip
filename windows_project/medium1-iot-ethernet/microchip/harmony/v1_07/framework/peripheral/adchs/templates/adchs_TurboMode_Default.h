/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_TurboMode_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : TurboMode
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_TurboModeEnable
        PLIB_ADCHS_TurboModeDisable
        PLIB_ADCHS_TurboModeErrorHasOccurred
        PLIB_ADCHS_TurboModeChannelSelect
        PLIB_ADCHS_ExistsTurboMode

*******************************************************************************/

//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013 released Microchip Technology Inc.  All rights reserved.

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

#ifndef _ADCHS_TURBOMODE_DEFAULT_H
#define _ADCHS_TURBOMODE_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_TURBO_MODE_ENABLE_CONTROL_VREG(index)
    _ADCHS_TURBO_MODE_ERROR_CHECK_VREG(index)
    _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_VREG(index)
    _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_VREG(index)

  MASKs: 
    _ADCHS_TURBO_MODE_ENABLE_CONTROL_MASK(index)
    _ADCHS_TURBO_MODE_ERROR_CHECK_MASK(index)
    _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_MASK(index)
    _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_MASK(index)

  POSs: 
    _ADCHS_TURBO_MODE_ENABLE_CONTROL_POS(index)
    _ADCHS_TURBO_MODE_ERROR_CHECK_POS(index)
    _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_POS(index)
    _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_POS(index)

  LENs: 
    _ADCHS_TURBO_MODE_ENABLE_CONTROL_LEN(index)
    _ADCHS_TURBO_MODE_ERROR_CHECK_LEN(index)
    _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_LEN(index)
    _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_TurboModeEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_TurboModeEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_TurboModeEnable function.
*/

PLIB_TEMPLATE void ADCHS_TurboModeEnable_Default( ADCHS_MODULE_ID index )
{
	_SFR_BIT_WRITE(_ADCHS_TURBO_MODE_ENABLE_CONTROL_VREG(index),
				 _ADCHS_TURBO_MODE_ENABLE_CONTROL_POS(index),
				  1 );
}


//******************************************************************************
/* Function :  ADCHS_TurboModeDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_TurboModeDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_TurboModeDisable function.
*/

PLIB_TEMPLATE void ADCHS_TurboModeDisable_Default( ADCHS_MODULE_ID index )
{
	_SFR_BIT_WRITE(_ADCHS_TURBO_MODE_ENABLE_CONTROL_VREG(index),
				 _ADCHS_TURBO_MODE_ENABLE_CONTROL_POS(index),
				  0 );
}


//******************************************************************************
/* Function :  ADCHS_TurboModeErrorHasOccurred_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_TurboModeErrorHasOccurred 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_TurboModeErrorHasOccurred function.
*/

PLIB_TEMPLATE bool ADCHS_TurboModeErrorHasOccurred_Default( ADCHS_MODULE_ID index )
{
        return _SFR_BIT_READ(_ADCHS_TURBO_MODE_ERROR_CHECK_VREG(index),
                             _ADCHS_TURBO_MODE_ERROR_CHECK_POS(index) );
}


//******************************************************************************
/* Function :  ADCHS_TurboModeChannelSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_TurboModeChannelSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_TurboModeChannelSelect function.
*/

PLIB_TEMPLATE bool ADCHS_TurboModeChannelSelect_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID masterChannelID , ADCHS_CHANNEL_ID slaveChannelID )
{
	if((masterChannelID == ADCHS_CHANNEL_7) || (slaveChannelID == ADCHS_CHANNEL_7))
		return false;
	
	_SFR_FIELD_WRITE(_ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_VREG(index),
					 _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_MASK(index),
					 _ADCHS_TURBO_MODE_MASTER_CHANNEL_SELECT_POS(index) ,
					 masterChannelID );
					 
	_SFR_FIELD_WRITE(_ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_VREG(index),
					 _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_MASK(index),
					 _ADCHS_TURBO_MODE_SLAVE_CHANNEL_SELECT_POS(index) ,
					 slaveChannelID );					 
					 
	 return true;
						 
}


//******************************************************************************
/* Function :  ADCHS_ExistsTurboMode_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsTurboMode

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsTurboMode function.
*/

#define PLIB_ADCHS_ExistsTurboMode PLIB_ADCHS_ExistsTurboMode
PLIB_TEMPLATE bool ADCHS_ExistsTurboMode_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_TURBOMODE_DEFAULT_H*/

/******************************************************************************
 End of File
*/

