#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is plugged into digital pin 2 on the Arduino
#define ONE_WIRE_BUS 2

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

int deviceCount = 0;
float tempInside = 0.0;
float tempOutside = 0.0;
const float baselineDifference = 5.0;
const int switchFanPin = 7;
//const int fanPwm = 5;
const float maxTempInside = 35.0;

void setup(void)
{
  // Serial opening
  Serial.begin(9600);
  // Fan pin setup
//Energy savings by writing all Digital IO status
for(int i=0; i<15; i++){
   if(i != 2 || i !=5  || i != 7){
    pinMode(i, OUTPUT);}
  }

  pinMode(switchFanPin, OUTPUT)
  digitalWrite(switchFanPin, LOW);
  //Temp Sensor Setup
  sensors.begin();  // Start up the library
  
  
  // locate devices on the bus
  Serial.print("Locating devices...");
  Serial.print("Found ");
  deviceCount = sensors.getDeviceCount();
  Serial.print(deviceCount, DEC);
  Serial.println(" devices.");
  Serial.println("");
}

void loop() {
  sensors.requestTemperatures();
  tempInside = sensors.getTempCByIndex(0);
  tempOutside = sensors.getTempCByIndex(1);
  Serial.print("Temperature Intérieur Celsius: ");
  Serial.println(tempInside);
  Serial.print("Temp outside Celsius:");
  Serial.println(tempOutside);
  
  
  if(tempInside - tempOutside > baselineDifference || tempInside > maxTempInside) {
    digitalWrite(switchFanPin, HIGH);
    } else {
      digitalWrite(switchFanPin, LOW);
      
      } 

      delay(5000);

}
