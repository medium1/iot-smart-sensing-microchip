/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
	 Microchip Technology Inc.
  
  File Name:
	 app.c

  Summary:
	 This file contains the source code for the MPLAB Harmony application.

  Description:
	 This file contains the source code for the MPLAB Harmony application.  It 
	 implements the logic of the application's state machine and it may call 
	 API routines of other MPLAB Harmony modules in the system, such as drivers,
	 system services, and middleware.  However, it does not call any of the
	 system interfaces (such as the "Initialize" and "Tasks" functions) of any of
	 the modules in the system or make any assumptions about when those functions
	 are called.  That is the responsibility of the configuration-specific system
	 files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
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
// DOM-IGNORE-END


// *****************************************************************************
// *****************************************************************************
// Section: Included Files 
// *****************************************************************************
// *****************************************************************************
#include "app.h"
#include "app1.h"
#include "parson.h"
#include "bsp_config.h"
#include "wolfmqttsdk/wolfmqtt/mqtt_client.h"
#include <math.h>

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
extern char validConfig;
extern char readBuff[SYS_CMD_READ_BUFFER_SIZE] SYS_CMD_BUFFER_DMA_READY;
extern BSP_DATA bspData;
APP_DATA appData;
APP1_DATA app1Data;

unsigned char topic_mqtt_event[256];
unsigned char configurationSignature[256];
unsigned char configuration[NVM_CONFIGURATION_SIZE];

char txBuffer[MAX_BUFFER_SIZE];
char rxBuffer[MAX_BUFFER_SIZE];
int txrxLedStateCount=0;

struct switchMessage mySwitchMessage;
double ppm;												// ppm
unsigned int adc_rd;

static int mPacketIdLast;
static int mStopRead = 0;
static char clickid=0;
static char display_message=0;
static char motion_detected = 1;	//Detect & read from motion_click sensor
static bool HumChanged,PotChanged,PressureChanged,AirChanged,MotionChanged,Button1Changed,Button2Changed,Button3Changed,Button4Changed; 


// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

// WolfMQTT Callbacks for network connectivity
int APP_tcpipConnect_cb(void *context, const char* host, word16 port, int timeout_ms)
{
	uint32_t timeout = 0;
	timeout = SYS_TMR_TickCountGet();
	SYS_CONSOLE_PRINT("App:  DNS:   Resolving host '%s'\r\n", &appData.host);
	TCPIP_DNS_RESULT dnsResult;
	dnsResult = TCPIP_DNS_Resolve((const char *)appData.host, TCPIP_DNS_TYPE_A);
	if (dnsResult < 0)
	{
		SYS_CONSOLE_MESSAGE("App:  DNS:  Failed to begin\r\n");
		return APP_CODE_ERROR_FAILED_TO_BEGIN_DNS_RESOLUTION;
	}
	SYS_CONSOLE_MESSAGE("App:  DNS:  Beginning DNS resolution\r\n");

	while ((dnsResult = TCPIP_DNS_IsResolved((const char *)appData.host, &appData.host_ipv4, IP_ADDRESS_TYPE_IPV4)) == TCPIP_DNS_RES_PENDING)
	{
		if (APP_TIMER_Expired_ms(&timeout, timeout_ms))
		{
			return APP_CODE_ERROR_CMD_TIMEOUT;
		}
	}
	if (dnsResult != (TCPIP_DNS_RES_OK))
	{
		SYS_CONSOLE_PRINT("App:  DNS:  Resolution failed - Aborting\r\n");
		return APP_CODE_ERROR_DNS_FAILED;
	}
	else if (dnsResult == TCPIP_DNS_RES_OK)
	{
        sprintf(appData.remote_ip, "%d.%d.%d.%d", appData.host_ipv4.v4Add.v[0],
								appData.host_ipv4.v4Add.v[1],
								appData.host_ipv4.v4Add.v[2],
								appData.host_ipv4.v4Add.v[3]);
        
		SYS_CONSOLE_PRINT("App:  DNS:  Resolved IPv4 Address: %d.%d.%d.%d for host '%s'\r\n",
								appData.host_ipv4.v4Add.v[0],
								appData.host_ipv4.v4Add.v[1],
								appData.host_ipv4.v4Add.v[2],
								appData.host_ipv4.v4Add.v[3],
								appData.host);
	}

	SYS_CONSOLE_PRINT("App:  TCPIP:  Opening socket to '%d.%d.%d.%d:%d'\r\n", 
							appData.host_ipv4.v4Add.v[0],
							appData.host_ipv4.v4Add.v[1],
							appData.host_ipv4.v4Add.v[2],
							appData.host_ipv4.v4Add.v[3],
							appData.port);
	uint32_t timeSocketbefore = SYS_TMR_TickCountGet();
	appData.socket = NET_PRES_SocketOpen(0, NET_PRES_SKT_ENCRYPTED_STREAM_CLIENT, IP_ADDRESS_TYPE_IPV4, (NET_PRES_SKT_PORT_T)port, (NET_PRES_ADDRESS *)&appData.host_ipv4, (NET_PRES_SKT_ERROR_T*)&appData.error);
	NET_PRES_SocketWasReset(appData.socket);

	if (appData.socket == INVALID_SOCKET)
	{
		SYS_CONSOLE_MESSAGE("App:  TCPIP:  Invalid socket error\r\n");
		NET_PRES_SocketClose(appData.socket);
		return APP_CODE_ERROR_INVALID_SOCKET;
	}

	while (!NET_PRES_SKT_IsConnected(appData.socket))
	{
		if (APP_TIMER_Expired_ms(&timeout, timeout_ms))
		{
			return APP_CODE_ERROR_CMD_TIMEOUT;
		}
	}
    
	while (NET_PRES_SKT_IsNegotiatingEncryption(appData.socket))
	{
		if (APP_TIMER_Expired_ms(&timeout, timeout_ms))
		{
			return APP_CODE_ERROR_CMD_TIMEOUT;
		}
	}

	if (!NET_PRES_SKT_IsSecure(appData.socket))
	{
		SYS_CONSOLE_MESSAGE("App:  TCPIP:  SSL failed to negotiate\r\n");
		NET_PRES_SocketClose(appData.socket);
		return APP_CODE_ERROR_FAILED_SSL_NEGOTIATION;
	}
    
	uint32_t timeSocketafter = SYS_TMR_TickCountGet();
	SYS_CONSOLE_MESSAGE("App:  TCPIP:  Secure socket opened\r\n");
	SYS_CONSOLE_PRINT("Socket Time Tick Before: %d, Tick After: %d, Tick Diff: %d\r\n", timeSocketbefore, timeSocketafter, timeSocketafter-timeSocketbefore);

	return 0; //Success
}

int APP_tcpipWrite_cb(void *context, const byte* buf, int buf_len, int timeout_ms)
{
	int ret = 0;
	uint32_t timeout;

	APP_TIMER_Set(&timeout);

	//wait for data to be read, or error, or timeout
	while (NET_PRES_SocketWriteIsReady(appData.socket, buf_len, 0) == 0)
	{
		if (NET_PRES_SocketWasReset(appData.socket))
		{
			ret = APP_CODE_ERROR_SSL_FATAL;
			return ret;
		}
		if (APP_TIMER_Expired_ms(&timeout, (uint32_t)timeout_ms))
		{
			ret = APP_CODE_ERROR_CMD_TIMEOUT;
			return ret;
		}
	}
	ret = NET_PRES_SocketWrite(appData.socket, (uint8_t*)buf, buf_len);
	return ret;
}

int APP_tcpipRead_cb(void *context, byte* buf, int buf_len, int timeout_ms)
{
	int ret = 0;
	uint32_t timeout;

	APP_TIMER_Set(&timeout);

	// Wait for data to be read, or error, or timeout
	while (NET_PRES_SocketReadIsReady(appData.socket) == 0)
	{
		if (NET_PRES_SocketWasReset(appData.socket))
		{
			ret = APP_CODE_ERROR_SSL_FATAL;
			return ret;
		}
		if (APP_TIMER_Expired_ms(&timeout, (uint32_t)timeout_ms))
		{
			ret = APP_CODE_ERROR_CMD_TIMEOUT;
			return ret;
		}
	}
	ret = NET_PRES_SocketRead(appData.socket, (uint8_t*)buf, buf_len);
	return ret;
}

int APP_tcpipDisconnect_cb(void *context)
{
	int ret = 0;
	NET_PRES_SKT_Close(appData.socket);
	appData.state = APP_TCPIP_MQTT_NET_CONNECT;
	return ret;
}

static word16 mqttclient_get_packetid(void)
{
	mPacketIdLast = (mPacketIdLast >= MAX_PACKET_ID) ?
						 1 : mPacketIdLast + 1;
	return(word16)mPacketIdLast;
}

const char* APP_Switch_Publish_Helper(BSP_SWITCH_ENUM sw)
{
	switch (sw)
	{
		case BSP_SWITCH_1:
			return "state.reported.button1";
		case BSP_SWITCH_2:
			return "state.reported.button2";
		case BSP_SWITCH_3:
			return "state.reported.button3";
		case BSP_SWITCH_4:
			return "state.reported.button4";
		case BSP_SWITCH_MINT:
			return "state.reported.MInt";
		default:
			break;
	}
}

