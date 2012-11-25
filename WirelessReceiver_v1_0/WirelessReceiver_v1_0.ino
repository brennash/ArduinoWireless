/**********************************************
* This is the skeleton wireless receiver (RX) 
* sketch for the Arduino Uno. 
*
* Author: Shane Brennan
* Email: Shane.Brennan.Irl@gmail.com
* Date: 25-NOV-2012
***********************************************/

#include <VirtualWire.h>
	 
uint8_t buf[VW_MAX_MESSAGE_LEN]; 
uint8_t buflen = VW_MAX_MESSAGE_LEN; 
	 
void setup() 
{
    Serial.begin(9600); 
    Serial.println("Setting up..."); 
 
    vw_setup(2000); 
    vw_rx_start();  
}
	 
void loop() 
{
    if (vw_wait_rx_max(200)) 
    {
        if (vw_get_message(buf, &buflen)) 
        {
            Serial.print("RX : ");
            for (byte i = 0; i < buflen; i++) 
            Serial.print(buf[i]);
            Serial.println("");
        }
    }
}
