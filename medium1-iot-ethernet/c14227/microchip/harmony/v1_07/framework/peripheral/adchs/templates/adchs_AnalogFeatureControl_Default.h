/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_AnalogFeatureControl_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AnalogFeatureControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_ChannelAnalogFeatureEnable
        PLIB_ADCHS_ChannelAnalogFeatureDisable
        PLIB_ADCHS_ChannelIsReady
        PLIB_ADCHS_ChannelIsReadyInterruptEnable
        PLIB_ADCHS_ChannelIsReadyInterruptDisable
        PLIB_ADCHS_ExistsChannelAnalogControl

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

#ifndef _ADCHS_ANALOGFEATURECONTROL_DEFAULT_H
#define _ADCHS_ANALOGFEATURECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_ANALOG_CONTROL_REG_VREG(index)
    _ADCHS_CHANNEL_7_WARM_UP_INTERRUPT_ENABLE_VREG(index)
    _ADCHS_CHANNEL_4_WARM_UP_INTERRUPT_ENABLE_VREG(index)
    _ADCHS_CHANNEL_3_WARM_UP_INTERRUPT_ENABLE_VREG(index)
    _ADCHS_CHANNEL_2_WARM_UP_INTERRUPT_ENABLE_VREG(index)
    _ADCHS_CHANNEL_1_WARM_UP_INTERRUPT_ENABLE_VREG(index)
    _ADCHS_CHANNEL_0_WARM_UP_INTERRUPT_ENABLE_VREG(index)
    _ADCHS_CHANNEL_7_WARMP_UP_READY_STATUS_VREG(index)
    _ADCHS_CHANNEL_4_WARMP_UP_READY_STATUS_VREG(index)
    _ADCHS_CHANNEL_3_WARMP_UP_READY_STATUS_VREG(index)
    _ADCHS_CHANNEL_2_WARMP_UP_READY_STATUS_VREG(index)
    _ADCHS_CHANNEL_1_WARMP_UP_READY_STATUS_VREG(index)
    _ADCHS_CHANNEL_0_WARMP_UP_READY_STATUS_VREG(index)
    _ADCHS_CHANNEL_7_ANALOG_ENABLE_CONTROL_VREG(index)
    _ADCHS_CHANNEL_4_ANALOG_ENABLE_CONTROL_VREG(index)
    _ADCHS_CHANNEL_3_ANALOG_ENABLE_CONTROL_VREG(index)
    _ADCHS_CHANNEL_2_ANALOG_ENABLE_CONTROL_VREG(index)
    _ADCHS_CHANNEL_1_ANALOG_ENABLE_CONTROL_VREG(index)
    _ADCHS_CHANNEL_0_ANALOG_ENABLE_CONTROL_VREG(index)

  MASKs: 
    _ADCHS_ANALOG_CONTROL_REG_MASK(index)
    _ADCHS_CHANNEL_7_WARM_UP_INTERRUPT_ENABLE_MASK(index)
    _ADCHS_CHANNEL_4_WARM_UP_INTERRUPT_ENABLE_MASK(index)
    _ADCHS_CHANNEL_3_WARM_UP_INTERRUPT_ENABLE_MASK(index)
    _ADCHS_CHANNEL_2_WARM_UP_INTERRUPT_ENABLE_MASK(index)
    _ADCHS_CHANNEL_1_WARM_UP_INTERRUPT_ENABLE_MASK(index)
    _ADCHS_CHANNEL_0_WARM_UP_INTERRUPT_ENABLE_MASK(index)
    _ADCHS_CHANNEL_7_WARMP_UP_READY_STATUS_MASK(index)
    _ADCHS_CHANNEL_4_WARMP_UP_READY_STATUS_MASK(index)
    _ADCHS_CHANNEL_3_WARMP_UP_READY_STATUS_MASK(index)
    _ADCHS_CHANNEL_2_WARMP_UP_READY_STATUS_MASK(index)
    _ADCHS_CHANNEL_1_WARMP_UP_READY_STATUS_MASK(index)
    _ADCHS_CHANNEL_0_WARMP_UP_READY_STATUS_MASK(index)
    _ADCHS_CHANNEL_7_ANALOG_ENABLE_CONTROL_MASK(index)
    _ADCHS_CHANNEL_4_ANALOG_ENABLE_CONTROL_MASK(index)
    _ADCHS_CHANNEL_3_ANALOG_ENABLE_CONTROL_MASK(index)
    _ADCHS_CHANNEL_2_ANALOG_ENABLE_CONTROL_MASK(index)
    _ADCHS_CHANNEL_1_ANALOG_ENABLE_CONTROL_MASK(index)
    _ADCHS_CHANNEL_0_ANALOG_ENABLE_CONTROL_MASK(index)

  POSs: 
    _ADCHS_ANALOG_CONTROL_REG_POS(index)
    _ADCHS_CHANNEL_7_WARM_UP_INTERRUPT_ENABLE_POS(index)
    _ADCHS_CHANNEL_4_WARM_UP_INTERRUPT_ENABLE_POS(index)
    _ADCHS_CHANNEL_3_WARM_UP_INTERRUPT_ENABLE_POS(index)
    _ADCHS_CHANNEL_2_WARM_UP_INTERRUPT_ENABLE_POS(index)
    _ADCHS_CHANNEL_1_WARM_UP_INTERRUPT_ENABLE_POS(index)
    _ADCHS_CHANNEL_0_WARM_UP_INTERRUPT_ENABLE_POS(index)
    _ADCHS_CHANNEL_7_WARMP_UP_READY_STATUS_POS(index)
    _ADCHS_CHANNEL_4_WARMP_UP_READY_STATUS_POS(index)
    _ADCHS_CHANNEL_3_WARMP_UP_READY_STATUS_POS(index)
    _ADCHS_CHANNEL_2_WARMP_UP_READY_STATUS_POS(index)
    _ADCHS_CHANNEL_1_WARMP_UP_READY_STATUS_POS(index)
    _ADCHS_CHANNEL_0_WARMP_UP_READY_STATUS_POS(index)
    _ADCHS_CHANNEL_7_ANALOG_ENABLE_CONTROL_POS(index)
    _ADCHS_CHANNEL_4_ANALOG_ENABLE_CONTROL_POS(index)
    _ADCHS_CHANNEL_3_ANALOG_ENABLE_CONTROL_POS(index)
    _ADCHS_CHANNEL_2_ANALOG_ENABLE_CONTROL_POS(index)
    _ADCHS_CHANNEL_1_ANALOG_ENABLE_CONTROL_POS(index)
    _ADCHS_CHANNEL_0_ANALOG_ENABLE_CONTROL_POS(index)

  LENs: 
    _ADCHS_ANALOG_CONTROL_REG_LEN(index)
    _ADCHS_CHANNEL_7_WARM_UP_INTERRUPT_ENABLE_LEN(index)
    _ADCHS_CHANNEL_4_WARM_UP_INTERRUPT_ENABLE_LEN(index)
    _ADCHS_CHANNEL_3_WARM_UP_INTERRUPT_ENABLE_LEN(index)
    _ADCHS_CHANNEL_2_WARM_UP_INTERRUPT_ENABLE_LEN(index)
    _ADCHS_CHANNEL_1_WARM_UP_INTERRUPT_ENABLE_LEN(index)
    _ADCHS_CHANNEL_0_WARM_UP_INTERRUPT_ENABLE_LEN(index)
    _ADCHS_CHANNEL_7_WARMP_UP_READY_STATUS_LEN(index)
    _ADCHS_CHANNEL_4_WARMP_UP_READY_STATUS_LEN(index)
    _ADCHS_CHANNEL_3_WARMP_UP_READY_STATUS_LEN(index)
    _ADCHS_CHANNEL_2_WARMP_UP_READY_STATUS_LEN(index)
    _ADCHS_CHANNEL_1_WARMP_UP_READY_STATUS_LEN(index)
    _ADCHS_CHANNEL_0_WARMP_UP_READY_STATUS_LEN(index)
    _ADCHS_CHANNEL_7_ANALOG_ENABLE_CONTROL_LEN(index)
    _ADCHS_CHANNEL_4_ANALOG_ENABLE_CONTROL_LEN(index)
    _ADCHS_CHANNEL_3_ANALOG_ENABLE_CONTROL_LEN(index)
    _ADCHS_CHANNEL_2_ANALOG_ENABLE_CONTROL_LEN(index)
    _ADCHS_CHANNEL_1_ANALOG_ENABLE_CONTROL_LEN(index)
    _ADCHS_CHANNEL_0_ANALOG_ENABLE_CONTROL_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_ChannelAnalogFeatureEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelAnalogFeatureEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelAnalogFeatureEnable function.
