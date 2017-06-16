/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_ConversionResult_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : ConversionResult
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_AnalogInputDataReadyInterruptEnable
        PLIB_ADCHS_AnalogInputDataReadyInterruptDisable
        PLIB_ADCHS_AnalogInputDataIsReady
        PLIB_ADCHS_AnalogInputResultGet
        PLIB_ADCHS_ExistsConversionResults

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

#ifndef _ADCHS_CONVERSIONRESULT_DEFAULT_H
#define _ADCHS_CONVERSIONRESULT_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_GLOBAL_INT_EN_REG_1_VREG(index)
    _ADCHS_GLOBAL_INT_EN_REG_2_VREG(index)
    _ADCHS_DATA_RDY_STATUS_1_VREG(index)
    _ADCHS_DATA_RDY_STATUS_2_VREG(index)
    _ADCHS_CONVERSION_RESULT_BASE_ADDRESS_VREG(index)

  MASKs: 
    _ADCHS_GLOBAL_INT_EN_REG_1_MASK(index)
    _ADCHS_GLOBAL_INT_EN_REG_2_MASK(index)
    _ADCHS_DATA_RDY_STATUS_1_MASK(index)
    _ADCHS_DATA_RDY_STATUS_2_MASK(index)
    _ADCHS_CONVERSION_RESULT_BASE_ADDRESS_MASK(index)

  POSs: 
    _ADCHS_GLOBAL_INT_EN_REG_1_POS(index)
    _ADCHS_GLOBAL_INT_EN_REG_2_POS(index)
    _ADCHS_DATA_RDY_STATUS_1_POS(index)
    _ADCHS_DATA_RDY_STATUS_2_POS(index)
    _ADCHS_CONVERSION_RESULT_BASE_ADDRESS_POS(index)

  LENs: 
    _ADCHS_GLOBAL_INT_EN_REG_1_LEN(index)
    _ADCHS_GLOBAL_INT_EN_REG_2_LEN(index)
    _ADCHS_DATA_RDY_STATUS_1_LEN(index)
    _ADCHS_DATA_RDY_STATUS_2_LEN(index)
    _ADCHS_CONVERSION_RESULT_BASE_ADDRESS_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_AnalogInputDataReadyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputDataReadyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputDataReadyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputDataReadyInterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput <= 31 )
	{
		_SFR_BIT_WRITE( _ADCHS_GLOBAL_INT_EN_REG_1_VREG( index ),
					  analogInput, 1 );
	}
	else
	{
		_SFR_BIT_WRITE( _ADCHS_GLOBAL_INT_EN_REG_2_VREG( index ),
					  (analogInput - 32), 1 );
	}
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputDataReadyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputDataReadyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputDataReadyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputDataReadyInterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput <= 31 )
	{
		_SFR_BIT_WRITE( _ADCHS_GLOBAL_INT_EN_REG_1_VREG( index ),
					  analogInput, 0 );
	}
	else
	{
		_SFR_BIT_WRITE( _ADCHS_GLOBAL_INT_EN_REG_2_VREG( index ),
					  (analogInput - 32), 0 );
	}
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputDataIsReady_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputDataIsReady 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputDataIsReady function.
*/

PLIB_TEMPLATE bool ADCHS_AnalogInputDataIsReady_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	if( analogInput <= 31 )
	{
		return (_SFR_BIT_READ( _ADCHS_DATA_RDY_STATUS_1_VREG( index ),
					  analogInput ));	
	}
	else
	{
		return(_SFR_BIT_READ( _ADCHS_DATA_RDY_STATUS_2_VREG( index ),
					  (analogInput - 32) ));
	}
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputResultGet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputResultGet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputResultGet function.
*/

PLIB_TEMPLATE uint32_t ADCHS_AnalogInputResultGet_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	return((uint32_t) _SFR_READ( _ADCHS_CONVERSION_RESULT_BASE_ADDRESS_VREG(index) + analogInput ));
}


//******************************************************************************
/* Function :  ADCHS_ExistsConversionResults_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsConversionResults

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsConversionResults function.
*/

#define PLIB_ADCHS_ExistsConversionResults PLIB_ADCHS_ExistsConversionResults
PLIB_TEMPLATE bool ADCHS_ExistsConversionResults_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_CONVERSIONRESULT_DEFAULT_H*/

/******************************************************************************
 End of File
*/

