/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_DigitalFeatureControl_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : DigitalFeatureControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_ChannelDigitalFeatureEnable
        PLIB_ADCHS_ChannelDigitalFeatureDisable
        PLIB_ADCHS_ExistsChannelDigitalControl

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

#ifndef _ADCHS_DIGITALFEATURECONTROL_DEFAULT_H
#define _ADCHS_DIGITALFEATURECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_CHANNEL_7_DIGITAL_CONTROL_VREG(index)
    _ADCHS_CHANNEL_4_DIGITAL_CONTROL_VREG(index)
    _ADCHS_CHANNEL_3_DIGITAL_CONTROL_VREG(index)
    _ADCHS_CHANNEL_2_DIGITAL_CONTROL_VREG(index)
    _ADCHS_CHANNEL_1_DIGITAL_CONTROL_VREG(index)
    _ADCHS_CHANNEL_0_DIGITAL_CONTROL_VREG(index)

  MASKs: 
    _ADCHS_CHANNEL_7_DIGITAL_CONTROL_MASK(index)
    _ADCHS_CHANNEL_4_DIGITAL_CONTROL_MASK(index)
    _ADCHS_CHANNEL_3_DIGITAL_CONTROL_MASK(index)
    _ADCHS_CHANNEL_2_DIGITAL_CONTROL_MASK(index)
    _ADCHS_CHANNEL_1_DIGITAL_CONTROL_MASK(index)
    _ADCHS_CHANNEL_0_DIGITAL_CONTROL_MASK(index)

  POSs: 
    _ADCHS_CHANNEL_7_DIGITAL_CONTROL_POS(index)
    _ADCHS_CHANNEL_4_DIGITAL_CONTROL_POS(index)
    _ADCHS_CHANNEL_3_DIGITAL_CONTROL_POS(index)
    _ADCHS_CHANNEL_2_DIGITAL_CONTROL_POS(index)
    _ADCHS_CHANNEL_1_DIGITAL_CONTROL_POS(index)
    _ADCHS_CHANNEL_0_DIGITAL_CONTROL_POS(index)

  LENs: 
    _ADCHS_CHANNEL_7_DIGITAL_CONTROL_LEN(index)
    _ADCHS_CHANNEL_4_DIGITAL_CONTROL_LEN(index)
    _ADCHS_CHANNEL_3_DIGITAL_CONTROL_LEN(index)
    _ADCHS_CHANNEL_2_DIGITAL_CONTROL_LEN(index)
    _ADCHS_CHANNEL_1_DIGITAL_CONTROL_LEN(index)
    _ADCHS_CHANNEL_0_DIGITAL_CONTROL_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_ChannelDigitalFeatureEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelDigitalFeatureEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelDigitalFeatureEnable function.
*/

PLIB_TEMPLATE void ADCHS_ChannelDigitalFeatureEnable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	_SFR_BIT_WRITE( _ADCHS_CHANNEL_0_DIGITAL_CONTROL_VREG( index ),
				  (16 + channelID), 1 );
}


//******************************************************************************
/* Function :  ADCHS_ChannelDigitalFeatureDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelDigitalFeatureDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelDigitalFeatureDisable function.
*/

PLIB_TEMPLATE void ADCHS_ChannelDigitalFeatureDisable_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID )
{
	_SFR_BIT_WRITE( _ADCHS_CHANNEL_0_DIGITAL_CONTROL_VREG( index ),
				  (16 + channelID), 0 );
}


//******************************************************************************
/* Function :  ADCHS_ExistsChannelDigitalControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsChannelDigitalControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsChannelDigitalControl function.
*/

#define PLIB_ADCHS_ExistsChannelDigitalControl PLIB_ADCHS_ExistsChannelDigitalControl
PLIB_TEMPLATE bool ADCHS_ExistsChannelDigitalControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_DIGITALFEATURECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/
