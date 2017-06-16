# MediumOne Microchip IoT Ethernet Monitoring Kit Development
####                        Developed by Saritasa 2016


This guide is intended Windows users.

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

