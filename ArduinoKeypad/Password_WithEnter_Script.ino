#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#define Password_Length 7

LiquidCrystal_I2C lcd(0x20, 20, 2);
bool Pass_Is_Good;
byte data_count = 0;
byte master_count = 0;
const byte ROWS = 4;
const byte COLS = 3;
const byte pinRed = 6;
const byte pinGreen = 7;
const byte rowPins[ROWS] = {5,4,3,2};
const byte colPins[COLS] = {10,9,8};
char Data[Password_Length]; // 6 karakter data + 1 karakter null = 7
char Master[Password_Length] = "123456";
char customKey;
char keys[ROWS][COLS] = {
  {'1', '2', '3'},
  {'4', '5', '6'},
  {'7', '8', '9'},
  {'*', '0', '#'}
};
Keypad customKeypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin();
  lcd.backlight();
  pinMode(pinRed, OUTPUT);
  pinMode(pinGreen, OUTPUT);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  customKey = customKeypad.getKey();
  switch(customKey){
    case '0' ... '9':
      Data[data_count] = customKey;
      lcd.setCursor(data_count, 1);
      lcd.print(Data[data_count]);
      data_count++;
      break;
    case '#':
      lcd.clear();
      lcd.setCursor(3, 0);
      if(!strcmp(Data, Master)){
        lcd.print("SELAMAT DATANG");
        digitalWrite(pinGreen, HIGH);
      } else {
        lcd.print("PASSWORD SALAH");
        digitalWrite(pinRed, HIGH);
      }
      delay(5000);
      lcd.clear();
      clearData();
      resetLED();
      break;
  }
}

void clearData(){
  while(data_count != 0){
    Data[data_count--] = 0;
  }
  return;
}

void resetLED(){
  digitalWrite(pinRed, LOW);
  digitalWrite(pinGreen, LOW);
}
