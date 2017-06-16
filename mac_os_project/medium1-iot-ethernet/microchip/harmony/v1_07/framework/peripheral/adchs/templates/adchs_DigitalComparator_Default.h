/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DigitalComparator_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DigitalComparator
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_DigitalComparatorAnalogInputSelect
        PLIB_ADCHS_DigitalComparatorAnalogInputGet
        PLIB_ADCHS_DigitalComparatorEnable
        PLIB_ADCHS_DigitalComparatorDisable
        PLIB_ADCHS_DigitalComparatorInterruptEnable
        PLIB_ADCHS_DigitalComparatorInterruptDisable
        PLIB_ADCHS_DigitalComparatorSetup
        PLIB_ADCHS_DigitalComparatorEventHasOccurred
        PLIB_ADCHS_DigitalComparatorLimitSet
        PLIB_ADCHS_ExistsDigitalComparator

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

#ifndef _ADCHS_DIGITALCOMPARATOR_DEFAULT_H
#define _ADCHS_DIGITALCOMPARATOR_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_COMPARATOR_AN_INPUT_REG_1_VREG(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_2_VREG(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_3_VREG(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_4_VREG(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_5_VREG(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_6_VREG(index)
    _ADCHS_COMPARATOR_LIMIT_REG_1_VREG(index)
    _ADCHS_COMPARATOR_LIMIT_REG_2_VREG(index)
    _ADCHS_COMPARATOR_LIMIT_REG_3_VREG(index)
    _ADCHS_COMPARATOR_LIMIT_REG_4_VREG(index)
    _ADCHS_COMPARATOR_LIMIT_REG_5_VREG(index)
    _ADCHS_COMPARATOR_LIMIT_REG_6_VREG(index)
    _ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_VREG(index)
    _ADCHS_COMPARATOR_2_ANALOG_INPUT_ID_GET_VREG(index)
    _ADCHS_COMPARATOR_3_ANALOG_INPUT_ID_GET_VREG(index)
    _ADCHS_COMPARATOR_4_ANALOG_INPUT_ID_GET_VREG(index)
    _ADCHS_COMPARATOR_5_ANALOG_INPUT_ID_GET_VREG(index)
    _ADCHS_COMPARATOR_6_ANALOG_INPUT_ID_GET_VREG(index)
    _ADCHS_COMPARATOR_1_ENABLE_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_2_ENABLE_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_3_ENABLE_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_4_ENABLE_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_5_ENABLE_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_6_ENABLE_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_2_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_3_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_4_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_5_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_6_INTERRUPT_CONTROL_VREG(index)
    _ADCHS_COMPARATOR_1_EVENT_STATUS_VREG(index)
    _ADCHS_COMPARATOR_2_EVENT_STATUS_VREG(index)
    _ADCHS_COMPARATOR_3_EVENT_STATUS_VREG(index)
    _ADCHS_COMPARATOR_4_EVENT_STATUS_VREG(index)
    _ADCHS_COMPARATOR_5_EVENT_STATUS_VREG(index)
    _ADCHS_COMPARATOR_6_EVENT_STATUS_VREG(index)
    _ADCHS_COMPARATOR_CONTROL_REG_1_VREG(index)
    _ADCHS_COMPARATOR_CONTROL_REG_2_VREG(index)
    _ADCHS_COMPARATOR_CONTROL_REG_3_VREG(index)
    _ADCHS_COMPARATOR_CONTROL_REG_4_VREG(index)
    _ADCHS_COMPARATOR_CONTROL_REG_5_VREG(index)
    _ADCHS_COMPARATOR_CONTROL_REG_6_VREG(index)

  MASKs: 
    _ADCHS_COMPARATOR_AN_INPUT_REG_1_MASK(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_2_MASK(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_3_MASK(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_4_MASK(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_5_MASK(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_6_MASK(index)
    _ADCHS_COMPARATOR_LIMIT_REG_1_MASK(index)
    _ADCHS_COMPARATOR_LIMIT_REG_2_MASK(index)
    _ADCHS_COMPARATOR_LIMIT_REG_3_MASK(index)
    _ADCHS_COMPARATOR_LIMIT_REG_4_MASK(index)
    _ADCHS_COMPARATOR_LIMIT_REG_5_MASK(index)
    _ADCHS_COMPARATOR_LIMIT_REG_6_MASK(index)
    _ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_MASK(index)
    _ADCHS_COMPARATOR_2_ANALOG_INPUT_ID_GET_MASK(index)
    _ADCHS_COMPARATOR_3_ANALOG_INPUT_ID_GET_MASK(index)
    _ADCHS_COMPARATOR_4_ANALOG_INPUT_ID_GET_MASK(index)
    _ADCHS_COMPARATOR_5_ANALOG_INPUT_ID_GET_MASK(index)
    _ADCHS_COMPARATOR_6_ANALOG_INPUT_ID_GET_MASK(index)
    _ADCHS_COMPARATOR_1_ENABLE_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_2_ENABLE_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_3_ENABLE_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_4_ENABLE_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_5_ENABLE_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_6_ENABLE_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_2_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_3_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_4_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_5_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_6_INTERRUPT_CONTROL_MASK(index)
    _ADCHS_COMPARATOR_1_EVENT_STATUS_MASK(index)
    _ADCHS_COMPARATOR_2_EVENT_STATUS_MASK(index)
    _ADCHS_COMPARATOR_3_EVENT_STATUS_MASK(index)
    _ADCHS_COMPARATOR_4_EVENT_STATUS_MASK(index)
    _ADCHS_COMPARATOR_5_EVENT_STATUS_MASK(index)
    _ADCHS_COMPARATOR_6_EVENT_STATUS_MASK(index)
    _ADCHS_COMPARATOR_CONTROL_REG_1_MASK(index)
    _ADCHS_COMPARATOR_CONTROL_REG_2_MASK(index)
    _ADCHS_COMPARATOR_CONTROL_REG_3_MASK(index)
    _ADCHS_COMPARATOR_CONTROL_REG_4_MASK(index)
    _ADCHS_COMPARATOR_CONTROL_REG_5_MASK(index)
    _ADCHS_COMPARATOR_CONTROL_REG_6_MASK(index)

  POSs: 
    _ADCHS_COMPARATOR_AN_INPUT_REG_1_POS(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_2_POS(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_3_POS(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_4_POS(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_5_POS(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_6_POS(index)
    _ADCHS_COMPARATOR_LIMIT_REG_1_POS(index)
    _ADCHS_COMPARATOR_LIMIT_REG_2_POS(index)
    _ADCHS_COMPARATOR_LIMIT_REG_3_POS(index)
    _ADCHS_COMPARATOR_LIMIT_REG_4_POS(index)
    _ADCHS_COMPARATOR_LIMIT_REG_5_POS(index)
    _ADCHS_COMPARATOR_LIMIT_REG_6_POS(index)
    _ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_POS(index)
    _ADCHS_COMPARATOR_2_ANALOG_INPUT_ID_GET_POS(index)
    _ADCHS_COMPARATOR_3_ANALOG_INPUT_ID_GET_POS(index)
    _ADCHS_COMPARATOR_4_ANALOG_INPUT_ID_GET_POS(index)
    _ADCHS_COMPARATOR_5_ANALOG_INPUT_ID_GET_POS(index)
    _ADCHS_COMPARATOR_6_ANALOG_INPUT_ID_GET_POS(index)
    _ADCHS_COMPARATOR_1_ENABLE_CONTROL_POS(index)
    _ADCHS_COMPARATOR_2_ENABLE_CONTROL_POS(index)
    _ADCHS_COMPARATOR_3_ENABLE_CONTROL_POS(index)
    _ADCHS_COMPARATOR_4_ENABLE_CONTROL_POS(index)
    _ADCHS_COMPARATOR_5_ENABLE_CONTROL_POS(index)
    _ADCHS_COMPARATOR_6_ENABLE_CONTROL_POS(index)
    _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_POS(index)
    _ADCHS_COMPARATOR_2_INTERRUPT_CONTROL_POS(index)
    _ADCHS_COMPARATOR_3_INTERRUPT_CONTROL_POS(index)
    _ADCHS_COMPARATOR_4_INTERRUPT_CONTROL_POS(index)
    _ADCHS_COMPARATOR_5_INTERRUPT_CONTROL_POS(index)
    _ADCHS_COMPARATOR_6_INTERRUPT_CONTROL_POS(index)
    _ADCHS_COMPARATOR_1_EVENT_STATUS_POS(index)
    _ADCHS_COMPARATOR_2_EVENT_STATUS_POS(index)
    _ADCHS_COMPARATOR_3_EVENT_STATUS_POS(index)
    _ADCHS_COMPARATOR_4_EVENT_STATUS_POS(index)
    _ADCHS_COMPARATOR_5_EVENT_STATUS_POS(index)
    _ADCHS_COMPARATOR_6_EVENT_STATUS_POS(index)
    _ADCHS_COMPARATOR_CONTROL_REG_1_POS(index)
    _ADCHS_COMPARATOR_CONTROL_REG_2_POS(index)
    _ADCHS_COMPARATOR_CONTROL_REG_3_POS(index)
    _ADCHS_COMPARATOR_CONTROL_REG_4_POS(index)
    _ADCHS_COMPARATOR_CONTROL_REG_5_POS(index)
    _ADCHS_COMPARATOR_CONTROL_REG_6_POS(index)

  LENs: 
    _ADCHS_COMPARATOR_AN_INPUT_REG_1_LEN(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_2_LEN(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_3_LEN(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_4_LEN(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_5_LEN(index)
    _ADCHS_COMPARATOR_AN_INPUT_REG_6_LEN(index)
    _ADCHS_COMPARATOR_LIMIT_REG_1_LEN(index)
    _ADCHS_COMPARATOR_LIMIT_REG_2_LEN(index)
    _ADCHS_COMPARATOR_LIMIT_REG_3_LEN(index)
    _ADCHS_COMPARATOR_LIMIT_REG_4_LEN(index)
    _ADCHS_COMPARATOR_LIMIT_REG_5_LEN(index)
    _ADCHS_COMPARATOR_LIMIT_REG_6_LEN(index)
    _ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_LEN(index)
    _ADCHS_COMPARATOR_2_ANALOG_INPUT_ID_GET_LEN(index)
    _ADCHS_COMPARATOR_3_ANALOG_INPUT_ID_GET_LEN(index)
    _ADCHS_COMPARATOR_4_ANALOG_INPUT_ID_GET_LEN(index)
    _ADCHS_COMPARATOR_5_ANALOG_INPUT_ID_GET_LEN(index)
    _ADCHS_COMPARATOR_6_ANALOG_INPUT_ID_GET_LEN(index)
    _ADCHS_COMPARATOR_1_ENABLE_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_2_ENABLE_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_3_ENABLE_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_4_ENABLE_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_5_ENABLE_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_6_ENABLE_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_2_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_3_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_4_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_5_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_6_INTERRUPT_CONTROL_LEN(index)
    _ADCHS_COMPARATOR_1_EVENT_STATUS_LEN(index)
    _ADCHS_COMPARATOR_2_EVENT_STATUS_LEN(index)
    _ADCHS_COMPARATOR_3_EVENT_STATUS_LEN(index)
    _ADCHS_COMPARATOR_4_EVENT_STATUS_LEN(index)
    _ADCHS_COMPARATOR_5_EVENT_STATUS_LEN(index)
    _ADCHS_COMPARATOR_6_EVENT_STATUS_LEN(index)
    _ADCHS_COMPARATOR_CONTROL_REG_1_LEN(index)
    _ADCHS_COMPARATOR_CONTROL_REG_2_LEN(index)
    _ADCHS_COMPARATOR_CONTROL_REG_3_LEN(index)
    _ADCHS_COMPARATOR_CONTROL_REG_4_LEN(index)
    _ADCHS_COMPARATOR_CONTROL_REG_5_LEN(index)
    _ADCHS_COMPARATOR_CONTROL_REG_6_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorAnalogInputSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalComparatorAnalogInputSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalComparatorAnalogInputSelect function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorAnalogInputSelect_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput >= 32)
		return;
		
	_SFR_BIT_WRITE( _ADCHS_COMPARATOR_AN_INPUT_REG_1_VREG( index ) + ((digComparator)*2),
				  analogInput, 1 );
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorAnalogInputGet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalComparatorAnalogInputGet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalComparatorAnalogInputGet function.
*/

PLIB_TEMPLATE ADCHS_AN_INPUT_ID ADCHS_DigitalComparatorAnalogInputGet_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{

    return (ADCHS_AN_INPUT_ID)_SFR_FIELD_READ( (_ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_VREG(index) + ((digComparator)*2)),
	_ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_MASK(index),
	_ADCHS_COMPARATOR_1_ANALOG_INPUT_ID_GET_POS(index) );

}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalComparatorEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalComparatorEnable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorEnable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
	_SFR_BIT_WRITE( (_ADCHS_COMPARATOR_1_ENABLE_CONTROL_VREG( index ) + (digComparator)),
				  _ADCHS_COMPARATOR_1_ENABLE_CONTROL_POS( index ), 1 );
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalComparatorDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalComparatorDisable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorDisable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
	_SFR_BIT_WRITE( (_ADCHS_COMPARATOR_1_ENABLE_CONTROL_VREG( index ) + (digComparator)),
				  _ADCHS_COMPARATOR_1_ENABLE_CONTROL_POS( index ), 0 );
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalComparatorInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalComparatorInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorInterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
	_SFR_BIT_WRITE( (_ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_VREG( index ) + (digComparator)),
				  _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_POS( index ), 1 );
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalComparatorInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalComparatorInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorInterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID digComparator )
{
	_SFR_BIT_WRITE( (_ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_VREG( index ) + (digComparator)),
				  _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_POS( index ), 0 );
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorSetup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalComparatorSetup 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalComparatorSetup function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorSetup_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID id , bool intEnable , bool inBetweenOrEqual , bool greaterEqualHi , bool lessThanHi , bool greaterEqualLo , bool lessThanLo , ADCHS_AN_INPUT_ID analogInput , int16_t  hiLimit , int16_t  loLimit )
{
	uint32_t comparatorLogic = 0;
	
	if( analogInput >= 32)
		return;
	
	if( inBetweenOrEqual )
	{
		comparatorLogic |= 0x10;
	}
	if( greaterEqualHi )
	{
		comparatorLogic |= 0x08;
	}
	if( lessThanHi )
	{
		comparatorLogic |= 0x04;
	}
	if( greaterEqualLo )
	{
		comparatorLogic |= 0x02;
	}	
	if( lessThanLo )
	{
		comparatorLogic |= 0x01;
	}
	
    _SFR_FIELD_WRITE( (_ADCHS_COMPARATOR_CONTROL_REG_1_VREG( index ) + (id)),
					  0x0000001F,
					  0,
					  comparatorLogic );
					  
	if(intEnable)
	{
		_SFR_BIT_WRITE( (_ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_VREG( index ) + (id)),
					  _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_POS( index ), 1 );		
	}
	else
	{
		_SFR_BIT_WRITE( (_ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_VREG( index ) + (id)),
					  _ADCHS_COMPARATOR_1_INTERRUPT_CONTROL_POS( index ), 0 );	
        }

	_SFR_BIT_WRITE( (_ADCHS_COMPARATOR_AN_INPUT_REG_1_VREG( index ) + ((id)*2)),
				  analogInput, 1 );
				  
	_SFR_WRITE( (_ADCHS_COMPARATOR_LIMIT_REG_1_VREG( index ) + ((id)*2)),
				((uint32_t)(hiLimit << 16) | loLimit) );	
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorEventHasOccurred_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalComparatorEventHasOccurred 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalComparatorEventHasOccurred function.
*/

PLIB_TEMPLATE bool ADCHS_DigitalComparatorEventHasOccurred_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID id )
{
	return _SFR_BIT_READ( (_ADCHS_COMPARATOR_1_EVENT_STATUS_VREG(index) + (id)),
						 _ADCHS_COMPARATOR_1_EVENT_STATUS_POS(index) );
}


//******************************************************************************
/* Function :  ADCHS_DigitalComparatorLimitSet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_DigitalComparatorLimitSet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_DigitalComparatorLimitSet function.
*/

PLIB_TEMPLATE void ADCHS_DigitalComparatorLimitSet_Default( ADCHS_MODULE_ID index , ADCHS_DIGITAL_COMPARATOR_ID id , int16_t  hiLimit , int16_t  loLimit )
{
	_SFR_WRITE( (_ADCHS_COMPARATOR_LIMIT_REG_1_VREG( index ) + ((id)*2)),
				((uint32_t)(hiLimit << 16) | loLimit) );	
}


//******************************************************************************
/* Function :  ADCHS_ExistsDigitalComparator_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsDigitalComparator

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsDigitalComparator function.
*/

#define PLIB_ADCHS_ExistsDigitalComparator PLIB_ADCHS_ExistsDigitalComparator
PLIB_TEMPLATE bool ADCHS_ExistsDigitalComparator_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_DIGITALCOMPARATOR_DEFAULT_H*/

/******************************************************************************
 End of File
*/