void process_led_update_command(JSON_Object* tObject)
{
    SYS_CONSOLE_PRINT("App:  Processing led_state update command.\r\n");
    
    const char* value = json_object_dotget_string(tObject, "led_state.led_1");
    if (value)
    {
        appData.led1 = true;
        if (!strcmp(value, "on"))
        {
            BSP_LEDOn(BSP_LED_1_CHANNEL, BSP_LED_1_PORT);
            appData.led1val = true;
        }
        else if (!strcmp(value, "off"))
        {
            BSP_LEDOff(BSP_LED_1_CHANNEL, BSP_LED_1_PORT);
            appData.led1val = false;
        }
    }

    value = json_object_dotget_string(tObject, "led_state.led_2");
    if (value)
    {
        appData.led2 = true;
        if (!strcmp(value, "on"))
        {
            BSP_LEDOn(BSP_LED_2_CHANNEL, BSP_LED_2_PORT);
            appData.led2val = true;
        }
        else if (!strcmp(value, "off"))
        {
            BSP_LEDOff(BSP_LED_2_CHANNEL, BSP_LED_2_PORT);
            appData.led2val = false;
        }
    }

    value = json_object_dotget_string(tObject, "led_state.led_3");
    if (value)
    {
        appData.led3 = true;
        if (!strcmp(value, "on"))
        {
            BSP_LEDOn(BSP_LED_3_CHANNEL, BSP_LED_3_PORT);
            appData.led3val = true;
        }
        else if (!strcmp(value, "off"))
        {
            BSP_LEDOff(BSP_LED_3_CHANNEL, BSP_LED_3_PORT);
            appData.led3val = false;
        }
    }

    value = json_object_dotget_string(tObject, "led_state.led_4");
    if (value)
    {
        appData.led4 = true;
        if (!strcmp(value, "on"))
        {
            BSP_LEDOn(BSP_LED_4_CHANNEL, BSP_LED_4_PORT);
            appData.led4val = true;
        }
        else if (!strcmp(value, "off"))
        {
            BSP_LEDOff(BSP_LED_4_CHANNEL, BSP_LED_4_PORT);
            appData.led4val = false;
        }
    }
    
    APP_Send_DeviceInfo();
}

void process_sensor_config_update_command(JSON_Object* tObject)
{
    SYS_CONSOLE_PRINT("App:  Processing sensor_profiles update command.\r\n");
    
    JSON_Array* sensor_profiles_value = json_object_get_array(tObject, "sensor_profiles");
    int i = 0;
    int nNumItems = json_array_get_count(sensor_profiles_value);
    
    for ( ;i<nNumItems; i++)
    {
        JSON_Object* sensor_profile = json_array_get_object(sensor_profiles_value, i);
        const char* sSensor_type = json_object_get_string(sensor_profile, "sensor");
            
        if(!strcmp(sSensor_type, (const char*)"pressure_click"))
        {
            appData.pressure_click_config.threshold_pct = json_object_get_number(sensor_profile, "threshold_pct");
            appData.pressure_click_config.period_sec = (int)(json_object_get_number(sensor_profile, "period_sec") + 0.5);
            SYS_CONSOLE_PRINT("\t- pressure_click_config(threshold_pct: %f, period_sec: %d)\r\n", 
                appData.pressure_click_config.threshold_pct, appData.pressure_click_config.period_sec);
        }
        else if(!strcmp(sSensor_type, (const char*)"air_quality_click"))
        {
            appData.air_quality_click_config.threshold_pct = json_object_get_number(sensor_profile, "threshold_pct");
            appData.air_quality_click_config.period_sec = (int)(json_object_get_number(sensor_profile, "period_sec") + 0.5);
            SYS_CONSOLE_PRINT("\t- air_quality_click_config(threshold_pct: %f, period_sec: %d)\r\n",
                appData.air_quality_click_config.threshold_pct, appData.air_quality_click_config.period_sec);
        }
        else if(!strcmp(sSensor_type, (const char*)"humidity_click"))
        {
            appData.humidity_click_config.threshold_pct = json_object_get_number(sensor_profile, "threshold_pct");
            appData.humidity_click_config.period_sec = (int)(json_object_get_number(sensor_profile, "period_sec") + 0.5);
            SYS_CONSOLE_PRINT("\t- humidity_click_config(threshold_pct: %f, period_sec: %d)\r\n",
                appData.humidity_click_config.threshold_pct, appData.humidity_click_config.period_sec);
        }
        else if(!strcmp(sSensor_type, (const char*)"temperature_click"))
        {
            appData.temperature_click_config.threshold_pct = json_object_get_number(sensor_profile, "threshold_pct");
            appData.temperature_click_config.period_sec = (int)(json_object_get_number(sensor_profile, "period_sec") + 0.5);
            SYS_CONSOLE_PRINT("\t- temperature_click_config(threshold_pct: %f, period_sec: %d)\r\n",
                appData.temperature_click_config.threshold_pct, appData.temperature_click_config.period_sec);
        }
        else if(!strcmp(sSensor_type, (const char*)"motion_click"))
        {
            appData.motion_click_config.period_sec = (int)(json_object_get_number(sensor_profile, "interval_sec") + 0.5);
            SYS_CONSOLE_PRINT("\t- motion_click_config(interval_sec: %d)\r\n",
                appData.motion_click_config.period_sec);
        }
    }
        
    APP_Save_SensorConfiguration();
}

// This callback is executed when received an mqtt message
int mqttclient_message_cb(MqttClient *client, MqttMessage *msg, byte msg_new, byte msg_done)
{
    appData.lightShowVal = BSP_LED_RX;
	xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);
        
	int ret = MQTT_CODE_SUCCESS;
	char payload[MAX_BUFFER_SIZE];
	memcpy(payload, msg->buffer, msg->total_len);
	payload[msg->total_len] = '\0';
	SYS_CONSOLE_PRINT("\r\nApp:  MQTT.Message Received: %s -- Topic %s\r\n\r\n", payload, msg->topic_name);

#ifdef USE_VERIFY_EVENT_TOPIC_NAME
    // If the topic matches our MediumOne IoT delta topic
	if (!strncmp(topic_mqtt_event, msg->topic_name, msg->topic_name_len))
#endif
	{
		JSON_Value *root_value = json_parse_string(payload);
		if (json_value_get_type(root_value) != JSONObject)
		{
			if (root_value) json_value_free(root_value);
			return ret;
		}

		JSON_Object * tObject = json_value_get_object(root_value);

		if (json_object_get_value(tObject, "led_state"))
		{
			process_led_update_command(tObject);
		}
		else if (json_object_get_value(tObject, "sensor_profiles"))
		{
			process_sensor_config_update_command(tObject);
		}

		if (root_value) json_value_free(root_value);
	}

	return ret;
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************

