# MediumOne Microchip IoT Ethernet Monitoring Kit Development
####                        Developed by Saritasa 2016

## Introduction
This kit is designed to provide product designers or IOT enabled companies, a baseline and open reference design. The kit is complete with sensor, embedded, cloud, and mobile app. The kit supports out-of-the-box capabilities for sensors, including enterprise grade security and real-time cloud processing, dashboards, and companion mobile app. For information about ordering the kit & sensors, activate and setup guide, please visit https://mediumone.com/microchip/index.

This guide is intended to help you compile the firmware code for the kit and installation.

##IOT Ethernet Monitoring Kit installation:

1. Download and install MPLAB X v3.26 (no other version) Integrated Development Environment (IDE) software (make sure to install IPE as well) from Microchip website (Download Archive tab at the bottom of the page).
  http://www.microchip.com/mplab/mplab-x-ide
2. Download and install MPLAB XC32 Compiler v1.42 (no other version) from Microchip website (Downloads or Download Archive tab at the bottom of the page).
  http://www.microchip.com/mplab/compilers
3. Download and install MPLAB Harmony v1.07 (not v1.07.01 or any other version) from Microchip website (Download Archive Tab at the bottom of the page).
  http://www.microchip.com/mplab/mplab-harmony
4. On the Medium One GitHub page, click "Clone or download" on the top right and select "Download ZIP".
5. Unzip the downloaded zipped file to:
  C:/iot-smart-sensing-microchip-master which is at the same level as C:/microchip directory of MPLAB Harmony (for Mac and Linux users, the unzipped directory must be at the same level as ~/microchip directory of MPLAB Harmony).
6. Copy the entire content of ~/iot-smart-sensing-microchip-master/medium1-iot-ethernet/microchip to C:/microchip; say yes to all overwrites (for Mac and Linux users, the destination "~/microchip" directory is where MPLAB Harmony is installed).
7. Connect the PICKit, ICD3 or Real ICE debugger to your computer on one end and to the development board on the other. Connect the USB/microUSB cable to your computer on one end and to the development board on the other (this is for power, you can also power the board from its bottom using 2 x AA batteries). Finally, connect the Ethernet cable to the Internet on one end and to the development board on the other.
8. Start MPLAB X IDE, open the project located under ~/iot-smart-sensing-microchip-master/medium1-iot-ethernet/firmware/medium1-iot-ethernet.X, and click Run to download the code to the board.
  ![Running Code on the board](https://raw.githubusercontent.com/maxsaritasa/m1docs/master/images/Mplab_run.jpg)

9. Another way to run the IoT application is to download the HEX file directly onto the development board using the MPLAB Integrated Programming Environment (IPE) and the HEX file located in ~/iot-smart-sensing-microchip-master/medium1-iot-ethernet/bin.

10. Download CoolTerm if you have not installed it.
  http://freeware.the-meiers.org

11. Open Coolterm, click connect and hit enter, then write down the ip address.
![Coolterm UI](https://raw.githubusercontent.com/maxsaritasa/m1docs/master/images/cooltermm1.jpg)

12. Go to https://mediumone.com/microchip/activate to activate the kit. After activation you will receive email instruction to configure and control the kit.

##Sensors information:

  *Motion Sensor Click*

MOTION click is a motion detector sensitive only to live bodies. It carries PIR500B, a pyroelectric sensor which generates a voltage when exposed to infrared light. The signal is processed by a BIS0001 PIR sensor controller which sends an interrupt to the MCU through the mikroBUS™ INT (out) line. An onboard potentiometer lets you adjust the detecting range of the sensor (up to 4 meters). MOTION click also has a night only mode—resoldering a zero-ohm jumper activates the onboard photo resistor which acts as a light-sensitive switch. You can also switch the sensor ON and OFF by sending a signal from the MCU through the mikroBUS™ RST pin. The board uses a 3.3V power supply only.
http://www.mikroe.com/click/motion/

  *Air Quality Click*

Air quality click carries an MQ-135 sensor for detecting poisonous gases that impact air quality in homes and offices. The gas sensing layer on the sensor unit is made of tin dioxide (SnO2), which has lower conductivity in clean air. The conductivity increases with air pollution. The sensor reacts to ammonia (NH3), nitrogen oxides (NOx), benzene, smoke, CO2 and other harmful gases. To calibrate the sensor for the environment you’ll be using it in, Air quality click has a small potentiometer that allows you to adjust the load resistance of the sensor circuit. Air quality click communicates with the target board through AN (OUT) mikroBUS™ line. It’s designed to use a 5V power supply only.
http://www.mikroe.com/click/air-quality/

  *Temperature and Humidity Click*

Temp&Hum click carries ST’s HTS221 temperature and relative humidity sensor. Its temperature measurement accuracy is ±1°C within a 0-60°C range. The precision is increased to ±0.5°C in a narrower range from 15 to 40°C. The highly sensitive relative humidity measurement range is from 0 to 100% with ±6% accuracy (or ±4.5 in 20-80% range) The measurements are outputted in a 16-bit resolution through the mikroBUS™ I2C interface. The board uses a 3.3V power supply.
http://www.mikroe.com/click/temp-hum/

  *Pressure and Temperature Click*

Pressure Click™ is a compact and easy solution for adding pressure measurement to your design. It features LPS331AP digital output pressure sensor. LPS331AP IC is an ultra compact absolute piezoresistive pressure sensor capable to measure pressure (260-1260 mbar) or temperature (-40°C to 80°C) and provide a digital signal to main board microcontroller. Pressure Click™ communicates with the target board microcontroller via mikroBUS™ SPI (MOSI, MISO, SCK, CS), I2C (SDA, SCL) and INT lines. The board is designed to use 3.3V power supply only.
http://www.mikroe.com/click/pressure/
