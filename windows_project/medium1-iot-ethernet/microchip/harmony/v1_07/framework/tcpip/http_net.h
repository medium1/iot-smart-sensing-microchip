/*******************************************************************************
  HTTP Headers for Microchip TCP/IP Stack

  Company:
    Microchip Technology Inc.
    
  File Name:
    http_net.h

  Summary:
    The HTTP web server module together with a file system (SYS_FS) allow
    the board to act as a web server.
    This module uses the network presentation layer to allow for encrypted 
    connections.
    
  Description:
    The HTTP module runs a web server within the TCP/IP stack.
    This facilitates an easy method to view status information
    and control applications using any standard web browser.

*******************************************************************************/
//DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright 2015 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED AS IS WITHOUT WARRANTY OF ANY KIND,
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

#ifndef __HTTP_NET_H_
#define __HTTP_NET_H_

#include "system/fs/sys_fs.h"
#include "net/pres/net_pres.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END  

// *****************************************************************************
// *****************************************************************************
// Section: Commands and Server Responses
// *****************************************************************************
// *****************************************************************************

//******************************************************************************

//Supported Commands and Server Response Codes
typedef enum
{
    TCPIP_HTTP_NET_STAT_GET = 0u,               // GET command is being processed
    TCPIP_HTTP_NET_STAT_POST,                   // POST command is being processed
    TCPIP_HTTP_NET_STAT_BAD_REQUEST,            // 400 Bad Request will be returned
    TCPIP_HTTP_NET_STAT_UNAUTHORIZED,           // 401 Unauthorized will be returned
    TCPIP_HTTP_NET_STAT_NOT_FOUND,              // 404 Not Found will be returned
    TCPIP_HTTP_NET_STAT_OVERFLOW,               // 414 Request-URI Too Long will be returned
    TCPIP_HTTP_NET_STAT_INTERNAL_SERVER_ERROR,  // 500 Internal Server Error will be returned
    TCPIP_HTTP_NET_STAT_NOT_IMPLEMENTED,        // 501 Not Implemented (not a GET or POST command)
    TCPIP_HTTP_NET_STAT_REDIRECT,               // 302 Redirect will be returned
    TCPIP_HTTP_NET_STAT_TLS_REQUIRED,           // 403 Forbidden is returned, indicating 
                                                // TLS is required
    TCPIP_HTTP_NET_STAT_UPLOAD_FORM,            // Show the Upload form
    TCPIP_HTTP_NET_STAT_UPLOAD_STARTED,         // An upload operation is being processed
    TCPIP_HTTP_NET_STAT_UPLOAD_OK,              // An Upload was successful
    TCPIP_HTTP_NET_STAT_UPLOAD_ERROR,           // An Upload was not a valid image

} TCPIP_HTTP_NET_STATUS;

// *****************************************************************************
// *****************************************************************************
// Section: HTTP Definitions
// *****************************************************************************
// *****************************************************************************

//******************************************************************************

// Result states for execution callbacks
typedef enum
{
    TCPIP_HTTP_NET_IO_RES_DONE = 0u,  // Finished with procedure
    TCPIP_HTTP_NET_IO_RES_NEED_DATA,  // More data needed to continue, call again later
    TCPIP_HTTP_NET_IO_RES_WAITING,    // Waiting for asynchronous process to complete, 
                                      // call again later
    TCPIP_HTTP_NET_IO_RES_ERROR,      // Some error has occurred, operation will be aborted

} TCPIP_HTTP_NET_IO_RESULT;

// Result states for  TCPIP_HTTP_NET_ConnectionPostNameRead, TCPIP_HTTP_NET_ConnectionPostValueRead 
// and TCPIP_HTTP_NET_ConnectionPostReadPair

typedef enum
{
    TCPIP_HTTP_NET_READ_OK = 0,       // Read was successful
    TCPIP_HTTP_NET_READ_TRUNCATED,    // Buffer overflow prevented by truncating value
    TCPIP_HTTP_NET_READ_INCOMPLETE    // Entire object is not yet in the buffer.  
                                      // Try again later.

} TCPIP_HTTP_NET_READ_STATUS;


// *****************************************************************************
/*
  Enumeration:
    TCPIP_HTTP_NET_EVENT_TYPE

  Summary:
    HTTP reported run-time events.

  Description:
    This enumeration defines the types of the HTTP reported events
    when processing dynamic variables, files, etc.
   
  Remarks:
    Multiple warnings can be set simultaneously.

*/
typedef enum
{
    /* no event */
    TCPIP_HTTP_NET_EVENT_NONE                           = 0,

    /* an error occurred when opening a HTTP file */
    TCPIP_HTTP_NET_EVENT_FILE_OPEN_ERROR,

    /* a file name was not specified */
    TCPIP_HTTP_NET_EVENT_FILE_NAME_ERROR,

    /* a file name was longer than the HTTP storage space */
    TCPIP_HTTP_NET_EVENT_FILE_NAME_SIZE_ERROR,

    /* file size error */
    TCPIP_HTTP_NET_EVENT_FILE_SIZE_ERROR,

    /* file read error */
    TCPIP_HTTP_NET_EVENT_FILE_READ_ERROR,

    /* file parse error: line too long */
    TCPIP_HTTP_NET_EVENT_FILE_PARSE_ERROR,

    /* the depth allowed for a recursive call was exceeded */
    TCPIP_HTTP_NET_EVENT_DEPTH_ERROR,

    /* an error occurred when parsing: dynamic variable name terminator could not be found */
    TCPIP_HTTP_NET_EVENT_DYNVAR_NO_TERM_ERROR,

    /* a write error was reported while performing an FS upload */
    TCPIP_HTTP_NET_EVENT_FS_WRITE_ERROR,

    /* a write error was reported while mounting after an FS upload */
    TCPIP_HTTP_NET_EVENT_FS_MOUNT_ERROR,
    
    /* Notification that a FS upload operation was completed successfully */
    TCPIP_HTTP_NET_EVENT_FS_UPLOAD_COMPLETE,

    /* Dynamic variable warnings. Multiple flags could be set */

    /* warning: dynamic variable name too long, truncated */
    TCPIP_HTTP_NET_EVENT_DYNVAR_NAME_TRUNCATED          = 0x8001,

    /* warning: a dynamic variable argument name too long, truncated */
    TCPIP_HTTP_NET_EVENT_DYNVAR_ARG_NAME_TRUNCATED      = 0x8002,

    /* warning: too many arguments for a dynamic variable, truncated */
    TCPIP_HTTP_NET_EVENT_DYNVAR_ARG_NUMBER_TRUNCATED    = 0x8004,

    /* Other run-time warnings */

    /* warning: allocation from the HTTP dynamic variables processing pool failed */
    /* (the allocation will be retried) */
    TCPIP_HTTP_NET_EVENT_POOL_EMPTY                     = 0x8010,

    /* warning: the HTTP peek buffer is too small and cannot contain */
    /* all the data available in the transport socket buffer */
    /* and a HTTP search operation may fail */
    /* This will happen only for transport sockets that do not support */
    /* peek operation with an offset parameter */
    TCPIP_HTTP_NET_EVENT_PEEK_BUFFER_SIZE_EXCEEDED      = 0x8020,


}TCPIP_HTTP_NET_EVENT_TYPE;


// HTTP connection identifier, handle of a HTTP connection
typedef const void*     TCPIP_HTTP_NET_CONN_HANDLE;

// HTTP module configuration flags
// Multiple flags can be OR-ed
typedef enum
{
    TCPIP_HTTP_NET_MODULE_FLAG_DEFAULT              = 0x00,     // Default flags value

    TCPIP_HTTP_NET_MODULE_FLAG_NON_PERSISTENT       = 0x01,     // Use non-persistent connections
                                                                // This flag will cause the HTTP 
                                                                // connections to be non-persistent
                                                                // and closed after serving each request 
                                                                // to the client
                                                                // By default the HTTP connections are persistent
    TCPIP_HTTP_NET_MODULE_FLAG_NO_DELAY             = 0x02,     // Create the HTTP sockets with NO-DELAY option.
                                                                // It will flush data as soon as possible.
    TCPIP_HTTP_NET_MODULE_FLAG_SECURE_ON            = 0x10,     // All HTTP connections have to be secure
                                                                // (supposing the network presentation layer 
                                                                // supports encryption)
                                                                // Cannot be used together with 
                                                                // TCPIP_HTTP_NET_MODULE_FLAG_SECURE_OFF

    TCPIP_HTTP_NET_MODULE_FLAG_SECURE_OFF           = 0x20,     // HTTP connections will be non-secure
                                                                // Cannot be used together with 
                                                                // TCPIP_HTTP_NET_MODULE_FLAG_SECURE_ON

    TCPIP_HTTP_NET_MODULE_FLAG_SECURE_DEFAULT       = 0x00,     //  HTTP security is based on the port numbers

}TCPIP_HTTP_NET_MODULE_FLAGS;

// HTTP module dynamic configuration data
typedef struct
{
    uint16_t    nConnections;   // number of simultaneous HTTP connections allowed
    uint16_t    dataLen;        // size of the data buffer for reading cookie and GET/POST arguments (bytes)
    uint16_t    sktTxBuffSize;  // size of TX buffer for the associated socket; leave 0 for default
    uint16_t    sktRxBuffSize;  // size of RX buffer for the associated socket; leave 0 for default
    uint16_t    listenPort;     // HTTP listening port: 80, 443, etc.
    uint16_t    nDescriptors;   // how many buffers descriptors for dynamic variable processing to create
                                // they are independent of the HTTP connection number
                                // all the HTTP connections use from the dynamic descriptors pool
    uint16_t    nChunks;        // maximum number of chunks that are created
                                // It depends on the TCPIP_HTTP_NET_MAX_RECURSE_LEVEL and
                                // on the number of connections
                                // Maximum number should be TCPIP_HTTP_NET_MAX_CONNECTIONS * TCPIP_HTTP_NET_MAX_RECURSE_LEVEL
                                // All the chunks are in a pool and are used by all connections                                 
    uint16_t    maxRecurseLevel;// The maximum depth of recursive calls for serving a web page:
                                // - files without dynvars: 1
                                // - file including another file: + 1
                                // - file including a dynamic variable: + 1
                                // etc.
    uint16_t    configFlags;    // a TCPIP_HTTP_NET_MODULE_FLAGS value.

} TCPIP_HTTP_NET_MODULE_CONFIG;

