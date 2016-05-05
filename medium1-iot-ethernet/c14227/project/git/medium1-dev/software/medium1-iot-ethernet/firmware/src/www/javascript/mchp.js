
/*********************************************************************
 * Microchip TCP/IP Stack Javascript Library
 **********************************************************************
 *
 * Software License Agreement
 *
 * Copyright © 2002-2010 Microchip Technology Inc.  All rights 
 * reserved.
 *
 * Microchip licenses to you the right to use, modify, copy, and 
 * distribute: 
 * (i)  the Software when embedded on a Microchip microcontroller or 
 *      digital signal controller product (“Device”) which is 
 *      integrated into Licensee’s product; or
 * (ii) ONLY the Software driver source files ENC28J60.c and 
 *      ENC28J60.h ported to a non-Microchip device used in 
 *      conjunction with a Microchip ethernet controller for the 
 *      sole purpose of interfacing with the ethernet controller. 
 *
 * You should refer to the license agreement accompanying this 
 * Software for additional information regarding your rights and 
 * obligations.
 *
 * THE SOFTWARE AND DOCUMENTATION ARE PROVIDED “AS IS” WITHOUT 
 * WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
 * LIMITATION, ANY WARRANTY OF MERCHANTABILITY, FITNESS FOR A 
 * PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT SHALL 
 * MICROCHIP BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR 
 * CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF 
 * PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS 
 * BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE 
 * THEREOF), ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER 
 * SIMILAR COSTS, WHETHER ASSERTED ON THE BASIS OF CONTRACT, TORT 
 * (INCLUDING NEGLIGENCE), BREACH OF WARRANTY, OR OTHERWISE.
 *
 *
 * Author               Date        Comment
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Elliott Wood			12/5/07		Updated newAJAXCommand
 ********************************************************************/

// Determines when a request is considered "timed out"
var timeOutMS = 5000; //ms
 
// Stores a queue of AJAX events to process
var ajaxList = new Array();

/**
 * stores the number of dots current being shown in the rescan button
 */
var scanDots = 0;

/**
 * current iteration of the bss info read from WiFi module.
 */
var currBss = 0;

/**
 * whether to destroy or build other networks table
 */
var otherNetworkExpanded = 1;

// Initiates a new AJAX command
//	url: the url to access
//	container: the document ID to fill, or a function to call with response XML (optional)
//	repeat: true to repeat this call indefinitely (optional)
//	data: an URL encoded string to be submitted as POST data (optional)
function newAJAXCommand(url, container, repeat, data)
{
	// Set up our object
	var newAjax = new Object();
	var theTimer = new Date();
	newAjax.url = url;
	newAjax.container = container;
	newAjax.repeat = repeat;
	newAjax.ajaxReq = null;
	
	// Create and send the request
	if(window.XMLHttpRequest) {
        newAjax.ajaxReq = new XMLHttpRequest();
        newAjax.ajaxReq.open((data==null)?"GET":"POST", newAjax.url, true);
        newAjax.ajaxReq.send(data);
    // If we're using IE6 style (maybe 5.5 compatible too)
    } else if(window.ActiveXObject) {
        newAjax.ajaxReq = new ActiveXObject("Microsoft.XMLHTTP");
        if(newAjax.ajaxReq) {
            newAjax.ajaxReq.open((data==null)?"GET":"POST", newAjax.url, true);
            newAjax.ajaxReq.send(data);
        }
    }
    
    newAjax.lastCalled = theTimer.getTime();
    
    // Store in our array
    ajaxList.push(newAjax);
}

// Loops over all pending AJAX events to determine if any action is required
function pollAJAX() {	
	var curAjax = new Object();
	var theTimer = new Date();
	var elapsed;
	
	// Read off the ajaxList objects one by one
	for(i = ajaxList.length; i > 0; i--)
	{
		curAjax = ajaxList.shift();
		if(!curAjax)
			continue;
		elapsed = theTimer.getTime() - curAjax.lastCalled;
				
		// If we succeeded
		if(curAjax.ajaxReq.readyState == 4 && curAjax.ajaxReq.status == 200) {
			// If it has a container, write the result
			if(typeof(curAjax.container) == 'function'){
				curAjax.container(curAjax.ajaxReq.responseXML.documentElement);
			} else if(typeof(curAjax.container) == 'string') {
				document.getElementById(curAjax.container).innerHTML = curAjax.ajaxReq.responseText;
			} // (otherwise do nothing for null values)
			
	    	curAjax.ajaxReq.abort();
	    	curAjax.ajaxReq = null;

			// If it's a repeatable request, then do so
			if(curAjax.repeat)
				newAJAXCommand(curAjax.url, curAjax.container, curAjax.repeat);
			continue;
		}
		
		// If we've waited over 1 second, then we timed out
		if(elapsed > timeOutMS) {
			// Invoke the user function with null input
			if(typeof(curAjax.container) == 'function'){
				curAjax.container(null);
			} else {
				// Alert the user
				alert("Command failed.\nConnection to development board was lost.");
			}

	    	curAjax.ajaxReq.abort();
	    	curAjax.ajaxReq = null;
			
			// If it's a repeatable request, then do so
			if(curAjax.repeat)
				newAJAXCommand(curAjax.url, curAjax.container, curAjax.repeat);
			continue;
		}
		
		// Otherwise, just keep waiting
		ajaxList.push(curAjax);
	}
	
	// Call ourselves again in 10ms
	setTimeout("pollAJAX()",10);
	
}		

function joinNetwork() {
	// copy elements from hidden form and submit them through
	// the normal form
	
	var project_mqtt_id = document.getElementById('_project_mqtt_id').value;
	if (project_mqtt_id.length <= 0)
	{
		alert('Please enter a valid project_mqtt_id.');
		return;
	}
	document.getElementById("project_mqtt_id").value = project_mqtt_id;

	var user_mqtt_id = document.getElementById('_user_mqtt_id').value;
	if (user_mqtt_id.length <= 0)
	{
		alert('Please enter a valid user_mqtt_id.');
		return;
	}
	document.getElementById("user_mqtt_id").value = user_mqtt_id;

	var api_key = document.getElementById('_api_key').value;
	if (api_key.length <= 0)
	{
		alert('Please enter a valid api_key.');
		return;
	}
	document.getElementById("api_key").value = api_key;

	var api_password = document.getElementById('_api_password').value;
	if (api_password.length <= 0)
	{
		alert('Please enter a valid api_password.');
		return;
	}
	document.getElementById("api_password").value = api_password;

	var device_name = document.getElementById('_device_name').value;
	if (device_name.length <= 0)
	{
		alert('Please enter a valid device_name.');
		return;
	}
	document.getElementById("device_name").value = device_name;

	var sensor_type = document.getElementById('_sensor_type').value;
	if (sensor_type.length <= 0)
	{
		alert('Please select a valid sensor_type.');
		return;
	}
	document.getElementById("sensor_type").value = sensor_type;

	document.kickoff.submit();
}

function fillInputHashParams()
{
	var hashParams = window.location.hash.substr(1).split('&');
	for(var i=0; i<hashParams.length; i++)
	{
		var p = hashParams[i].split('=');
		document.getElementById(p[0]).value = decodeURIComponent(p[1]);
	}
}

window.onload = fillInputHashParams;

//kick off the AJAX Updater
setTimeout("pollAJAX()", 10);
