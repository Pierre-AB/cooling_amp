const int firstSensorPin = A0;
const float baselineTemp = 30.0;
const float firstTemp = 0;
const int switchFanPin = 7; //3
const int fanPwm = 5;

void setup() {
  Serial.begin(9600);
  pinMode(switchFanPin, OUTPUT);
  digitalWrite(switchFanPin, LOW);
  

}

void loop() {
  int sensorVal = analogRead(firstSensorPin);
  Serial.print("Valeur capteur : ");
  Serial.print(sensorVal);

  float voltage = (sensorVal/1024.0)*5.0;
  Serial.print(", Volts : ");
  Serial.print(voltage);
  Serial.print(", degres C : ");
  float temperature = (voltage - 0.5)*100;
  Serial.println(temperature);


  if(temperature > baselineTemp) {
    digitalWrite(switchFanPin, HIGH);
    } else {
      digitalWrite(switchFanPin, LOW);
      
      }

}
