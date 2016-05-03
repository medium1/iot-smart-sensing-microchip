/*******************************************************************************
  MPLAB Harmony Application Header File

  Company:
	 Microchip Technology Inc.

  File Name:
	 app.h

  Summary:
	 This header file provides prototypes and definitions for the application.

  Description:
	 This header file provides function prototypes and data type definitions for
	 the application.  Some of these are required by the system (such as the
	 "APP_Initialize" and "APP_Tasks" prototypes) and some of them are only used
	 internally by the application (such as the "APP_STATES" definition).  Both
	 are defined here for convenience.
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

#ifndef _APP_H
#define _APP_H

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
#include "wolfmqttsdk/wolfmqtt/mqtt_client.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

extern "C" {

#endif
// DOM-IGNORE-END 

#define ABS(a) (((a)>0)?(a):-(a))

// *****************************************************************************
// *****************************************************************************
// Section: Type Definitions
// *****************************************************************************
// *****************************************************************************
//#define MediumOne_IOT_PORT 8883 // M1 Comment
#define MediumOne_IOT_PORT 61620

//#define NVM_CLIENT_CERTIFICATE_SPACE    (32 * 1024)
//#define NVM_CLIENT_KEY_SPACE            (16 * 1024)

#define NVM_CONFIGURATION_SPACE (32 * 1024)
    
#define NVM_HOST_ADDRESS_OFFSET             (0 * 256)
#define NVM_PROJECT_MQTT_ID_OFFSET          (1 * 256)
#define NVM_USER_MQTT_ID_OFFSET             (2 * 256)
#define NVM_API_KEY_OFFSET                  (3 * 256)
#define NVM_API_PASSWORD_OFFSET             (4 * 256)
#define NVM_DEVICE_NAME_OFFSET              (5 * 256)
#define NVM_SENSOR_TYPE_OFFSET              (6 * 256)
#define NVM_CONFIGURATION_SIGNATURE_OFFSET  (7 * 256)
    
#define NVM_CONFIGURATION_SIZE              (8*256)
    

    
#define NVM_SENSORS_CONFIGURATION_SPACE (48 * 1024)

#define NVM_SENSOR_CONFIG_PRESSURE_CLICK_OFFSET     (0 * sizeof(APP_SENSOR_CONFIG))
#define NVM_SENSOR_CONFIG_TEMPERATURE_CLICK_OFFSET  (1 * sizeof(APP_SENSOR_CONFIG))
#define NVM_SENSOR_CONFIG_HUMIDITY_CLICK_OFFSET     (2 * sizeof(APP_SENSOR_CONFIG))
#define NVM_SENSOR_CONFIG_MOTION_CLICK_OFFSET       (3 * sizeof(APP_SENSOR_CONFIG))
#define NVM_SENSOR_CONFIG_AIR_QUALITY_OFFSET        (4 * sizeof(APP_SENSOR_CONFIG))

#define NVM_SENSORS_CONFIGURATION_SIZE              (5 * sizeof(APP_SENSOR_CONFIG))

    
/* Application Codes */
	enum AppCodes
	{
		APP_CODE_SUCCESS = 0,
		APP_CODE_ERROR_BAD_ARG = -1,
		APP_CODE_ERROR_OUT_OF_BUFFER = -2,
		APP_CODE_ERROR_SSL_FATAL = -3,
		APP_CODE_ERROR_INVALID_SOCKET = -4,
		APP_CODE_ERROR_FAILED_TO_BEGIN_DNS_RESOLUTION = -5,
		APP_CODE_ERROR_DNS_FAILED = -6,
		APP_CODE_ERROR_FAILED_SSL_NEGOTIATION = -7,
		APP_CODE_ERROR_TIMEOUT = -8,
		APP_CODE_ERROR_CMD_TIMEOUT = -9,
	};
// *****************************************************************************
/* Application states

  Summary:
	 Application states enumeration

  Description:
	 This enumeration defines the valid application states.  These states
	 determine the behavior of the application at various times.
*/

	typedef enum
	{
		/* Application's state machine's initial state. */
		APP_STATE_INIT=0,
		APP_NVM_MOUNT_DISK,
		APP_NVM_ERASE_CONFIGURATION,
		APP_NVM_LOAD_CONFIGURATION,
		APP_TCPIP_WAIT_INIT,
		APP_TCPIP_WAIT_FOR_IP,
		APP_TCPIP_WAIT_CONFIGURATION,
		APP_TCPIP_MQTT_INIT,
		APP_TCPIP_MQTT_NET_CONNECT,
		APP_TCPIP_MQTT_PROTOCOL_CONNECT,
		APP_TCPIP_MQTT_SUBSCRIBE,
		APP_TCPIP_MQTT_LOOP,
		APP_TCPIP_ERROR,

	} APP_STATES;


	typedef enum
	{
		APP_SENSOR_TYPE_NONE,
		APP_SENSOR_TYPE_PRESSURE_CLICK,
		APP_SENSOR_TYPE_AIR_QUALITY_CLICK,
		APP_SENSOR_TYPE_HUMIDITY_CLICK,
		APP_SENSOR_TYPE_MOTION_CLICK
	} APP_SENSOR_TYPE;


typedef struct
{
    double          threshold_pct;
    int             period_sec;
} APP_SENSOR_CONFIG;

