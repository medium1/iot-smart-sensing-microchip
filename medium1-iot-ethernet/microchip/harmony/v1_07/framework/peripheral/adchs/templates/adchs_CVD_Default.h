/*******************************************************************************
  ADCHS Peripheral Library Template Implementation

  File Name:
    adchs_CVD_Default.h

  Summary:
    ADCHS PLIB Template Implementation

  Description:
    This header file contains template implementations
    For Feature : CVD
    and its Variant : Default
    For following APIs :
        PLIB_ADCHS_CVDEnable
        PLIB_ADCHS_CVDDisable
        PLIB_ADCHS_CVDSetup
        PLIB_ADCHS_CVDResultGet
        PLIB_ADCHS_ExistsCVD

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

#ifndef _ADCHS_CVD_DEFAULT_H
#define _ADCHS_CVD_DEFAULT_H

//******************************************************************************
/* Routines available for accessing VREGS, MASKS, POS, LEN are 

  VREGs: 
    _ADCHS_CVD_CAP_CONTROL_VREG(index)
    _ADCHS_CVD_RESULT_VREG(index)
    _ADCHS_CVD_MODE_ENABLE_CONTROL_VREG(index)

  MASKs: 
    _ADCHS_CVD_CAP_CONTROL_MASK(index)
    _ADCHS_CVD_RESULT_MASK(index)
    _ADCHS_CVD_MODE_ENABLE_CONTROL_MASK(index)

  POSs: 
    _ADCHS_CVD_CAP_CONTROL_POS(index)
    _ADCHS_CVD_RESULT_POS(index)
    _ADCHS_CVD_MODE_ENABLE_CONTROL_POS(index)

  LENs: 
    _ADCHS_CVD_CAP_CONTROL_LEN(index)
    _ADCHS_CVD_RESULT_LEN(index)
    _ADCHS_CVD_MODE_ENABLE_CONTROL_LEN(index)

*/


//******************************************************************************
/* Function :  ADCHS_CVDEnable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_CVDEnable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_CVDEnable function.
*/

PLIB_TEMPLATE void ADCHS_CVDEnable_Default( ADCHS_MODULE_ID index )
{
	_SFR_BIT_WRITE( _ADCHS_CVD_MODE_ENABLE_CONTROL_VREG( index ),
				  _ADCHS_CVD_MODE_ENABLE_CONTROL_POS( index ), 1 );
}


//******************************************************************************
/* Function :  ADCHS_CVDDisable_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_CVDDisable 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_CVDDisable function.
*/

PLIB_TEMPLATE void ADCHS_CVDDisable_Default( ADCHS_MODULE_ID index )
{
	_SFR_BIT_WRITE( _ADCHS_CVD_MODE_ENABLE_CONTROL_VREG( index ),
				  _ADCHS_CVD_MODE_ENABLE_CONTROL_POS( index ), 0 );
}


//******************************************************************************
/* Function :  ADCHS_CVDSetup_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_CVDSetup 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_CVDSetup function.
*/

PLIB_TEMPLATE void ADCHS_CVDSetup_Default( ADCHS_MODULE_ID index , ADCHS_CVD_CAPACITOR capSel , bool inBetweenOrEqual , bool greaterEqualHi , bool lessThanHi , bool greaterEqualLo , bool lessThanLo , ADCHS_AN_INPUT_ID inputEnable , int16_t  hiLimit , int16_t  loLimit )
{
	uint32_t comparatorLogic = 0;
	
	if( inputEnable >= 32)
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
	
	_SFR_FIELD_WRITE( _ADCHS_CVD_CAP_CONTROL_VREG( index ),
				  _ADCHS_CVD_CAP_CONTROL_MASK( index ),
				  _ADCHS_CVD_CAP_CONTROL_POS( index ),
				  capSel );
				  
    _SFR_FIELD_WRITE( _ADCHS_COMPARATOR_CONTROL_REG_1_VREG( index ),
					  0x0000001F,
					  0,
					  comparatorLogic );
	
	_SFR_BIT_WRITE( _ADCHS_COMPARATOR_AN_INPUT_REG_1_VREG( index ),
				  inputEnable, 1 );
				  
	_SFR_WRITE( _ADCHS_COMPARATOR_LIMIT_REG_1_VREG( index ),
				((uint32_t)(hiLimit << 16) | loLimit) );
}


//******************************************************************************
/* Function :  ADCHS_CVDResultGet_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_CVDResultGet 

  Description:
    This template implements the Default variant of the PLIB_ADCHS_CVDResultGet function.
*/

PLIB_TEMPLATE int16_t ADCHS_CVDResultGet_Default( ADCHS_MODULE_ID index )
{
    return( _SFR_FIELD_READ( _ADCHS_CVD_RESULT_VREG( index ),
							_ADCHS_CVD_RESULT_MASK( index ),
							_ADCHS_CVD_RESULT_POS( index )) );
}


//******************************************************************************
/* Function :  ADCHS_ExistsCVD_Default

  Summary:
    Implements Default variant of PLIB_ADCHS_ExistsCVD

  Description:
    This template implements the Default variant of the PLIB_ADCHS_ExistsCVD function.
*/

#define PLIB_ADCHS_ExistsCVD PLIB_ADCHS_ExistsCVD
PLIB_TEMPLATE bool ADCHS_ExistsCVD_Default( ADCHS_MODULE_ID index )
{
    return true;
}


#endif /*_ADCHS_CVD_DEFAULT_H*/

/******************************************************************************
 End of File
*/

