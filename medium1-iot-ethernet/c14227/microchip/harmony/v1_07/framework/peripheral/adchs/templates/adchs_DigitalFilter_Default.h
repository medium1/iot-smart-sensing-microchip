/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DigitalFilter_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DigitalFilter
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_DigitalFilterEnable
        PLIB_ADCHS_DigitalFilterDisable
        PLIB_ADCHS_DigitalFilterOversamplingModeSetup
        PLIB_ADCHS_DigitalFilterAveragingModeSetup
        PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect
        PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect
        PLIB_ADCHS_DigitalFilterDataIsReady
        PLIB_ADCHS_DigitalFilterDataGet
        PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable
        PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable
        PLIB_ADCHS_ExistsDigitalFilter

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

#ifndef _ADCHS_DIGITALFILTER_DEFAULT_H
#define _ADCHS_DIGITALFILTER_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_2_ENABLE_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_3_ENABLE_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_4_ENABLE_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_5_ENABLE_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_6_ENABLE_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_REG_1_VREG(index)
    _ADCHS_DIGITAL_FILTER_REG_2_VREG(index)
    _ADCHS_DIGITAL_FILTER_REG_3_VREG(index)
    _ADCHS_DIGITAL_FILTER_REG_4_VREG(index)
    _ADCHS_DIGITAL_FILTER_REG_5_VREG(index)
    _ADCHS_DIGITAL_FILTER_REG_6_VREG(index)
    _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_VREG(index)
    _ADCHS_DIGITAL_FILTER_2_RATIO_SELECT_VREG(index)
    _ADCHS_DIGITAL_FILTER_3_RATIO_SELECT_VREG(index)
    _ADCHS_DIGITAL_FILTER_4_RATIO_SELECT_VREG(index)
    _ADCHS_DIGITAL_FILTER_5_RATIO_SELECT_VREG(index)
    _ADCHS_DIGITAL_FILTER_6_RATIO_SELECT_VREG(index)
    _ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_VREG(index)
    _ADCHS_DIGITAL_FILTER_2_DATA_READY_STATUS_VREG(index)
    _ADCHS_DIGITAL_FILTER_3_DATA_READY_STATUS_VREG(index)
    _ADCHS_DIGITAL_FILTER_4_DATA_READY_STATUS_VREG(index)
    _ADCHS_DIGITAL_FILTER_5_DATA_READY_STATUS_VREG(index)
    _ADCHS_DIGITAL_FILTER_6_DATA_READY_STATUS_VREG(index)
    _ADCHS_DIGITAL_FILTER_1_DATA_VREG(index)
    _ADCHS_DIGITAL_FILTER_2_DATA_VREG(index)
    _ADCHS_DIGITAL_FILTER_3_DATA_VREG(index)
    _ADCHS_DIGITAL_FILTER_4_DATA_VREG(index)
    _ADCHS_DIGITAL_FILTER_5_DATA_VREG(index)
    _ADCHS_DIGITAL_FILTER_6_DATA_VREG(index)
    _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_2_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_3_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_4_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_5_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_6_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_DIGITAL_FILTER_1_ANALOG_INPUT_ID_VREG(index)
    _ADCHS_DIGITAL_FILTER_2_ANALOG_INPUT_ID_VREG(index)
    _ADCHS_DIGITAL_FILTER_3_ANALOG_INPUT_ID_VREG(index)
    _ADCHS_DIGITAL_FILTER_4_ANALOG_INPUT_ID_VREG(index)
    _ADCHS_DIGITAL_FILTER_5_ANALOG_INPUT_ID_VREG(index)
    _ADCHS_DIGITAL_FILTER_6_ANALOG_INPUT_ID_VREG(index)
    _ADCHS_DIGITAL_FILTER_1_MODE_VREG(index)
    _ADCHS_DIGITAL_FILTER_2_MODE_VREG(index)
    _ADCHS_DIGITAL_FILTER_3_MODE_VREG(index)
    _ADCHS_DIGITAL_FILTER_4_MODE_VREG(index)
    _ADCHS_DIGITAL_FILTER_5_MODE_VREG(index)
    _ADCHS_DIGITAL_FILTER_6_MODE_VREG(index)
    _ADCHS_DIGITAL_FILTER_1_SIGNIFICANT_BIT_VREG(index)
    _ADCHS_DIGITAL_FILTER_2_SIGNIFICANT_BIT_VREG(index)
    _ADCHS_DIGITAL_FILTER_3_SIGNIFICANT_BIT_VREG(index)
    _ADCHS_DIGITAL_FILTER_4_SIGNIFICANT_BIT_VREG(index)
    _ADCHS_DIGITAL_FILTER_5_SIGNIFICANT_BIT_VREG(index)
    _ADCHS_DIGITAL_FILTER_6_SIGNIFICANT_BIT_VREG(index)

  MASKs: 
    _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_2_ENABLE_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_3_ENABLE_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_4_ENABLE_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_5_ENABLE_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_6_ENABLE_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_REG_1_MASK(index)
    _ADCHS_DIGITAL_FILTER_REG_2_MASK(index)
    _ADCHS_DIGITAL_FILTER_REG_3_MASK(index)
    _ADCHS_DIGITAL_FILTER_REG_4_MASK(index)
    _ADCHS_DIGITAL_FILTER_REG_5_MASK(index)
    _ADCHS_DIGITAL_FILTER_REG_6_MASK(index)
    _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_MASK(index)
    _ADCHS_DIGITAL_FILTER_2_RATIO_SELECT_MASK(index)
    _ADCHS_DIGITAL_FILTER_3_RATIO_SELECT_MASK(index)
    _ADCHS_DIGITAL_FILTER_4_RATIO_SELECT_MASK(index)
    _ADCHS_DIGITAL_FILTER_5_RATIO_SELECT_MASK(index)
    _ADCHS_DIGITAL_FILTER_6_RATIO_SELECT_MASK(index)
    _ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_MASK(index)
    _ADCHS_DIGITAL_FILTER_2_DATA_READY_STATUS_MASK(index)
    _ADCHS_DIGITAL_FILTER_3_DATA_READY_STATUS_MASK(index)
    _ADCHS_DIGITAL_FILTER_4_DATA_READY_STATUS_MASK(index)
    _ADCHS_DIGITAL_FILTER_5_DATA_READY_STATUS_MASK(index)
    _ADCHS_DIGITAL_FILTER_6_DATA_READY_STATUS_MASK(index)
    _ADCHS_DIGITAL_FILTER_1_DATA_MASK(index)
    _ADCHS_DIGITAL_FILTER_2_DATA_MASK(index)
    _ADCHS_DIGITAL_FILTER_3_DATA_MASK(index)
    _ADCHS_DIGITAL_FILTER_4_DATA_MASK(index)
    _ADCHS_DIGITAL_FILTER_5_DATA_MASK(index)
    _ADCHS_DIGITAL_FILTER_6_DATA_MASK(index)
    _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_2_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_3_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_4_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_5_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_6_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_DIGITAL_FILTER_1_ANALOG_INPUT_ID_MASK(index)
    _ADCHS_DIGITAL_FILTER_2_ANALOG_INPUT_ID_MASK(index)
    _ADCHS_DIGITAL_FILTER_3_ANALOG_INPUT_ID_MASK(index)
    _ADCHS_DIGITAL_FILTER_4_ANALOG_INPUT_ID_MASK(index)
    _ADCHS_DIGITAL_FILTER_5_ANALOG_INPUT_ID_MASK(index)
    _ADCHS_DIGITAL_FILTER_6_ANALOG_INPUT_ID_MASK(index)
    _ADCHS_DIGITAL_FILTER_1_MODE_MASK(index)
    _ADCHS_DIGITAL_FILTER_2_MODE_MASK(index)
    _ADCHS_DIGITAL_FILTER_3_MODE_MASK(index)
    _ADCHS_DIGITAL_FILTER_4_MODE_MASK(index)
    _ADCHS_DIGITAL_FILTER_5_MODE_MASK(index)
    _ADCHS_DIGITAL_FILTER_6_MODE_MASK(index)
    _ADCHS_DIGITAL_FILTER_1_SIGNIFICANT_BIT_MASK(index)
    _ADCHS_DIGITAL_FILTER_2_SIGNIFICANT_BIT_MASK(index)
    _ADCHS_DIGITAL_FILTER_3_SIGNIFICANT_BIT_MASK(index)
    _ADCHS_DIGITAL_FILTER_4_SIGNIFICANT_BIT_MASK(index)
    _ADCHS_DIGITAL_FILTER_5_SIGNIFICANT_BIT_MASK(index)
    _ADCHS_DIGITAL_FILTER_6_SIGNIFICANT_BIT_MASK(index)

  POSs: 
    _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_2_ENABLE_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_3_ENABLE_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_4_ENABLE_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_5_ENABLE_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_6_ENABLE_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_REG_1_POS(index)
    _ADCHS_DIGITAL_FILTER_REG_2_POS(index)
    _ADCHS_DIGITAL_FILTER_REG_3_POS(index)
    _ADCHS_DIGITAL_FILTER_REG_4_POS(index)
    _ADCHS_DIGITAL_FILTER_REG_5_POS(index)
    _ADCHS_DIGITAL_FILTER_REG_6_POS(index)
    _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_POS(index)
    _ADCHS_DIGITAL_FILTER_2_RATIO_SELECT_POS(index)
    _ADCHS_DIGITAL_FILTER_3_RATIO_SELECT_POS(index)
    _ADCHS_DIGITAL_FILTER_4_RATIO_SELECT_POS(index)
    _ADCHS_DIGITAL_FILTER_5_RATIO_SELECT_POS(index)
    _ADCHS_DIGITAL_FILTER_6_RATIO_SELECT_POS(index)
    _ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_POS(index)
    _ADCHS_DIGITAL_FILTER_2_DATA_READY_STATUS_POS(index)
    _ADCHS_DIGITAL_FILTER_3_DATA_READY_STATUS_POS(index)
    _ADCHS_DIGITAL_FILTER_4_DATA_READY_STATUS_POS(index)
    _ADCHS_DIGITAL_FILTER_5_DATA_READY_STATUS_POS(index)
    _ADCHS_DIGITAL_FILTER_6_DATA_READY_STATUS_POS(index)
    _ADCHS_DIGITAL_FILTER_1_DATA_POS(index)
    _ADCHS_DIGITAL_FILTER_2_DATA_POS(index)
    _ADCHS_DIGITAL_FILTER_3_DATA_POS(index)
    _ADCHS_DIGITAL_FILTER_4_DATA_POS(index)
    _ADCHS_DIGITAL_FILTER_5_DATA_POS(index)
    _ADCHS_DIGITAL_FILTER_6_DATA_POS(index)
    _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_2_INTERRUPT_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_3_INTERRUPT_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_4_INTERRUPT_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_5_INTERRUPT_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_6_INTERRUPT_CONTROL_POS(index)
    _ADCHS_DIGITAL_FILTER_1_ANALOG_INPUT_ID_POS(index)
    _ADCHS_DIGITAL_FILTER_2_ANALOG_INPUT_ID_POS(index)
    _ADCHS_DIGITAL_FILTER_3_ANALOG_INPUT_ID_POS(index)
    _ADCHS_DIGITAL_FILTER_4_ANALOG_INPUT_ID_POS(index)
    _ADCHS_DIGITAL_FILTER_5_ANALOG_INPUT_ID_POS(index)
    _ADCHS_DIGITAL_FILTER_6_ANALOG_INPUT_ID_POS(index)
    _ADCHS_DIGITAL_FILTER_1_MODE_POS(index)
    _ADCHS_DIGITAL_FILTER_2_MODE_POS(index)
    _ADCHS_DIGITAL_FILTER_3_MODE_POS(index)
    _ADCHS_DIGITAL_FILTER_4_MODE_POS(index)
    _ADCHS_DIGITAL_FILTER_5_MODE_POS(index)
    _ADCHS_DIGITAL_FILTER_6_MODE_POS(index)
    _ADCHS_DIGITAL_FILTER_1_SIGNIFICANT_BIT_POS(index)
    _ADCHS_DIGITAL_FILTER_2_SIGNIFICANT_BIT_POS(index)
    _ADCHS_DIGITAL_FILTER_3_SIGNIFICANT_BIT_POS(index)
    _ADCHS_DIGITAL_FILTER_4_SIGNIFICANT_BIT_POS(index)
    _ADCHS_DIGITAL_FILTER_5_SIGNIFICANT_BIT_POS(index)
    _ADCHS_DIGITAL_FILTER_6_SIGNIFICANT_BIT_POS(index)

  LENs: 
    _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_2_ENABLE_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_3_ENABLE_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_4_ENABLE_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_5_ENABLE_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_6_ENABLE_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_REG_1_LEN(index)
    _ADCHS_DIGITAL_FILTER_REG_2_LEN(index)
    _ADCHS_DIGITAL_FILTER_REG_3_LEN(index)
    _ADCHS_DIGITAL_FILTER_REG_4_LEN(index)
    _ADCHS_DIGITAL_FILTER_REG_5_LEN(index)
    _ADCHS_DIGITAL_FILTER_REG_6_LEN(index)
    _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_LEN(index)
    _ADCHS_DIGITAL_FILTER_2_RATIO_SELECT_LEN(index)
    _ADCHS_DIGITAL_FILTER_3_RATIO_SELECT_LEN(index)
    _ADCHS_DIGITAL_FILTER_4_RATIO_SELECT_LEN(index)
    _ADCHS_DIGITAL_FILTER_5_RATIO_SELECT_LEN(index)
    _ADCHS_DIGITAL_FILTER_6_RATIO_SELECT_LEN(index)
    _ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_LEN(index)
    _ADCHS_DIGITAL_FILTER_2_DATA_READY_STATUS_LEN(index)
    _ADCHS_DIGITAL_FILTER_3_DATA_READY_STATUS_LEN(index)
    _ADCHS_DIGITAL_FILTER_4_DATA_READY_STATUS_LEN(index)
    _ADCHS_DIGITAL_FILTER_5_DATA_READY_STATUS_LEN(index)
    _ADCHS_DIGITAL_FILTER_6_DATA_READY_STATUS_LEN(index)
    _ADCHS_DIGITAL_FILTER_1_DATA_LEN(index)
    _ADCHS_DIGITAL_FILTER_2_DATA_LEN(index)
    _ADCHS_DIGITAL_FILTER_3_DATA_LEN(index)
    _ADCHS_DIGITAL_FILTER_4_DATA_LEN(index)
    _ADCHS_DIGITAL_FILTER_5_DATA_LEN(index)
    _ADCHS_DIGITAL_FILTER_6_DATA_LEN(index)
    _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_2_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_3_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_4_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_5_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_6_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_DIGITAL_FILTER_1_ANALOG_INPUT_ID_LEN(index)
    _ADCHS_DIGITAL_FILTER_2_ANALOG_INPUT_ID_LEN(index)
    _ADCHS_DIGITAL_FILTER_3_ANALOG_INPUT_ID_LEN(index)
    _ADCHS_DIGITAL_FILTER_4_ANALOG_INPUT_ID_LEN(index)
    _ADCHS_DIGITAL_FILTER_5_ANALOG_INPUT_ID_LEN(index)
    _ADCHS_DIGITAL_FILTER_6_ANALOG_INPUT_ID_LEN(index)
    _ADCHS_DIGITAL_FILTER_1_MODE_LEN(index)
    _ADCHS_DIGITAL_FILTER_2_MODE_LEN(index)
    _ADCHS_DIGITAL_FILTER_3_MODE_LEN(index)
    _ADCHS_DIGITAL_FILTER_4_MODE_LEN(index)
    _ADCHS_DIGITAL_FILTER_5_MODE_LEN(index)
    _ADCHS_DIGITAL_FILTER_6_MODE_LEN(index)
    _ADCHS_DIGITAL_FILTER_1_SIGNIFICANT_BIT_LEN(index)
    _ADCHS_DIGITAL_FILTER_2_SIGNIFICANT_BIT_LEN(index)
    _ADCHS_DIGITAL_FILTER_3_SIGNIFICANT_BIT_LEN(index)
    _ADCHS_DIGITAL_FILTER_4_SIGNIFICANT_BIT_LEN(index)
    _ADCHS_DIGITAL_FILTER_5_SIGNIFICANT_BIT_LEN(index)
    _ADCHS_DIGITAL_FILTER_6_SIGNIFICANT_BIT_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_DigitalFilterEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterEnable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterEnable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id )
{
	_SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_VREG( index ) + (id)),
				  _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_POS( index), 1  );
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDisable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterDisable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id )
{
	_SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_VREG( index ) + (id)),
				  _ADCHS_DIGITAL_FILTER_1_ENABLE_CONTROL_POS( index), 0  );
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterOversamplingModeSetup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterOversamplingModeSetup 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterOversamplingModeSetup function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterOversamplingModeSetup_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_AN_INPUT_ID analogInput , ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length , ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio , bool intEnable )
{
	uint32_t filterVal = 0;

        if(analogInput > 31)
            return;
	
	filterVal = filterVal | (analogInput << 16);
	
	if( ADCHS_DIGITAL_FILTER_SIGNIFICANT_ALL_16BITS == length )
	{
		filterVal = filterVal | 0x40000000;
	}
	
	filterVal = filterVal | (ratio << 26);
	
	filterVal = filterVal & ~0x20000000;	// Oversampling mode

	_SFR_WRITE( (_ADCHS_DIGITAL_FILTER_REG_1_VREG( index ) + (id)),
				 filterVal );	
				 
	if(intEnable)
	{
		_SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_VREG( index ) + (id)),
					  _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_POS( index), 1  );
	}	
	else
	{
		_SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_VREG( index ) + (id)),
					  _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_POS( index), 0  );
	
	}
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterAveragingModeSetup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterAveragingModeSetup 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterAveragingModeSetup function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterAveragingModeSetup_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_AN_INPUT_ID analogInput , ADCHS_DIGITAL_FILTER_SIGNIFICANT_BITS length , ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count , bool intEnable )
{
	uint32_t filterVal = 0;

        if(analogInput > 31)
            return;
	
	filterVal = filterVal | (analogInput << 16);
	
	if( ADCHS_DIGITAL_FILTER_SIGNIFICANT_ALL_16BITS == length )
	{
		filterVal = filterVal | 0x40000000;
	}
	
	filterVal = filterVal | (count << 26);
	
	filterVal = filterVal | 0x20000000;	// Averaging mode

	_SFR_WRITE( (_ADCHS_DIGITAL_FILTER_REG_1_VREG( index ) + (id)),
				 filterVal );
				 
	if(intEnable)
	{
		_SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_VREG( index ) + (id)),
					  _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_POS( index), 1  );
	}	
	else
	{
		_SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_VREG( index ) + (id)),
					  _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_POS( index), 0  );
	
	}				 
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterOversamplingModeRatioSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterOversamplingModeRatioSelect function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterOversamplingModeRatioSelect_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_DIGITAL_FILTER_OVERSAMPLE_RATIO ratio )
{
	_SFR_FIELD_WRITE( (_ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_VREG(index) + (id)),
					 _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_MASK(index),
					 _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_POS(index) ,
					 ratio );

        _SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_MODE_VREG( index ) + (id)),
                         _ADCHS_DIGITAL_FILTER_1_MODE_POS( index ), 0 );
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterAveragingModeSampleCountSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterAveragingModeSampleCountSelect function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterAveragingModeSampleCountSelect_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id , ADCHS_DIGITAL_FILTER_AVERAGE_SAMPLE_COUNT count )
{
	_SFR_FIELD_WRITE( (_ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_VREG(index) + (id)),
					 _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_MASK(index),
					 _ADCHS_DIGITAL_FILTER_1_RATIO_SELECT_POS(index) ,
					 count );

        _SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_MODE_VREG( index ) + (id)),
                         _ADCHS_DIGITAL_FILTER_1_MODE_POS( index ), 1 );
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataIsReady_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDataIsReady 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDataIsReady function.
*/

