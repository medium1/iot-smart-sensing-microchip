/*******************************************************************************
  Application to Demo HTTP Server

  Summary:
    Support for HTTP module in Microchip TCP/IP Stack

  Description:
    -Implements the application
    -Reference: RFC 1002
*******************************************************************************/

/*******************************************************************************
File Name: configuration_http.c
Copyright (C) 2012 released Microchip Technology Inc.  All rights
reserved.

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

#define __CUSTOMHTTPAPP_C

#include "system_config.h"

#if defined(TCPIP_STACK_USE_HTTP_SERVER)

#include "tcpip/tcpip.h"
#include "system/tmr/sys_tmr.h"
#include "system/random/sys_random.h"
#include "tcpip/src/common/helpers.h"
#include "tcpip/src/tcpip_private.h"

#include "app.h"
#include "app_nvm_support.h"


/****************************************************************************
  Section:
    Definitions
  ***************************************************************************/
extern APP_DATA appData;

/****************************************************************************
  Section:
    Function Prototypes and Memory Globalizers
  ***************************************************************************/
static HTTP_IO_RESULT HTTPPostConfig(HTTP_CONN_HANDLE connHandle);

// Sticky status message variable.
// This is used to indicated whether or not the previous POST operation was
// successful.  The application uses these to store status messages when a
// POST operation redirects.  This lets the application provide status messages
// after a redirect, when connection instance data has already been lost.
//static bool lastSuccess = false;

// Stick status message variable.  See lastSuccess for details.
static bool lastFailure = false;

/****************************************************************************
  Section:
    GET Form Handlers
  ***************************************************************************/

/*****************************************************************************
  Function:
    HTTP_IO_RESULT TCPIP_HTTP_GetExecute(HTTP_CONN_HANDLE connHandle)

  Internal:
    See documentation in the TCP/IP Stack API or HTTP.h for details.
  ***************************************************************************/
HTTP_IO_RESULT TCPIP_HTTP_GetExecute(HTTP_CONN_HANDLE connHandle)
{
    uint8_t filename[20];
    uint8_t* httpDataBuff;

    // Load the file name
    // Make sure uint8_t filename[] above is large enough for your longest name
    SYS_FS_FileNameGet(TCPIP_HTTP_CurrentConnectionFileGet(connHandle), filename, 20);

    httpDataBuff = TCPIP_HTTP_CurrentConnectionDataBufferGet(connHandle);

    // Example of how to process a GET request call
    // If its the forms.htm page
//    if(!memcmp(filename, "forms.htm", 9))
//    {
//
//    }
    return HTTP_IO_DONE;
}

/****************************************************************************
  Section:
    POST Form Handlers
  ***************************************************************************/
#if defined(TCPIP_HTTP_USE_POST)

/*****************************************************************************
  Function:
    HTTP_IO_RESULT TCPIP_HTTP_PostExecute(HTTP_CONN_HANDLE connHandle)

  Internal:
    See documentation in the TCP/IP Stack API or HTTP.h for details.
  ***************************************************************************/
HTTP_IO_RESULT TCPIP_HTTP_PostExecute(HTTP_CONN_HANDLE connHandle)
{
    // Resolve which function to use and pass along
    uint8_t filename[20];

    // Load the file name
    // Make sure uint8_t filename[] above is large enough for your longest name
    SYS_FS_FileNameGet(TCPIP_HTTP_CurrentConnectionFileGet(connHandle), filename, sizeof(filename));

    if(!memcmp(filename, "index.htm", 9))
        return HTTPPostConfig(connHandle) /*HTTPPostConfig()*/;


    return HTTP_IO_DONE;
}


/*****************************************************************************
  Function:
    static HTTP_IO_RESULT HTTPPostConfig(HTTP_CONN_HANDLE connHandle)

  Summary:
    Processes the configuration form on index.htm

  Description:
    Accepts configuration parameters from the form, saves them to a
    temporary location in RAM, then eventually saves the data to EEPROM or
    external Flash.

    When complete, this function redirects to reconnect.htm, which will
    display information on the board connecting to the amazon server.

    If an error occurs, error.htm will be seen.

  Precondition:
    None

  Parameters:
    connHandle  - HTTP connection handle

  Return Values:
    HTTP_IO_DONE - all parameters have been processed
    HTTP_IO_NEED_DATA - data needed by this function has not yet arrived
  ***************************************************************************/

