#include <Stepper.h>

#define IN1 2
#define IN2 3
#define IN3 4
#define IN4 5
#define stepPerRevolution 100

Stepper stepper(stepPerRevolution, IN1, IN2, IN3, IN4);
String text;

void setup() {
  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  stepper.setSpeed(5);
}

void loop() {
  while(Serial.available())
  {
    delay(10);
    char c = Serial.read();
    text += c;
  }
  if(text.length() > 0)
  {
    if(text == "90")
    {
      stepper.step(25);
    }
    else if(text == "-90")
    {
      stepper.step(-25);
    }
    text = "";
  }
}
