/**********************************************
* This is the skeleton wireless transmitter (TX) 
* sketch for the Arduino Uno. 
*
* Author: Shane Brennan
* Email: Shane.Brennan.Irl@gmail.com
* Date: 25-NOV-2012
***********************************************/

#include <VirtualWire.h>
	 
const char *msg = "Hello World";
int ledFlag = 0;
const int led_pin = 13;
	 
void setup()
{
    vw_setup(2000);
}
	 
void loop()
{
    vw_send((uint8_t *)msg, strlen(msg));
    vw_wait_tx();
    delay(2000);
    
    //Flash the LED
    if(ledFlag == 0)
    {
      ledFlag = 1;
      digitalWrite(led_pin, HIGH);
    }
    else
    {
      ledFlag = 0;
      digitalWrite(led_pin, LOW);    
    }
}
