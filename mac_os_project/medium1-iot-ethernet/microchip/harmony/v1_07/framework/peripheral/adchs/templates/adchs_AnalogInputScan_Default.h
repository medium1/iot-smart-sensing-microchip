/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_AnalogInputScan_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AnalogInputScan
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_AnalogInputScanIsComplete
        PLIB_ADCHS_AnalogInputScanSelect
        PLIB_ADCHS_AnalogInputScanRemove
        PLIB_ADCHS_AnalogInputScanIsSelected
        PLIB_ADCHS_AnalogInputScanSetup
        PLIB_ADCHS_ScanCompleteInterruptEnable
        PLIB_ADCHS_ScanCompleteInterruptDisable
        PLIB_ADCHS_ExistsAnalogInputScan

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

#ifndef _ADCHS_ANALOGINPUTSCAN_DEFAULT_H
#define _ADCHS_ANALOGINPUTSCAN_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are

  VREGs:
    _ADCHS_SCAN_COMPLETE_CHECK_VREG(index)
    _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_VREG(index)
    _ADCHS_SCAN_TRG_LEVEL_CONTROL_VREG(index)
    _ADCHS_SCAN_SELECT_REG_1_VREG(index)
    _ADCHS_SCAN_SELECT_REG_2_VREG(index)

  MASKs:
    _ADCHS_SCAN_COMPLETE_CHECK_MASK(index)
    _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_MASK(index)
    _ADCHS_SCAN_TRG_LEVEL_CONTROL_MASK(index)
    _ADCHS_SCAN_SELECT_REG_1_MASK(index)
    _ADCHS_SCAN_SELECT_REG_2_MASK(index)

  POSs:
    _ADCHS_SCAN_COMPLETE_CHECK_POS(index)
    _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_POS(index)
    _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_POS(index)
    _ADCHS_SCAN_TRG_LEVEL_CONTROL_POS(index)
    _ADCHS_SCAN_SELECT_REG_1_POS(index)
    _ADCHS_SCAN_SELECT_REG_2_POS(index)

  LENs:
    _ADCHS_SCAN_COMPLETE_CHECK_LEN(index)
    _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_LEN(index)
    _ADCHS_SCAN_TRG_LEVEL_CONTROL_LEN(index)
    _ADCHS_SCAN_SELECT_REG_1_LEN(index)
    _ADCHS_SCAN_SELECT_REG_2_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanIsComplete_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputScanIsComplete

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputScanIsComplete function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputScanIsComplete_Default( ADCHS_MODULE_ID index )
{
    return( _SFR_BIT_READ( _ADCHS_SCAN_COMPLETE_CHECK_VREG( index ),
                           _ADCHS_SCAN_COMPLETE_CHECK_POS( index ) ) );
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputScanSelect

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputScanSelect function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputScanSelect_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput <= 31 )
	{
		_SFR_BIT_WRITE( _ADCHS_SCAN_SELECT_REG_1_VREG( index ),
					  analogInput,
						1 );
	}
	else
	{
		_SFR_BIT_WRITE( _ADCHS_SCAN_SELECT_REG_2_VREG( index ),
					  (analogInput - 32),
						1 );
	}
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanRemove_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputScanRemove

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputScanRemove function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputScanRemove_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput <= 31 )
	{
		_SFR_BIT_WRITE( _ADCHS_SCAN_SELECT_REG_1_VREG( index ),
					  analogInput,
						0 );
	}
	else
	{
		_SFR_BIT_WRITE( _ADCHS_SCAN_SELECT_REG_2_VREG( index ),
					  (analogInput - 32),
						0 );
	}
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanIsSelected_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputScanIsSelected

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputScanIsSelected function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputScanIsSelected_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput <= 31 )
	{
		return( _SFR_BIT_READ( _ADCHS_SCAN_SELECT_REG_1_VREG( index ),
					  analogInput ));
	}
	else
	{
		return( _SFR_BIT_READ( _ADCHS_SCAN_SELECT_REG_2_VREG( index ),
					  (analogInput - 32) ));
	}
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputScanSetup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputScanSetup

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputScanSetup function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputScanSetup_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput,	ADCHS_SCAN_TRIGGER_SENSITIVE trgSensitive , ADCHS_SCAN_TRIGGER_SOURCE triggerSource )
{
 	if( analogInput <= 31 )
	{
		_SFR_BIT_WRITE( _ADCHS_SCAN_SELECT_REG_1_VREG( index ),
					  analogInput,
						1 );
	}
	else
	{
		_SFR_BIT_WRITE( _ADCHS_SCAN_SELECT_REG_2_VREG( index ),
					  (analogInput - 32),
						1 );
	}

	switch( trgSensitive )
	{
		case ADCHS_SCAN_TRIGGER_SENSITIVE_EDGE:
			_SFR_BIT_WRITE( _ADCHS_SCAN_TRG_LEVEL_CONTROL_VREG( index ),
						  _ADCHS_SCAN_TRG_LEVEL_CONTROL_POS( index ), 0 );
			break;

		case ADCHS_SCAN_TRIGGER_SENSITIVE_LEVEL:
			_SFR_BIT_WRITE( _ADCHS_SCAN_TRG_LEVEL_CONTROL_VREG( index ),
						  _ADCHS_SCAN_TRG_LEVEL_CONTROL_POS( index ), 1 );
			break;

		default:
			break;
	}

	_SFR_FIELD_WRITE( _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_VREG( index ),
				  _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_MASK( index ),
				  _ADCHS_SCAN_TRIGGER_SOURCE_SELECT_POS( index ),
				  triggerSource );
}


//******************************************************************************
/* Function :  ADCHS_ScanCompleteInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ScanCompleteInterruptEnable

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ScanCompleteInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_ScanCompleteInterruptEnable_Default( ADCHS_MODULE_ID index )
{
	_SFR_BIT_WRITE( _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_VREG( index ),
				  _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_POS( index ), 1 );
}


//******************************************************************************
/* Function :  ADCHS_ScanCompleteInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ScanCompleteInterruptDisable

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ScanCompleteInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_ScanCompleteInterruptDisable_Default( ADCHS_MODULE_ID index )
{
	_SFR_BIT_WRITE( _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_VREG( index ),
				  _ADCHS_SCAN_COMPLETE_INTERRUPT_CONTROL_POS( index ), 0 );
}


//******************************************************************************
/* Function :  ADCHS_ExistsAnalogInputScan_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsAnalogInputScan

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsAnalogInputScan function.
*/

#define PLIB_ADCHS_ExistsAnalogInputScan PLIB_ADCHS_ExistsAnalogInputScan
PLIB_TEMPLATE bool ADCHS_ExistsAnalogInputScan_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_ANALOGINPUTSCAN_DEFAULT_H*/

/******************************************************************************
 End of File
*/

