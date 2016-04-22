/*******************************************************************************
 * Project name:
     Temp&Hum click
 * Copyright:
     (c) Mikroelektronika, 2015
 * Revision History:
     20150908:
       - initial release (DM);
 * Description:
    Temp&Hum click carries ST’s HTS221 temperature and relative humidity sensor.
    The board communicates with the target MCU through mikroBUSI2C interface,
    with an additional interrupt (INT). Designed to use a 3.3V power supply only.
    This example demonstrates usage of the Temp&Hum click. It
    establishes I2C bus communication with HTS221 chip, and writes temperature
    and humidity data on TFT display.
 * Test configuration:
     MCU:             STM32F107VC
                      http://www.st.com/st-web-ui/static/active/en/resource/technical/document/reference_manual/CD00171190.pdf
     Dev. Board:      EasyMx PRO v7 for STM32
                      http://www.mikroe.com/eng/products/view/852/easymx-pro-v7-for-stm32/
     Ext.modules      Temp&Hum Click
                      http://www.mikroe.com/click/temp-hum/
     Oscillator:      HS-PLL 72.0000 MHz
                      http://www.mikroe.com/store/components/displays/
     SW:              mikroC PRO for ARM
                      http://www.mikroe.com/mikroc/arm/
 * NOTES:
     - Place Temp&Hum click board at the mikroBUS socket 1 on the EasyMx Pro v7 board.
     - Put EasyTFT in its socket, turn on backlight using the SW11.3, and backlight PWM using the SW11.4.
*******************************************************************************/

#include "resources.h"

#define HTS221_I2C_ADDR   0x5F                                                  // HTS221 I2C slave address

#define MaxTemp       120
#define MinTemp       -40
#define MaxHumi       100
#define MinHumi       0

//Variables
char tmp_data[16];
char txt[10];
char old_txt[10];
char old_txt1[10];
char lab1[10] = {0};
char lab2[10] = {0};
char res;

char H0_rH_x2;
char H1_rH_x2;
unsigned int T0_degC_x8;
unsigned int T1_degC_x8;

int H0_T0_OUT;
int H1_T0_OUT;
int T0_OUT;
int T1_OUT;

float T0_DegC_cal;
float T1_DegC_cal;
float H0_RH_cal;
float H1_RH_cal;

float Temperature;
float Humidity;

// TFT module connections
unsigned int TFT_DataPort at GPIOE_ODR;
sbit TFT_RST at GPIOE_ODR.B8;
sbit TFT_RS at GPIOE_ODR.B12;
sbit TFT_CS at GPIOE_ODR.B15;
sbit TFT_RD at GPIOE_ODR.B10;
sbit TFT_WR at GPIOE_ODR.B11;
sbit TFT_BLED at GPIOE_ODR.B9;
// End TFT module connections