// *****************************************************************************
// *****************************************************************************
// Section: Function Prototypes
// *****************************************************************************
// *****************************************************************************

//*****************************************************************************
/*
  Function:
    uint8_t* TCPIP_HTTP_NET_URLDecode(uint8_t* cData)

  Summary:
    Parses a string from URL encoding to plain text.

  Description:
    This function parses a string from URL encoding to plain text.  The following
    conversions are made: �=� to �\0�, �&� to �\0�, �+� to � �, and
    �%xx� to a single hex byte.

    After completion, the data has been decoded and a null terminator
    signifies the end of a name or value.  A second null terminator (or a
    null name parameter) indicates the end of all the data.

  Precondition:
    The data parameter is null terminated and has at least one extra
    byte free.

  Parameters:
    cData - The string which is to be decoded in place.

  Returns:
    A pointer to the last null terminator in data, which is also the
    first free byte for new data.

  Remarks:
    This function is called by the stack to parse GET arguments and
    cookie data.  User applications can use this function to decode POST
    data, but first need to verify that the string is null-terminated.
 */
uint8_t*  TCPIP_HTTP_NET_URLDecode(uint8_t* cData);


//*****************************************************************************
/*
  Function:
    const uint8_t* TCPIP_HTTP_NET_ArgGet(const uint8_t* cData, const uint8_t* cArg)

  Summary:
    Locates a form field value in a given data array.

  Description:
    This function searches through a data array to find the value associated with a
    given argument.  It can be used to find form field values in data
    received over GET or POST.

    The end of data is assumed to be reached when a null name parameter is
    encountered.  This requires the string to have an even number of
    null-terminated strings, followed by an additional null terminator.

  Precondition:
    The data array has a valid series of null terminated name/value pairs.

  Parameters:
    cData - the buffer to search
    cArg - the name of the argument to find

  Returns:
    A pointer to the argument value, or NULL if not found.

  Example:
  <code>
    TCPIP_HTTP_NET_DynPrint(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const TCPIP_HTTP_DYN_VAR_DCPT* 
                            varDcpt, const TCPIP_HTTP_NET_USER_CALLBACK* pCBack)
    {
        const uint8_t *ptr;

        ptr = TCPIP_HTTP_NET_ArgGet(TCPIP_HTTP_NET_ConnectionDataBufferGet(connHandle), 
                                   (const uint8_t*)"name");
        if(ptr == 0)
        {
            ptr = "not set";
        }
        else
        {
            strncpy(myBuffer, ptr, sizeof(myBuffer));
            ptr = myBuffer;
        }

        TCPIP_HTTP_NET_DynamicWrite(varDcpt, ptr, strlen(ptr), false);
            
    }
  </code>

  Remarks:
    None.
 */
const uint8_t*      TCPIP_HTTP_NET_ArgGet(const uint8_t* cData, const uint8_t* cArg);


//*****************************************************************************
/*
  Function:
    int TCPIP_HTTP_NET_ConnectionDescriptors(void);

  Summary:
    Returns the number of dynamic variable descriptors
    
  Description:
    This function returns the number of the dynamic variable buffer descriptors 
    that are allocated by the HTTP for dynamic variable processing.

  Precondition:
    None

  Parameters:
    None.

  Returns:
    The number of descriptors allocated by the HTTP module.
     
  Remarks:
    Currently the dynamic variable descriptors are allocated at the HTTP 
    initialization and cannot be changed at run-time.

 */

int TCPIP_HTTP_NET_ConnectionDescriptors(void);



//*****************************************************************************
/*
  Function:
    TCPIP_HTTP_NET_READ_STATUS TCPIP_HTTP_NET_ConnectionPostNameRead (TCPIP_HTTP_NET_CONN_HANDLE 
                                                      connHandle, uint8_t* cData, uint16_t wLen)

  Summary:
    Reads a name from a URL encoded string in the network transport buffer.

  Description:
    This function reads a name from a URL encoded string in the network transport 
    buffer. This function is meant to be called from an TCPIP_HTTP_NET_ConnectionPostExecute 
    callback to facilitate easier parsing of incoming data.
    This function also prevents buffer overflows by forcing the programmer
    to indicate how many bytes are expected.
    At least two extra bytes are needed in cData over the maximum
    length of data expected to be read.

    This function will read until the next '=' character, which indicates the
    end of a name parameter.  It assumes that the front of the buffer is
    the beginning of the name parameter to be read.

    This function properly updates pHttpCon->byteCount by decrementing it
    by the number of bytes read.  It also removes the delimiting '=' from
    the buffer.

  Precondition:
    The front of the network transport buffer is the beginning of a name parameter, 
    and the rest of the network transport buffer contains a URL-encoded string with 
    a name parameter terminated by a '=' character.

  Parameters:
    connHandle  - HTTP connection handle
    cData - where to store the name once it is read
    wLen - how many bytes can be written to cData

  Returns:
    - TCPIP_HTTP_NET_READ_OK - name was successfully read
    - TCPIP_HTTP_NET_READ_TRUNCTATED - entire name could not fit in the buffer, 
                                       so the value was truncated and data has been lost
    - TCPIP_HTTP_NET_READ_INCOMPLETE - entire name was not yet in the buffer, so call
                                       this function again later to retrieve

  Remarks:
    None.
 */
TCPIP_HTTP_NET_READ_STATUS    TCPIP_HTTP_NET_ConnectionPostNameRead (TCPIP_HTTP_NET_CONN_HANDLE 
                                                    connHandle, uint8_t* cData, uint16_t wLen);


//*****************************************************************************
/*
  Function:
    TCPIP_HTTP_NET_READ_STATUS TCPIP_HTTP_NET_ConnectionPostValueRead (TCPIP_HTTP_NET_CONN_HANDLE 
                                                        connHandle, uint8_t* cData, uint16_t wLen)

  Summary:
    Reads a value from a URL encoded string in the network transport buffer.

  Description:
    This function reads a value from a URL encoded string in the network transport 
    buffer.
    This function is meant to be called from an TCPIP_HTTP_NET_ConnectionPostExecute 
    callback to facilitate easier parsing of incoming data.  This function also 
    prevents buffer overflows by forcing the programmer to indicate how many bytes 
    are expected.  At least two extra bytes are needed in cData above the maximum
    length of data expected to be read.

    This function will read until the next '&' character, which indicates the
    end of a value parameter.  It assumes that the front of the buffer is
    the beginning of the value parameter to be read.  If pHttpCon->byteCount
    indicates that all expected bytes are in the buffer, it assumes that
    all remaining data is the value and acts accordingly.

    This function properly updates pHttpCon->byteCount by decrementing it
    by the number of bytes read.  The terminating '&' character is also
    removed from the buffer.

  Precondition:
    The front of the network transport buffer is the beginning of a name parameter, 
    and the rest of the network transport buffer contains a URL-encoded string with 
    a name parameter terminated by a '=' character.

  Parameters:
    connHandle  - HTTP connection handle
    cData - where to store the value once it is read
    wLen - how many bytes can be written to cData

  Returns:
    - TCPIP_HTTP_NET_READ_OK - value was successfully read
    - TCPIP_HTTP_NET_READ_TRUNCTATED - entire value could not fit in the buffer, 
                                       so the value was truncated and data has been lost
    - TCPIP_HTTP_NET_READ_INCOMPLETE - entire value was not yet in the buffer, so call
                                       this function again later to retrieve

  Remarks:
    None.
 */
TCPIP_HTTP_NET_READ_STATUS  TCPIP_HTTP_NET_ConnectionPostValueRead (TCPIP_HTTP_NET_CONN_HANDLE 
                                                   connHandle, uint8_t* cData, uint16_t wLen);


//*****************************************************************************
/*
  Function:
    FILE_HANDLE  TCPIP_HTTP_NET_ConnectionFileGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle)

  Summary:
    Get handle to current connection's file.

  Description:
    This function returns the handle of the current HTTP connection file.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    Handle to File System file belonging to the connection defined by connHandle

  Example:
  <code>
    uint8_t myBuff[20];

    // Get the file handle and read from that file
    SYS_FS_FileRead(myBuff, sizeof(myBuff), TCPIP_HTTP_NET_ConnectionFileGet(connHandle));
  </code>

  Remarks:
    None.
 */
SYS_FS_HANDLE  TCPIP_HTTP_NET_ConnectionFileGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

//*****************************************************************************
/*
  Function:
    uint16_t  TCPIP_HTTP_NET_ConnectionPostSmGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle)

  Summary:
    Get the POST state machine state.

  Description:
    This function returns the POST state machine state for the connection defined by 
    connHandle.
    This state is maintained by the HTTP connection and can be used by the user of the
    HTTP to maintain its own POST state machine.
    The values of the POST state machine have significance only for the user of the 
    HTTP connection.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    16-bit integer POST state machine state.

  Example:
  <code>
    #define SM_POST_LCD_READ_NAME   1
    #define SM_POST_LCD_READ_VALUE  2
  
    switch(TCPIP_HTTP_NET_ConnectionPostSmGet(connHandle))
    {
        // Find the name
        case SM_POST_LCD_READ_NAME:
         .
         .
         .
        // Found the value, so store the LCD and return
        case SM_POST_LCD_READ_VALUE:
         .
         .
         .
    }
  </code>

  Remarks:
    None.
 */
