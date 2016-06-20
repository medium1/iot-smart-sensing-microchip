/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    app1.c

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

#include "app1.h"
#include "peripheral/cmp/plib_cmp.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************
struct switchMessage mySwitchMessage;
#define APP_LOW_VOLTAGE 630
#define APP_GOOD_VOLTAGE 650

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

APP1_DATA app1Data;
extern APP_DATA appData;
extern BSP_DATA bspData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************



// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void APP1_Initialize ( void )

  Remarks:
    See prototype in app1.h.
 */

void APP1_Initialize ( void )
{
    /* Place the App state machine in its initial state. */
    app1Data.state = APP1_STATE_INIT;
    BSP_Initialize();
    BSP_LED_LightShowSet(BSP_LED_CONNECTING_TO_AP);
    app1Data.newPotSamp = 0;
    app1Data.newAirSamp = 0;
    app1Data.potTimer = 0;
    app1Data.newVoltageSamp = 0;
    app1Data.currIsLVD = true;
    
    // Queue for switch data
    app1Data.switchQueue = xQueueCreate( 20, sizeof(mySwitchMessage) );
    if(app1Data.switchQueue == NULL) {
        ; // Handle this
    }
    // Queue for LED light show data
    // This will hold the requested Light Show state only
    app1Data.lightShowQueue = xQueueCreate( 1, 4 );
    if(app1Data.lightShowQueue == NULL) {
        ; // Handle this
    }
    // Queue for potentiometer data
    // This will hold the latest potentionmeter data
    app1Data.potentiometerQueue = xQueueCreate( 20, sizeof(app1Data.potValue) );
    if(app1Data.potentiometerQueue == NULL) {
        ; // Handle this
    }
    // Queue for air quality data
    // This will hold the latest air quality data
    app1Data.airqualityQueue = xQueueCreate( 20, sizeof(app1Data.airValue) );
    if(app1Data.airqualityQueue == NULL) {
        ; // Handle this
    }
    app1Data.pressureQueue = xQueueCreate( 20, sizeof(app1Data.pressureValue) );
    if(app1Data.pressureQueue == NULL) {
        ; // Handle this
    }
    xQueueReset(app1Data.switchQueue);
    xQueueReset(app1Data.lightShowQueue);
    xQueueReset(app1Data.potentiometerQueue);
	 xQueueReset(app1Data.airqualityQueue);
	 xQueueReset(app1Data.pressureQueue);
}

 

/*******************************************************************************
 End of File
 */