static HTTP_IO_RESULT HTTPPostConfig(HTTP_CONN_HANDLE connHandle)
{
    uint8_t i;

    uint8_t* httpDataBuff = 0;
    bool bConfigFailure = false;
    uint32_t byteCount;
    TCP_SOCKET sktHTTP;

    byteCount = TCPIP_HTTP_CurrentConnectionByteCountGet(connHandle);
    sktHTTP = TCPIP_HTTP_CurrentConnectionSocketGet(connHandle);
    if(byteCount > TCPIP_TCP_GetIsReady(sktHTTP) + TCPIP_TCP_FifoRxFreeGet(sktHTTP))
    {   // Configuration Failure
        lastFailure = true;
        TCPIP_HTTP_CurrentConnectionStatusSet(connHandle, HTTP_REDIRECT);
        return HTTP_IO_DONE;
    }

    // Ensure that all data is waiting to be parsed.  If not, keep waiting for
    // all of it to arrive.
    if(TCPIP_TCP_GetIsReady(sktHTTP) < byteCount)
        return HTTP_IO_NEED_DATA;

    // Use current config in non-volatile memory as defaults
    httpDataBuff = TCPIP_HTTP_CurrentConnectionDataBufferGet(connHandle);

    int nMAX_FIELD_NAME_LEN = 20;
    
    // Read all browser POST data
    while(TCPIP_HTTP_CurrentConnectionByteCountGet(connHandle))
    {
        // Read a form field name
        if(TCPIP_HTTP_PostNameRead(connHandle, httpDataBuff, nMAX_FIELD_NAME_LEN) != HTTP_READ_OK)
        {
            bConfigFailure = true;
            break;
        }

        // Read a form field value
        if(TCPIP_HTTP_PostValueRead(connHandle, httpDataBuff + nMAX_FIELD_NAME_LEN, TCPIP_HTTP_MAX_DATA_LEN-nMAX_FIELD_NAME_LEN-2) != HTTP_READ_OK)
        {
            bConfigFailure = true;
            break;
        }

        // Default MQTT host
        strcpy(appData.host, "mqtt.mediumone.com");
                
        // Parse the value that was read
        if(!strcmp((char*)httpDataBuff, (const char*)"mqtt_host"))
        {
            memcpy((uint8_t *)appData.host, (void*)(httpDataBuff+nMAX_FIELD_NAME_LEN), strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN)));
            appData.host[strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN))] = 0; /* Terminate string */        
        }
        else if(!strcmp((char*)httpDataBuff, (const char*)"project_mqtt_id"))
        {
            memcpy((uint8_t *)appData.project_mqtt_id, (void*)(httpDataBuff+nMAX_FIELD_NAME_LEN), strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN)));
            appData.project_mqtt_id[strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN))] = 0; /* Terminate string */
        }
        else if(!strcmp((char*)httpDataBuff, (const char*)"user_mqtt_id"))
        {
            memcpy((uint8_t *)appData.user_mqtt_id, (void*)(httpDataBuff+nMAX_FIELD_NAME_LEN), strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN)));
            appData.user_mqtt_id[strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN))] = 0; /* Terminate string */
        }
        else if(!strcmp((char*)httpDataBuff, (const char*)"api_key"))
        {
            memcpy((uint8_t *)appData.api_key, (void*)(httpDataBuff+nMAX_FIELD_NAME_LEN), strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN)));
            appData.api_key[strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN))] = 0; /* Terminate string */
        }
        else if(!strcmp((char*)httpDataBuff, (const char*)"api_password"))
        {
            memcpy((uint8_t *)appData.api_password, (void*)(httpDataBuff+nMAX_FIELD_NAME_LEN), strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN)));
            appData.api_password[strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN))] = 0; /* Terminate string */
        }
        else if(!strcmp((char*)httpDataBuff, (const char*)"device_name"))
        {
            memcpy((uint8_t *)appData.device_name, (void*)(httpDataBuff+nMAX_FIELD_NAME_LEN), strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN)));
            appData.device_name[strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN))] = 0; /* Terminate string */
        }
        else if(!strcmp((char*)httpDataBuff, (const char*)"sensor_type"))
        {
            char sSensor_type[32];
            memcpy(sSensor_type, (void*)(httpDataBuff+nMAX_FIELD_NAME_LEN), strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN)));
            sSensor_type[strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN))] = 0; /* Terminate string */
            
            if(!strcmp(sSensor_type, (const char*)"none"))
            {
                appData.app_sensor_type = APP_SENSOR_TYPE_NONE;
            }
            else if(!strcmp(sSensor_type, (const char*)"pressure_click"))
            {
                appData.app_sensor_type = APP_SENSOR_TYPE_PRESSURE_CLICK;
            }
            else if(!strcmp(sSensor_type, (const char*)"air_quality_click"))
            {
                appData.app_sensor_type = APP_SENSOR_TYPE_AIR_QUALITY_CLICK;
            }
            else if(!strcmp(sSensor_type, (const char*)"humidity_click"))
            {
                appData.app_sensor_type = APP_SENSOR_TYPE_HUMIDITY_CLICK;
            }
            else if(!strcmp(sSensor_type, (const char*)"motion_click"))
            {
                appData.app_sensor_type = APP_SENSOR_TYPE_MOTION_CLICK;
            }
        }
        else if(!strcmp((char*)httpDataBuff, (const char*)"cc"))
        {
            memcpy((uint8_t *)appData.clientCert, (void*)(httpDataBuff+nMAX_FIELD_NAME_LEN), strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN)));
            appData.clientCert[strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN))] = 0; /* Terminate string */
        }
        else if(!strcmp((char*)httpDataBuff, (const char*)"ck"))
        {
            memcpy((uint8_t *)appData.clientKey, (void*)(httpDataBuff+nMAX_FIELD_NAME_LEN), strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN)));
            appData.clientKey[strlen((char*)(httpDataBuff+nMAX_FIELD_NAME_LEN))] = 0; /* Terminate string */
        }
    }

    if(bConfigFailure == false)
    {
        // All parsing complete!  Save new settings and force an interface restart
        // Set the interface to restart and display reconnecting information
        strcpy((char*)httpDataBuff, "reconnect.htm?");
        httpDataBuff[20+16] = 0x00; // Force null termination
        for(i = 20; i < 20u+16u; i++)
        {
            if(httpDataBuff[i] == ' ')
                httpDataBuff[i] = 0x00;
        }

    }
    else
    {   // Configuration error

        lastFailure = true;
        if(httpDataBuff)
        {
            strcpy((char*)httpDataBuff, "error.htm");
        }
    }

    TCPIP_HTTP_CurrentConnectionStatusSet(connHandle, HTTP_REDIRECT);

    SYS_CONSOLE_PRINT("App configuration - host '%s'\r\n", appData.host);
    SYS_CONSOLE_PRINT("App configuration - project_mqtt_id '%s'\r\n", appData.project_mqtt_id);
    SYS_CONSOLE_PRINT("App configuration - user_mqtt_id '%s'\r\n", appData.user_mqtt_id);
    SYS_CONSOLE_PRINT("App configuration - api_key '%s'\r\n", appData.api_key);
    SYS_CONSOLE_PRINT("App configuration - api_password '%s'\r\n", appData.api_password);
    SYS_CONSOLE_PRINT("App configuration - device_name '%s'\r\n", appData.device_name);
    SYS_CONSOLE_PRINT("App configuration - sensor_type '%d'\r\n", appData.app_sensor_type);
                            
    sprintf(appData.username, "%s/%s", appData.project_mqtt_id, appData.user_mqtt_id);
    sprintf(appData.password, "%s/%s", appData.api_key, appData.api_password);
    //sprintf(appData.publish_topic_name, "0/%s/%s/%s", appData.project_mqtt_id, appData.user_mqtt_id, appData.uuid);
    sprintf(appData.publish_topic_name, "0/%s/%s/%s", appData.project_mqtt_id, appData.user_mqtt_id, appData.device_name);
    //sprintf(appData.subscribe_topic_name, "1/%s/%s/%s/#", appData.project_mqtt_id, appData.user_mqtt_id, appData.uuid);
    sprintf(appData.subscribe_topic_name, "1/%s/%s/%s/#", appData.project_mqtt_id, appData.user_mqtt_id, appData.device_name);

    //TODO: Check is it safe if we force change state like this to support configure modify on fly
    appData.state = APP_TCPIP_WAIT_CONFIGURATION;
    
    return HTTP_IO_DONE;
}

#endif


/****************************************************************************
  Section:
    Dynamic Variable Callback Functions
  ***************************************************************************/
/****************************************************************************
  Section:
    Dynamic Variable Callback Functions
  ***************************************************************************/

/*****************************************************************************
  Function:
    void TCPIP_HTTP_Print_varname(void)

  Internal:
    See documentation in the TCP/IP Stack API or HTTP.h for details.
  ***************************************************************************/
void TCPIP_HTTP_Print_remoteServer(HTTP_CONN_HANDLE connHandle)
{
    TCP_SOCKET sktHTTP;
    sktHTTP = TCPIP_HTTP_CurrentConnectionSocketGet(connHandle);
    TCPIP_TCP_StringPut(sktHTTP, (const uint8_t*)appData.host);
}

void TCPIP_HTTP_Print_uuid(HTTP_CONN_HANDLE connHandle)
{
    TCP_SOCKET sktHTTP;
    sktHTTP = TCPIP_HTTP_CurrentConnectionSocketGet(connHandle);
    TCPIP_TCP_StringPut(sktHTTP, (const uint8_t*)appData.uuid); //nextSSID
}


#endif
