// Basic Bluetooth sketch HC-05_AT_MODE_01
// Communicate with a HC-05 using the serial monitor
//
// The HC-05 defaults to communication mode when first powered on you will need to manually enter AT mode
// The default baud rate for AT mode is 38400
// See www.martyncurrey.com for details
// And http://www.martyncurrey.com/arduino-with-hc-05-bluetooth-module-at-mode/


// AT commands
// AT : Check the connection
// AT+NAME : See default name
// AT+ADDR : see default address
// AT+VERSION : See version
// AT+UART : See baudrate
// AT+ROLE: See role of bt module(1=master/0=slave)
// AT+RESET : Reset and exit AT mode
// AT+ORGL : Restore factory settings
// AT+PSWD: see default password
// Set them by using = e.g. AT+PSWD=0000

#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 11); // RX | TX

char c = ' ';

void setup()
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    Serial.println("Remember to select Both NL & CR in the serial monitor");

    // HC-05 default serial speed for AT mode is 38400
    BTserial.begin(38400);
}

void loop()
{

    // Keep reading from HC-05 and send to Arduino Serial Monitor
    if (BTserial.available())
    {
        c = BTserial.read();
        Serial.write(c);
    }

    // Keep reading from Arduino Serial Monitor and send to HC-05
    if (Serial.available())
    {
        c =  Serial.read();
        BTserial.write(c);
    }

}
