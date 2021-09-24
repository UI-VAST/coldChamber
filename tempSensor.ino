#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);


// Addresses of 3 DS18B20s
uint8_t sensor1[8] = { 0x28, 0x2C, 0xC2, 0x99, 0x09, 0x00, 0x00, 0x88 };
uint8_t sensor2[8] = { 0x28, 0x75, 0xF2, 0xA7, 0x08, 0x00, 0x00, 0x42 };
uint8_t sensor3[8] = { 0x28, 0x54, 0x4E, 0x98, 0x09, 0x00, 0x00, 0xD4 };


int time;

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
 
}

void loop(void)
{
  time = millis()/1000;
  sensors.requestTemperatures();

  Serial.print("Time: ");
  Serial.print(time);
  Serial.print("  ,   ");
  
  Serial.print("Temp1: ");
  printTemperature(sensor1);
  Serial.print("  ,   ");
  
  Serial.print("Temp2: ");
  printTemperature(sensor2);
  Serial.print("  ,   ");

  Serial.print("Temp3: ");
  printTemperature(sensor3);
  
  Serial.println();
  
  delay(1000);
}

void printTemperature(DeviceAddress deviceAddress)
{
  float tempC = sensors.getTempC(deviceAddress);
  Serial.print(tempC);
  Serial.print("C");
 
}
