/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_EarlyInterruptControl_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : EarlyInterruptControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_EarlyInterruptEnable
        PLIB_ADCHS_EarlyInterruptDisable
        PLIB_ADCHS_AnalogInputEarlyInterruptEnable
        PLIB_ADCHS_AnalogInputEarlyInterruptDisable
        PLIB_ADCHS_AnalogInputEarlyInterruptIsReady
        PLIB_ADCHS_ExistsEarlyInterruptControl

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

#ifndef _ADCHS_EARLYINTERRUPTCONTROL_DEFAULT_H
#define _ADCHS_EARLYINTERRUPTCONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_CONTROL_REG_2_VREG(index)
    _ADCHS_EARLY_INTERRUPT_REG_1_VREG(index)
    _ADCHS_EARLY_INTERRUPT_REG_2_VREG(index)
    _ADCHS_EARLY_INTERRUPT_STATUS_REG_1_VREG(index)
    _ADCHS_EARLY_INTERRUPT_STATUS_REG_2_VREG(index)

  MASKs: 
    _ADCHS_CONTROL_REG_2_MASK(index)
    _ADCHS_EARLY_INTERRUPT_REG_1_MASK(index)
    _ADCHS_EARLY_INTERRUPT_REG_2_MASK(index)
    _ADCHS_EARLY_INTERRUPT_STATUS_REG_1_MASK(index)
    _ADCHS_EARLY_INTERRUPT_STATUS_REG_2_MASK(index)

  POSs: 
    _ADCHS_CONTROL_REG_2_POS(index)
    _ADCHS_EARLY_INTERRUPT_REG_1_POS(index)
    _ADCHS_EARLY_INTERRUPT_REG_2_POS(index)
    _ADCHS_EARLY_INTERRUPT_STATUS_REG_1_POS(index)
    _ADCHS_EARLY_INTERRUPT_STATUS_REG_2_POS(index)

  LENs: 
    _ADCHS_CONTROL_REG_2_LEN(index)
    _ADCHS_EARLY_INTERRUPT_REG_1_LEN(index)
    _ADCHS_EARLY_INTERRUPT_REG_2_LEN(index)
    _ADCHS_EARLY_INTERRUPT_STATUS_REG_1_LEN(index)
    _ADCHS_EARLY_INTERRUPT_STATUS_REG_2_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_EarlyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_EarlyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_EarlyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_EarlyInterruptEnable_Default( ADCHS_MODULE_ID index )
{
	_SFR_BIT_WRITE(_ADCHS_EARLY_INT_OVERRIDE_VREG(index),
				 _ADCHS_EARLY_INT_OVERRIDE_POS(index), 0 );
}


//******************************************************************************
/* Function :  ADCHS_EarlyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_EarlyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_EarlyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_EarlyInterruptDisable_Default( ADCHS_MODULE_ID index )
{
	_SFR_BIT_WRITE(_ADCHS_EARLY_INT_OVERRIDE_VREG(index),
				 _ADCHS_EARLY_INT_OVERRIDE_POS(index), 1 );
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEarlyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputEarlyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputEarlyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputEarlyInterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput <= 31 )
	{
		_SFR_BIT_WRITE( _ADCHS_EARLY_INTERRUPT_REG_1_VREG( index ),
					  analogInput, 1 );
	}
	else
	{
		_SFR_BIT_WRITE( _ADCHS_EARLY_INTERRUPT_REG_2_VREG( index ),
					  (analogInput - 32), 1 );
	}
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEarlyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputEarlyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputEarlyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputEarlyInterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput <= 31 )
	{
		_SFR_BIT_WRITE( _ADCHS_EARLY_INTERRUPT_REG_1_VREG( index ),
					  analogInput, 0 );
	}
	else
	{
		_SFR_BIT_WRITE( _ADCHS_EARLY_INTERRUPT_REG_2_VREG( index ),
					  (analogInput - 32), 0 );
	}
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputEarlyInterruptIsReady_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputEarlyInterruptIsReady 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputEarlyInterruptIsReady function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputEarlyInterruptIsReady_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput <= 31 )
	{
		return _SFR_BIT_READ( _ADCHS_EARLY_INTERRUPT_STATUS_REG_1_VREG( index ),
					  analogInput );	
	}
	else
	{
		return _SFR_BIT_READ( _ADCHS_EARLY_INTERRUPT_STATUS_REG_2_VREG( index ),
					  (analogInput - 32) );	
	}
}


//******************************************************************************
/* Function :  ADCHS_ExistsEarlyInterruptControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsEarlyInterruptControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsEarlyInterruptControl function.
*/

#define PLIB_ADCHS_ExistsEarlyInterruptControl PLIB_ADCHS_ExistsEarlyInterruptControl
PLIB_TEMPLATE bool ADCHS_ExistsEarlyInterruptControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_EARLYINTERRUPTCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

