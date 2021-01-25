#include <HCSR04.h>

#define echoPin 7
#define trigPin 8
#define LEDPin 13

HCSR04 ultrasonic(trigPin, echoPin);
const int maximumRange = 300;
const int minimumRange = 3;
long distance;

void setup() {
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  distance = ultrasonic.dist();
  if(distance <= minimumRange || distance >= maximumRange){
    Serial.println("Out of Range");
    digitalWrite(LEDPin, HIGH);
  } else {
    Serial.println("Distance : " + String(distance));
    digitalWrite(LEDPin, LOW);
  }
  delay(1000);
}
