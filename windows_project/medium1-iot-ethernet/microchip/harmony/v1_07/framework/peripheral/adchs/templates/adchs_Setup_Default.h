/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_Setup_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : Setup
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_Setup
        PLIB_ADCHS_ChannelSetup
        PLIB_ADCHS_ExistsConfiguration

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

#ifndef _ADCHS_SETUP_DEFAULT_H
#define _ADCHS_SETUP_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_CHANNEL_0_SAMPLE_TIME_VREG(index)
    _ADCHS_CHANNEL_1_SAMPLE_TIME_VREG(index)
    _ADCHS_CHANNEL_2_SAMPLE_TIME_VREG(index)
    _ADCHS_CHANNEL_3_SAMPLE_TIME_VREG(index)
    _ADCHS_CHANNEL_4_SAMPLE_TIME_VREG(index)
    _ADCHS_CHANNEL_7_SAMPLE_TIME_VREG(index)
    _ADCHS_EARLY_INT_OVERRIDE_VREG(index)
    _ADCHS_CHANNEL_0_EARLY_INTERRUPT_SELECTION_VREG(index)
    _ADCHS_CHANNEL_1_EARLY_INTERRUPT_SELECTION_VREG(index)
    _ADCHS_CHANNEL_2_EARLY_INTERRUPT_SELECTION_VREG(index)
    _ADCHS_CHANNEL_3_EARLY_INTERRUPT_SELECTION_VREG(index)
    _ADCHS_CHANNEL_4_EARLY_INTERRUPT_SELECTION_VREG(index)
    _ADCHS_CHANNEL_7_EARLY_INTERRUPT_SELECTION_VREG(index)
    _ADCHS_CHANNEL_0_CLOCK_DIVISOR_VREG(index)
    _ADCHS_CHANNEL_1_CLOCK_DIVISOR_VREG(index)
    _ADCHS_CHANNEL_2_CLOCK_DIVISOR_VREG(index)
    _ADCHS_CHANNEL_3_CLOCK_DIVISOR_VREG(index)
    _ADCHS_CHANNEL_4_CLOCK_DIVISOR_VREG(index)
    _ADCHS_CHANNEL_7_CLOCK_DIVISOR_VREG(index)
    _ADCHS_CLOCK_SOURCE_SELECT_VREG(index)
    _ADCHS_CONTROL_CLK_DIVISOR_VREG(index)
    _ADCHS_CONTROL_REG_1_VREG(index)
    _ADCHS_CONTROL_REG_2_VREG(index)
    _ADCHS_CONTROL_REG_3_VREG(index)
    _ADCHS_VREF_SOURCE_SELECTION_VREG(index)
    _ADCHS_ADCBASE_BASE_ADDR_VREG(index)
    _ADCHS_FRACTIONAL_VREG(index)
    _ADCHS_IDLE_MODE_CONTROL_VREG(index)
    _ADCHS_CHARGE_PUMP_CONTROL_VREG(index)
    _ADCHS_FAST_SYNC_SYS_CLK_CONTROL_VREG(index)
    _ADCHS_FAST_SYNC_PERIPH_CLK_CONTROL_VREG(index)
    _ADCHS_VECTOR_SHIFT_CONTROL_VREG(index)
    _ADCHS_CHANNEL_0_RESOLUTION_SELECTION_VREG(index)
    _ADCHS_CHANNEL_1_RESOLUTION_SELECTION_VREG(index)
    _ADCHS_CHANNEL_2_RESOLUTION_SELECTION_VREG(index)
    _ADCHS_CHANNEL_3_RESOLUTION_SELECTION_VREG(index)
    _ADCHS_CHANNEL_4_RESOLUTION_SELECTION_VREG(index)
    _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_VREG(index)
    _ADCHS_ADC_0_TIME_REG_VREG(index)
    _ADCHS_ADC_1_TIME_REG_VREG(index)
    _ADCHS_ADC_2_TIME_REG_VREG(index)
    _ADCHS_ADC_3_TIME_REG_VREG(index)
    _ADCHS_ADC_4_TIME_REG_VREG(index)
    _ADCHS_WARM_UP_COUNT_VREG(index)

  MASKs: 
    _ADCHS_CHANNEL_0_SAMPLE_TIME_MASK(index)
    _ADCHS_CHANNEL_1_SAMPLE_TIME_MASK(index)
    _ADCHS_CHANNEL_2_SAMPLE_TIME_MASK(index)
    _ADCHS_CHANNEL_3_SAMPLE_TIME_MASK(index)
    _ADCHS_CHANNEL_4_SAMPLE_TIME_MASK(index)
    _ADCHS_CHANNEL_7_SAMPLE_TIME_MASK(index)
    _ADCHS_EARLY_INT_OVERRIDE_MASK(index)
    _ADCHS_CHANNEL_0_EARLY_INTERRUPT_SELECTION_MASK(index)
    _ADCHS_CHANNEL_1_EARLY_INTERRUPT_SELECTION_MASK(index)
    _ADCHS_CHANNEL_2_EARLY_INTERRUPT_SELECTION_MASK(index)
    _ADCHS_CHANNEL_3_EARLY_INTERRUPT_SELECTION_MASK(index)
    _ADCHS_CHANNEL_4_EARLY_INTERRUPT_SELECTION_MASK(index)
    _ADCHS_CHANNEL_7_EARLY_INTERRUPT_SELECTION_MASK(index)
    _ADCHS_CHANNEL_0_CLOCK_DIVISOR_MASK(index)
    _ADCHS_CHANNEL_1_CLOCK_DIVISOR_MASK(index)
    _ADCHS_CHANNEL_2_CLOCK_DIVISOR_MASK(index)
    _ADCHS_CHANNEL_3_CLOCK_DIVISOR_MASK(index)
    _ADCHS_CHANNEL_4_CLOCK_DIVISOR_MASK(index)
    _ADCHS_CHANNEL_7_CLOCK_DIVISOR_MASK(index)
    _ADCHS_CLOCK_SOURCE_SELECT_MASK(index)
    _ADCHS_CONTROL_CLK_DIVISOR_MASK(index)
    _ADCHS_CONTROL_REG_1_MASK(index)
    _ADCHS_CONTROL_REG_2_MASK(index)
    _ADCHS_CONTROL_REG_3_MASK(index)
    _ADCHS_VREF_SOURCE_SELECTION_MASK(index)
    _ADCHS_ADCBASE_BASE_ADDR_MASK(index)
    _ADCHS_FRACTIONAL_MASK(index)
    _ADCHS_IDLE_MODE_CONTROL_MASK(index)
    _ADCHS_CHARGE_PUMP_CONTROL_MASK(index)
    _ADCHS_FAST_SYNC_SYS_CLK_CONTROL_MASK(index)
    _ADCHS_FAST_SYNC_PERIPH_CLK_CONTROL_MASK(index)
    _ADCHS_VECTOR_SHIFT_CONTROL_MASK(index)
    _ADCHS_CHANNEL_0_RESOLUTION_SELECTION_MASK(index)
    _ADCHS_CHANNEL_1_RESOLUTION_SELECTION_MASK(index)
    _ADCHS_CHANNEL_2_RESOLUTION_SELECTION_MASK(index)
    _ADCHS_CHANNEL_3_RESOLUTION_SELECTION_MASK(index)
    _ADCHS_CHANNEL_4_RESOLUTION_SELECTION_MASK(index)
    _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_MASK(index)
    _ADCHS_ADC_0_TIME_REG_MASK(index)
    _ADCHS_ADC_1_TIME_REG_MASK(index)
    _ADCHS_ADC_2_TIME_REG_MASK(index)
    _ADCHS_ADC_3_TIME_REG_MASK(index)
    _ADCHS_ADC_4_TIME_REG_MASK(index)
    _ADCHS_WARM_UP_COUNT_MASK(index)

  POSs: 
    _ADCHS_CHANNEL_0_SAMPLE_TIME_POS(index)
    _ADCHS_CHANNEL_1_SAMPLE_TIME_POS(index)
    _ADCHS_CHANNEL_2_SAMPLE_TIME_POS(index)
    _ADCHS_CHANNEL_3_SAMPLE_TIME_POS(index)
    _ADCHS_CHANNEL_4_SAMPLE_TIME_POS(index)
    _ADCHS_CHANNEL_7_SAMPLE_TIME_POS(index)
    _ADCHS_EARLY_INT_OVERRIDE_POS(index)
    _ADCHS_CHANNEL_0_EARLY_INTERRUPT_SELECTION_POS(index)
    _ADCHS_CHANNEL_1_EARLY_INTERRUPT_SELECTION_POS(index)
    _ADCHS_CHANNEL_2_EARLY_INTERRUPT_SELECTION_POS(index)
    _ADCHS_CHANNEL_3_EARLY_INTERRUPT_SELECTION_POS(index)
    _ADCHS_CHANNEL_4_EARLY_INTERRUPT_SELECTION_POS(index)
    _ADCHS_CHANNEL_7_EARLY_INTERRUPT_SELECTION_POS(index)
    _ADCHS_CHANNEL_0_CLOCK_DIVISOR_POS(index)
    _ADCHS_CHANNEL_1_CLOCK_DIVISOR_POS(index)
    _ADCHS_CHANNEL_2_CLOCK_DIVISOR_POS(index)
    _ADCHS_CHANNEL_3_CLOCK_DIVISOR_POS(index)
    _ADCHS_CHANNEL_4_CLOCK_DIVISOR_POS(index)
    _ADCHS_CHANNEL_7_CLOCK_DIVISOR_POS(index)
    _ADCHS_CLOCK_SOURCE_SELECT_POS(index)
    _ADCHS_CONTROL_CLK_DIVISOR_POS(index)
    _ADCHS_CONTROL_REG_1_POS(index)
    _ADCHS_CONTROL_REG_2_POS(index)
    _ADCHS_CONTROL_REG_3_POS(index)
    _ADCHS_VREF_SOURCE_SELECTION_POS(index)
    _ADCHS_ADCBASE_BASE_ADDR_POS(index)
    _ADCHS_FRACTIONAL_POS(index)
    _ADCHS_IDLE_MODE_CONTROL_POS(index)
    _ADCHS_CHARGE_PUMP_CONTROL_POS(index)
    _ADCHS_FAST_SYNC_SYS_CLK_CONTROL_POS(index)
    _ADCHS_FAST_SYNC_PERIPH_CLK_CONTROL_POS(index)
    _ADCHS_VECTOR_SHIFT_CONTROL_POS(index)
    _ADCHS_CHANNEL_0_RESOLUTION_SELECTION_POS(index)
    _ADCHS_CHANNEL_1_RESOLUTION_SELECTION_POS(index)
    _ADCHS_CHANNEL_2_RESOLUTION_SELECTION_POS(index)
    _ADCHS_CHANNEL_3_RESOLUTION_SELECTION_POS(index)
    _ADCHS_CHANNEL_4_RESOLUTION_SELECTION_POS(index)
    _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_POS(index)
    _ADCHS_ADC_0_TIME_REG_POS(index)
    _ADCHS_ADC_1_TIME_REG_POS(index)
    _ADCHS_ADC_2_TIME_REG_POS(index)
    _ADCHS_ADC_3_TIME_REG_POS(index)
    _ADCHS_ADC_4_TIME_REG_POS(index)
    _ADCHS_WARM_UP_COUNT_POS(index)

  LENs: 
    _ADCHS_CHANNEL_0_SAMPLE_TIME_LEN(index)
    _ADCHS_CHANNEL_1_SAMPLE_TIME_LEN(index)
    _ADCHS_CHANNEL_2_SAMPLE_TIME_LEN(index)
    _ADCHS_CHANNEL_3_SAMPLE_TIME_LEN(index)
    _ADCHS_CHANNEL_4_SAMPLE_TIME_LEN(index)
    _ADCHS_CHANNEL_7_SAMPLE_TIME_LEN(index)
    _ADCHS_EARLY_INT_OVERRIDE_LEN(index)
    _ADCHS_CHANNEL_0_EARLY_INTERRUPT_SELECTION_LEN(index)
    _ADCHS_CHANNEL_1_EARLY_INTERRUPT_SELECTION_LEN(index)
    _ADCHS_CHANNEL_2_EARLY_INTERRUPT_SELECTION_LEN(index)
    _ADCHS_CHANNEL_3_EARLY_INTERRUPT_SELECTION_LEN(index)
    _ADCHS_CHANNEL_4_EARLY_INTERRUPT_SELECTION_LEN(index)
    _ADCHS_CHANNEL_7_EARLY_INTERRUPT_SELECTION_LEN(index)
    _ADCHS_CHANNEL_0_CLOCK_DIVISOR_LEN(index)
    _ADCHS_CHANNEL_1_CLOCK_DIVISOR_LEN(index)
    _ADCHS_CHANNEL_2_CLOCK_DIVISOR_LEN(index)
    _ADCHS_CHANNEL_3_CLOCK_DIVISOR_LEN(index)
    _ADCHS_CHANNEL_4_CLOCK_DIVISOR_LEN(index)
    _ADCHS_CHANNEL_7_CLOCK_DIVISOR_LEN(index)
    _ADCHS_CLOCK_SOURCE_SELECT_LEN(index)
    _ADCHS_CONTROL_CLK_DIVISOR_LEN(index)
    _ADCHS_CONTROL_REG_1_LEN(index)
    _ADCHS_CONTROL_REG_2_LEN(index)
    _ADCHS_CONTROL_REG_3_LEN(index)
    _ADCHS_VREF_SOURCE_SELECTION_LEN(index)
    _ADCHS_ADCBASE_BASE_ADDR_LEN(index)
    _ADCHS_FRACTIONAL_LEN(index)
    _ADCHS_IDLE_MODE_CONTROL_LEN(index)
    _ADCHS_CHARGE_PUMP_CONTROL_LEN(index)
    _ADCHS_FAST_SYNC_SYS_CLK_CONTROL_LEN(index)
    _ADCHS_FAST_SYNC_PERIPH_CLK_CONTROL_LEN(index)
    _ADCHS_VECTOR_SHIFT_CONTROL_LEN(index)
    _ADCHS_CHANNEL_0_RESOLUTION_SELECTION_LEN(index)
    _ADCHS_CHANNEL_1_RESOLUTION_SELECTION_LEN(index)
    _ADCHS_CHANNEL_2_RESOLUTION_SELECTION_LEN(index)
    _ADCHS_CHANNEL_3_RESOLUTION_SELECTION_LEN(index)
    _ADCHS_CHANNEL_4_RESOLUTION_SELECTION_LEN(index)
    _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_LEN(index)
    _ADCHS_ADC_0_TIME_REG_LEN(index)
    _ADCHS_ADC_1_TIME_REG_LEN(index)
    _ADCHS_ADC_2_TIME_REG_LEN(index)
    _ADCHS_ADC_3_TIME_REG_LEN(index)
    _ADCHS_ADC_4_TIME_REG_LEN(index)
    _ADCHS_WARM_UP_COUNT_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_Setup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_Setup 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_Setup function.
