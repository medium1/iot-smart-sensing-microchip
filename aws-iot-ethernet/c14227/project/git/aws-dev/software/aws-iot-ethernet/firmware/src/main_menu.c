#include <stdio.h>
#include "app.h"


// Function Declarations
void write_read_address_menu(char inkey);
void store_key_history(void);
void disp_key_history_value(int up_down, int mode);
void log_key_value(void);
void display_main_menu(void);
void process_menus(char inkey);
#ifndef TRUE
	#define TRUE  1
#endif
#ifndef FALSE
	#define FALSE 0
#endif
#define FIRMWARE_VERSION_LABLE "v1.01"
#define READ_WRITE_MEMORY_ADDRESS 0
#define DISPLAY_MENU 1
#define QUEUE_DEPTH 50
#define KEY_UP 0
#define KEY_DOWN 1

// Data Declarations
unsigned int inputaddressvalue, inputwritevalue,incharid,inchar_add_offset,menuid,debug_flag;
char inkeyc,validConfig = 0;
static unsigned int history_inputaddressvalue[QUEUE_DEPTH], history_inputwritevalue[QUEUE_DEPTH];
static int lastinvalue[10], historylogid = 0, historydispid = 0, history_active = FALSE;
extern APP_DATA appData;
/*======================================================================
|    @function: write_read_address_menu(char inkey)
|
|----------------------------------------------------------------------
|    Purpose: display read register menu according to inkey
|
|    Additional Comments:
|    @param param1  - inkey
|
|    @return        - none
|    @assumptions -
|    4/19/2016 Fai Cheng
|---------------------------------------------------------------------*/
void write_read_address_menu(char inkey)
{
	int i=(int)(inkey), hexvalue=-1;
	//SYS_CONSOLE_PRINT("\nwrite_read_address_menu inkey=0x%x\n",i);
	switch (i)
	{
		case 0x7a:
			SYS_CONSOLE_PRINT("e.g. 1234r, 123a=56w, q to quit");
			incharid = 0;
			inputaddressvalue = 0;
			inputwritevalue = 0;
			inchar_add_offset = 0;
			historydispid=historylogid;
			break;
		case 0x30:
		case 0x31:
		case 0x32:
		case 0x33:
		case 0x34:	// 0-9
		case 0x35:
		case 0x36:
		case 0x37:
		case 0x38:
		case 0x39:
			hexvalue = i - 0x30;
			if (hexvalue == -1)
				hexvalue = i - 0x61 + 10;
			lastinvalue[incharid] = hexvalue;
			incharid++;
			break;
		case 0x3D: // '='
			for (i=0; i<incharid; i++)
			{
				inputaddressvalue += lastinvalue[i] << ((incharid-i-1) * 4);
			}
			log_key_value();
			inchar_add_offset=incharid;
			break;
		case 0x61:
		case 0x62:
		case 0x63:	// a-f
		case 0x64:
		case 0x65:
		case 0x66:
			if (hexvalue == -1)
				hexvalue = i - 0x61 + 10;
			lastinvalue[incharid] = hexvalue;
			incharid++;
			//SYS_CONSOLE_PRINT("B %c incharid=%x inputaddressvalue=%x",inkey,incharid,inputaddressvalue);
			break;
		case 0x72: //'r'
			for (i=0; i<incharid; i++)
			{
				inputaddressvalue += lastinvalue[i] << ((incharid-i-1) * 4);
			}
			log_key_value();
			//SYS_CONSOLE_PRINT("\nAddr 0x%x=0x%x\n",inputaddressvalue,registerRead(inputaddressvalue));
			incharid = 0;
			inputaddressvalue = 0;
			inputwritevalue = 0;
			break;
		case 0x77: //'w'
			for (i=inchar_add_offset; i<incharid; i++)
			{
				inputwritevalue += lastinvalue[i] << ((incharid-i-1) * 4);
			}
			log_key_value();
			//registerWrite(inputaddressvalue,inputwritevalue);
			//SYS_CONSOLE_PRINT("\nAddr 0x%x=0x%x indata=0x%x\n",inputaddressvalue,registerRead(inputaddressvalue),inputwritevalue);
			incharid = 0;
			inchar_add_offset = 0;
			inputaddressvalue = 0;
			inputwritevalue = 0;
			break;
		case 0x5b:
			disp_key_history_value(KEY_UP, READ_WRITE_MEMORY_ADDRESS);
			break;
		case 0x5d:
			disp_key_history_value(KEY_DOWN, READ_WRITE_MEMORY_ADDRESS);
			break;
			//case 27:
		case 0x71: //'q'
			display_main_menu();
			menuid=MAIN_MENU;
			break;
	}
}