*/

PLIB_TEMPLATE void ADCHS_ChannelAnalogFeatureEnable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	_SFR_BIT_WRITE( _ADCHS_ANALOG_CONTROL_REG_VREG( index ),
				  channelID, 1 );
}


//******************************************************************************
/* Function :  ADCHS_ChannelAnalogFeatureDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelAnalogFeatureDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelAnalogFeatureDisable function.
*/

PLIB_TEMPLATE void ADCHS_ChannelAnalogFeatureDisable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	_SFR_BIT_WRITE( _ADCHS_ANALOG_CONTROL_REG_VREG( index ),
				  channelID, 0 );
}


//******************************************************************************
/* Function :  ADCHS_ChannelIsReady_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelIsReady 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelIsReady function.
*/

PLIB_TEMPLATE bool ADCHS_ChannelIsReady_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
    return( _SFR_BIT_READ( _ADCHS_ANALOG_CONTROL_REG_VREG( index ),
                           (channelID + 8)) );
}


//******************************************************************************
/* Function :  ADCHS_ChannelIsReadyInterruptEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelIsReadyInterruptEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelIsReadyInterruptEnable function.
*/

PLIB_TEMPLATE void ADCHS_ChannelIsReadyInterruptEnable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	_SFR_BIT_WRITE( _ADCHS_ANALOG_CONTROL_REG_VREG( index ),
				  (channelID + 16), 1 );
}


//******************************************************************************
/* Function :  ADCHS_ChannelIsReadyInterruptDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelIsReadyInterruptDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelIsReadyInterruptDisable function.
*/

PLIB_TEMPLATE void ADCHS_ChannelIsReadyInterruptDisable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	_SFR_BIT_WRITE( _ADCHS_ANALOG_CONTROL_REG_VREG( index ),
				  (channelID + 16), 0 );
}


//******************************************************************************
/* Function :  ADCHS_ExistsChannelAnalogControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsChannelAnalogControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsChannelAnalogControl function.
*/

#define PLIB_ADCHS_ExistsChannelAnalogControl PLIB_ADCHS_ExistsChannelAnalogControl
PLIB_TEMPLATE bool ADCHS_ExistsChannelAnalogControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_ANALOGFEATURECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