*/

PLIB_TEMPLATE void ADCHS_Setup_Default( ADCHS_MODULE_ID index , ADCHS_VREF_SOURCE voltageRefSelect , ADCHS_CHARGEPUMP_MODE chargePump , ADCHS_OUTPUT_DATA_FORMAT outputFormat , bool stopInIdle , ADCHS_FAST_SYNC_SYSTEM_CLOCK sysClk , ADCHS_FAST_SYNC_PERIPHERAL_CLOCK periClk , ADCHS_INTERRUPT_BIT_SHIFT_LEFT intVectorShift , uint16_t intVectorBase , ADCHS_CLOCK_SOURCE adcClockSource , int8_t adcClockDivider , ADCHS_WARMUP_CLOCK warmUpClock )
{
    uint32_t	adc_1_Val = 0;
	uint32_t	adc_3_Val = 0;
	
	SFR_TYPE * baseAddr = _ADCHS_CONTROL_REG_1_VREG(index);
	
	_SFR_FIELD_WRITE(_ADCHS_VREF_SOURCE_SELECTION_VREG(index),
					 _ADCHS_VREF_SOURCE_SELECTION_MASK(index),
					 _ADCHS_VREF_SOURCE_SELECTION_POS(index) ,
					 voltageRefSelect );	
					 
	if( chargePump == ADCHS_CHARGEPUMP_ENABLE)
	{
		adc_1_Val = adc_1_Val | 0x00001000;
	}
	
	if(outputFormat == ADCHS_OUTPUT_DATA_FORMAT_FRACTIONAL)
	{
		adc_1_Val = adc_1_Val | 0x00800000;
	}
	
	if( stopInIdle == true )
	{
		adc_1_Val = adc_1_Val | 0x00002000;
	}
	
	if( sysClk == ADCHS_FAST_SYNC_SYSTEM_CLOCK_ENABLE )
	{
		adc_1_Val = adc_1_Val | 0x00000400;
	}
	
	if( periClk == ADCHS_FAST_SYNC_PERIPHERAL_CLOCK_ENABLE )
	{
		adc_1_Val = adc_1_Val | 0x00000200;
	}

	adc_1_Val = adc_1_Val | (uint32_t)(intVectorShift <<4);
	
	// First clear the bits before writing
	*(baseAddr) &= ~ (0x00001000 | 0x00800000 | 0x00002000 | 0x00000400 | 0x00000200 | 0x00000070);
	*(baseAddr) |= adc_1_Val;

	
	_SFR_WRITE(_ADCHS_ADCBASE_BASE_ADDR_VREG(index),intVectorBase);
	
	
	adc_3_Val = adc_3_Val | (uint32_t)(adcClockSource << 30);
	
	if(adcClockDivider > 64)
		adcClockDivider = 64;
		
	adc_3_Val = adc_3_Val | (uint32_t)(adcClockDivider << 24);
	
	// First clear the bits before writing
	*(baseAddr + 2) &= ~ 0xFF000000;
	*(baseAddr + 2) |= adc_3_Val;	
	
	_SFR_FIELD_WRITE(_ADCHS_WARM_UP_COUNT_VREG(index),
					 _ADCHS_WARM_UP_COUNT_MASK(index),
					 _ADCHS_WARM_UP_COUNT_POS(index) ,
					 warmUpClock );	
	
}


