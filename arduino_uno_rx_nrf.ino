/*
* Arduino Wireless Communication Tutorial
*       Example 1 - Receiver Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
* 
* arduino uno rx 
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
int count =0;

void setup() {
  Serial.begin(9600);
  radio.begin();
  
/////////////////////////////////////////////////////////////////////////////////////////
  while (!Serial) { // some boards need to wait to ensure access to serial over USB
  }
  // initialize the transceiver on the SPI bus
  if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {}  // hold in infinite loop
  }
  else Serial.println(F("radio hardware is  responding!!"));
/////////////////////////////////////////////////////////////////////////////////////////
  
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
}

void loop() {
  
  if (radio.available()) {
    Serial.println(F("radio signal is available >> "));
    //char text[32] = "";
    //radio.read(&text, sizeof(text));
    //Serial.print(text);

    int data;
    radio.read(&data, sizeof(data));
    Serial.print(data);
    
    Serial.print(" ");
    Serial.println(count);
    count++;
  }
}
