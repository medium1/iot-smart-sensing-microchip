/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_AnalogInputModeControl_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : AnalogInputModeControl
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_AnalogInputModeSelect
        PLIB_ADCHS_AnalogInputModeGet
        PLIB_ADCHS_ExistsAnalogInputModeControl

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

#ifndef _ADCHS_ANALOGINPUTMODECONTROL_DEFAULT_H
#define _ADCHS_ANALOGINPUTMODECONTROL_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_INPUT_MODE_CON_REG_1_VREG(index)

  MASKs: 
    _ADCHS_INPUT_MODE_CON_REG_1_MASK(index)

  POSs: 
    _ADCHS_INPUT_MODE_CON_REG_1_POS(index)

  LENs: 
    _ADCHS_INPUT_MODE_CON_REG_1_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_AnalogInputModeSelect_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputModeSelect 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputModeSelect function.
*/

PLIB_TEMPLATE void ADCHS_AnalogInputModeSelect_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput , ADCHS_INPUT_MODE mode )
{
	switch( mode )
	{
		case ADCHS_INPUT_MODE_SINGLE_ENDED_UNIPOLAR:
			if( analogInput <= ADCHS_AN15 )
			{
				_SFR_BIT_WRITE( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
							  ((2 * analogInput) + 1), 0 );
				_SFR_BIT_WRITE( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
							  (2 * analogInput), 0 );
			}
			else if(( analogInput > ADCHS_AN15 ) && ( analogInput <= 31 ))
			{
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
							  ((2 * (analogInput - ADCHS_AN16)) + 1), 0 );
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
							  (2 * (analogInput - ADCHS_AN16)), 0);
			}
			else if( analogInput > 31 )
			{
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
							  ((2 * (analogInput - 32)) + 1), 0 );
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
							  (2 * (analogInput - 32)), 0);
			}
			break;
		case ADCHS_INPUT_MODE_SINGLE_ENDED_TWOS_COMP:
			if( analogInput <= ADCHS_AN15 )
			{
				_SFR_BIT_WRITE( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
							  ((2 * analogInput) + 1), 0 );
				_SFR_BIT_WRITE( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
							  (2 * analogInput), 1);
			}
			else if(( analogInput > ADCHS_AN15 ) && ( analogInput <= 31 ))
			{
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
							  ((2 * (analogInput - ADCHS_AN16)) + 1), 0 );
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
							  (2 * (analogInput - ADCHS_AN16)), 1);
			}
			else if( analogInput > 31 )
			{
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
							  ((2 * (analogInput - 32)) + 1), 0 );
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
							  (2 * (analogInput - 32)), 1);
			}
			break;
		case ADCHS_INPUT_MODE_DIFFERENTIAL_UNIPOLAR:
			if( analogInput <= ADCHS_AN15 )
			{
				_SFR_BIT_WRITE( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
							  ((2 * analogInput) + 1), 1 );
				_SFR_BIT_WRITE( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
							  (2 * analogInput), 0);
			}
			else if(( analogInput > ADCHS_AN15 ) && ( analogInput <= 31 ))
			{
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
							  ((2 * (analogInput - ADCHS_AN16)) + 1), 1 );
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
							  (2 * (analogInput - ADCHS_AN16)), 0);
			}
			else if( analogInput > 31 )
			{
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
							  ((2 * (analogInput - 32)) + 1), 1 );
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
							  (2 * (analogInput - 32)), 0);
			}
			break;
		case ADCHS_INPUT_MODE_DIFFERENTIAL_TWOS_COMP:
			if( analogInput <= ADCHS_AN15 )
			{
				_SFR_BIT_WRITE( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
							  ((2 * analogInput) + 1), 1 );
				_SFR_BIT_WRITE( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
							  (2 * analogInput), 1);
			}
			else if(( analogInput > ADCHS_AN15 ) && ( analogInput <= 31 ))
			{
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
							  ((2 * (analogInput - ADCHS_AN16)) + 1), 1 );
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
							  (2 * (analogInput - ADCHS_AN16)), 1);
			}
			else if( analogInput > 31 )
			{
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
							  ((2 * (analogInput - 32)) + 1), 1 );
				_SFR_BIT_WRITE( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
							  (2 * (analogInput - 32)), 1);
			}
			break;
		default:
			break;
	}
}


//******************************************************************************
/* Function :  ADCHS_AnalogInputModeGet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_AnalogInputModeGet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_AnalogInputModeGet function.
*/

PLIB_TEMPLATE ADCHS_INPUT_MODE ADCHS_AnalogInputModeGet_Default( ADCHS_MODULE_ID index , ADCHS_AN_INPUT_ID analogInput )
{
	bool msb = false, lsb = false;

	if( analogInput <= ADCHS_AN15 )
	{
		msb = _SFR_BIT_READ( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
					  ((2 * analogInput) + 1));
		lsb = _SFR_BIT_READ( _ADCHS_INPUT_MODE_CON_REG_1_VREG( index ),
					  (2 * analogInput) );
	}
	else if(( analogInput > ADCHS_AN15 ) && ( analogInput <= 31 ))
	{
		msb = _SFR_BIT_READ( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
					  ((2 * (analogInput - ADCHS_AN16)) + 1));
		lsb = _SFR_BIT_READ( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 1),
					  (2 * (analogInput - ADCHS_AN16)) );
	}
	else if( analogInput > 31 )
	{
		msb = _SFR_BIT_READ( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
					  ((2 * (analogInput - 32)) + 1));
		lsb = _SFR_BIT_READ( (_ADCHS_INPUT_MODE_CON_REG_1_VREG( index ) + 2),
					  (2 * (analogInput - 32)) );
	}

	if( (msb == true) && (lsb == true) )
	{
		return ADCHS_INPUT_MODE_DIFFERENTIAL_TWOS_COMP;
	}
	else if( (msb == true) && (lsb == false) )
	{
		return ADCHS_INPUT_MODE_DIFFERENTIAL_UNIPOLAR;
	}
	else if( (msb == false) && (lsb == true) )
	{
		return ADCHS_INPUT_MODE_SINGLE_ENDED_TWOS_COMP;
	}
	else if( (msb == false) && (lsb == false) )
	{
		return ADCHS_INPUT_MODE_SINGLE_ENDED_UNIPOLAR;
	}
        else
        {
            return ADCHS_INPUT_MODE_SINGLE_ENDED_UNIPOLAR;
        }
}


//******************************************************************************
/* Function :  ADCHS_ExistsAnalogInputModeControl_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsAnalogInputModeControl

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsAnalogInputModeControl function.
*/

#define PLIB_ADCHS_ExistsAnalogInputModeControl PLIB_ADCHS_ExistsAnalogInputModeControl
PLIB_TEMPLATE bool ADCHS_ExistsAnalogInputModeControl_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_ANALOGINPUTMODECONTROL_DEFAULT_H*/

/******************************************************************************
 End of File
*/