//******************************************************************************
/* Function :  ADCHS_ChannelSetup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelSetup 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelSetup function.
*/

PLIB_TEMPLATE void ADCHS_ChannelSetup_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID , ADCHS_DATA_RESOLUTION res , uint8_t	channelClockDivider , uint16_t sampleTimeCount , ADCHS_EARLY_INTERRUPT_PRIOR_CLOCK earlyInterruptClk )
{
	uint32_t tempVal = 0;
	SFR_TYPE * baseAddr;
		
	if( channelID == ADCHS_CHANNEL_7)
	{
		tempVal = tempVal | (uint32_t)(channelClockDivider);
		tempVal = tempVal | (uint32_t)(sampleTimeCount << 16);
		tempVal = tempVal | (uint32_t)(earlyInterruptClk << 8);
	
		baseAddr = _ADCHS_CONTROL_REG_2_VREG(index);
		
		// First clear the bits before writing
		*(baseAddr) &= ~ (0x0000007F | 0x03FF0000 | 0x00000700);
		*(baseAddr) |= tempVal;						 
		
        _SFR_FIELD_WRITE(_ADCHS_CHANNEL_7_RESOLUTION_SELECTION_VREG(index),
                         _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_MASK(index),
                         _ADCHS_CHANNEL_7_RESOLUTION_SELECTION_POS(index) ,
                         res );		
	}
	else
	{
		tempVal = tempVal | (uint32_t)(sampleTimeCount);
		tempVal = tempVal | (uint32_t)(channelClockDivider << 16);
		tempVal = tempVal | (uint32_t)(earlyInterruptClk << 26);
		tempVal = tempVal | (uint32_t)(res << 24);		
	
		baseAddr = (_ADCHS_ADC_0_TIME_REG_VREG(index) + channelID);
		
		// First clear the bits before writing
		*(baseAddr) &= ~ (0x000003FF | 0x007F0000 | 0x1C0000000 | 0x03000000);
		*(baseAddr) |= tempVal;						 
	}
}


//******************************************************************************
/* Function :  ADCHS_ExistsConfiguration_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsConfiguration

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsConfiguration function.
*/

#define PLIB_ADCHS_ExistsConfiguration PLIB_ADCHS_ExistsConfiguration
PLIB_TEMPLATE bool ADCHS_ExistsConfiguration_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_SETUP_DEFAULT_H*/

/******************************************************************************
 End of File
*/

