/*
* Arduino Wireless Communication Tutorial
*     Example 1 - Transmitter Code
*                
* by Dejan Nedelkovski, www.HowToMechatronics.com
* 
* Library: TMRh20/RF24, https://github.com/tmrh20/RF24/
* 
* arduino  tx
*/

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
int data =0;

// Struct to hold sensor data
struct SensorData {
  float temperature;
  float humidity;
};
void setup() {
  
////////////////////////////////////////////////////////////////////////////////////////
  Serial.begin(9600);
  while (!Serial) {
    // some boards need to wait to ensure access to serial over USB
  }

  // initialize the transceiver on the SPI bus
  if (!radio.begin()) {
    Serial.println(F("radio hardware is not responding!!"));
    while (1) {}  // hold in infinite loop
  }
  else Serial.println(F("radio hardware is  responding!!"));
/////////////////////////////////////////////////////////////////////////////////////////
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  /*

    for sending string
    ------------------

    const char text[] = "Hello World";
    radio.write(&text, sizeof(text));

    for sending int 
    ---------------

    radio.write(&data, sizeof(data));
    Serial.println(data);
    data++;

  
  */
  
  SensorData data;
  
  // Simulate sensor readings (replace with actual sensor readings)
  data.temperature = 25.5;  // Example temperature value
  data.humidity = 50.0;     // Example humidity value


  radio.write(&data, sizeof(data));
  
  Serial.println(F("radio hardware is sending >> "));
  
  delay(1000);
}