/*======================================================================
|    @function: store_key_history(void)
|
|----------------------------------------------------------------------
|    Purpose: store key history
|
|    Additional Comments:
|    @param param1  - none
|
|    @return        - none
|    @assumptions -
|    4/20/2016 Fai Cheng
|---------------------------------------------------------------------*/
void store_key_history(void)
{
	history_inputaddressvalue[historylogid] = inputaddressvalue;
	history_inputwritevalue[historylogid] = inputwritevalue;
	//SYS_CONSOLE_PRINT("\nReg 0x%x historylogid=%x\n",history_inputaddressvalue[historylogid],historylogid);
	historylogid++;
	if (historylogid == QUEUE_DEPTH)
		historylogid = 0;
}

/*======================================================================
|    @function: disp_key_history_value(int up_down, int mode)
|
|----------------------------------------------------------------------
|    Purpose: display key history
|
|    Additional Comments:
|    @param param1  - arrow up or down
|
|    @return        - none
|    @assumptions -
|    4/20/2016 Fai Cheng
|---------------------------------------------------------------------*/
void disp_key_history_value(int up_down, int mode)
{
	if (up_down == KEY_UP)
	{
		historydispid--;
		if (historydispid < 0)
			historydispid = QUEUE_DEPTH - 1;
	}
	else
	{
		historydispid++;
		if (historydispid == QUEUE_DEPTH)
			historydispid = 0;
	}
	if (mode == READ_WRITE_MEMORY_ADDRESS)
	{
		SYS_CONSOLE_PRINT("Reg 0x%x historydispid=%x\n", history_inputaddressvalue[historydispid], historydispid);
		inputaddressvalue = history_inputaddressvalue[historydispid];
	}
	history_active = TRUE;
}