// *****************************************************************************
/* Application Data

  Summary:
	 Holds application data

  Description:
	 This structure holds the application's data.

  Remarks:
	 Application strings and buffers are be defined outside this structure.
 */

	typedef struct
	{
		/* The application's current state */
		APP_STATES state;

		// Last twelve characters of MAC address
		unsigned char uuid[12 + 1];

		// Client certificate location
    //__attribute__ ((aligned(4))) unsigned char clientCert[2048];
    
		// Client key location
    //__attribute__ ((aligned(4))) unsigned char clientKey[2048];
    
		// Network handles
		NET_PRES_SKT_HANDLE_T socket;
		TCP_PORT port;
		NET_PRES_SKT_ERROR_T error;
		void* ctx;
		void* ssl;

		// The MediumOne endpoint to access the MediumOne IoT Service
		unsigned char host[256];
		unsigned char project_mqtt_id[256];
		unsigned char user_mqtt_id[256];
		unsigned char api_key[256];
		unsigned char api_password[256];
		unsigned char device_name[256];
		APP_SENSOR_TYPE app_sensor_type;

		unsigned char username[256];
		unsigned char password[256];
		unsigned char publish_topic_name[256];
		unsigned char subscribe_topic_name[256];

		// The MediumOne endpoint IP address location
		IP_MULTI_ADDRESS  host_ipv4;

		TCPIP_MAC_ADDR          macAddress;
		unsigned char local_ip[16]; 

		// NVM Driver
		DRV_HANDLE nvmHandle;
		DRV_NVM_COMMAND_HANDLE      nvmCommandHandle;
		SYS_FS_MEDIA_GEOMETRY       *gAppNVMMediaGeometry;
		DRV_NVM_COMMAND_STATUS      nvmStatus;

		// Timers
		uint32_t genericUseTimer;
		uint32_t tenminutesTimer;
		uint32_t sampleTimer;
		uint32_t airTimer;
		uint32_t humdTimer;
		uint32_t pressureTimer;
		uint32_t tempTimer;
		uint32_t motionTimer;
		uint32_t timerTCPIP;
		uint32_t mqttKeepAlive;
		uint32_t mqttSendDeviceInfo;
		uint32_t mqttSendPressureClick;
    	uint32_t mqttSendHumidityClick;
    	uint32_t mqttSendAirQualityClick;
    	uint32_t mqttSendMotionClick;

		// Mqtt Client
		MqttNet myNet;
		MqttClient myClient;

		// Value for light show
		uint32_t lightShowVal;

		// LED Values
		bool led1;
		bool led2;
		bool led3;
		bool led4;

		bool led1val;
		bool led2val;
		bool led3val;
		bool led4val;

        //Sensors configuration
        APP_SENSOR_CONFIG pressure_click_config;
        APP_SENSOR_CONFIG temperature_click_config;
        APP_SENSOR_CONFIG humidity_click_config;
        APP_SENSOR_CONFIG motion_click_config;
        APP_SENSOR_CONFIG air_quality_click_config;

        //Sensors values
        double last_pressure_value;
        double last_temperature_value;
        double last_humidity_value;
        double last_air_quality_value;
	} APP_DATA;


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Routines
// *****************************************************************************
// *****************************************************************************
/* These routines are called by drivers when certain events occur.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
	 void APP_Initialize ( void )

  Summary:
	  MPLAB Harmony application initialization routine.

  Description:
	 This function initializes the Harmony application.  It places the 
	 application in its initial state and prepares it to run so that its 
	 APP_Tasks function can be called.

  Precondition:
	 All other system initialization routines should be called before calling
	 this routine (in "SYS_Initialize").

  Parameters:
	 None.

  Returns:
	 None.

  Example:
	 <code>
	 APP_Initialize();
	 </code>

  Remarks:
	 This routine must be called from the SYS_Initialize function.
*/

	void APP_Initialize ( void );


/*******************************************************************************
  Function:
	 void APP_Tasks ( void )

  Summary:
	 MPLAB Harmony Demo application tasks function

  Description:
	 This routine is the Harmony Demo application's tasks function.  It
	 defines the application's state machine and core logic.

  Precondition:
	 The system and application initialization ("SYS_Initialize") should be
	 called before calling this.

  Parameters:
	 None.

  Returns:
	 None.

  Example:
	 <code>
	 APP_Tasks();
	 </code>

  Remarks:
	 This routine must be called from SYS_Tasks() routine.
 */

	void APP_Tasks( void );

	bool APP_TIMER_Expired(uint32_t * timer, uint32_t seconds);
	bool APP_TIMER_Expired_ms(uint32_t * timer, uint32_t mseconds);
	bool APP_TIMER_Set(uint32_t * timer);

	void pressure_temp_read(void);

#define HTS221_ADDRESS           0xBE // Address of HTS221 Humidity sensor, actual address on I2C 0x5F
#define HTS221_WHO_AM_I          0xF // should be 0xBC
	void InitI2C1(void);
	bool ReadI2C1(unsigned short reg);
	bool writeI2C1reg(unsigned short reg,unsigned short val);
	bool waitForI2C1(void);
	bool ReadI2C2(unsigned short reg, unsigned short bytecnt);
	uint8_t ReadI2C0(unsigned short reg);

	int I2C1_val1,I2C1_val2;
	long int pressure_value;										// Declaration of pressure variable in mbar
	float temperature_value;										// Declaration of temperature variable
	unsigned char chip_id_address;
	float Temperature;
	float Humidity;
	char tmp_data[16];
// Device addresses
	float HTS221_humidity, HTS221_temperature;
	int16_t readTempData(void);
	int16_t readHumidityData(void);
	void humidity_temperature_read(void);
	int16_t temperatureCount;
	int16_t humidityCount;  // variables to hold raw HTS221 temperature and humidity values
#endif /* _APP_H */

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

/*******************************************************************************
 End of File
 */