uint16_t  TCPIP_HTTP_NET_ConnectionPostSmGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);


//*****************************************************************************
/*
  Function:
    void  TCPIP_HTTP_NET_ConnectionPostSmSet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                             uint16_t state)

  Summary:
    Set the POST state machine state.

  Description:
    This function sets the POST state machine state for the connection defined by 
    connHandle.
    This state is maintained by the HTTP connection and can be used by the user 
    of the HTTP to maintain its own POST state machine.
    The values of the POST state machine have significance only for the user of 
    the HTTP connection.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    state - 16 bit integer state for POST state machine

  Returns:
    None.

  Example:
  <code>
    uint8_t* httpDataBuff;
    #define SM_POST_LCD_READ_NAME   1
    #define SM_POST_LCD_READ_VALUE  2

    switch(TCPIP_HTTP_NET_ConnectionPostSmGet(connHandle))
    {
        // Find the name
        case SM_POST_LCD_READ_NAME:

            // Read a name
            if(TCPIP_HTTP_NET_ConnectionPostNameRead(connHandle, httpDataBuff, 
               TCPIP_HTTP_NET_MAX_DATA_LEN) == TCPIP_HTTP_NET_READ_INCOMPLETE)
                return TCPIP_HTTP_NET_IO_RES_NEED_DATA;

            TCPIP_HTTP_NET_ConnectionPostSmSet(connHandle, SM_POST_LCD_READ_VALUE);
            // No break...continue reading value

        // Found the value, so store the LCD and return
        case SM_POST_LCD_READ_VALUE:
         .
         .
         .
    }
  </code>

  Remarks:
    None.
 */
void  TCPIP_HTTP_NET_ConnectionPostSmSet(TCPIP_HTTP_NET_CONN_HANDLE 
                                         connHandle, uint16_t state);

//*****************************************************************************
/*
  Function:
    uint8_t*  TCPIP_HTTP_NET_ConnectionDataBufferGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle)

  Summary:
    Returns pointer to connection general purpose data buffer.

  Description:
    This function returns  a pointer to the HTTP connection internal data buffer.
    This gives access to the application to the data that's stored in the
    HTTP connection buffer.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    Pointer to the connection's general purpose data buffer.

  Example:
  <code>
    TCPIP_HTTP_NET_DynPrint(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
       const TCPIP_HTTP_DYN_VAR_DCPT* varDcpt, 
       const TCPIP_HTTP_NET_USER_CALLBACK* pCBack)
    {
        const uint8_t *ptr;

        ptr = TCPIP_HTTP_NET_ArgGet(TCPIP_HTTP_NET_ConnectionDataBufferGet
                                   (connHandle), (const uint8_t*)"name");
        if(ptr == 0)
        {
            ptr = "not set";
        }
        else
        {
            strncpy(myBuffer, ptr, sizeof(myBuffer));
            ptr = myBuffer;
        }
        TCPIP_HTTP_NET_DynamicWrite(varDcpt, ptr, strlen(ptr), false);
    }
  </code>

  Remarks:
    None.
 */
uint8_t*  TCPIP_HTTP_NET_ConnectionDataBufferGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);


//*****************************************************************************
/*
  Function:
    uint32_t  TCPIP_HTTP_NET_ConnectionCallbackPosGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle)

  Summary:
    Returns the callback position indicator.

  Description:
    This function will return the current value of the callback position indicator
    for the HTTP connection identified by connHandle.
    The callback position indicator is used in the processing of the
    HTTP dynamic variables.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    Callback position indicator for connection defined by connHandle.

  Example:
  <code>
  </code>

  Remarks:
    None.
 */
uint32_t  TCPIP_HTTP_NET_ConnectionCallbackPosGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);


//*****************************************************************************
/*
  Function:
    void  TCPIP_HTTP_NET_ConnectionCallbackPosSet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                                  uint32_t callbackPos)

  Summary:
    Sets the callback position indicator.

  Description:
    This function will set the current value of the callback position indicator
    for the HTTP connection identified by connHandle.
    The callback position indicator is used in the processing of the
    HTTP dynamic variables.
    When set to a value != 0, it indicates to the HTTP server that the application
    has more pending processing that needs to be done.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    callbackPos - new connection callback position value

  Returns:
    None.

  Example:
  <code>
  </code>

  Remarks:
    None.
 */
void  TCPIP_HTTP_NET_ConnectionCallbackPosSet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                              uint32_t callbackPos);

//*****************************************************************************
/*
  Function:
    TCPIP_HTTP_NET_STATUS TCPIP_HTTP_NET_ConnectionStatusGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

  Summary:
    Gets HTTP status.

  Description:
    This function returns the current HTTP status of the selected HTTP connection.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    A TCPIP_HTTP_NET_STATUS value.

  Example:
  <code>
    TCPIP_HTTP_NET_STATUS currStat =  TCPIP_HTTP_NET_ConnectionStatusGet(connHandle);
  </code>

  Remarks:
    None.
 */
TCPIP_HTTP_NET_STATUS         TCPIP_HTTP_NET_ConnectionStatusGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);



//*****************************************************************************
/*
  Function:
    void TCPIP_HTTP_NET_ConnectionStatusSet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                            TCPIP_HTTP_NET_STATUS stat)

  Summary:
    Sets HTTP status.

  Description:
    Allows write access to the HTTP status of the selected HTTP connection.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    stat        - new TCPIP_HTTP_NET_STATUS enumeration value.

  Returns:
    None.

  Example:
  <code>
    byteCount = TCPIP_HTTP_NET_ConnectionByteCountGet(connHandle);
    int sktRxSize;
    
    sktRxSize = TCPIP_HTTP_NET_ConnectionReadBufferSize(connHandle);

    if(byteCount > sktRxSize)
    {   // Configuration Failure
        // 302 Redirect will be returned
        TCPIP_HTTP_NET_ConnectionStatusSet(connHandle, TCPIP_HTTP_NET_STAT_REDIRECT);
    }
  </code>

  Remarks:
    None.
 */
void  TCPIP_HTTP_NET_ConnectionStatusSet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                         TCPIP_HTTP_NET_STATUS stat);


//*****************************************************************************
/*
  Function:
    uint8_t TCPIP_HTTP_NET_ConnectionHasArgsGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle)

  Summary:
    Checks whether there are get or cookie arguments.

  Description:
    The function will get the value of the "cookies or get arguments" that are present.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    The current value of the connection hasArgs.

  Example:
  <code>
    uint8_t hasArgs = TCPIP_HTTP_NET_ConnectionHasArgsGet(connHandle);
  </code>

  Remarks:
    None.
 */
uint8_t        TCPIP_HTTP_NET_ConnectionHasArgsGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

//*****************************************************************************
/*
  Function:
    void TCPIP_HTTP_NET_ConnectionHasArgsSet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, uint8_t args)

  Summary:
    Sets whether there are get or cookie arguments.

  Description:
    The function sets the value of the "cookies or get arguments" that are present.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    args        - boolean if there are arguments or not

  Returns:
    None.

  Example:
  <code>
    else if(!memcmp(filename, "cookies.htm", 11))
    { 
        TCPIP_HTTP_NET_ConnectionHasArgsSet(connHandle, true);
    }
  </code>

  Remarks:
    None.
 */
void   TCPIP_HTTP_NET_ConnectionHasArgsSet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, uint8_t args);


//*****************************************************************************
/*
  Function:
    uint32_t TCPIP_HTTP_NET_ConnectionByteCountGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle)

  Summary:
    Returns how many bytes have been read so far.

  Description:
    This function returns the current value of the counter showing the number of bytes
    read from the connection so far.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    Current connection byte count, how many bytes have been read so far.

  Example:
  <code>
    switch(TCPIP_HTTP_NET_ConnectionPostSmGet(connHandle))
    {
        case SM_CFG_SNMP_READ_NAME:
            // If all parameters have been read, end
            if(TCPIP_HTTP_NET_ConnectionByteCountGet(connHandle) == 0u)
            {
                return TCPIP_HTTP_NET_IO_RES_DONE;
            }
         .
         .
         .
    }
  </code>

  Remarks:
    None.
 */
uint32_t  TCPIP_HTTP_NET_ConnectionByteCountGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);


//*****************************************************************************
/*
  Function:
    void  TCPIP_HTTP_NET_ConnectionByteCountSet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                                uint32_t byteCount)

  Summary:
    Sets how many bytes have been read so far.

  Description:
    This function sets the current value of the counter showing the number of bytes
    read from the connection so far.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    byteCount   - byte count to be set

  Returns:
    None.

  Remarks:
    None.
 */
void  TCPIP_HTTP_NET_ConnectionByteCountSet(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                            uint32_t byteCount);


//*****************************************************************************
/*
  Function:
    void  TCPIP_HTTP_NET_ConnectionByteCountDec(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                                uint32_t byteCount)

  Summary:
    Decrements the connection byte count.

  Description:
    This function decrements the current value of the counter showing the number of bytes
    read from the connection so far.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    byteCount   - byte count reduction

  Returns:
    None.

  Remarks:
    None.
 */
void  TCPIP_HTTP_NET_ConnectionByteCountDec(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                            uint32_t byteCount);