/*******************************************************************************
* Function Display_Init()
* ------------------------------------------------------------------------------
* Overview: Function initialize display
* Input: Nothing
* Output: Nothing
*******************************************************************************/
static void Display_Init(){
  TFT_Init_ILI9341_8bit(320, 240);
  TFT_Set_Pen(CL_WHITE, 1);
  TFT_Set_Brush(1,CL_WHITE,0,0,0,0);
  TFT_Set_Font(TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
  TFT_Fill_Screen(CL_WHITE);
  TFT_Set_Pen(CL_Black, 1);
  TFT_Line(20, 220, 300, 220);
  TFT_LIne(20,  46, 300,  46);
  TFT_Set_Font(&HandelGothic_BT21x22_Regular, CL_RED, FO_HORIZONTAL);
  TFT_Write_Text("Temp&Hum   click", 85, 14);
  TFT_Set_Font(&Verdana12x13_Regular, CL_BLACK, FO_HORIZONTAL);
  TFT_Write_Text("EasyMx PRO v7 for STM32", 19, 223);
  TFT_Set_Font(&Verdana12x13_Regular, CL_RED, FO_HORIZONTAL);
  TFT_Write_Text("www.mikroe.com", 200, 223);
  TFT_Set_Font(&TFT_defaultFont, CL_BLACK, FO_HORIZONTAL);
  TFT_Image(20, 75, TempHum_bmp, 1);
}
/*******************************************************************************
* Function HTS221_Calibration()
* ------------------------------------------------------------------------------
* Overview: Reads calibration values from HTS221
* Input: Nothing
* Output: Nothing
*******************************************************************************/
void HTS221_Calibration(void)
{
  tmp_data[0] = 0xB0;
  I2C1_Start();
  I2C1_Write(HTS221_I2C_ADDR,tmp_data,1,END_MODE_RESTART);
  I2C1_Read(HTS221_I2C_ADDR,tmp_data,16,END_MODE_STOP);

  H0_rH_x2 = tmp_data[0];
  H1_rH_x2 = tmp_data[1];
  T0_degC_x8 = ((tmp_data[5] & 0x03) << 8) + tmp_data[2];
  T1_degC_x8 = ((tmp_data[5] & 0x0C) << 6) + tmp_data[3];
  
  H0_T0_OUT = (tmp_data[7] << 8) + tmp_data[6];
  H1_T0_OUT = (tmp_data[11] << 8) + tmp_data[10];
  T0_OUT = (tmp_data[13] << 8) + tmp_data[12];
  T1_OUT = (tmp_data[15] << 8) + tmp_data[14];

  // convert negative 2's complement values to native negative value
  if (H0_T0_OUT&0x8000) H0_T0_OUT = -(0x8000-(0x7fff&H0_T0_OUT));
  if (H1_T0_OUT&0x8000) H1_T0_OUT = -(0x8000-(0x7fff&H1_T0_OUT));
  if (T0_OUT&0x8000) T0_OUT = -(0x8000-(0x7fff&T0_OUT));
  if (T1_OUT&0x8000) T1_OUT = -(0x8000-(0x7fff&T1_OUT));

  T0_DegC_cal = (float) T0_degC_x8/8;
  T1_DegC_cal = (float) T1_degC_x8/8;
  H0_RH_cal = (float) H0_rH_x2/2;
  H1_RH_cal = (float) H1_rH_x2/2;
}
/*******************************************************************************
* Function linear_interpolation(int x0, float y0, int x1, float y1, float mes)
* ------------------------------------------------------------------------------
* Overview: Function performs linear interpolation on sensors data
* Input: Nothing
* Output: Temperature data
*******************************************************************************/
float linear_interpolation(int x0, float y0, int x1, float y1, float mes)
{
   float a = (float) ((y1 - y0) / (x1 - x0));
   float b = (float) (-a*x0 + y0);
   float cal = (float) (a * mes + b);
   return cal;
}
/*******************************************************************************
* Function HTS221_Init()
* ------------------------------------------------------------------------------
* Overview: Initializes HTS221 Temperature and Humidity sensor
* Input: Nothing
* Output: Nothig
*******************************************************************************/
void HTS221_init(){
  I2C1_Start();
  tmp_data[0] = 0x10;
  tmp_data[1] = 0x1B;
  I2C1_Write(HTS221_I2C_ADDR,tmp_data,2,END_MODE_RESTART);
  tmp_data[0] = 0x20;
  tmp_data[1] = 0x85;
  I2C1_Write(HTS221_I2C_ADDR,tmp_data,2,END_MODE_RESTART);
  tmp_data[0] = 0x21;
  tmp_data[1] = 0x00;
  I2C1_Write(HTS221_I2C_ADDR,tmp_data,2,END_MODE_RESTART);
  tmp_data[0] = 0x22;
  tmp_data[1] = 0x00;
  I2C1_Write(HTS221_I2C_ADDR,tmp_data,2,END_MODE_STOP);
}
/*******************************************************************************
* Function Get_Temperature_and_Humidity()
* ------------------------------------------------------------------------------
* Overview: Function gets temperature and humidity data from HTS221 sensor
* Input: Nothing
* Output: Nothing
*******************************************************************************/
void Get_Temperature_and_Humidity() {
  int H_OUT;
  int T_OUT;

  tmp_data[0] = 0xA8;
  I2C1_Start();
  I2C1_Write(HTS221_I2C_ADDR,tmp_data,1,END_MODE_RESTART);
  I2C1_Read(HTS221_I2C_ADDR,tmp_data,4,END_MODE_STOP);
  
  H_OUT = (tmp_data[1] << 8) + tmp_data[0];
  T_OUT = (tmp_data[3] << 8) + tmp_data[2];

  if (H_OUT&0x8000) H_OUT = -(0x8000-(0x7fff&H_OUT));
  if (T_OUT&0x8000) T_OUT = -(0x8000-(0x7fff&T_OUT));
  
  Temperature = linear_interpolation(T0_OUT, T0_DegC_cal, T1_OUT, T1_DegC_cal, T_OUT);
  Humidity = linear_interpolation(H0_T0_OUT, H0_RH_cal, H1_T0_OUT, H1_RH_cal, H_OUT);
  
  // Constraint for measurement after calibration
  if ((int)Humidity>MaxHumi-1 | (int)Humidity==-72) Humidity = MaxHumi;
  if ((int)Humidity<MinHumi ) Humidity = MinHumi;
  if ((int)Temperature>MaxTemp-1) Temperature = MaxTemp;
  if ((int)Temperature<MinTemp ) Temperature = MinTemp;
}
/*******************************************************************************
* Function updateLabel(char *newText, int x, int y, char* lbl)
* ------------------------------------------------------------------------------
* Overview: Function writes text on display and erase old text
* Input: Nothing
* Output: Nothing
*******************************************************************************/
void updateLabel(char *newText, int x, int y, char* lbl){
  TFT_Set_Font(&Tahoma52x52_Bold, CL_WHITE, FO_HORIZONTAL);                     // Color of background
  TFT_Write_Text(lbl, x, y);                                                    // Write text on TFT display with background color
  strcpy(lbl, newText);                                                         // Copy newText to lbl
  TFT_Set_Font(&Tahoma52x52_Bold, CL_BLACK, FO_HORIZONTAL);                     // Color of text
  TFT_Write_Text(lbl, x, y);                                                    // Write text on  TFT display with black color
}
//******************************************************************************
// Main function
//******************************************************************************
void main() {
  Display_Init();                                                               // Display initialization

  I2C1_Init_Advanced(400000, &_GPIO_MODULE_I2C1_PB67);                          // I2C1 initialization
  delay_ms(200);                                                                // Delay (200 ms)
  
  HTS221_init();                                                                // HTS221 initialization
  HTS221_Calibration();                                                         // Gets calibration data from HTS221 temeprature and Humidity sensor

  while(1){
  Get_Temperature_and_Humidity();                                               // Read Temperature and Humidity data
  
  sprintf(txt, "%2.1f", Temperature);                                           // Format Temperature data and store it to txt
  res = strcmp(txt,old_txt);                                                    // Compare old_txt and txt
  if(res != 0){                                                                 // If old_txt and txt are not equal
  updateLabel(txt, 130, 70, lab1);                                              // Write Temperature data on display
  TFT_Write_Char(0xBA,225,70);                                                  // Write º character on TFT display
  TFT_Write_Char(0x43,250,70);                                                  // Write C character on TFT display
  strcpy(old_txt,txt);                                                          // Copy txt to old_txt string array
  }

  sprintf(txt, "%2.1f", Humidity);                                              // Format Humdity data and store it to txt
  res = strcmp(txt,old_txt1);                                                   // Compare old_txt1 and txt
  if(res != 0){                                                                 // If old_txt1 and txt are not equal
  updateLabel(txt, 130, 130, lab2);                                             // Write Humidity data on display
  TFT_Write_Char(0x25,225,130);                                                 // Write % character on TFT display
  strcpy(old_txt1,txt);                                                         // Copy txt to old_txt1 string array
  }
  
  delay_ms(1000);                                                               // Delay (1000 ms)
  }
}
/*******************************************************************************
*** End of File
*******************************************************************************/