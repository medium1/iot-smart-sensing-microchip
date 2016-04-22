#include "xc.h"
#include "app.h"


bool writeI2C1reg(unsigned short reg,unsigned short I2C1_val)
{
	unsigned short temp=reg, temp1=I2C1_val;
	I2C1CONbits.ON=1;
	if (waitForI2C1()==false)
		return false;

	I2C1CONbits.SEN=1;
	if (waitForI2C1()==false)
		return false;

	I2C1TRN=chip_id_address;
	if (waitForI2C1()==false)
		return false;

	I2C1TRN=reg;
	if (waitForI2C1()==false)
		return false;

	I2C1TRN=I2C1_val;
	if (waitForI2C1()==false)
		return false;

	I2C1CONbits.PEN=1;
	if (waitForI2C1()==false)
		return false;

	I2C1CONbits.ON=0;
	return true;
}

// reads status registers of I2C1
// updates event flags
bool ReadI2C1(unsigned short reg)
{

	unsigned short temp=reg;
	I2C1CONbits.ON=1;
	if (waitForI2C1()==false)
		return false;

	I2C1CONbits.SEN=1;  // send start
	if (waitForI2C1()==false)
		return false;

	I2C1TRN=chip_id_address;		// send chip addr as write
	if (waitForI2C1()==false)
		return false;

	I2C1TRN=reg;		 // reg number on remote chip
	if (waitForI2C1()==false)
		return false;

	I2C1CONbits.RSEN=1;	// generate re-start
	if (waitForI2C1()==false)
		return false;

	I2C1TRN=chip_id_address + 1;	 // send addr with read bit set
	if (waitForI2C1()==false)
		return false;

	I2C1STATbits.I2COV = 0;
	I2C1CONbits.RCEN=1;		// receive first status byte
	if (waitForI2C1()==false)
		return false;
	I2C1_val1=I2C1RCV;

	I2C1CONbits.ACKDT=0;	 // generate ACK
	I2C1CONbits.ACKEN=1;
	if (waitForI2C1()==false)
		return false;

	I2C1CONbits.RCEN=1;		// receive second status byte
	if (waitForI2C1()==false)
		return false;
	I2C1_val2=I2C1RCV;

	I2C1CONbits.ACKDT=1;	// generate NACK
	I2C1CONbits.ACKEN=1;
	if (waitForI2C1()==false)
		return false;

	I2C1CONbits.PEN=1;  // send stop
	if (waitForI2C1()==false)
		return false;

	I2C1CONbits.ON=0;

	return true;
}

void InitI2C1(void)
{
	// set up I2C 4
	I2C1CON=0;
	I2C1BRG=0x2f;
	I2C1CONbits.DISSLW=1;
	return;
}


bool waitForI2C1(void)
{
	volatile unsigned int timeout=0, timeoutlimit=5000;
	while ((I2C1CONbits.SEN || I2C1CONbits.PEN ||   I2C1CONbits.RCEN ||
			  I2C1CONbits.RSEN   || I2C1CONbits.ACKEN || I2C1STATbits.TRSTAT) && timeout < timeoutlimit)
		timeout++;
	if (timeout > (timeoutlimit-1))
		return false;
	else
		return true;
}



