
#define s1Analog A5
#define s1Digital 5
#define s1PowerPin 7

#define s2Analog A4
#define s2Digital 6
#define s2PowerPin 8

/*
testing with a cup of water and a dry sensor at 5V:
  - water is around 200
  - dry is around 900
testing with a cup of water and a dry sensor at 3V:
  - water is around 260
  - dry is around 1006
spec sheet says:
  - sensor in dry soil: 0
  - sensor in humid soil: 300
  - sensor in water: 700
*/

int sensorFloor = 250;
int sensorCeiling = 1010;

// establish base vars
int s1AnalogValue = 0;
int s2AnalogValue = 0;
int s1DigitalValue = 0;
int s2DigitalValue = 0;

void setup() {
  Serial.begin(9600);
  
  // sensors are powered by digital pins to
  // this allows us to powerdown the sensor when not in use
  pinMode(s1PowerPin, OUTPUT);
  pinMode(s2PowerPin, OUTPUT);


}

void loop() {
  // bring senors online  
  digitalWrite(s1PowerPin, HIGH);
  digitalWrite(s2PowerPin, HIGH);
  delay(600);  
  
  s1AnalogValue = analogRead(s1Analog);
  s2AnalogValue = analogRead(s2Analog);
  
  s1DigitalValue = digitalRead(s1Digital);
  s2DigitalValue = digitalRead(s2Digital);

  // 0 is wet, 100 is dry

  int s1 = map(s1AnalogValue, sensorFloor, sensorCeiling, 0, 100);
  int s2 = map(s2AnalogValue, sensorFloor, sensorCeiling, 0, 100);

  if (s1 < 25 ) {
    Serial.println("Sensor 1 is wet");
  }

  if (s2 < 25 ) {
    Serial.println("Sensor 2 is wet");
  }
  
  Serial.print("s1Analog: ");
  Serial.print(s1AnalogValue);
  Serial.print("\t");

  Serial.print("s1Digital: ");
  Serial.print(s1DigitalValue);
  Serial.print("\t");

  Serial.print("s1 Mapped: ");
  Serial.print(s1);
  Serial.print("\t");

  Serial.print("s2Analog: ");
  Serial.print(s2AnalogValue);
  Serial.print("\t");

  Serial.print("s2Digital: ");
  Serial.print(s2DigitalValue);
  Serial.print("\t");

  Serial.print("s2 Mapped: ");
  Serial.print(s2);
  Serial.println("\t");
  
  Serial.println("napping...");

  digitalWrite(s1PowerPin, LOW);
  digitalWrite(s2PowerPin, LOW);
  delay(6000);

 

}