bool APP_TIMER_Expired(uint32_t * timer, uint32_t seconds)
{
	if ((SYS_TMR_TickCountGet() - *timer) > (seconds * 1000))
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

bool APP_TIMER_Expired_ms(uint32_t * timer, uint32_t mseconds)
{
	if ((SYS_TMR_TickCountGet() - *timer) > (mseconds))
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

bool APP_TIMER_Set(uint32_t * timer)
{
	*timer = SYS_TMR_TickCountGet();
	return true;
}

bool APP_TIMER_Set2(uint32_t * timer, int32_t delta_seconds)
{
    *timer = SYS_TMR_TickCountGet() + (delta_seconds * 1000);
    return true;
}

const char* APP_ReturnCodeToString(int return_code)
{
	switch (return_code)
	{
		case APP_CODE_SUCCESS:
			return "Success";
		case APP_CODE_ERROR_BAD_ARG:
			return "Error (Bad argument)";
		case APP_CODE_ERROR_OUT_OF_BUFFER:
			return "Error (Out of buffer)";
		case APP_CODE_ERROR_SSL_FATAL:
			return "Error (SSL Fatal)";
		case APP_CODE_ERROR_INVALID_SOCKET:
			return "Error (Invalid Socket)";
		case APP_CODE_ERROR_FAILED_TO_BEGIN_DNS_RESOLUTION:
			return "Error (Failed to Begin DNS)";
		case APP_CODE_ERROR_DNS_FAILED:
			return "Error (DNS Failed)";
		case APP_CODE_ERROR_FAILED_SSL_NEGOTIATION:
			return "Error (Failed SSL Negotiation)";
		case APP_CODE_ERROR_TIMEOUT:
			return "Error (Timeout)";
		case APP_CODE_ERROR_CMD_TIMEOUT:
			return "Error (Command Timeout)";
	}
	return "Unknown";
}

void APP_UpdateMQTTLoginInfo()
{
	sprintf(appData.username, "%s/%s", appData.project_mqtt_id, appData.user_mqtt_id);
	sprintf(appData.password, "%s/%s", appData.api_key, appData.api_password);
	sprintf(appData.publish_topic_name, "0/%s/%s//", appData.project_mqtt_id, appData.user_mqtt_id);
	sprintf(appData.subscribe_topic_name, "1/%s/%s/#", appData.project_mqtt_id, appData.user_mqtt_id);
	sprintf(topic_mqtt_event, "1/%s/%s//event", appData.project_mqtt_id, appData.user_mqtt_id);
}

_Bool APP_LoadConfiguration ( void )
{
    SYS_CONSOLE_PRINT("App:  Loading configuration from NVM\r\n");
    
    XMEMSET(appData.host, 0, sizeof(appData.host));
    XMEMSET(appData.project_mqtt_id, 0, sizeof(appData.project_mqtt_id));
    XMEMSET(appData.user_mqtt_id, 0, sizeof(appData.user_mqtt_id));
    XMEMSET(appData.api_key, 0, sizeof(appData.api_key));
    XMEMSET(appData.api_password, 0, sizeof(appData.api_password));
    XMEMSET(appData.device_name, 0, sizeof(appData.device_name));
    XMEMSET(&appData.app_sensor_type, 0, sizeof(appData.app_sensor_type));
    XMEMSET(configurationSignature, 0, sizeof(configurationSignature));
    
    _Bool ret = APP_NVM_Read(NVM_CONFIGURATION_SPACE, configuration, NVM_CONFIGURATION_SIZE);
    memcpy(appData.host, configuration+NVM_HOST_ADDRESS_OFFSET, sizeof(appData.host)-1);
    memcpy(appData.project_mqtt_id, configuration+NVM_PROJECT_MQTT_ID_OFFSET, sizeof(appData.project_mqtt_id)-1);
    memcpy(appData.user_mqtt_id, configuration+NVM_USER_MQTT_ID_OFFSET, sizeof(appData.user_mqtt_id)-1);
    memcpy(appData.api_key, configuration+NVM_API_KEY_OFFSET, sizeof(appData.api_key)-1);
    memcpy(appData.api_password, configuration+NVM_API_PASSWORD_OFFSET, sizeof(appData.api_password)-1);
    memcpy(appData.device_name, configuration+NVM_DEVICE_NAME_OFFSET, sizeof(appData.device_name)-1);
    memcpy(&appData.app_sensor_type, configuration+NVM_SENSOR_TYPE_OFFSET, sizeof(appData.app_sensor_type));
    memcpy(configurationSignature, configuration+NVM_CONFIGURATION_SIGNATURE_OFFSET, sizeof(configurationSignature)-1);
          
    /*
    SYS_CONSOLE_PRINT("App:  Read configuration - host '%s'\r\n", appData.host);
    SYS_CONSOLE_PRINT("App:  Read configuration - project_mqtt_id '%s'\r\n", appData.project_mqtt_id);
    SYS_CONSOLE_PRINT("App:  Read configuration - user_mqtt_id '%s'\r\n", appData.user_mqtt_id);
    SYS_CONSOLE_PRINT("App:  Read configuration - api_key '%s'\r\n", "********");
    SYS_CONSOLE_PRINT("App:  Read configuration - api_password '%s'\r\n", "********");
    SYS_CONSOLE_PRINT("App:  Read configuration - device_name '%s'\r\n", appData.device_name);
    SYS_CONSOLE_PRINT("App:  Read configuration - sensor_type '%d'\r\n", appData.app_sensor_type);
    SYS_CONSOLE_PRINT("App:  Read configuration - Configuration signature '%s'\r\n", configurationSignature);
    */
    
    if (!strcmp(configurationSignature, APP_CONFIGURATION_SIGNATURE) &&
        appData.host[0] &&
        appData.project_mqtt_id[0] &&
        appData.user_mqtt_id[0] &&
        appData.api_key[0] &&
        appData.api_password[0] &&
        appData.device_name[0])
    {
        APP_UpdateMQTTLoginInfo();
        
        // Load sensors configuration
        ret = APP_NVM_Read(NVM_SENSORS_CONFIGURATION_SPACE, configuration, NVM_SENSORS_CONFIGURATION_SIZE);
        memcpy(&appData.pressure_click_config, configuration+NVM_SENSOR_CONFIG_PRESSURE_CLICK_OFFSET, sizeof(APP_SENSOR_CONFIG));
        memcpy(&appData.temperature_click_config, configuration+NVM_SENSOR_CONFIG_TEMPERATURE_CLICK_OFFSET, sizeof(APP_SENSOR_CONFIG));
        memcpy(&appData.humidity_click_config, configuration+NVM_SENSOR_CONFIG_HUMIDITY_CLICK_OFFSET, sizeof(APP_SENSOR_CONFIG));
        memcpy(&appData.motion_click_config, configuration+NVM_SENSOR_CONFIG_MOTION_CLICK_OFFSET, sizeof(APP_SENSOR_CONFIG));
        memcpy(&appData.air_quality_click_config, configuration+NVM_SENSOR_CONFIG_AIR_QUALITY_OFFSET, sizeof(APP_SENSOR_CONFIG));
    
        SYS_CONSOLE_PRINT("App:  Found configuration - host '%s'\r\n", appData.host);
        SYS_CONSOLE_PRINT("App:  Found configuration - project_mqtt_id '%s'\r\n", appData.project_mqtt_id);
        SYS_CONSOLE_PRINT("App:  Found configuration - user_mqtt_id '%s'\r\n", appData.user_mqtt_id);
        SYS_CONSOLE_PRINT("App:  Found configuration - api_key '%s'\r\n", "********");
        SYS_CONSOLE_PRINT("App:  Found configuration - api_password '%s'\r\n", "********");
        SYS_CONSOLE_PRINT("App:  Found configuration - device_name '%s'\r\n", appData.device_name);
        SYS_CONSOLE_PRINT("App:  Found configuration - sensor_type '%d'\r\n", appData.app_sensor_type);        
        SYS_CONSOLE_PRINT("App:  Found configuration - sensor profiles:\r\n");
        SYS_CONSOLE_PRINT("\t- pressure_click_config(threshold_pct: %f, period_sec: %d)\r\n", 
                appData.pressure_click_config.threshold_pct, appData.pressure_click_config.period_sec);
        SYS_CONSOLE_PRINT("\t- temperature_click_config(threshold_pct: %f, period_sec: %d)\r\n",
                appData.temperature_click_config.threshold_pct, appData.temperature_click_config.period_sec);
        SYS_CONSOLE_PRINT("\t- humidity_click_config(threshold_pct: %f, period_sec: %d)\r\n",
                appData.humidity_click_config.threshold_pct, appData.humidity_click_config.period_sec);
        SYS_CONSOLE_PRINT("\t- motion_click_config(interval_sec: %d)\r\n",
                appData.motion_click_config.period_sec);
        SYS_CONSOLE_PRINT("\t- air_quality_click_config(threshold_pct: %f, period_sec: %d)\r\n",
                appData.air_quality_click_config.threshold_pct, appData.air_quality_click_config.period_sec);
    }
    else 
    {
        appData.host[0] = 0;
        appData.project_mqtt_id[0] = 0;
        
        ret = false;
    }

    return ret;
}

void APP_SaveConfiguration ( void )
{
    strcpy(configurationSignature, APP_CONFIGURATION_SIGNATURE);
    XMEMSET(configuration, 0, NVM_CONFIGURATION_SIZE);
    
    memcpy(configuration+NVM_HOST_ADDRESS_OFFSET, appData.host, sizeof(appData.host)-1);
    memcpy(configuration+NVM_PROJECT_MQTT_ID_OFFSET, appData.project_mqtt_id, sizeof(appData.project_mqtt_id)-1);
    memcpy(configuration+NVM_USER_MQTT_ID_OFFSET, appData.user_mqtt_id, sizeof(appData.user_mqtt_id)-1);
    memcpy(configuration+NVM_API_KEY_OFFSET, appData.api_key, sizeof(appData.api_key)-1);
    memcpy(configuration+NVM_API_PASSWORD_OFFSET, appData.api_password, sizeof(appData.api_password)-1);
    memcpy(configuration+NVM_DEVICE_NAME_OFFSET, appData.device_name, sizeof(appData.device_name)-1);
    memcpy(configuration+NVM_SENSOR_TYPE_OFFSET, &appData.app_sensor_type, sizeof(appData.app_sensor_type));
    memcpy(configuration+NVM_CONFIGURATION_SIGNATURE_OFFSET, configurationSignature, sizeof(appData.api_password)-1);
    
    _Bool ret = APP_NVM_Write(NVM_CONFIGURATION_SPACE, configuration);
    if (ret)
    {
        SYS_CONSOLE_PRINT("App:  Writing configuration to NVM - success\r\n");
	}
	else
	{
        SYS_CONSOLE_PRINT("App:  Writing configuration to NVM - failed\r\n");
        while(1);
    }
    
    SYS_CONSOLE_PRINT("App:  Configured host - '%s'\r\n", appData.host);
    SYS_CONSOLE_PRINT("App:  Configured project_mqtt_id - '%s'\r\n", appData.project_mqtt_id);
    SYS_CONSOLE_PRINT("App:  Configured user_mqtt_id - '%s'\r\n", appData.user_mqtt_id);
    SYS_CONSOLE_PRINT("App:  Configured api_key - '%s'\r\n", "********");
    SYS_CONSOLE_PRINT("App:  Configured api_password - '%s'\r\n", "********");
    SYS_CONSOLE_PRINT("App:  Configured device_name - '%s'\r\n", appData.device_name);
    SYS_CONSOLE_PRINT("App:  Configured sensor_type - '%d'\r\n", appData.app_sensor_type);
    
    APP_UpdateMQTTLoginInfo();
    
    APP_Save_SensorConfiguration();
}

void APP_EraseConfiguration ( void )
{
    appData.host[0] = 0;
    APP_NVM_Erase(NVM_CONFIGURATION_SPACE);
    SYS_CONSOLE_PRINT(  "************************************\r\n"
                        "App:  Erasing configuration!\r\n"
                        "************************************\r\n");
}

void APP_Save_SensorConfiguration ( void )
{
    XMEMSET(configuration, 0, NVM_SENSORS_CONFIGURATION_SIZE);
    memcpy(configuration+NVM_SENSOR_CONFIG_PRESSURE_CLICK_OFFSET, &appData.pressure_click_config, sizeof(APP_SENSOR_CONFIG));
    memcpy(configuration+NVM_SENSOR_CONFIG_TEMPERATURE_CLICK_OFFSET, &appData.temperature_click_config, sizeof(APP_SENSOR_CONFIG));
    memcpy(configuration+NVM_SENSOR_CONFIG_HUMIDITY_CLICK_OFFSET, &appData.humidity_click_config, sizeof(APP_SENSOR_CONFIG));
    memcpy(configuration+NVM_SENSOR_CONFIG_MOTION_CLICK_OFFSET, &appData.motion_click_config, sizeof(APP_SENSOR_CONFIG));
    memcpy(configuration+NVM_SENSOR_CONFIG_AIR_QUALITY_OFFSET, &appData.air_quality_click_config, sizeof(APP_SENSOR_CONFIG));
 
    _Bool ret = APP_NVM_Write(NVM_SENSORS_CONFIGURATION_SPACE, configuration);
    if (ret)
    {
        SYS_CONSOLE_PRINT("App:  Writing sensors configuration to NVM - success\r\n");
	}
	else
	{
        SYS_CONSOLE_PRINT("App:  Writing sensors configuration to NVM - failed\r\n");
        while(1);
    }
    
    SYS_CONSOLE_PRINT("App:  Configured sensor profiles:\r\n");
    SYS_CONSOLE_PRINT("\t- pressure_click_config(threshold_pct: %f, period_sec: %d)\r\n", 
            appData.pressure_click_config.threshold_pct, appData.pressure_click_config.period_sec);
    SYS_CONSOLE_PRINT("\t- temperature_click_config(threshold_pct: %f, period_sec: %d)\r\n",
            appData.temperature_click_config.threshold_pct, appData.temperature_click_config.period_sec);
    SYS_CONSOLE_PRINT("\t- humidity_click_config(threshold_pct: %f, period_sec: %d)\r\n",
            appData.humidity_click_config.threshold_pct, appData.humidity_click_config.period_sec);
    SYS_CONSOLE_PRINT("\t- motion_click_config(interval_sec: %d)\r\n",
            appData.motion_click_config.period_sec);
    SYS_CONSOLE_PRINT("\t- air_quality_click_config(threshold_pct: %f, period_sec: %d)\r\n",
            appData.air_quality_click_config.threshold_pct, appData.air_quality_click_config.period_sec);
}


int APP_Send_MQTTMessage (char* publishPayload)
{
    MqttPublish publish;
    XMEMSET(&publish, 0, sizeof(MqttPublish));
    publish.retain = 0;
    publish.qos = 0;
    publish.duplicate = 0;
    publish.topic_name = appData.publish_topic_name;
    publish.packet_id = mqttclient_get_packetid();
    publish.buffer = publishPayload;
    publish.total_len = strlen(publish.buffer);
    int rc = MqttClient_Publish(&appData.myClient, &publish);
    SYS_CONSOLE_PRINT("App:  MQTT.Publish: Topic %s, %s (%d)\r\n    Payload: %s\r\n",
        publish.topic_name, MqttClient_ReturnCodeToString(rc), rc, publish.buffer);
    if(rc != MQTT_CODE_SUCCESS)
    {
        SYS_CONSOLE_PRINT("App:  MQTT.Publish: failed\r\n");   
    }
    else 
    {
        appData.lightShowVal = BSP_LED_TX;
		xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);
    }
    
    // Reset keep alive timer since we sent a publish
    APP_TIMER_Set(&appData.mqttKeepAlive);
    
    return rc;
}

int APP_Send_IPDetectionCommand ( void )
{
    char publishPayload[512] = "{\"event_data\":{'detect_ip':true}, \"add_client_ip\": true}";
    return APP_Send_MQTTMessage(publishPayload);
}

int APP_Send_DeviceInfo ( void )
{
    char publishPayload[512];
    char mac_address[20];
    long mb_mem_used = 933; //TODO: Query used memory, currently hardcoded in KB with value reported from compiler
    char connected_sensor[32] = "none";
    char led1_status = (BSP_LEDStateGet(BSP_LED_1_CHANNEL, BSP_LED_1_PORT) == BSP_LED_STATE_ON);
    char led2_status = (BSP_LEDStateGet(BSP_LED_2_CHANNEL, BSP_LED_2_PORT) == BSP_LED_STATE_ON);
    char led3_status = (BSP_LEDStateGet(BSP_LED_3_CHANNEL, BSP_LED_3_PORT) == BSP_LED_STATE_ON);
    char led4_status = (BSP_LEDStateGet(BSP_LED_4_CHANNEL, BSP_LED_4_PORT) == BSP_LED_STATE_ON);

	if (appData.app_sensor_type == APP_SENSOR_TYPE_PRESSURE_CLICK)
	{
        strcpy(connected_sensor, "pressure_click");
    }
	else if (appData.app_sensor_type == APP_SENSOR_TYPE_AIR_QUALITY_CLICK)
	{
        strcpy(connected_sensor, "air_quality_click");
    }
	else if (appData.app_sensor_type == APP_SENSOR_TYPE_HUMIDITY_CLICK)
	{
        strcpy(connected_sensor, "humidity_click");
    }
	else if (appData.app_sensor_type == APP_SENSOR_TYPE_MOTION_CLICK)
	{
        strcpy(connected_sensor, "motion_click");
    }

    sprintf(mac_address, "%02x:%02x:%02x:%02x:%02x:%02x",
                appData.macAddress.v[0], appData.macAddress.v[1], appData.macAddress.v[2],
                appData.macAddress.v[3], appData.macAddress.v[4], appData.macAddress.v[5]);

    sprintf(publishPayload, "{\"event_data\": {\"mac\": \"%s\", \"lan_ip\": \"%s\", \"memory_usage\": %d, \"connected_sensor\": \"%s\", \"device_type\": \"Ethernet\", \"device_name\": \"%s\", \"led_1\": \"%s\", \"led_2\": \"%s\", \"led_3\": \"%s\", \"led_4\": \"%s\"}}",
            mac_address, appData.local_ip, mb_mem_used, connected_sensor, appData.device_name, 
            (led1_status)?"on":"off", (led2_status)?"on":"off", (led3_status)?"on":"off", (led4_status)?"on":"off");

    return APP_Send_MQTTMessage(publishPayload);
}

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
	 void APP_Initialize ( void )

  Remarks:
	 See prototype in app.h.
 */
void APP_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    appData.state = APP_STATE_INIT;
    appData.lightShowVal = BSP_LED_ALL_OFF;
    XMEMSET(appData.host, '\0', sizeof(appData.host));
    appData.port = MediumOne_IOT_PORT;
    appData.remote_ip[0] = 0;
    appData.project_mqtt_id[0] = 0;
    appData.user_mqtt_id[0] = 0;
    appData.api_key[0] = 0;
    appData.api_password[0] = 0;
    appData.device_name[0] = 0;
    appData.app_sensor_type = APP_SENSOR_TYPE_NONE;
    
    // Initialize MQTT net callbacks
    appData.myNet.connect = APP_tcpipConnect_cb;
    appData.myNet.disconnect = APP_tcpipDisconnect_cb;
    appData.myNet.read = APP_tcpipRead_cb;
    appData.myNet.write = APP_tcpipWrite_cb;
    
    // Init LED publish bools
    appData.led1 = false;
    appData.led2 = false;
    appData.led3 = false;
    appData.led4 = false;
    
    appData.led1val = false;
    appData.led2val = false;
    appData.led3val = false;
    appData.led4val = false;
    
    appData.pressure_click_config.threshold_pct = 0.15;
    appData.pressure_click_config.period_sec = DEFAULT_PRESSURE_CLICK_INTERVAL;
    appData.air_quality_click_config.threshold_pct = 0.15;
    appData.air_quality_click_config.period_sec = DEFAULT_AIR_QUALITY_CLICK_INTERVAL;
    appData.humidity_click_config.threshold_pct = 0.15;
    appData.humidity_click_config.period_sec = DEFAULT_HUMIDITY_CLICK_INTERVAL;
    appData.temperature_click_config.threshold_pct = 0.15;
    appData.temperature_click_config.period_sec = DEFAULT_TEMPERATURE_CLICK_INTERVAL;
    appData.motion_click_config.period_sec = DEFAULT_MOTION_CLICK_INTERVAL;
}