PLIB_TEMPLATE bool ADCHS_DigitalFilterDataIsReady_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID id )
{
	return _SFR_BIT_READ( (_ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_VREG(index) + (id)),
						 _ADCHS_DIGITAL_FILTER_1_DATA_READY_STATUS_POS(index) );
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataGet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDataGet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDataGet function.
*/

PLIB_TEMPLATE int16_t ADCHS_DigitalFilterDataGet_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID dfltrID )
{
	return _SFR_FIELD_READ( (_ADCHS_DIGITAL_FILTER_1_DATA_VREG(index) + (dfltrID)),
						   _ADCHS_DIGITAL_FILTER_1_DATA_MASK(index),
						   _ADCHS_DIGITAL_FILTER_1_DATA_POS(index) );
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataReadyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDataReadyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterDataReadyInterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID digFilter )
{
	_SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_VREG( index ) + (digFilter)),
				  _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_POS( index), 1  );
}


//******************************************************************************
/* Function :  ADCHS_DigitalFilterDataReadyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalFilterDataReadyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalFilterDataReadyInterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_FILTER_ID digFilter )
{
	_SFR_BIT_WRITE( (_ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_VREG( index ) + (digFilter)),
				  _ADCHS_DIGITAL_FILTER_1_INTERRUPT_CONTROL_POS( index), 0  );
}


//******************************************************************************
/* Function :  ADCHS_ExistsDigitalFilter_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsDigitalFilter

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsDigitalFilter function.
*/

#define PLIB_ADCHS_ExistsDigitalFilter PLIB_ADCHS_ExistsDigitalFilter
PLIB_TEMPLATE bool ADCHS_ExistsDigitalFilter_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_DIGITALFILTER_DEFAULT_H*/

/******************************************************************************
 End of File
*/

