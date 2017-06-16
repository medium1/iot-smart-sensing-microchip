# MediumOne Microchip IoT Ethernet Monitoring Kit Development

## Introduction
This kit is designed to provide product designers or IOT enabled companies, a baseline and open reference design. The kit is complete with sensor, embedded, cloud, and mobile app. The kit supports out-of-the-box capabilities for sensors, including enterprise grade security and real-time cloud processing, dashboards, and companion mobile app. For information about ordering the kit & sensors, activate and setup guide, please visit https://mediumone.com/microchip/index.

##IOT Ethernet Monitoring Kit installation:

Follow this guide to download and compile the project. https://blog.mediumone.com/2017/04/microchip-iot-ethernet-kit-instructions/

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
