#include <OneWire.h>
#include <DallasTemperature.h>

//Data wire is connected to the Arduino digital pin 4
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature sensor
DallasTemperature sensors(&oneWire);

void setup() {
Serial.begin(9600);
sensors.begin();
}

void loop() {
sensors.requestTemperatures();
Serial.println(sensors.getTempCByIndex(0));
delay(5000);

}
