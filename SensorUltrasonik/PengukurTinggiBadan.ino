#include <HCSR04.h>
#include <LiquidCrystal_I2C.h>

#define echoPin 7
#define trigPin 8

HCSR04 ultrasonic(trigPin, echoPin);
LiquidCrystal_I2C lcd(0x20, 16, 2);

const int sensorPosition = 200;
const int maximumDistance = 200;
const int minimumDistance = 3;
int distance, height;

void setup() {
  lcd.begin();
}

void loop() {
  distance = ultrasonic.dist();
  lcd.clear();
  if(distance >= maximumDistance || distance <= minimumDistance){
    lcd.setCursor(2, 0);
    lcd.print("Jarak  tidak");
    lcd.setCursor(0, 1);
    lcd.print("dalam  jangkauan");
  } else {
    height = sensorPosition - distance;
    lcd.setCursor(0, 0);
    lcd.print("TINGGI = " + String(height) + " cm");
  }
  delay(2000);
}
