#include <Stepper.h>
#include <HCSR04.h>

#define echoPin 7
#define trigPin 8
#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5

const int maximumRange = 300;
const int minimumRange = 3;
const int stepPerRevolution = 100;
long distance;
int state;

HCSR04 ultrasonic(trigPin, echoPin);
Stepper stepper(stepPerRevolution, IN1, IN2, IN3, IN4);

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  stepper.setSpeed(10);
}

void loop() {
  distance = ultrasonic.dist();
  if(distance <= minimumRange || distance >= maximumRange){
    Serial.println("Tidak ada objek terdeteksi");
    if(state == 1){
      stepper.step(-300);
      state = 0;
    }
  } else {
    if(state == 0){
      stepper.step(300);
      state = 1;
    }
  }
  delay(1000);
}
