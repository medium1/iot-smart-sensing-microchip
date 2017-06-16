/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_InputControl_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : InputControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_ChannelInputSelect
        PLIB_ADCHS_ExistsChannelInputSelectControl

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

#ifndef _ADCHS_INPUTCONTROL_DEFAULT_H
#define _ADCHS_INPUTCONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_CHANNEL_4_ALT_INPUT_SEL_VREG(index)
    _ADCHS_CHANNEL_3_ALT_INPUT_SEL_VREG(index)
    _ADCHS_CHANNEL_2_ALT_INPUT_SEL_VREG(index)
    _ADCHS_CHANNEL_1_ALT_INPUT_SEL_VREG(index)
    _ADCHS_CHANNEL_0_ALT_INPUT_SEL_VREG(index)
    _ADCHS_TRIGGER_MODE_REG_VREG(index)

  MASKs: 
    _ADCHS_CHANNEL_4_ALT_INPUT_SEL_MASK(index)
    _ADCHS_CHANNEL_3_ALT_INPUT_SEL_MASK(index)
    _ADCHS_CHANNEL_2_ALT_INPUT_SEL_MASK(index)
    _ADCHS_CHANNEL_1_ALT_INPUT_SEL_MASK(index)
    _ADCHS_CHANNEL_0_ALT_INPUT_SEL_MASK(index)
    _ADCHS_TRIGGER_MODE_REG_MASK(index)

  POSs: 
    _ADCHS_CHANNEL_4_ALT_INPUT_SEL_POS(index)
    _ADCHS_CHANNEL_3_ALT_INPUT_SEL_POS(index)
    _ADCHS_CHANNEL_2_ALT_INPUT_SEL_POS(index)
    _ADCHS_CHANNEL_1_ALT_INPUT_SEL_POS(index)
    _ADCHS_CHANNEL_0_ALT_INPUT_SEL_POS(index)
    _ADCHS_TRIGGER_MODE_REG_POS(index)

  LENs: 
    _ADCHS_CHANNEL_4_ALT_INPUT_SEL_LEN(index)
    _ADCHS_CHANNEL_3_ALT_INPUT_SEL_LEN(index)
    _ADCHS_CHANNEL_2_ALT_INPUT_SEL_LEN(index)
    _ADCHS_CHANNEL_1_ALT_INPUT_SEL_LEN(index)
    _ADCHS_CHANNEL_0_ALT_INPUT_SEL_LEN(index)
    _ADCHS_TRIGGER_MODE_REG_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_ChannelInputSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ChannelInputSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ChannelInputSelect function.
*/

PLIB_TEMPLATE bool ADCHS_ChannelInputSelect_Default( ADCHS_MODULE_ID index , ADCHS_CHANNEL_ID channelID , ADCHS_CHANNEL_INP_SEL sel )
{
	if( channelID > ADCHS_CHANNEL_4)
		return false;
		
	switch( channelID )
	{
		case ADCHS_CHANNEL_0:
			if( sel > 3 )
				return false;
				
			_SFR_FIELD_WRITE(_ADCHS_CHANNEL_0_ALT_INPUT_SEL_VREG(index),
							 _ADCHS_CHANNEL_0_ALT_INPUT_SEL_MASK(index),
							 _ADCHS_CHANNEL_0_ALT_INPUT_SEL_POS(index) ,
							 sel );
			break;
		case ADCHS_CHANNEL_1:
			if((sel < 4) || (sel > 7 ))
				return false;	
				
			_SFR_FIELD_WRITE(_ADCHS_CHANNEL_1_ALT_INPUT_SEL_VREG(index),
							 _ADCHS_CHANNEL_1_ALT_INPUT_SEL_MASK(index),
							 _ADCHS_CHANNEL_1_ALT_INPUT_SEL_POS(index) ,
							 (sel - 4));
			break;
		case ADCHS_CHANNEL_2:
			if((sel < 8) || (sel > 11 ))
				return false;	
				
			_SFR_FIELD_WRITE(_ADCHS_CHANNEL_2_ALT_INPUT_SEL_VREG(index),
							 _ADCHS_CHANNEL_2_ALT_INPUT_SEL_MASK(index),
							 _ADCHS_CHANNEL_2_ALT_INPUT_SEL_POS(index) ,
							 (sel - 8));
			break;
		case ADCHS_CHANNEL_3:
			if((sel < 12) || (sel > 15 ))
				return false;		
				
			_SFR_FIELD_WRITE(_ADCHS_CHANNEL_3_ALT_INPUT_SEL_VREG(index),
							 _ADCHS_CHANNEL_3_ALT_INPUT_SEL_MASK(index),
							 _ADCHS_CHANNEL_3_ALT_INPUT_SEL_POS(index) ,
							 (sel - 12));
			break;
		case ADCHS_CHANNEL_4:
			if((sel < 16) || (sel > 19 ))
				return false;		
				
			_SFR_FIELD_WRITE(_ADCHS_CHANNEL_4_ALT_INPUT_SEL_VREG(index),
							 _ADCHS_CHANNEL_4_ALT_INPUT_SEL_MASK(index),
							 _ADCHS_CHANNEL_4_ALT_INPUT_SEL_POS(index) ,
							 (sel - 16));
			break;
		default:
			break;
	}
	
        return true;
}


//******************************************************************************
/* Function :  ADCHS_ExistsChannelInputSelectControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsChannelInputSelectControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsChannelInputSelectControl function.
*/

#define PLIB_ADCHS_ExistsChannelInputSelectControl PLIB_ADCHS_ExistsChannelInputSelectControl
PLIB_TEMPLATE bool ADCHS_ExistsChannelInputSelectControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_INPUTCONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