//*****************************************************************************
/*
  Function:
    uint8_t   TCPIP_HTTP_NET_ConnectionIsAuthorizedGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle)

  Summary:
    Gets the authorized state for the current connection.

  Description:
    This function returns the authorization status for the current HTTP connection.
    This is one of the values returned by the TCPIP_HTTP_NET_ConnectionFileAuthenticate 
    function.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    A uint8_t representing the authorization status.

  Example:
  <code>
    uint8_t isAuth;

    isAuth = TCPIP_HTTP_NET_ConnectionIsAuthorizedGet(connHandle);
  </code>

  Remarks:
    None.
 */
uint8_t   TCPIP_HTTP_NET_ConnectionIsAuthorizedGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);


//*****************************************************************************
/*
  Function:
    void   TCPIP_HTTP_NET_ConnectionIsAuthorizedSet(TCPIP_HTTP_NET_CONN_HANDLE 
                                                      connHandle, uint8_t auth)

  Summary:
    Sets the authorized state for the current connection.

  Description:
    This function sets the authorization status for the current HTTP connection.
    This has to be one of the values in the set returned by the 
    TCPIP_HTTP_NET_ConnectionFileAuthenticate function.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    auth        - new authorization state

  Returns:
    None.

  Example:
  <code>
    uint8_t auth = 0x80;

    TCPIP_HTTP_NET_ConnectionIsAuthorizedSet(connHandle, auth);
  </code>

  Remarks:
    None.
 */
void   TCPIP_HTTP_NET_ConnectionIsAuthorizedSet(TCPIP_HTTP_NET_CONN_HANDLE 
                                                connHandle, uint8_t auth);


//*****************************************************************************
/*
  Function:
    void    TCPIP_HTTP_NET_ConnectionUserDataSet(TCPIP_HTTP_NET_CONN_HANDLE 
                                              connHandle, const void* uData)

  Summary:
    Sets the user data parameter for the current connection.

  Description:
    This function will set the user data value for the current HTTP connection.
    This data belongs to the user and is not used in any way by the HTTP server module.
    It is available to the user by calling TCPIP_HTTP_NET_ConnectionUserDataGet.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    uData       - user supplied data

  Returns:
    None.

  Example:
  <code>
    uint32_t myConnData;

    TCPIP_HTTP_NET_ConnectionUserDataSet(connHandle, (const void*)myConnData);
  </code>

  Remarks:
    None.
 */
void    TCPIP_HTTP_NET_ConnectionUserDataSet(TCPIP_HTTP_NET_CONN_HANDLE 
                                             connHandle, const void* uData);


//*****************************************************************************
/*
  Function:
    const void*    TCPIP_HTTP_NET_ConnectionUserDataGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle)

  Summary:
    Gets the user data parameter for the current connection.

  Description:
    This function returns the user data value for the current HTTP connection.
    This data belongs to the user and is not used in any way by the HTTP server module.
    It can be set by the user with TCPIP_HTTP_NET_ConnectionUserDataSet.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    User data that's stored as part of the connection.

  Example:
  <code>
    uint32_t myConnData;

    myConnData = (uint32_t)TCPIP_HTTP_NET_ConnectionUserDataGet(connHandle);
  </code>

  Remarks:
    None.
 */
const void*    TCPIP_HTTP_NET_ConnectionUserDataGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);


//*****************************************************************************
/*
  Function:
    int    TCPIP_HTTP_NET_ActiveConnectionCountGet(int* pOpenCount);

  Summary:
    Gets the number of active (and inactive) connections.

  Description:
    This function will return the number of active and total opened HTTP connections
    at the current time.
   
  Precondition:
    None.

  Parameters:
    pOpenCount  - address to store the number of total HTTP opened connections
                  Could be NULL if not needed

  Returns:
    The number of active/total connections.

  Example:
  <code>
    int nConns;

    nConns = TCPIP_HTTP_NET_ActiveConnectionCountGet(0);
  </code>

  Remarks:
    The value returned by this function is informational only.
    The number of active connections changes dynamically.

 */
int    TCPIP_HTTP_NET_ActiveConnectionCountGet(int* pOpenCount);


//*****************************************************************************
/*
  Function:
    TCPIP_HTTP_NET_READ_STATUS TCPIP_HTTP_NET_ConnectionPostReadPair(TCPIP_HTTP_NET_CONN_HANDLE 
                                                     connHandle, uint8_t* cData, uint16_t wLen)

  Summary:
    Reads a name and value pair from a URL encoded string in the network transport 
    buffer.

  Description:
    Reads a name and value pair from a URL encoded string in the network transport 
    buffer.
    This function is meant to be called from an TCPIP_HTTP_NET_ConnectionPostExecute 
    callback to facilitate easier parsing of incoming data.  This function also prevents
    buffer overflows by forcing the programmer to indicate how many bytes are
    expected.  At least 2 extra bytes are needed in cData over the maximum
    length of data expected to be read.

    This function will read until the next '&' character, which indicates the
    end of a value parameter.  It assumes that the front of the buffer is
    the beginning of the name parameter to be read.

    This function properly updates the connection byteCount 
    (see TCPIP_HTTP_NET_ConnectionByteCountGet) by decrementing it by the number 
    of bytes read.  It also removes the delimiting '&' from the buffer.

    Once complete, two strings will exist in the cData buffer.  The first is
    the parameter name that was read, while the second is the associated
    value.

  Precondition:
    The front of the network transport buffer is the beginning of a name parameter, 
    and the rest of the network transport buffer contains a URL-encoded string with 
    a name parameter terminated by a '=' character and a value parameter terminated 
    by a '&'.

  Parameters:
    connHandle  - HTTP connection handle
    cData - where to store the name and value strings once they are read
    wLen - how many bytes can be written to cData

  Returns:
    - TCPIP_HTTP_NET_READ_OK - name and value were successfully read
    - TCPIP_HTTP_NET_READ_TRUNCTATED - entire name and value could not fit in 
                                       the buffer, so input was truncated and 
                                       data has been lost
    - TCPIP_HTTP_NET_READ_INCOMPLETE - entire name and value was not yet in 
                                       the buffer, so call this function again 
                                       later to retrieve

  Remarks:
    This function is aliased to TCPIP_HTTP_NET_ConnectionPostValueRead, 
    since they effectively perform the same task.  The name is provided only 
    for completeness.
 */
#define TCPIP_HTTP_NET_ConnectionPostReadPair(connHandle, cData, wLen) \
        TCPIP_HTTP_NET_ConnectionPostValueRead(connHandle, cData, wLen)

// *****************************************************************************
// Section: HTTP User-implemented Callback data structure
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*
  Enumeration:
    TCPIP_HTTP_DYN_ARG_TYPE

  Summary:
    HTTP supported dynamic variables argument types.

  Description:
    This enumeration defines the types of the HTTP supported dynamic variables
    arguments.
   
  Remarks:
    Currently a dynamic variable can have either string or int32_t parameters.

    Only 16 bit values are currently supported.
*/
typedef enum
{
    /* the dynamic variable argument is a int32_t */
    TCPIP_HTTP_DYN_ARG_TYPE_INT32      = 0,

    /* the dynamic variable argument is a ASCII string */
    TCPIP_HTTP_DYN_ARG_TYPE_STRING,


}TCPIP_HTTP_DYN_ARG_TYPE;

// *****************************************************************************
/*
  Data structure:
    TCPIP_HTTP_DYN_ARG_DCPT

  Summary:
    HTTP dynamic argument descriptor.

  Description:
    This data type defines the structure of a HTTP dynamic variable argument.
    It is used for describing the dynamic variables arguments.


  Remarks:
    The argument flags are currently not used.
    They are meant for further extensions.

*/
typedef struct
{
    /* argument type */
    uint16_t            argType;        // a TCPIP_HTTP_DYN_ARG_TYPE value
    uint16_t            argFlags;       // extra argument flags
    union
    {
        int32_t         argInt32;       // use this member when the arg type is INT32
        const char*     argStr;         // use this member when the arg type is string
    };
}TCPIP_HTTP_DYN_ARG_DCPT;

// *****************************************************************************
/*
  Enumeration:
    TCPIP_HTTP_DYN_VAR_FLAGS

  Summary:
    HTTP supported dynamic variables flags.

  Description:
    This enumeration defines the flags associated with the HTTP supported dynamic 
    variables.
   
  Remarks:
    Multiple flags con be set simultaneously.
    New flags will be eventually added.
    Only 16-bit values are currently supported.

*/
typedef enum
{
    /* no flag associated with this dynamic variable */
    TCPIP_HTTP_DYN_VAR_FLAG_NONE      = 0,

    /* dynamic variable field exceeded available parsing space */
    /* the dynamic variable name has been truncated */
    TCPIP_HTTP_DYN_VAR_FLAG_NAME_TRUNCATED      = 0x01,

    /* dynamic variable field exceeded available parsing space */
    /* the dynamic variable arguments have been truncated */
    TCPIP_HTTP_DYN_VAR_FLAG_ARG_NAME_TRUNCATED  = 0x02,

    /* dynamic variable arguments exceeded available buffering space */
    /* the number of arguments of the dynamic variable has been truncated */
    TCPIP_HTTP_DYN_VAR_FLAG_ARG_NO_TRUNCATED   = 0x04,


}TCPIP_HTTP_DYN_VAR_FLAGS;

// *****************************************************************************
/*
  Enumeration:
    TCPIP_HTTP_DYN_PRINT_RES

  Summary:
    Dynamic print result when a dynamic variable print callback function is returned;

  Description:
    This enumeration defines the results associated with the HTTP dynamic variables
    callbacks (TCPIP_HTTP_NET_DynPrint).
   
  Remarks:
    Currently the default action for a user defined dynamic variable is "do nothing".
    Keywords like "inc" have an internal implementation and don't need to be
    processed by the user.

*/
typedef enum
{
    /* dynamic callback is done */
    TCPIP_HTTP_DYN_PRINT_RES_DONE      = 0,

    /* no implementation supported for this dynamic variable, call the default action */
    TCPIP_HTTP_DYN_PRINT_RES_DEFAULT,

    /* process the action of this call and then call again */
    /* data written to the HTTP connection but more data is pending */ 
    TCPIP_HTTP_DYN_PRINT_RES_PROCESS_AGAIN,

    /* do not process any action just call again */
    /* no data was available to be written to the connection */
    /* or the written data should be ignored this turn */
    TCPIP_HTTP_DYN_PRINT_RES_AGAIN,


}TCPIP_HTTP_DYN_PRINT_RES;




