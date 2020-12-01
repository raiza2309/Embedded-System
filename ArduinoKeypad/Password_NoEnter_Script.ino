#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#define Password_Length 7

LiquidCrystal_I2C lcd(0x20, 20, 2);
bool Pass_Is_Good;
byte data_count = 0;
byte master_count = 0;
const byte ROWS = 4;
const byte COLS = 3;
const byte rowPins[ROWS] = {2,3,4,5};
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
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Enter Password");
  customKey = customKeypad.getKey();
  if(customKey){
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    data_count++;
  }
  if(data_count == Password_Length - 1){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Password is ");
    if(!strcmp(Data, Master)){
      lcd.print("Good");
    } else {
      lcd.print("Bad");
    }
    delay(5000);
    lcd.clear();
    clearData();
  }
}

void clearData(){
  while(data_count != 0){
    Data[data_count--] = 0;
  }
  return;
}