/******************************************************************************
  Function:
	 void APP_Tasks ( void )

  Remarks:
	 See prototype in app.h.
 */
void APP_Tasks ( void )
{
	static int validConfig = 0;
	uint32_t cmd_timeout_ms = MQTT_DEFAULT_CMD_TIMEOUT_MS;

	/* Check the application's current state. */
	switch ( appData.state )
	{
		/* Application's initial state. */
		case APP_STATE_INIT:
			{
				bool appInitialized = true;
				if (appInitialized)
				{
					SYS_CONSOLE_MESSAGE("App:  Initialized\r\n");
					appData.state = APP_NVM_MOUNT_DISK;
				}
				break;
			}

			// Mount the file system where the webpages are loaded
		case APP_NVM_MOUNT_DISK:
			{
				if (SYS_FS_Mount(SYS_FS_NVM_VOL, LOCAL_WEBSITE_PATH_FS, MPFS2, 0, NULL) == 0)
				{
					SYS_CONSOLE_PRINT("App:  The %s File System is mounted.\r\n", SYS_FS_MPFS_STRING);
					appData.state = APP_NVM_ERASE_CONFIGURATION;
				}
				else
				{	// Timeout 5 seconds
					if (APP_TIMER_Expired(&appData.genericUseTimer, 5))
					{
						SYS_CONSOLE_PRINT("App:  The %s File System failed to mount.  Critical Error, reset board\r\n", SYS_FS_MPFS_STRING);
						appData.lightShowVal = BSP_LED_NVM_FAILED_MOUNT;
						xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);  
						while (1);
					}
				}
				break;
			}    

			// If user presses switch 2 and 3 on powerup, the configuration will be erased
		case APP_NVM_ERASE_CONFIGURATION:
			{
				if ((BSP_SWITCH_StateGet(BSP_SWITCH_3_CHANNEL, BSP_SWITCH_3_PORT) == BSP_SWITCH_STATE_ASSERTED) 
					 && (BSP_SWITCH_StateGet(BSP_SWITCH_2_CHANNEL, BSP_SWITCH_2_PORT) == BSP_SWITCH_STATE_ASSERTED))
				{
					APP_EraseConfiguration();
					appData.state = APP_TCPIP_WAIT_INIT;
					break;
				}
				appData.state = APP_NVM_LOAD_CONFIGURATION;
				break;
			}

			// Load the configuration stored in NVM on powerup
		case APP_NVM_LOAD_CONFIGURATION:
			{
				validConfig = APP_LoadConfiguration();
				appData.state = APP_TCPIP_WAIT_INIT;
				break;
			}

			// Wait for the TCPIP stack to initialize, store the boards MAC address and initialize mDNS service
		case APP_TCPIP_WAIT_INIT:
			{
				SYS_STATUS          tcpipStat;
				const char          *netName, *netBiosName;
				TCPIP_NET_HANDLE    netH;
				int                 i, nNets;

				tcpipStat = TCPIP_STACK_Status(sysObj.tcpip);
				if (tcpipStat < 0)
				{	 // some error occurred
					break;
				}
				else if (tcpipStat == SYS_STATUS_READY)
				{
					// now that the stack is ready we can check the
					// available interfaces
					nNets = TCPIP_STACK_NumberOfNetworksGet();
					for (i = 0; i < nNets; i++)
					{

						netH = TCPIP_STACK_IndexToNet(i);
						netName = TCPIP_STACK_NetNameGet(netH);
						netBiosName = TCPIP_STACK_NetBIOSName(netH);

						// Retrieve MAC Address for UUID
						TCPIP_NET_HANDLE netH = TCPIP_STACK_NetHandleGet("PIC32INT");
						TCPIP_MAC_ADDR* pAdd = 0;
						pAdd = (TCPIP_MAC_ADDR *)TCPIP_STACK_NetAddressMac(netH);

						// Store UUID for application
						appData.macAddress.v[5] = pAdd->v[5];
						appData.macAddress.v[4] = pAdd->v[4];
						appData.macAddress.v[3] = pAdd->v[3];
						appData.macAddress.v[2] = pAdd->v[2];
						appData.macAddress.v[1] = pAdd->v[1];
						appData.macAddress.v[0] = pAdd->v[0];

						sprintf(appData.uuid, "%02x%02x%02x%02x%02x%02x",
								  appData.macAddress.v[0], appData.macAddress.v[1], appData.macAddress.v[2],
								  appData.macAddress.v[3], appData.macAddress.v[4], appData.macAddress.v[5]);	// convert to string

						char mDNSServiceName[16]; // base name of the service Must not exceed 16 bytes long
						strcpy(mDNSServiceName, &appData.uuid[6]); //Copy over UUID last 6 characters, 
						strcat(mDNSServiceName, "_IoT-E");
						SYS_CONSOLE_PRINT("App:  Registering mDNS service as '%s'\r\n", mDNSServiceName);
						// mDNS name will be xxxxxx_ECM where "xxxxxx" is the last three bytes of MAC address
						mDNSServiceName[sizeof(mDNSServiceName) - 2] = '1' + i;
						TCPIP_MDNS_ServiceRegister( netH
															 , mDNSServiceName							// name of the service
															 ,"_http._tcp.local"							// type of the service
															 ,80												// TCP or UDP port, at which this service is available
															 ,((const uint8_t *)"path=/index.htm")	// TXT info
															 ,1												// auto rename the service when if needed
															 ,NULL											// no callback function
															 ,NULL);      
					}

					appData.state = APP_TCPIP_WAIT_FOR_IP;
				}
				break;
			}

		case APP_TCPIP_WAIT_FOR_IP:
			{
				static IPV4_ADDR    dwLastIP[2] = { {-1}, {-1}};
				IPV4_ADDR           ipAddr;
				TCPIP_NET_HANDLE    netH;
				int i, nNets;

				nNets = TCPIP_STACK_NumberOfNetworksGet();
				for (i = 0; i < nNets; i++)
				{
					netH = TCPIP_STACK_IndexToNet(i);
					ipAddr.Val = TCPIP_STACK_NetAddress(netH);
					if (dwLastIP[i].Val != ipAddr.Val)
					{
						dwLastIP[i].Val = ipAddr.Val;
						if (ipAddr.v[0] != 0 && ipAddr.v[0] != 169) // Wait for a Valid IP
						{
							sprintf(appData.local_ip, "%d.%d.%d.%d", ipAddr.v[0], ipAddr.v[1], ipAddr.v[2], ipAddr.v[3]);
							uint32_t lightShowVal = BSP_LED_EASY_CONFIGURATION;
							xQueueSendToFront(app1Data.lightShowQueue, &lightShowVal, 1);
							SYS_CONSOLE_PRINT("App:  Waiting for configuration from host: %s ...\r\n", appData.local_ip);
							appData.state = APP_TCPIP_WAIT_CONFIGURATION;
						}
					}
				}
				break;
			}

		case APP_TCPIP_WAIT_CONFIGURATION:
			{
				if (!appData.host[0] || !appData.project_mqtt_id[0])
				{
					break;
				}
				else
				{
					appData.lightShowVal = BSP_LED_ALL_GOOD;
					xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);  
					TCPIP_NET_HANDLE    netH;
					int i, nNets;

					//Disable ZeroConf and HTTP server since we have server
					nNets = TCPIP_STACK_NumberOfNetworksGet();
					for (i = 0; i < nNets; i++)
					{
						netH = TCPIP_STACK_IndexToNet(i);
						TCPIP_ZCLL_Disable(netH);
						// Disable http here as well
					}
				}
				appData.state = APP_TCPIP_MQTT_INIT;
				break;
			}

		case APP_TCPIP_MQTT_INIT:
			{
				SYS_CONSOLE_MESSAGE("App:  Beginning MQTT Client application\r\n");
				int rc = MqttClient_Init(&appData.myClient, &appData.myNet, mqttclient_message_cb, txBuffer, MAX_BUFFER_SIZE, rxBuffer, MAX_BUFFER_SIZE, cmd_timeout_ms);
				SYS_CONSOLE_PRINT("App:  MQTT.Client_Init: %s (%d)\r\n", MqttClient_ReturnCodeToString(rc), rc);
				if (rc != MQTT_CODE_SUCCESS)
				{
					appData.lightShowVal = BSP_LED_TCPIP_STACK_INIT_FAILURE;
					xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);
					SYS_CONSOLE_MESSAGE("App:  MQTT.Client_Init: Failed (catastrophic)\r\n");
					while (1);
				}
				APP_TIMER_Set(&appData.genericUseTimer);
				appData.state = APP_TCPIP_MQTT_NET_CONNECT;
				break;
			}

		case APP_TCPIP_MQTT_NET_CONNECT:
			{
				SYS_CONSOLE_MESSAGE("App:  MQTT.Net_Connect\r\n");
				int rc = MqttClient_NetConnect(&appData.myClient, (const char *)&appData.host, MediumOne_IOT_PORT, MQTT_DEFAULT_CMD_TIMEOUT_MS, NULL, NULL);
				SYS_CONSOLE_PRINT("App:  MQTT.Net_Connect: %s (%d)\r\n", MqttClient_ReturnCodeToString(rc), rc);
				if (rc != MQTT_CODE_SUCCESS)
				{
					SYS_CONSOLE_PRINT("App:  %s (%d)\r\n", APP_ReturnCodeToString(rc), rc);
					SYS_CONSOLE_PRINT("App:  Closing Socket %d\r\n\r\n", appData.socket);
					NET_PRES_SocketClose(appData.socket);
					appData.lightShowVal = BSP_LED_SERVER_CONNECT_FAILED;
					xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);  
					while (!APP_TIMER_Expired(&appData.genericUseTimer, 5));
					APP_TIMER_Set(&appData.genericUseTimer);
					break;
				}
				appData.lightShowVal = BSP_LED_ALL_GOOD;
				xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);  
				appData.state = APP_TCPIP_MQTT_PROTOCOL_CONNECT;
				break;
			}

		case APP_TCPIP_MQTT_PROTOCOL_CONNECT:
			{
				MqttConnect connect;
				MqttMessage lwt_msg;
				XMEMSET(&connect, 0, sizeof(MqttConnect));
				connect.username = appData.username;
				connect.password = appData.password;
				connect.keep_alive_sec = KEEP_ALIVE;
				connect.clean_session = 1;
				char clientIdString[13];
				sprintf(clientIdString, appData.uuid, "%02x%02x%02x%02x%02x%02x\0", 
						  appData.macAddress.v[0], appData.macAddress.v[1], appData.macAddress.v[2],
						  appData.macAddress.v[3], appData.macAddress.v[4], appData.macAddress.v[5]);
				connect.client_id = (byte *)clientIdString;
				XMEMSET(&lwt_msg, 0, sizeof(lwt_msg));
				connect.lwt_msg = &lwt_msg;
				connect.enable_lwt = 0;

				/* Send Connect and wait for Connect Ack */
				int rc = MqttClient_Connect(&appData.myClient, &connect);
				SYS_CONSOLE_PRINT("App:  MQTT.Client_Connect: %s (%d)\r\n", MqttClient_ReturnCodeToString(rc), rc);
				if (rc != MQTT_CODE_SUCCESS)
				{
					appData.lightShowVal = BSP_LED_SERVER_CONNECT_FAILED;
					xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);
					SYS_CONSOLE_MESSAGE("App:  MQTT.Client_Connect: failed\r\n");
					APP_TIMER_Set(&appData.genericUseTimer);
					while (!APP_TIMER_Expired(&appData.genericUseTimer, 5));   
					appData.state = APP_TCPIP_ERROR;
					break;
				}
				/* Validate Connect Ack info */
				SYS_CONSOLE_PRINT("App:  MQTT.Connect Ack: Return Code %u, Session Present %d, keep alive: %d\r\n",
										connect.ack.return_code,
										(connect.ack.flags & MQTT_CONNECT_ACK_FLAG_SESSION_PRESENT) ?
										1 : 0, connect.keep_alive_sec);
				APP_TIMER_Set(&appData.mqttKeepAlive);
				APP_TIMER_Set(&appData.mqttSendDeviceInfo);
				APP_TIMER_Set2(&appData.mqttSendPressureClick, -DEFAULT_PRESSURE_CLICK_INTERVAL);
				APP_TIMER_Set2(&appData.mqttSendHumidityClick, -DEFAULT_HUMIDITY_CLICK_INTERVAL);
				APP_TIMER_Set2(&appData.mqttSendAirQualityClick, -DEFAULT_AIR_QUALITY_CLICK_INTERVAL);
				APP_TIMER_Set2(&appData.mqttSendMotionClick, -DEFAULT_MOTION_CLICK_INTERVAL);
            
				appData.state = APP_TCPIP_MQTT_SUBSCRIBE;
				break;
			}

		case APP_TCPIP_MQTT_SUBSCRIBE:
			{
				MqttSubscribe subscribe;
				MqttUnsubscribe unsubscribe;
				MqttTopic topics[1], *topic;
				int i, rc;

				/* Build list of topics */
				topics[0].topic_filter = appData.subscribe_topic_name;
				topics[0].qos = 0;

				/* Subscribe Topic */
				XMEMSET(&subscribe, 0, sizeof(MqttSubscribe));
				subscribe.packet_id = mqttclient_get_packetid();
				subscribe.topic_count = sizeof(topics)/sizeof(MqttTopic);
				subscribe.topics = topics;
				rc = MqttClient_Subscribe(&appData.myClient, &subscribe);
                for (i = 0; i < subscribe.topic_count; i++)
				{
					topic = &subscribe.topics[i];
					SYS_CONSOLE_PRINT("App:  MQTT.Topic List: %s, Qos %u, Return Code %u\r\n",
											topic->topic_filter, topic->qos, topic->return_code);
				}
                
				SYS_CONSOLE_PRINT("App:  MQTT.Subscribe: %s (%d)\r\n",
										MqttClient_ReturnCodeToString(rc), rc);
				if (rc != MQTT_CODE_SUCCESS)
				{
					appData.lightShowVal = BSP_LED_SERVER_CONNECT_FAILED;
					xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);
					SYS_CONSOLE_MESSAGE("App:  MQTT.Subscribe: failed\r\n");
					APP_TIMER_Set(&appData.genericUseTimer);
					while (!APP_TIMER_Expired(&appData.genericUseTimer, 5));   
					appData.state = APP_TCPIP_ERROR;
					break;
				}
				  

				BSP_LEDOff(BSP_LED_1_CHANNEL, BSP_LED_1_PORT); 
				BSP_LEDOff(BSP_LED_2_CHANNEL, BSP_LED_2_PORT); 
				BSP_LEDOff(BSP_LED_3_CHANNEL, BSP_LED_3_PORT); 
				BSP_LEDOff(BSP_LED_4_CHANNEL, BSP_LED_4_PORT);

				if (APP_Send_IPDetectionCommand() != MQTT_CODE_SUCCESS)
            	{
                	appData.state = APP_TCPIP_ERROR;
                	break;
            	}
            
            	if (APP_Send_DeviceInfo() != MQTT_CODE_SUCCESS)
            	{
                	appData.state = APP_TCPIP_ERROR;
                	break;
            	}
				
				appData.state = APP_TCPIP_MQTT_LOOP;
				break;
			}

		case APP_TCPIP_MQTT_LOOP:
			{
				int rc;
				char publishPayload[512]="";
                
                // Update heart beat led state
				if (appData.lightShowVal != BSP_LED_ALL_GOOD)
				{
                    if (!((appData.lightShowVal==BSP_LED_TX || appData.lightShowVal==BSP_LED_RX) && 
                          txrxLedStateCount<=1))
                    {
                        txrxLedStateCount = 0;
                        appData.lightShowVal = BSP_LED_ALL_GOOD;
                        xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);
                    }
				}
                
				// Pressure_Click
				double pressure_changed_percent = ABS(pressure_value-appData.last_pressure_value)/appData.last_pressure_value;
				double temperature_changed_percent = ABS(temperature_value-appData.last_temperature_value)/appData.last_temperature_value;
				int nWaittingTime = (appData.pressure_click_config.period_sec>0)?
                        appData.pressure_click_config.period_sec:DEFAULT_PRESSURE_CLICK_INTERVAL;
                int nTempWaittingTime = (appData.temperature_click_config.period_sec>0)?
                        appData.temperature_click_config.period_sec:DEFAULT_TEMPERATURE_CLICK_INTERVAL;
                if (nWaittingTime>nTempWaittingTime) nWaittingTime = nTempWaittingTime;
				if (appData.app_sensor_type == APP_SENSOR_TYPE_PRESSURE_CLICK && pressure_value > 0 &&
                    ( APP_TIMER_Expired(&appData.mqttSendPressureClick, nWaittingTime) ||
                      (pressure_changed_percent >= appData.pressure_click_config.threshold_pct) ||
                      (temperature_changed_percent >= appData.temperature_click_config.threshold_pct) ))
                {
                    sprintf(publishPayload, "{\"event_data\": {\"pressure\":%f, \"temperature\":%f, \"connected_sensor\":\"pressure_click\"}}",
                            (double)pressure_value, (double)temperature_value);
                    if (APP_Send_MQTTMessage(publishPayload) != MQTT_CODE_SUCCESS)
                    {
                        appData.state = APP_TCPIP_ERROR;
                        break;
                    }
                    
                    appData.last_pressure_value = (double)pressure_value;
                    appData.last_temperature_value = (double)temperature_value;
                    
                    // Reset send pressure_click timer
                    APP_TIMER_Set(&appData.mqttSendPressureClick);
                }
                
                
                // Humidity_Click
                double humidity_changed_percent = ABS(HTS221_humidity-appData.last_humidity_value)/appData.last_humidity_value;
                temperature_changed_percent = ABS(HTS221_temperature-appData.last_temperature_value)/appData.last_temperature_value;
                nWaittingTime = (appData.humidity_click_config.period_sec>0)?
                        appData.humidity_click_config.period_sec:DEFAULT_HUMIDITY_CLICK_INTERVAL;
				nTempWaittingTime = (appData.temperature_click_config.period_sec>0)?
                        appData.temperature_click_config.period_sec:DEFAULT_TEMPERATURE_CLICK_INTERVAL;
                if (nWaittingTime>nTempWaittingTime) nWaittingTime = nTempWaittingTime;
                if (appData.app_sensor_type == APP_SENSOR_TYPE_HUMIDITY_CLICK && 
                    ( APP_TIMER_Expired(&appData.mqttSendHumidityClick, nWaittingTime) ||
                      (humidity_changed_percent >= appData.humidity_click_config.threshold_pct) ||
                      (temperature_changed_percent >= appData.temperature_click_config.threshold_pct) ))
                {
                    sprintf(publishPayload, "{\"event_data\": {\"humidity\":%f, \"temperature\":%f, \"connected_sensor\":\"humidity_click\"}}",
                            (double)HTS221_humidity, (double)HTS221_temperature);
                    if (APP_Send_MQTTMessage(publishPayload) != MQTT_CODE_SUCCESS)
                    {
                        appData.state = APP_TCPIP_ERROR;
                        break;
                    }
                    
                    appData.last_humidity_value = (double)HTS221_humidity;
                    appData.last_temperature_value = (double)HTS221_temperature;
                    
                    // Reset send humidity_click timer
                    APP_TIMER_Set(&appData.mqttSendHumidityClick);
                }
                
                
                // Air_Quality_Click
                double air_quality_changed_percent = ABS(app1Data.airValue-appData.last_air_quality_value)/appData.last_air_quality_value;
				nWaittingTime = (appData.air_quality_click_config.period_sec>0)?
                        appData.air_quality_click_config.period_sec:DEFAULT_AIR_QUALITY_CLICK_INTERVAL;
                if (appData.app_sensor_type == APP_SENSOR_TYPE_AIR_QUALITY_CLICK && 
                    ( APP_TIMER_Expired(&appData.mqttSendAirQualityClick, nWaittingTime) ||
                      (air_quality_changed_percent >= appData.air_quality_click_config.threshold_pct) ))
                {
                    sprintf(publishPayload, "{\"event_data\": {\"air_quality\":%f, \"connected_sensor\":\"air_quality_click\"}}",
                            (double)app1Data.airValue);
                    if (APP_Send_MQTTMessage(publishPayload) != MQTT_CODE_SUCCESS)
                    {
                        appData.state = APP_TCPIP_ERROR;
                        break;
                    }
                    
                    appData.last_air_quality_value = (double)app1Data.airValue;
                    
                    // Reset send air_quality_click timer
                    APP_TIMER_Set(&appData.mqttSendAirQualityClick);
                }

				
                //Motion_Click
                nWaittingTime = (appData.motion_click_config.period_sec>0)?
                        appData.motion_click_config.period_sec:DEFAULT_MOTION_CLICK_INTERVAL;
                if (appData.app_sensor_type == APP_SENSOR_TYPE_MOTION_CLICK && 
                    APP_TIMER_Expired(&appData.mqttSendMotionClick, nWaittingTime))
                {
                    if (bspData.previousStateMInt) 
                    {
                        sprintf(publishPayload, "{\"event_data\": {\"motion_detected\":true, \"connected_sensor\":\"motion_click\"}}");
                        if (APP_Send_MQTTMessage(publishPayload) != MQTT_CODE_SUCCESS)
                        {
                            appData.state = APP_TCPIP_ERROR;
                            break;
                        }

                        // Reset send motion_click timer
                        APP_TIMER_Set(&appData.mqttSendMotionClick);
                    }
                    else
                    {
                        // Reset send motion_click timer with keep expired
                        APP_TIMER_Set2(&appData.mqttSendMotionClick, -nWaittingTime);
                    }
                }
                
                
				// Send device information every 10 minutes
                if (APP_TIMER_Expired(&appData.mqttSendDeviceInfo, SEND_DEVICE_INFO_INTERVAL))
                {
                    // Reset send sensors data timer
                    APP_TIMER_Set(&appData.mqttSendDeviceInfo);

                    if (APP_Send_DeviceInfo() != MQTT_CODE_SUCCESS)
                    {
                            appData.state = APP_TCPIP_ERROR;
                            break;
                    }
                }


                // Check & send potentiometer event
                uint32_t potVal;
				if (uxQueueMessagesWaiting(app1Data.potentiometerQueue) > 0 && app1Data.potChanged == true)
				{
                    xQueueReceive( app1Data.potentiometerQueue, &potVal, 1);
					sprintf(publishPayload, "{\"event_data\": {\"pot\":%d}}", app1Data.potValue);
                    if (APP_Send_MQTTMessage(publishPayload) != MQTT_CODE_SUCCESS)
                    {
                        appData.state = APP_TCPIP_ERROR;
                        break;
                    }
					app1Data.potChanged = false;
				}


				// Check & send switches event	
                struct switchMessage switchMsg;
                if (uxQueueMessagesWaiting(app1Data.switchQueue ) > 0)
                {
                    xQueueReceive( app1Data.switchQueue, &switchMsg, 1);
                    if (switchMsg.switchNum != BSP_SWITCH_MINT && switchMsg.switchVal==BSP_SWITCH_STATE_ASSERTED) 
                    {
                        sprintf(publishPayload, "{\"event_data\": {\"button_press\":%d}}", switchMsg.switchNum);
                        if (APP_Send_MQTTMessage(publishPayload) != MQTT_CODE_SUCCESS)
                        {
                            appData.state = APP_TCPIP_ERROR;
                            break;
                        }
                    }
                }

					
                // Keep Alive
				if (APP_TIMER_Expired(&appData.mqttKeepAlive, KEEP_ALIVE))
				{
					rc = MqttClient_Ping(&appData.myClient);
					// Reset keep alive timer
					APP_TIMER_Set(&appData.mqttKeepAlive);
					if (rc != MQTT_CODE_SUCCESS)
					{
						SYS_CONSOLE_PRINT("App:  MQTT.Ping:  Keep Alive Error: %s (%d)\r\n",
												MqttClient_ReturnCodeToString(rc), rc);
						appData.state = APP_TCPIP_ERROR;
						break;
					}
					else
					{
						SYS_CONSOLE_PRINT("App:  MQTT.Ping: %s (%d)\r\n",
												MqttClient_ReturnCodeToString(rc), rc);
						appData.lightShowVal = BSP_LED_TX;
						xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);
					}
				}
                
                
                // Wait for coming message
				rc = MqttClient_WaitMessage(&appData.myClient, 50);
				if (rc == MQTT_CODE_ERROR_TIMEOUT)
				{
					// Keep Alive
					rc = MqttClient_Ping(&appData.myClient);
					if (rc != MQTT_CODE_SUCCESS)
					{
						SYS_CONSOLE_PRINT("App:  MQTT.Ping:  Keep Alive Error: %s (%d)\r\n",
												MqttClient_ReturnCodeToString(rc), rc);
						appData.state = APP_TCPIP_ERROR;
						break;
					}
				}
				else if (rc == MQTT_CODE_ERROR_NETWORK)
				{
					SYS_CONSOLE_PRINT("App:  MQTT.WaitMessage:  Network Error: %s (%d)\r\n",
											MqttClient_ReturnCodeToString(rc), rc);
					appData.state = APP_TCPIP_ERROR;
					break;
				}
				else if (rc == APP_CODE_ERROR_CMD_TIMEOUT)
				{
                    // There is no message come yet
					break;
				}
				else if (rc != MQTT_CODE_SUCCESS)
				{
					appData.lightShowVal = BSP_LED_SERVER_CONNECT_FAILED;
					xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);  
					SYS_CONSOLE_PRINT("App: MQTT.WaitMessage:  Error: %s (%d)\r\n", MqttClient_ReturnCodeToString(rc), rc);
					appData.state = APP_TCPIP_ERROR;
				}
				break;
			}

		case APP_TCPIP_ERROR:
			{
				appData.lightShowVal = BSP_LED_CONNECTION_FAILED;
				xQueueSendToFront(app1Data.lightShowQueue, &appData.lightShowVal, 1);
				SYS_CONSOLE_PRINT("App: Closing Socket %d\r\n\r\n", appData.socket);
				NET_PRES_SocketClose(appData.socket);
				appData.state = APP_TCPIP_MQTT_NET_CONNECT;
				break;
			}


			/* The default state should never be executed. */
		default:
			{
				/* TODO: Handle error in application's state machine. */
				break;
			}
	}
	
    switch (display_message)
	{
		case 1:
			SYS_CONSOLE_PRINT("App: app1Data.potValue=%d\r\n", app1Data.potValue);
			display_message=0;
			break;
		case 2:
			SYS_CONSOLE_PRINT("App: app1Data.airValue=%d\r\n", app1Data.airValue);
			display_message=0;
			break;
		case 3:
			SYS_CONSOLE_PRINT("App: Pressure=%d Temperature=%.2f\r\n", pressure_value,temperature_value);
			display_message=0;
			break;
		case 4:
			SYS_CONSOLE_PRINT("App: Temperature=%.2f Humidity=%.2f\r\n", HTS221_temperature,HTS221_humidity);
			display_message=0;
			break;
	}
}