// *****************************************************************************
/*
  Data structure:
    TCPIP_HTTP_DYN_VAR_DCPT

  Summary:
    HTTP dynamic variable descriptor.

  Description:
    This data type defines the structure of a HTTP dynamic variable descriptor.
    When the user registers a TCPIP_HTTP_NET_DynPrint function
    for dynamic variable processing, this callback will receive
    the dynamic variable descriptor as a parameter.

  Remarks:
    None.
*/
typedef struct
{
    const char*                     dynName;    // ASCII string storing the dynamic 
                                                // variable name
    const char*                     fileName;   // ASCII string storing the file name 
                                                // the dynamic variable belongs to
    uint16_t                        callbackID; // Call back ID: the dynamic variable 
                                                // index within the file
    uint8_t                         dynFlags;   // a TCPIP_HTTP_DYN_VAR_FLAGS value
    uint8_t                         nArgs;      // number of arguments that the variable has
    TCPIP_HTTP_DYN_ARG_DCPT*        dynArgs;    // array of argument descriptors carrying 
                                                // the dynamic variable arguments
    const void*                     dynContext; // dynamic context of the callback.
                                                // This context is used by the HTTP server 
                                                // and is irrelevant to the user.
}TCPIP_HTTP_DYN_VAR_DCPT;


// *****************************************************************************
/*
  Structure:
    TCPIP_HTTP_NET_USER_CALLBACK

  Summary:
    HTTP user implemented callback data structure.

  Description:
    This data structure defines the user callbacks that are implemented by the 
    user and the HTTP server calls at run-time.

  Remarks:
    See the detailed explanation for each callback in the callback templates section.  

    The extra pCBack parameter is passed back for allowing the user to store 
    additional info in the supplied TCPIP_HTTP_NET_USER_CALLBACK data structure that could be used at run-time.
*/
typedef struct _tag_TCPIP_HTTP_NET_USER_CALLBACK
{
    /*  TCPIP_HTTP_NET_ConnectionGetExecute GET process function */ 
    TCPIP_HTTP_NET_IO_RESULT (*getExecute)(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                         const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);
    /*  TCPIP_HTTP_NET_ConnectionPostExecute POST process function */ 
    TCPIP_HTTP_NET_IO_RESULT (*postExecute)(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                          const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);
    /*  TCPIP_HTTP_NET_ConnectionFileAuthenticate File Authenticate function */ 
    uint8_t (*fileAuthenticate)(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const char* cFile, 
              const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);
    /*  TCPIP_HTTP_NET_ConnectionUserAuthenticate User Authenticate function */ 
    uint8_t (*userAuthenticate)(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const char* cUser, 
             const char* cPass, const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);
    /*  TCPIP_HTTP_NET_DynPrint Dynamic variable process function */ 
    TCPIP_HTTP_DYN_PRINT_RES (*dynamicPrint)(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                              const TCPIP_HTTP_DYN_VAR_DCPT* varDcpt, 
                              const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);
    /*  TCPIP_HTTP_NET_DynAcknowledge Dynamic variable acknowledge function */ 
    void (*dynamicAck)(TCPIP_HTTP_NET_CONN_HANDLE connHandle, const void* buffer, 
          const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);
    /* TCPIP_HTTP_NET_EventReport run-time HTTP processing report */
    void (*eventReport)(TCPIP_HTTP_NET_CONN_HANDLE connHandle, TCPIP_HTTP_NET_EVENT_TYPE evType, 
          const void* evInfo, const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);

}TCPIP_HTTP_NET_USER_CALLBACK;

// *****************************************************************************
/*
  Type:
    TCPIP_HTTP_NET_USER_HANDLE

  Summary:
    HTTP user handle.

  Description:
    A handle that a client can use after the HTTP user callback has been registered.
 */

typedef const void* TCPIP_HTTP_NET_USER_HANDLE;

//*****************************************************************************
/*
  Function:
    TCPIP_HTTP_NET_USER_HANDLE  TCPIP_HTTP_NET_UserHandlerRegister 
                              (const TCPIP_HTTP_NET_USER_CALLBACK* userCallback);

  Summary:
    Registers a user callback structure with the HTTP server

  Description:
    The function registers a user callback data structure with the HTTP server.
    The HTTP server will call the user supplied callbacks at run-time when 
    processing the web pages.


  Precondition:
    The HTTP server module properly initialized.

  Parameters:
    userCallback    - user callback to be registered with the HTTP server  

  Returns:
    Returns a valid handle if the call succeeds, or a null handle if
    the call failed (out of memory, for example).

  Example:
  <code>
  </code>

  Remarks:
    Currently only one user callback structure could be registered.
    The call will fail if a user callback structure is already registered.

 */
TCPIP_HTTP_NET_USER_HANDLE    TCPIP_HTTP_NET_UserHandlerRegister 
                              (const TCPIP_HTTP_NET_USER_CALLBACK* userCallback);

// *****************************************************************************
/* Function:
    TCPIP_HTTP_NET_UserHandlerDeregister(TCPIP_HTTP_NET_USER_HANDLE hHttp)

  Summary:
    Deregisters a previously registered HTTP user handler.
    
  Description:
    This function deregisters a HTTP user callback handler.

  Precondition:
    The HTTP server module properly initialized.

  Parameters:
    hHttp   - A handle returned by a previous call to TCPIP_HTTP_NET_UserHandlerRegister

  Returns:
    - true	- if the call succeeds
    - false - if no such handler is registered
              or there are active connections

  Remarks:
    The call will fail if there is active HTTP traffic.
    The handler cannot be deregistered while HTTP traffic is in progress.
 */

bool             TCPIP_HTTP_NET_UserHandlerDeregister(TCPIP_HTTP_NET_USER_HANDLE hHttp);

// *****************************************************************************
// Section: Templates for User-implemented Callback Function Prototypes
// *****************************************************************************
// *****************************************************************************

//*****************************************************************************
/*
  Function:
    TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionGetExecute 
                          (TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                          const TCPIP_HTTP_NET_USER_CALLBACK* pCBack)

  Summary:
    Processes GET form field variables and cookies.

  Description:
    This function is implemented by the application developer.
    Its purpose is to parse the data received from URL parameters (GET method forms) 
    and cookies and perform any application-specific tasks in response to these inputs.  
    Any required authentication has already been validated.

    When this function is called, the connection data buffer
    (see TCPIP_HTTP_NET_ConnectionDataBufferGet) contains sequential name/value pairs 
    of strings representing the data received. In this format, TCPIP_HTTP_NET_ArgGet 
    can be used to search for specific variables in the input.  If data buffer space 
    associated with this connection is required, connection data buffer may be overwritten
    here once the application is done with the values.  Any data placed there will be 
    available to future callbacks for this connection, including 
    TCPIP_HTTP_NET_ConnectionPostExecute and any TCPIP_HTTP_NET_Print_varname dynamic
    substitutions.

    This function may also issue redirections by setting the connection data
    buffer to the destination file name or URL, and the connection
    httpStatus (TCPIP_HTTP_NET_ConnectionStatusSet()) to TCPIP_HTTP_NET_STAT_REDIRECT.

    Finally, this function may set cookies.  Set connection data buffer to a series
    of name/value string pairs (in the same format in which parameters
    arrive) and then set the connection hasArgs (TCPIP_HTTP_NET_ConnectionHasArgsSet)
    equal to the number of cookie name/value pairs.
    The cookies will be transmitted to the browser, and any future requests
    will have those values available in the connection data buffer.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    pCBack      - user TCPIP_HTTP_NET_USER_CALLBACK pointer

  Returns:
    - TCPIP_HTTP_NET_IO_RES_DONE - application is done processing
    - TCPIP_HTTP_NET_IO_RES_NEED_DATA - this value may not be returned because 
                                        more data will not become available
    - TCPIP_HTTP_NET_IO_RES_WAITING - the application is waiting for an asynchronous
                                      process to complete, and this function should be
                                      called again later

  Remarks:
    This function is only called if variables are received via URL
    parameters or Cookie arguments.
  
    This function may NOT write to the network transport buffer.

    This function may service multiple HTTP requests simultaneously.
    Exercise caution when using global or static variables inside this
    routine.
    Use the connection callbackPos (TCPIP_HTTP_NET_ConnectionCallbackPosGet)
    or the connection data buffer for storage associated with individual requests.
 */
TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionGetExecute 
                      (TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                      const TCPIP_HTTP_NET_USER_CALLBACK* pCBack);