/*======================================================================
|    @function: process_menus(char inkey)
|
|----------------------------------------------------------------------
|    Purpose: print menu according to inkey
|
|    Additional Comments:
|    @param param1  - inkey
|
|    @return        - none
|    @assumptions -
|    4/16/2016 Fai Cheng
|---------------------------------------------------------------------*/
void process_menus(char inkey)
{
	switch (menuid)
	{
		case MAIN_MENU:
			switch (inkey)
			{
				case  ' ':
					menuid=MAIN_MENU;	// FCKE0A pin R20 = SDR_MEM_CKE[0]
					break;
				case  '1':
					appData.state = APP_TCPIP_WAIT_CONFIGURATION;
					sprintf(appData.host, "mqtt.mediumone.com"); 
					sprintf(appData.project_mqtt_id, "4ZNl9dzePwU"); 
					sprintf(appData.user_mqtt_id, "aePcZNfE1M8"); 
					sprintf(appData.api_key, "K7MSXC435WPI2XABY2RK3CZQGNQTMNLCGFSDMZRQGQ4DAMBQ"); 
					sprintf(appData.api_password, "Microchip!123"); 
					sprintf(appData.device_name, "motion0002"); 
					appData.app_sensor_type=APP_SENSOR_TYPE_MOTION_CLICK;
					appData.port=AWS_IOT_PORT;
					validConfig = 1;
					break;
				case  '2':
					appData.state = APP_TCPIP_WAIT_CONFIGURATION;
					sprintf(appData.host, "mqtt.mediumone.com"); 
					sprintf(appData.project_mqtt_id, "4ZNl9dzePwU"); 
					sprintf(appData.user_mqtt_id, "aePcZNfE1M8"); 
					sprintf(appData.api_key, "K7MSXC435WPI2XABY2RK3CZQGNQTMNLCGFSDMZRQGQ4DAMBQ"); 
					sprintf(appData.api_password, "Microchip!123"); 
					sprintf(appData.device_name, "motion0002"); 
					appData.app_sensor_type=APP_SENSOR_TYPE_AIR_QUALITY_CLICK;
					appData.port=AWS_IOT_PORT;
					validConfig = 1;
					break;
				case  '3':
					appData.state = APP_TCPIP_WAIT_CONFIGURATION;
					sprintf(appData.host, "mqtt.mediumone.com"); 
					sprintf(appData.project_mqtt_id, "4ZNl9dzePwU"); 
					sprintf(appData.user_mqtt_id, "aePcZNfE1M8"); 
					sprintf(appData.api_key, "K7MSXC435WPI2XABY2RK3CZQGNQTMNLCGFSDMZRQGQ4DAMBQ"); 
					sprintf(appData.api_password, "Microchip!123"); 
					sprintf(appData.device_name, "motion0002"); 
					appData.app_sensor_type=APP_SENSOR_TYPE_PRESSURE_CLICK;
					appData.port=AWS_IOT_PORT;
					validConfig = 1;
					break;
				case  '4':
					appData.state = APP_TCPIP_WAIT_CONFIGURATION;
					sprintf(appData.host, "mqtt.mediumone.com"); 
					sprintf(appData.project_mqtt_id, "4ZNl9dzePwU"); 
					sprintf(appData.user_mqtt_id, "aePcZNfE1M8"); 
					sprintf(appData.api_key, "K7MSXC435WPI2XABY2RK3CZQGNQTMNLCGFSDMZRQGQ4DAMBQ"); 
					sprintf(appData.api_password, "Microchip!123"); 
					sprintf(appData.device_name, "motion0002"); 
					appData.app_sensor_type=APP_SENSOR_TYPE_HUMIDITY_CLICK;
					appData.port=AWS_IOT_PORT;
					validConfig = 1;
					break;
				case  '5':
					break;
				case  '6':
					break;
				case  '7':
					break;
				case  '8':
					if (debug_flag)
						debug_flag=0;
					else
						debug_flag=1;
					break;
				case  '9':
					break;
				case  'a':
					break;
				case  'b':
					break;
				case  'c':
					break;
				case  'd':
					break;
				case  'e':
					break;
				case  'f':
					break;
				case  'g':
					break;
				case  'h':
					break;
				case  'i':
					break;
				case  'j':
					menuid = READ_WRITE_MEMORY_ADDRESS;
					write_read_address_menu(DISPLAY_MENU);
					break;
				case  0x1b:
					display_main_menu();
					break;
			}
			//display_main_menu();
			break;
	}
}
/*======================================================================
|    @function: log_key_value(void)
|
|----------------------------------------------------------------------
|    Purpose: store key history
|
|    Additional Comments:
|    @param param1  - none
|
|    @return        - none
|    @assumptions -
|    4/20/2016 Fai Cheng
|---------------------------------------------------------------------*/
void log_key_value(void)
{
	history_inputaddressvalue[historylogid] = inputaddressvalue;
	history_inputwritevalue[historylogid] = inputwritevalue;
	historylogid++;
	if (historylogid == QUEUE_DEPTH)
		historylogid = 0;
}

/*======================================================================
|    @function: display_main_menu(void)
|
|----------------------------------------------------------------------
|    Purpose: menu display
|
|    Additional Comments:
|    @param param1  - none
|
|    @return        - none
|    @assumptions -
|    4/12/2016 Fai Cheng
|---------------------------------------------------------------------*/
void display_main_menu(void)
{
	SYS_CONSOLE_PRINT("Main Menu %s : %s %s\r\n",FIRMWARE_VERSION_LABLE,__DATE__,__TIME__);
	SYS_CONSOLE_MESSAGE("1. Send MQTT request to mqtt.mediumone.com Motion Click\r\n");
	SYS_CONSOLE_MESSAGE("2. Send MQTT request to mqtt.mediumone.com Air Quality Click\r\n");
	SYS_CONSOLE_MESSAGE("3. Send MQTT request to mqtt.mediumone.com Pressure Click\r\n");
	SYS_CONSOLE_MESSAGE("4. Send MQTT request to mqtt.mediumone.com Humidity Click\r\n");
}