/******************************************************************************
  Function:
	 void APP1_Tasks ( void )

  Remarks:
	 See prototype in app1.h.
 */
void APP1_Tasks ( void )
{
	/* Check the application's current state. */
	switch ( app1Data.state )
	{
		/* Application's initial state. */
		case APP1_STATE_INIT:
			{
				bool appInitialized = true;

				if (appInitialized)
				{
					app1Data.state = APP1_STATE_SERVICE_TASKS;
				}
				APP_TIMER_Set(&appData.airTimer);
				APP_TIMER_Set(&appData.humdTimer);
				APP_TIMER_Set(&appData.motionTimer);
				APP_TIMER_Set(&appData.pressureTimer);
				APP_TIMER_Set(&appData.tempTimer);
				APP_TIMER_Set(&appData.tenminutesTimer);
				break;
			}

		case APP1_STATE_SERVICE_TASKS:
			{
				// BSP tasks that control switch and led functions
				BSP_SYS_Tasks();

				// Check if switches are pressed and send a message to the queue
				if (BSP_SWITCH_SwitchGetState(BSP_SWITCH_1_PORT) != bspData.previousStateS1)
				{
					BSP_SWITCH_SwitchSetPreviousState(BSP_SWITCH_1_PORT, BSP_SWITCH_SwitchGetState(BSP_SWITCH_1_PORT));
					mySwitchMessage.switchNum = BSP_SWITCH_1;
					mySwitchMessage.switchVal = bspData.previousStateS1;
					xQueueSendToBack( app1Data.switchQueue, &mySwitchMessage, 1 );
					SYS_CONSOLE_MESSAGE("App:  Button1 Pressed\r\n"); 
					Button1Changed=true;
				}
				if (BSP_SWITCH_SwitchGetState(BSP_SWITCH_2_PORT) != bspData.previousStateS2)
				{
					BSP_SWITCH_SwitchSetPreviousState(BSP_SWITCH_2_PORT, BSP_SWITCH_SwitchGetState(BSP_SWITCH_2_PORT));
					mySwitchMessage.switchNum = BSP_SWITCH_2;
					mySwitchMessage.switchVal = bspData.previousStateS2;
					xQueueSendToBack( app1Data.switchQueue, &mySwitchMessage, 1 );
					SYS_CONSOLE_MESSAGE("App:  Button2 Pressed\r\n"); 
					Button2Changed=true;
				}
				if (BSP_SWITCH_SwitchGetState(BSP_SWITCH_3_PORT) != bspData.previousStateS3)
				{
					BSP_SWITCH_SwitchSetPreviousState(BSP_SWITCH_3_PORT, BSP_SWITCH_SwitchGetState(BSP_SWITCH_3_PORT));
					mySwitchMessage.switchNum = BSP_SWITCH_3;
					mySwitchMessage.switchVal = bspData.previousStateS3;
					xQueueSendToBack( app1Data.switchQueue, &mySwitchMessage, 1 );
					SYS_CONSOLE_MESSAGE("App:  Button3 Pressed\r\n"); 
					Button3Changed=true;
				}
				if (BSP_SWITCH_SwitchGetState(BSP_SWITCH_4_PORT) != bspData.previousStateS4)
				{
					BSP_SWITCH_SwitchSetPreviousState(BSP_SWITCH_4_PORT, BSP_SWITCH_SwitchGetState(BSP_SWITCH_4_PORT));
					mySwitchMessage.switchNum = BSP_SWITCH_4;
					mySwitchMessage.switchVal = bspData.previousStateS4;
					xQueueSendToBack( app1Data.switchQueue, &mySwitchMessage, 1 );
					SYS_CONSOLE_MESSAGE("App:  Button4 Pressed\r\n"); 
					Button4Changed=true;
				}
				if (BSP_SWITCH_SwitchGetState(BSP_SWITCH_MINT_PORT) != bspData.previousStateMInt &&
					 appData.app_sensor_type == APP_SENSOR_TYPE_MOTION_CLICK)
				{
					BSP_SWITCH_SwitchSetPreviousState(BSP_SWITCH_MINT_PORT, BSP_SWITCH_SwitchGetState(BSP_SWITCH_MINT_PORT));
					mySwitchMessage.switchNum = BSP_SWITCH_MINT;
					mySwitchMessage.switchVal = bspData.previousStateMInt;
					xQueueSendToBack( app1Data.switchQueue, &mySwitchMessage, 1 );
					if (mySwitchMessage.switchVal==BSP_SWITCH_STATE_ASSERTED)
					{
						SYS_CONSOLE_MESSAGE("App:  Motion Off\r\n");
						motion_detected = 0;	//Detect & read from motion_click sensor
					}
					else
					{
						SYS_CONSOLE_MESSAGE("App:  Motion Detected\r\n"); 
						motion_detected = 1;	//Detect & read from motion_click sensor
					}
					MotionChanged=true;
				}

				// Trigger an ADC reading every one second for the pot
				if ((SYS_TMR_TickCountGet() - app1Data.potTimer) > 1000)
				{
					app1Data.potTimer = SYS_TMR_TickCountGet();
					if (clickid==0)
					{
						/* Initialize ADC pot */
						DRV_ADC_Initialize();
						DRV_ADC0_Open();
						DRV_ADC_DigitalFilter0_Open();
						DRV_ADC_Start();
					}
					else if (clickid==1)
					{
						/* Initialize ADC air quality */
						DRV_ADC_Initialize1();
						DRV_ADC0_Open1();
						DRV_ADC_DigitalFilter0_Open1();
						DRV_ADC_Start1();
					}
				}

				// If the ADC Pot data is ready, see if value changed and send a message to queue
				if (clickid==0)
				{
					if (DRV_ADC_DigitalFilter0_DataIsReady())
					{
						int adcVal;
						app1Data.newPotSamp = (uint16_t)DRV_ADC_DigitalFilter0_DataRead();
						adcVal = app1Data.newPotSamp >> 6;
						if (abs(adcVal-app1Data.potValue) > POT_MARGIN)
						{
							app1Data.potValue = adcVal;
							app1Data.potChanged = true;
							PotChanged=true;
							display_message=1;
							xQueueSendToBack( app1Data.potentiometerQueue, &app1Data.potValue, 1 );
						}
						if (appData.app_sensor_type == APP_SENSOR_TYPE_AIR_QUALITY_CLICK)
							clickid=1;
					}
				}
				else if (clickid==1)
				{
					/* Initialize ADC air quality */
					if (DRV_ADC_DigitalFilter0_DataIsReady1())
					{
						uint32_t adcVal;
						adc_rd = (uint16_t)DRV_ADC_DigitalFilter0_DataRead1();
						app1Data.newAirSamp = adc_rd;
						adcVal = app1Data.newAirSamp >> 6;
						if (adcVal != app1Data.airValue)
						{
							app1Data.airValue = adcVal;
							app1Data.airChanged = true;
							AirChanged=true;
							display_message=2;
							xQueueSendToBack( app1Data.airqualityQueue, &app1Data.airValue, 1 );
						}
						clickid=0;
					}
				}
				if (appData.app_sensor_type == APP_SENSOR_TYPE_PRESSURE_CLICK && APP_TIMER_Expired(&appData.sampleTimer, SAMPLE_DURATION))
				{
					uint32_t tempVal;
					pressure_temp_read();
					app1Data.newPressureSamp = pressure_value;
					tempVal = app1Data.newPressureSamp;
					if (tempVal != app1Data.pressureValue && tempVal > 0)
					{
						app1Data.pressureValue = tempVal;
						app1Data.pressureChanged = true;
						PressureChanged=true;
					}

					display_message=3;
					if (app1Data.pressureChanged)
					{
						xQueueSendToBack( app1Data.pressureQueue, &app1Data.pressureValue, 1 );
						app1Data.pressureChanged = false;
						display_message=3;
					}
					APP_TIMER_Set(&appData.sampleTimer);
				}
				if (appData.app_sensor_type == APP_SENSOR_TYPE_HUMIDITY_CLICK && APP_TIMER_Expired(&appData.sampleTimer, SAMPLE_DURATION))
				{
					chip_id_address=HTS221_ADDRESS;
					if (HTS221init()==true)
						humidity_temperature_read();
					else
					{
						temperature_value=1;
						pressure_value=1;
					}
					display_message=4;
					APP_TIMER_Set(&appData.sampleTimer);
				}
				// Check light show queue for a state, if exists, set state
				if ( uxQueueMessagesWaiting( app1Data.lightShowQueue ) > 0 )
				{
					uint32_t lightShowVar;
					xQueueReceive( app1Data.lightShowQueue, &lightShowVar, 1 );
					BSP_LED_LightShowSet(lightShowVar);
				}

				break;
			}

			/* The default state should never be executed. */
		default:
			{
				/* TODO: Handle error in application's state machine. */
				break;
			}
	}
}

/*******************************************************************************
 End of File
 */