//*****************************************************************************
/*
  Function:
    TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionPostExecute 
                      (TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                      const TCPIP_HTTP_NET_USER_CALLBACK* pCBack)

  Summary:
    Processes POST form variables and data.

  Description:
    This function is implemented by the application developer.
    Its purpose is to parse the data received from
    POST forms and perform any application-specific tasks in response
    to these inputs.  Any required authentication has already been
    validated before this function is called.

    When this function is called, POST data will be waiting in the
    network transport buffer.
    The connection byteCount (see TCPIP_HTTP_NET_ConnectionByteCountGet
    will indicate the number of bytes remaining to be received before the 
	browser request is complete.

    Since data is still in the network transport buffer, the application must call
    TCPIP_HTTP_NET_ConnectionRead in order to retrieve bytes.  When this is done,
    connection byteCount MUST be updated to reflect how many bytes now
    remain.

    In general, data submitted from web forms via POST is URL encoded.
    The TCPIP_HTTP_NET_URLDecode function can be used to decode this information
    back to a standard string if required.  If data buffer space
    associated with this connection is required, the connection data buffer 
    (see TCPIP_HTTP_NET_ConnectionDataBufferGet) may be
    overwritten here once the application is done with the values.
    Any data placed there will be available to future callbacks for
    this connection,  including TCPIP_HTTP_NET_ConnectionPostExecute and any
    TCPIP_HTTP_NET_Print_varname dynamic substitutions.

    Whenever a POST form is processed it is recommended to issue a
    redirect back to the browser, either to a status page or to
    the same form page that was posted.  This prevents accidental
    duplicate submissions (by clicking refresh or back/forward) and
    avoids browser warnings about "resubmitting form data".  Redirects
    may be issued to the browser by setting the connection data buffer to the
    destination file or URL, and the connection httpStatus
    (TCPIP_HTTP_NET_ConnectionStatusSet) to TCPIP_HTTP_NET_STAT_REDIRECT.

    Finally, this function may set cookies.  Set the connection data buffer
    to a series of name/value string pairs (in the same format in which parameters
    arrive), and then set the connection hasArgs (TCPIP_HTTP_NET_ConnectionHasArgsSet)
    equal to the number of cookie name/value pairs.
    The cookies will be transmitted to the browser, and any future requests
    will have those values available in the connection data buffer.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    pCBack      - user TCPIP_HTTP_NET_USER_CALLBACK pointer

  Returns:
    - TCPIP_HTTP_NET_IO_RES_DONE - application is done processing
    - TCPIP_HTTP_NET_IO_RES_NEED_DATA - more data is needed to continue, and this
                                        function should be called again later
    - TCPIP_HTTP_NET_IO_RES_WAITING - the application is waiting for an asynchronous
                                      process to complete, and this function should
                                      be called again later

  Remarks:
    This function is only called when the request method is POST, and is
    only used when TCPIP_HTTP_NET_USE_POST is defined.
  
    This method may NOT write to the network transport buffer.

    This function may service multiple HTTP requests simultaneously.
    Exercise caution when using global or static variables inside this
    routine.
    Use the connection callbackPos (TCPIP_HTTP_NET_ConnectionCallbackPosGet)
    or connection data buffer for storage associated with individual requests.
 */
TCPIP_HTTP_NET_IO_RESULT TCPIP_HTTP_NET_ConnectionPostExecute 
                            (TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                            const TCPIP_HTTP_NET_USER_CALLBACK* pCBack);

//*****************************************************************************
/*
  Function:
    uint8_t TCPIP_HTTP_NET_ConnectionFileAuthenticate 
                       (TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                        const char* cFile, const TCPIP_HTTP_NET_USER_CALLBACK* pCBack)

  Summary:
    Determines if a given file name requires authentication

  Description:
    This function is implemented by the application developer.
    Its function is to determine if a file being
    requested requires authentication to view.  The user name and password,
    if supplied, will arrive later with the request headers, and will be
    processed at that time.

    Return values 0x80 - 0xff indicate that authentication is not required,
    while values from 0x00 to 0x79 indicate that a user name and password
    are required before proceeding.  While most applications will only use a
    single value to grant access and another to require authorization, the
    range allows multiple "realms" or sets of pages to be protected, with
    different credential requirements for each.

    The return value of this function is saved for the current connection
    and can be read using TCPIP_HTTP_NET_ConnectionIsAuthorizedGet.
    It will be available to future callbacks, including 
    TCPIP_HTTP_NET_ConnectionUserAuthenticate and any of the 
    TCPIP_HTTP_NET_ConnectionGetExecute, TCPIP_HTTP_NET_ConnectionPostExecute, 
    or TCPIP_HTTP_NET_Print_varname callbacks.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    cFile       - the name of the file being requested
    pCBack      - user TCPIP_HTTP_NET_USER_CALLBACK pointer

  Returns:
    - <= 0x79 - valid authentication is required
    - >= 0x80 - access is granted for this connection

  Remarks:
    This function may NOT write to the network transport buffer.
 */
uint8_t TCPIP_HTTP_NET_ConnectionFileAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                     const char* cFile, const TCPIP_HTTP_NET_USER_CALLBACK* pCBack);

//*****************************************************************************
/*
  Function:
    uint8_t TCPIP_HTTP_NET_ConnectionUserAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE 
                          connHandle, const char* cUser, const char* cPass, 
                          const TCPIP_HTTP_NET_USER_CALLBACK* pCBack)

  Summary:
    Performs validation on a specific user name and password.

  Description:
    This function is implemented by the application developer.
    Its function is to determine if the user name and
    password supplied by the client are acceptable for this resource.
    This callback function can thus to determine if only specific
    user names or passwords will be accepted for this resource.

    Return values 0x80 - 0xff indicate that the credentials were accepted,
    while values from 0x00 to 0x79 indicate that authorization failed.
    While most applications will only use a single value to grant access,
    flexibility is provided to store multiple values in order to
    indicate which user (or user's group) logged in.

    The value returned by this function is stored in the corresponding 
    connection data and will be available with 
    TCPIP_HTTP_NET_ConnectionIsAuthorizedGet in any of the 
    TCPIP_HTTP_NET_ConnectionGetExecute, TCPIP_HTTP_NET_ConnectionPostExecute, or 
	TCPIP_HTTP_NET_Print_varname callbacks.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    cUser       - the user name supplied by the client
    cPass       - the password supplied by the client
    pCBack      - user TCPIP_HTTP_NET_USER_CALLBACK pointer

  Returns:
    - <= 0x79 - the credentials were rejected
    - >= 0x80 - access is granted for this connection

  Remarks:
    This function is only called when an Authorization header is
    encountered.

    This function may NOT write to the network transport buffer.
 */
uint8_t TCPIP_HTTP_NET_ConnectionUserAuthenticate(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                          const char* cUser, const char* cPass, 
                                          const TCPIP_HTTP_NET_USER_CALLBACK* pCBack);

//*****************************************************************************
/*
  Function:
    TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_NET_DynPrint(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                           const TCPIP_HTTP_DYN_VAR_DCPT* varDcpt, 
                                           const TCPIP_HTTP_NET_USER_CALLBACK* pCBack);


  Summary:
    Inserts dynamic content into a web page

  Description:
    Functions in this style are implemented by the application developer.
    This function generates dynamic content to be
    inserted into web pages.

    The function of this type is called when a dynamic variable is located
    in a web page.  (i.e., ~varname~)  The name between the tilde '~'
    characters is passed as the dynamic variable name.

    The function currently supports int32_t and string parameters.
    The dynamic variable parameters are included in the varDcpt data structure
    that's passed at the time of the call.
    For example, the variable "~myArray(2,6)~" will generate the
    call with:
        varDcpt.dynName = "myArray";
        varDcpt.nArgs = 2;
        varDcpt.dynArgs->argType = TCPIP_HTTP_DYN_ARG_TYPE_INT32;
        varDcpt.dynArgs->argInt32 = 2;
        (varDcpt.dynArgs + 1)->argType = TCPIP_HTTP_DYN_ARG_TYPE_INT32;
        (varDcpt.dynArgs + 1)->argInt32 = 6;

    When called, this function should write its output to the HTTP connection
    using the TCPIP_HTTP_NET_DynamicWrite/TCPIP_HTTP_NET_DynamicWriteString 
    functions.

    In situations where the dynamic variable print function needs to perform 
    additional write operations, or simply needs to be called again, it must 
    return: TCPIP_HTTP_DYN_PRINT_RES_PROCESS_AGAIN/TCPIP_HTTP_DYN_PRINT_RES_AGAIN.
    Typically this is used when outputting large amounts of data that cannot fit 
    into one single buffer write operation or when the data is not available 
    all at once.
    
    An alternative (legacy) mechanism for that, is using the connection callbackPos 
    calls: (TCPIP_HTTP_NET_ConnectionCallbackPosGet/TCPIP_HTTP_NET_ConnectionCallbackPosSet).
    This value will be set to zero before the function is called.
    If the function is managing its output state, it must set this to a non-zero 
    value before returning.
    If the connection callbackPos is non-zero, the function will be called again 
    after the current data is processed (equivalent to returning 
    TCPIP_HTTP_DYN_PRINT_RES_PROCESS_AGAIN).
    Once the callback completes, set the callback value back to zero and return
    TCPIP_HTTP_DYN_PRINT_RES_DONE to resume normal servicing of the request.

    If the function does not process this dynamic variable callback (or it wants 
    the default action to be performed), it should return TCPIP_HTTP_DYN_PRINT_RES_DEFAULT.
    Then the default action for that variable will be performed by the HTTP module.

    Note that this is an advanced feature and will be used for processing of HTTP 
    dynamic variable keywords. No implementation currently exists for user added 
    variables and the default action in this case will do nothing.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    varDcpt     - pointer to a variable descriptor containing the dynamic variable name 
                  and arguments valid within this call context only.
    pCBack      - user TCPIP_HTTP_NET_USER_CALLBACK pointer


  Returns:
    A TCPIP_HTTP_DYN_PRINT_RES specifying the action to be taken. See the 
    TCPIP_HTTP_DYN_PRINT_RES definition for a list of allowed actions

  Remarks:
    This function may service multiple HTTP requests simultaneously,
    especially when managing its output state.  Exercise caution when using
    global or static variables inside this routine.  Use the connection
    callbackPos or the connection data buffer for storage associated with 
	individual requests.

    The varDcpt variable descriptor is valid only in the context of this call.
    Any parameters that are needed for further processing should be copied
    to user storage.

    The varDcpt variable descriptor is constant and should not be modified in any way
    by the callback.

    If the callback returned TCPIP_HTTP_DYN_PRINT_RES_DEFAULT, no further calls 
    will be made to the callback function.

    Returning TCPIP_HTTP_DYN_PRINT_RES_PROCESS_AGAIN/TCPIP_HTTP_DYN_PRINT_RES_AGAIN
    is an alternative mechanism to manipulation the connection status with
    TCPIP_HTTP_NET_ConnectionCallbackPosSet/TCPIP_HTTP_NET_ConnectionCallbackPosGet 
    functions (which mechanism is still valid).
    - If the TCPIP_HTTP_NET_DynPrint() returned TCPIP_HTTP_DYN_PRINT_RES_PROCESS_AGAIN, 
      the HTTP server will start sending the dynamic variable buffer
      (invoked by TCPIP_HTTP_NET_DynamicWrite/TCPIP_HTTP_NET_DynamicWriteString).
      Once sending is done, the HTTP server will again call TCPIP_HTTP_NET_DynPrint 
      regardless of the value set with the callback position.
    - If the TCPIP_HTTP_NET_DynPrint() returned TCPIP_HTTP_DYN_PRINT_RES_AGAIN, 
      there will be no processing of dynamic variable data (potentially written to 
      the connection) but the TCPIP_HTTP_NET_DynPrint will be invoked again.
      Returning TCPIP_HTTP_DYN_PRINT_RES_AGAIN is needed when 
      TCPIP_HTTP_NET_DynamicWrite failed or some condition is not satisfied and the 
      TCPIP_HTTP_NET_DynPrint needs to be called again.

    The callback position mechanism will be evaluated after the TCPIP_HTTP_NET_DynPrint
    returns TCPIP_HTTP_DYN_PRINT_RES_DONE.


 */
