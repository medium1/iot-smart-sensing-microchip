/*
 * Project name:
	  Pressure Click
 * Copyright:
	  (c) Mikroelektronika, 2013.
 * Revision History:
	  20130410:
		 - initial release (VP);
 * Description:
	  This program demonstrates measuring of the Pressure and Temprerature.
	  Microcontroller take the data about pressure and temperature wich is measured on the Pressure Click.
	  It establishes I2C bus communication with  LPS331AP MEMS pressure sensor ( who can messer 260-1260 mbar absolute digital output barometer),
	  writes bytes of data on some location, then reads it and displays it on TFT.
 * Test configuration:
	  MCU:             PIC32MX795F512L
							 http://ww1.microchip.com/downloads/en/DeviceDoc/61156H.pdf
	  Dev. Board:      EasyPIC v7 Fusion
							 http://www.mikroe.com/easypic-fusion/
	  Oscillator:      XT-PLL, 80.00000MHz
	  Ext. modules:    Pressure Click - ac:Pressure_click
							 http://www.mikroe.com/click/pressure/
	  SW:              mikroC PRO for PIC32
							 http://www.mikroe.com/mikroc/pic32/
 * NOTES:
	  - Place Pressure click board in the mikroBUS socket 1.
	  - Turn on TFT backlight on SW11.
 */

#include "app.h"

#define _REF_P_XL 0x08                       //  Reference pressure (LSB)
#define _REF_P_L 0x09                        //  Reference pressure  (middle)
#define _REF_P_H 0x0A                        //  Reference pressure   (MSB)

#define _WHO_AM_I 0x0F                       //  Device identification

#define _RES_CONF 0x10                       //  Pressure resolution

#define _CTRL_REG1 0x20                      //  Control register 1
#define _CTRL_REG2 0x21                      //  Control register 2
#define _CTRL_REG3 0x22                      //  Control register 3

#define _INT_CFG_REG 0x23                    //  Interrupt configuration
#define _INT_SOURCE_REG 0x24                 //  Interrupt source

#define _THS_P_LOW_REG 0x25                  //  Treshold pressure (LSB)
#define _THS_P_HIGH_REG 0x26                 //  Treshold pressure (MSB)

#define _STATUS_REG 0x27                     //  Status register

#define _PRESS_POUT_XL_REH 0x28                    //  Pressure data (LSB)
#define _PRESS_OUT_L   0x29                  //  Pressure data (middle)
#define _PRESS_OUT_H   0x2A                  //  Pressure data (MSB)

#define _TEMP_OUT_L 0x2B                     //  Temperature data (LSB)
#define _TEMP_OUT_H 0x2C                     //  Temperature data (MSB)

#define _AMP_CTRL 0x30                       //  Analog front ned control


#define _PRESSURE_W_ADDRESS  0xBA            //  BA       //alt 0xB8
#define _PRESSURE_R_ADDRESS  0xBB            //  BB       //alt 0xB9

char out_temp[14], out_pres[14];			  // Declaration of variable
short address, buffer;								// Declaration of variables
int tempor ;											// Declaration of variable

#define TEMP_OFFSET 11000

/* Declaration of function, which will initiate I2C communication on relation Miccrocontroler - Pressure Click
  and write one byte through I2C, onto memory address on the Pressure Click */
void Pressure_Write(unsigned short reg, unsigned short value)
{
	chip_id_address=_PRESSURE_W_ADDRESS;
	writeI2C1reg(reg,value);
	return;
}

// Declaration of function, which will read the measured data from Pressure Click, through I2C communication.
unsigned short Pressure_Read(unsigned short address)
{
	ReadI2C1(address);
	return I2C1_val2;
}

// Declaration of function, which will initiate Pressure values
char Pressure_Init(void)
{
	unsigned short temp;								 // Declaration of local variable
	int err = 0;										 // Declaration of local variable

	Pressure_Write(_RES_CONF, 0x78);				 // Initiating the pressure resolution on Pressure Click with writing HEX value in his register ( in this case HEX 0x78)
	temp = Pressure_Read(_RES_CONF);				 // Begining of checking of entered value in the register _RES_CONF of the Pressure Click

	if (temp != 0x78)
	{
		err++;
	}														 // End of checking of entered value in the register _RES_CONF of the Pressure Click

	Pressure_Write(_CTRL_REG1, 0x74);
	temp = Pressure_Read(_CTRL_REG1);			 // Begining of checking of entered value in the register _CTRL_REG1 (Control register 1) of the Pressure Click

	if (temp != 0x74)
	{
		err++;
	}														 // End of checking of entered value in the register _CTRL_REG1 (Control register 1) of the Pressure Click

	Pressure_Write(_CTRL_REG1, 0xF4);
	temp = Pressure_Read(_CTRL_REG1);			 // Begining of checking of entered value in the register _CTRL_REG1 (Control register 1) of the Pressure Click
	if (temp != 0xF4)
	{
		err++;
	}														 // End of checking of entered value in the register _CTRL_REG1 (Control register 1) of the Pressure Click

	temp = Pressure_Read(_WHO_AM_I);				 // Checking the read-only register from Pressure Click, which contains the device ID (Adresse of Device). For LPS331AP, is set to BBh
	if (temp != 0xBB)
	{
		err++;
	}

	return err;
}

// Declaration of function which will read the measuring values of pressure from the Pressure Click
long int Pressure_Read_value(void)
{
	unsigned short low_byte;											  // Declaration of local variable
	unsigned short mid_byte;											  // Declaration of local variable
	long int Out_pressure;												  // Declaration of local variable

	Out_pressure = Pressure_Read(_PRESS_OUT_H);					  // Taking values of placed setings from registers _PRESS_OUT_H, from Pressure Click
	mid_byte = Pressure_Read(_PRESS_OUT_L);						  // Taking values of placed setings from registers _PRESS_OUT_L, from Pressure Click
	low_byte = Pressure_Read(_PRESS_POUT_XL_REH);				  // Taking values of placed setings from registers _PRESS_POUT_XL_REH, from Pressure Click

	Out_pressure = (Out_pressure << 8);								  // Forming the resulting values of pressure
	Out_pressure = (Out_pressure | mid_byte);
	Out_pressure = (Out_pressure << 8);
	Out_pressure = (Out_pressure | low_byte);

	Out_pressure >>= 12;
	return Out_pressure;
}

// Declaration of function which will read the measuring values of temperature from the Pressure Click
long int Temperature_Read_value(void)
{
	volatile unsigned short low_byte;								  // Declaration of local variable
	volatile int Out_temperature;									  // Declaration of local variable

	Out_temperature = Pressure_Read(_TEMP_OUT_H);				  // Forming the resulting values of temperature
	low_byte = Pressure_Read(_TEMP_OUT_L);

	Out_temperature = (Out_temperature << 8);
	Out_temperature = (Out_temperature | low_byte) + TEMP_OFFSET;

	return Out_temperature;
}

void pressure_temp_read(void)
{
	volatile unsigned char retrycnt=2;
	while (Pressure_Init() && retrycnt > 0)
	{
		retrycnt--;
	}
	if (retrycnt > 0)
	{
		temperature_value = ((float)Temperature_Read_value()/1000-32.0)*5/9;
		pressure_value = Pressure_Read_value();
	}
	else
	{
		temperature_value = 0;
		pressure_value = 0;
	}
}

