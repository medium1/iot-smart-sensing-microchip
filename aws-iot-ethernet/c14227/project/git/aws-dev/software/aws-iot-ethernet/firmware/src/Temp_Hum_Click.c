#include <app.h>
// See HTS221 Humidity Sensor:
// "Capacitive digital sensor for relative humidity and temperature"
// http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/DM00116291.pdf

#define HTS221_AV_CONF           0x10       
#define HTS221_CTRL_REG1         0x20
#define HTS221_CTRL_REG2         0x21
#define HTS221_CTRL_REG3         0x22
#define HTS221_STATUS_REG        0x27
#define HTS221_HUMIDITY_OUT_L    0x28
#define HTS221_HUMIDITY_OUT_H    0x29
#define HTS221_TEMP_OUT_L        0x2A
#define HTS221_TEMP_OUT_H        0x2B
#define HTS221_CALIB_0           0x30  // CALIB 0 - F are read only!
#define HTS221_CALIB_1           0x31
#define HTS221_CALIB_2           0x32
#define HTS221_CALIB_3           0x33
#define HTS221_CALIB_4           0x34
#define HTS221_CALIB_5           0x35
#define HTS221_CALIB_6           0x36
#define HTS221_CALIB_7           0x37
#define HTS221_CALIB_8           0x38
#define HTS221_CALIB_9           0x39
#define HTS221_CALIB_A           0x3A
#define HTS221_CALIB_B           0x3B
#define HTS221_CALIB_C           0x3C
#define HTS221_CALIB_D           0x3D
#define HTS221_CALIB_E           0x3E
#define HTS221_CALIB_F           0x3F



// HTS221 temperature averaging
enum avgT
{
	avgT_2 = 0,
	avgT_4,
	avgT_8,
	avgT_16,	 // default
	avgT_32,
	avgT_64,
	avgT_128,
	avgT_256
};

// HTS221 humidity averaging
enum avgH
{
	avgH_4 = 0,
	avgH_8,
	avgH_16,	 // default
	avgH_32,
	avgH_64,
	avgH_128,
	avgH_256,
	avgH_512
};

// HTS221 humidity and temperature sample ODR
enum HTODR
{
	oneshot = 0,
	ODR_1Hz,
	ODR_7Hz, 
	ODR_12_5Hz 

};
// Specify sensor full scale
uint8_t avgT = avgT_256;			 // set temperature avergaging for HTS221
uint8_t avgH = avgH_512;			 // set humidity avergaging for HTS221
uint8_t HTODR = ODR_1Hz;		// set HTS221 humidity and temperature sample rate

// Calibration data for HTS221 humidity and temperature
uint8_t H0_rH_x2, H1_rH_x2, T0_degC_x8, T1_degC_x8, T0_msb, T1_msb;
int16_t H0_T0_OUT, H1_T0_OUT, T0_OUT, T1_OUT;

bool HTS221init(void)
{
	// Check WHO_AM_I register of HTS221
	ReadI2C1(HTS221_WHO_AM_I);
	if (I2C1_val1 == 0xBC)
	{
		writeI2C1reg(HTS221_AV_CONF, avgT << 3 | avgH);	 // set temperature and humidity averaging
		// power on HTS221 (bit 7) and enable block data update (bit 2)
		writeI2C1reg(HTS221_CTRL_REG1, 0x80 | 0x04 | HTODR);	 // set temperature and humidity sample ODR
		// Read calibrations data
		H0_rH_x2 = ReadI2C0(HTS221_CALIB_0);
		H1_rH_x2 = ReadI2C0(HTS221_CALIB_1);
		T0_degC_x8 = ReadI2C0(HTS221_CALIB_2);
		T1_degC_x8 = ReadI2C0(HTS221_CALIB_3);
		T0_msb = ReadI2C0(HTS221_CALIB_5) & 0x03;
		T1_msb = (ReadI2C0(HTS221_CALIB_5) & 0x0C) >> 2;
		H0_T0_OUT = (int16_t) ((int16_t) ReadI2C0(HTS221_CALIB_7) << 8 | ReadI2C0(HTS221_CALIB_6));
		H1_T0_OUT = (int16_t) ((int16_t) ReadI2C0(HTS221_CALIB_B) << 8 | ReadI2C0(HTS221_CALIB_A));
		T0_OUT = (int16_t) ((int16_t) ReadI2C0(HTS221_CALIB_D) << 8 | ReadI2C0(HTS221_CALIB_C));
		T1_OUT = (int16_t) ((int16_t) ReadI2C0(HTS221_CALIB_F) << 8 | ReadI2C0(HTS221_CALIB_E));
		return true;
	}
	return false;
}

void humidity_temperature_read(void)
{
	if (ReadI2C0(HTS221_STATUS_REG) & 0x02)
	{
		humidityCount = readHumidityData();
		HTS221_humidity = (((float)humidityCount - (float)H0_T0_OUT)/((float)H1_T0_OUT - (float)H0_T0_OUT))*((float)H1_rH_x2 - (float)H0_rH_x2)/2. + (float) H0_rH_x2/2.;
	}

	if (ReadI2C0(HTS221_STATUS_REG) & 0x01)
	{
		temperatureCount = readTempData();
		uint16_t outT0 = ((uint16_t) T0_msb << 8) | T0_degC_x8;
		uint16_t outT1 = ((uint16_t) T1_msb << 8) | T1_degC_x8;
		HTS221_temperature = (((float)temperatureCount - (float)T0_OUT)/((float)T1_OUT - (float)T0_OUT))*((float)outT1 - (float)outT0)/8. + (float) outT0/8.;
	}
}

int16_t readTempData(void)
{
	ReadI2C1(HTS221_TEMP_OUT_L | 0x80);	 // Read the two raw data registers sequentially into data array 
	return((int16_t)I2C1_val2 << 8) | I2C1_val1;	 // Turn the MSB and LSB into a 16-bit value
}

int16_t readHumidityData(void)
{
	ReadI2C1(HTS221_HUMIDITY_OUT_L | 0x80);  // Read the two raw data registers sequentially into data array 
	return((int16_t)I2C1_val2 << 8) | I2C1_val1;	 // Turn the MSB and LSB into a 16-bit value
}