TCPIP_HTTP_DYN_PRINT_RES TCPIP_HTTP_NET_DynPrint(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                      const TCPIP_HTTP_DYN_VAR_DCPT* varDcpt, 
                                      const TCPIP_HTTP_NET_USER_CALLBACK* pCBack);

//*****************************************************************************
/*
  Function:
    void TCPIP_HTTP_NET_DynAcknowledge(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                  const void* buffer, 
                                  const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);


  Summary:
    Dynamic variable acknowledge function

  Description:
    Functions in this style are implemented by the application developer.
    This function reports that a buffer that was passed as part of a dynamic 
    variable callback (dynamicPrint) was processed and can be reused, freed, etc.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    buffer      - the processed buffer
    pCBack      - user TCPIP_HTTP_NET_USER_CALLBACK pointer


  Returns:
    None.

  Remarks:
    The function is called only when TCPIP_HTTP_NET_DynamicWrite or 
    TCPIP_HTTP_NET_DynamicWriteString was specified with a true needAck 
    parameter. 

    The function is called from withing HTTP context.
    It should be kept as short as possible.

 */
void TCPIP_HTTP_NET_DynAcknowledge(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                          const void* buffer, 
                          const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);

//*****************************************************************************
/*
  Function:
    void TCPIP_HTTP_NET_EventReport(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                           TCPIP_HTTP_NET_EVENT_TYPE evType, const void* evInfo, 
                           const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);


  Summary:
    Reports an event that occurred in the processing of a HTTP web page

  Description:
    Functions in this style are implemented by the application developer.
    This function reports an event that occurred when processing a file, 
    dynamic variable, etc.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    evType      - the HTTP event that occurred
    evInfo      - additional info for that particular event
                    - TCPIP_HTTP_NET_EVENT_FILE_OPEN_ERROR: file name pointer
                    - TCPIP_HTTP_NET_EVENT_FILE_NAME_ERROR: 0
                    - TCPIP_HTTP_NET_EVENT_FILE_NAME_SIZE_ERROR: file name pointer
                    - TCPIP_HTTP_NET_EVENT_FILE_SIZE_ERROR: file name pointer
                    - TCPIP_HTTP_NET_EVENT_FILE_READ_ERROR: file name pointer
                    - TCPIP_HTTP_NET_EVENT_DEPTH_ERROR: file name pointer
                    - TCPIP_HTTP_NET_EVENT_DYNVAR_NO_TERM_ERROR: dynamic variable 
                      name pointer
                    - TCPIP_HTTP_NET_EVENT_FS_WRITE_ERROR: file name pointer
                    - TCPIP_HTTP_NET_EVENT_FS_MOUNT_ERROR: file name pointer
                    - TCPIP_HTTP_NET_EVENT_FS_UPLOAD_COMPLETE: file name pointer
                    - TCPIP_HTTP_NET_EVENT_DYNVAR_NAME_TRUNCATED : dynamic variable 
                      name pointer
                    - TCPIP_HTTP_NET_EVENT_DYNVAR_ARG_NAME_TRUNCATED: dynamic variable 
                      name pointer
                    - TCPIP_HTTP_NET_EVENT_DYNVAR_ARG_NUMBER_TRUNCATED: dynamic variable 
                      name pointer
                    - TCPIP_HTTP_NET_EVENT_POOL_EMPTY: file name pointer 
                    - TCPIP_HTTP_NET_EVENT_PEEK_BUFFER_SIZE_EXCEEDED: string with excess 
                      number of bytes that cannot be read 

                  Valid within this call context only!
    pCBack      - user TCPIP_HTTP_NET_USER_CALLBACK pointer


  Returns:
    None.

  Remarks:
    The evInfo parameter is valid only in the context of this call.
    Any data that is needed for further processing should be copied
    to user storage.

    This function may NOT write to the network transport buffer.

 */
void TCPIP_HTTP_NET_EventReport(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                 TCPIP_HTTP_NET_EVENT_TYPE evType, const void* evInfo, 
                                 const struct _tag_TCPIP_HTTP_NET_USER_CALLBACK* pCBack);


//*****************************************************************************
/*
  Function:
    bool TCPIP_HTTP_NET_ConnectionFileInclude(HTTP_CONN_HANDLE connHandle, 
                                              const char* fileName)

  Summary:
    Writes a file to the HTTP connection.

  Description:
    This function allows an entire file to be included as part of a dynamic 
    variable processing. This reduces unneeded duplication of visual elements 
    such as headers, menus, etc.
    
    It is not meant for the processing of dynamic variables that include files 
    by using the "inc" keyword (see the Remarks section below).


  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle
    fileName    - the name of the file to be included

  Returns:
    true if the call succeeded,
    false if the file could not be opened

  Remarks:
    Should be called from within a dynamic variable processing function context.
    The function allows to insert a file, as part of the dynamic variable processing.

    The included file can contain dynamic variables.
    However there's a limit for recursive calls (see TCPIP_HTTP_NET_MAX_RECURSE_LEVEL).

    The file is just added to the processing queue.
    Returning true does not mean that the whole file has been already sent to the 
    connection.

    If the function returns true but an error occurs during the file processing
    an event will be reported using the TCPIP_HTTP_NET_EventReport callback.

    If the function returns false an event will be reported using the
    TCPIP_HTTP_NET_EventReport callback with additional info.

    Please note that the processing of HTTP dynamic keywords in the HTML code
    such as <c>~inc:filename.ext~</c> is processed internally by the HTTP module!
    For such a dynamic variable, control is not passed to the user.

 */
bool  TCPIP_HTTP_NET_ConnectionFileInclude(HTTP_CONN_HANDLE connHandle, 
                                           const char* fileName);




// *****************************************************************************
// *****************************************************************************
// Section: HTTP Connection Data Manipulation API Prototypes
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*
  Function:
    bool TCPIP_HTTP_NET_DynamicWrite(const TCPIP_HTTP_DYN_VAR_DCPT* varDcpt, 
                              const void * buffer, uint16_t size, bool needAck);

  Summary:
    Writes a data buffer to the current connection
    
  Description:
    This function takes a buffer and sends it over the HTTP connection
    as part of the HTTP dynamic variable processing

  Precondition:
    varDcpt     - a valid dynamic variable descriptor.

  Parameters:
    varDcpt    - dynamic variable descriptor as passed in the 
                 TCPIP_HTTP_NET_DynPrint function
    buffer     - The pointer to the persistent buffer to be written to the HTTP 
                 connection as part of this dynamic variable callback
    size       - The number of bytes to be written
    needAck    - if true, once the buffer is processed internally,  
                 TCPIP_HTTP_NET_DynAcknowledge will be called  

  Returns:
    True if the data buffer has been queued for output.
    False if an invalid buffer was provided or the buffer could not be queued
    because of the lack of resources (descriptors).

  Remarks:
    The buffer passed in by the user with this call is queued internally
    using an available dynamic variable buffer descriptor.
    That means that the buffer has to be persistent.
    Once the buffer is processed and sent to output, the dynamicAck callback
    will be called, to inform the user that the corresponding buffer can be
    reused/freed.

    When multiple connections output their dynamic content concurrently
    the HTTP may run out of dynamic variable buffer descriptors that are used 
    in queuing the requests and the call may fail.
    If the call failed, because the buffer could not be queued,
    it may be retried using by returning
    TCPIP_HTTP_DYN_PRINT_RES_AGAIN in the TCPIP_HTTP_NET_DynPrint callback.

    If sequential write calls are done from within the same TCPIP_HTTP_NET_DynPrint 
    call the HTTP module will try to append the new dynamic data to the existent one.

    The number of internal HTTP dynamic variables buffer descriptors is controlled by
    TCPIP_HTTP_NET_DYNVAR_DESCRIPTORS_NUMBER.
    It can be obtained at run-time using the TCPIP_HTTP_NET_ConnectionDescriptors function.

 */

