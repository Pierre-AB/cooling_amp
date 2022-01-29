
// import DS18B20 related library

#include <OneWire.h>
#include <DallasTemperature.h>

//Data wire is connected to the Arduino digital pin 4
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

const float baselineTemp = 26.0;
float tempInside = 0;
const int switchFanPin = 7;
const int fanPwm = 5;

void setup() {
  Serial.begin(9600);
  pinMode(switchFanPin, OUTPUT);
  digitalWrite(switchFanPin, LOW);
  sensors.begin();  

}

void loop() {
  sensors.requestTemperatures();
  tempInside = sensors.getTempCByIndex(0);
  Serial.print("Temperature Celsius: ");
  Serial.println(tempInside);


  if(tempInside > baselineTemp) {
    digitalWrite(switchFanPin, HIGH);
    } else {
      digitalWrite(switchFanPin, LOW);
      
      }

   

      delay(5000);

}