bool TCPIP_HTTP_NET_DynamicWrite(const TCPIP_HTTP_DYN_VAR_DCPT* varDcpt, 
                            const void * buffer, uint16_t size, bool needAck);


//*****************************************************************************
/*
  Function:
    bool TCPIP_HTTP_NET_DynamicWriteString(const TCPIP_HTTP_DYN_VAR_DCPT* varDcpt, 
                                           const char* str, bool needAck);

  Summary:
    Helper for writing a string within a dynamic variable context.
    
  Description:
    This function takes a 0 terminated ACII string and sends it to the HTTP 
    connection as part of the HTTP dynamic variable processing

  Precondition:
    varDcpt     - a valid dynamic variable descriptor.

  Parameters:
    varDcpt    - dynamic variable descriptor as passed in the 
                 TCPIP_HTTP_NET_DynPrint function
    str        - The string to be written
    needAck    - if true, once the buffer is processed internally,  
                 TCPIP_HTTP_NET_DynAcknowledge will be called  

  Returns:
    True if the data buffer has been queued for output.
    False if an invalid buffer was provided or the buffer could not be queued
    because of the lack of resources (descriptors).
     
  Remarks:
    This is just a helper.
    The actual function called is still TCPIP_HTTP_NET_DynamicWrite.
    That means that the supplied string has to be persistent.

    See the remarks for TCPIP_HTTP_NET_DynamicWrite.

 */

bool TCPIP_HTTP_NET_DynamicWriteString(const TCPIP_HTTP_DYN_VAR_DCPT* varDcpt, 
                                       const char* str, bool needAck);


//*****************************************************************************
/*
  Function:
    uint16_t TCPIP_HTTP_NET_ConnectionFlush(TCPIP_HTTP_NET_CONN_HANDLE connHandle);
  
  Summary:
    Immediately transmits all connection pending TX data.

  Description:
    This function calls the transport layer's flush function

  Precondition:
    connHandle - a valid HTTP connection.

  Parameters:
    connHandle - connection handle

  Returns:
    - number of flushed bytes
    - 0 if no flushed bytes or some error

 */

uint16_t TCPIP_HTTP_NET_ConnectionFlush(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

//******************************************************************************
/*
  Function:
    uint16_t TCPIP_HTTP_NET_ConnectionReadIsReady(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

  Summary:
    Determines how many bytes can be read from the connection RX buffer.

  Description:
    This function determines how many bytes can be read from the
    connection RX buffer.
  
  Precondition:
    connHandle - a valid HTTP connection.

  Parameters:
    connHandle - connection handle

  Returns:
    The number of bytes available to be read from the connection RX buffer.
	
  Remarks:
    When using an encrypted connection the number of available unencrypted bytes
    may turn out to be different than what this function returns.

  */
uint16_t TCPIP_HTTP_NET_ConnectionReadIsReady(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

//*****************************************************************************
/*
  Function:
    uint16_t TCPIP_HTTP_NET_ConnectionRead(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                           void * buffer, uint16_t size);

  Summary:
    Reads an array of data bytes from a connection's RX buffer.

  Description:
    This function reads an array of data bytes from the connection RX buffer.  
	The data is removed from the FIFO in the process.

  Precondition:
    connHandle - a valid HTTP connection.

  Parameters:
    connHandle - connection handle
    buffer - The pointer to the array to store data that was read
    size   - The number of bytes to be read.

  Returns:
    The number of bytes read from the socket.
    If less than len, the connection RX buffer became empty
    or the underlying socket is not connected.

  Remarks:
    If the supplied buffer is null, the data is simply discarded.

 */
uint16_t TCPIP_HTTP_NET_ConnectionRead(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                                      void * buffer, uint16_t size);

//*****************************************************************************
/*
  Function:
    uint16_t TCPIP_HTTP_NET_ConnectionPeek(TCPIP_HTTP_NET_CONN_HANDLE connHandle,  
                void * buffer, uint16_t size);

  Summary:
    Reads a specified number of data bytes from the connection RX buffer
    without removing them from the buffer.

  Description:
    The function allows peeking into the connection buffer.
    The data will still be available for a next read operation.

  Precondition:
    connHandle - a valid HTTP connection.

  Parameters:
    connHandle - connection handle
    buffer - Destination to write the peeked data bytes
    size   - Length of bytes to peek from the connection RX buffer 
  

  Return Values:
    The number of bytes actually peeked from the stream and copied to the buffer.

  Remarks:
    None
 */

uint16_t TCPIP_HTTP_NET_ConnectionPeek(TCPIP_HTTP_NET_CONN_HANDLE connHandle,  
                                       void * buffer, uint16_t size);

//*****************************************************************************
/*
  Function:
    uint16_t TCPIP_HTTP_NET_ConnectionDiscard(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

  Summary:
    Discards any pending data in the connection RX buffer.
  
  Description:
    This function discards data from the connection RX buffer.

  Precondition:
    connHandle - a valid HTTP connection.

  Parameters:
    connHandle - connection handle

  Returns:
    The number of bytes that have been discarded from the RX buffer.

 */
uint16_t TCPIP_HTTP_NET_ConnectionDiscard(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

//*****************************************************************************
/*
  Function:
    uint16_t TCPIP_HTTP_NET_ConnectionReadBufferSize(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

  Summary:
    Returns the size of the connection RX buffer.
  
  Description:
    This function discards data from the connection RX buffer.

  Precondition:
    connHandle - a valid HTTP connection.

  Parameters:
    connHandle - connection handle

  Returns:
    The size of the connection RX buffer.

 */
uint16_t TCPIP_HTTP_NET_ConnectionReadBufferSize(TCPIP_HTTP_NET_CONN_HANDLE connHandle);


//*****************************************************************************
/*
  Function:
    TCPIP_NET_HANDLE TCPIP_HTTP_NET_ConnectionNetHandle(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

  Summary:
    Returns the network handle of the current connection.
  
  Description:
    This function returns the network handle over which the current HTTP connection 
    communicates.

  Precondition:
    connHandle - a valid HTTP connection.

  Parameters:
    connHandle - connection handle

  Returns:
    The connection network handle.

 */
TCPIP_NET_HANDLE TCPIP_HTTP_NET_ConnectionNetHandle(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

//*****************************************************************************
/*
  Function:
    NET_PRES_SKT_HANDLE_T  TCPIP_HTTP_NET_ConnectionSocketGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle)

  Summary:
    Get the socket for the current connection.

  Description:
    The function returns the network transport socket of the specified HTTP 
    connection.
    The user gets access to the connection socket which it can use directly for 
    sending/reading data.

  Precondition:
    None.

  Parameters:
    connHandle  - HTTP connection handle

  Returns:
    NET_PRES_SKT_HANDLE_T for the connection defined by connHandle.

  Example:
  <code>
    uint32_t byteCount;
    int sktRxSize;

    byteCount = TCPIP_HTTP_NET_ConnectionByteCountGet(connHandle);
    sktRxSize = TCPIP_HTTP_NET_ConnectionReadBufferSize(connHandle);

    if(byteCount > sktRxSize)
    {   // Configuration Failure
        TCPIP_HTTP_NET_ConnectionStatusSet(connHandle, TCPIP_HTTP_NET_STAT_REDIRECT);
        return TCPIP_HTTP_NET_IO_RES_DONE;
    }
  </code>

  Remarks:
    This function gives direct access to the underlying transport socket.
    It is meant for test/advanced usage only.
    The regular connection should be used for manipulation of the connection data. 
 */
NET_PRES_SKT_HANDLE_T  TCPIP_HTTP_NET_ConnectionSocketGet(TCPIP_HTTP_NET_CONN_HANDLE connHandle);

//*****************************************************************************
/*
  Function:
    uint16_t TCPIP_HTTP_NET_ConnectionStringFind(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                               const char* str, uint16_t startOffs, uint16_t searchLen);

  Summary:
    Helper to find a string of characters in an incoming connection buffer.

  Description:
    This function searches for an ASCIIZ string in the RX buffer of the connection.
    It does the search by performing a peek operation in the RX buffer,
    (i.e., the RX data in the buffer is not consumed and it is available for further read
    operations).
    It works for both encrypted and unencrypted connections.
   
  Precondition:
    connHandle - a valid HTTP connection.

  Parameters:
    connHandle  - HTTP connection handle
    str         - 0 terminated ASCII string to search for
    startOffs   - offset in the RX buffer to start the search from
    searchLen   - if !0 it is the length of buffer to search into (starting from startOffs);
                  if 0, the whole buffer is searched


  Returns:
    - If string was found - a zero-indexed position in the RX buffer of the string 
                            occurrence
    - 0xFFFF - Search array not found

  Remarks:
    This function currently performs the search by doing a whole buffer peek into one single operation.
    Note that the search will fail if there's more data in the TCP socket than could be read at once.

 */
uint16_t TCPIP_HTTP_NET_ConnectionStringFind(TCPIP_HTTP_NET_CONN_HANDLE connHandle, 
                          const char* str, uint16_t startOffs, uint16_t searchLen);

// *****************************************************************************
// *****************************************************************************
// Section: HTTP Service Task function Prototype
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/*
  Function:
    void  TCPIP_HTTP_NET_Task(void)

  Summary:
    Standard TCP/IP stack module task function.

  Description:
    This function performs HTTP module tasks in the TCP/IP stack.

  Precondition:
    The HTTP module should have been initialized.

  Parameters:
    None.

  Returns:
    None.

  Remarks:
    None.
*/
void  TCPIP_HTTP_NET_Task(void);

//DOM-IGNORE-BEGIN
#ifdef __cplusplus
}
#endif
//DOM-IGNORE-END

#endif  // __HTTP_NET_H_
