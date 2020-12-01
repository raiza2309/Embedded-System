#include <Keypad.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Tes Edit

long first = 0;
long second = 0;
double total = 0;

// Tes Edit 2

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'7', '8', '9', '/'},
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};

byte rowPins[ROWS] = {11, 10, 9, 8};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  lcd.begin();
  lcd.backlight();
}

void loop() {
  customKey = customKeypad.getKey();
  switch(customKey){
    case '0' ... '9':
      lcd.setCursor(0,0);
      first = first * 10 + (customKey - '0');
      lcd.print(first);
      break;
    case '+':
      first = (total != 0 ? total : first);
      lcd.print(" + ");
      second = secondNumber();
      total = first + second;
      lcd.setCursor(0,1);
      lcd.print(total);
      first = 0;
      second = 0;
      break;
    case '-':
      first = (total != 0 ? total : first);
      lcd.print(" - ");
      second = secondNumber();
      total = first - second;
      lcd.setCursor(0,1);
      lcd.print(total);
      first = 0;
      second = 0;
      break;
    case '*':
      first = (total != 0 ? total : first);
      lcd.print(" * ");
      second = secondNumber();
      total = first * second;
      lcd.setCursor(0,1);
      lcd.print(total);
      first = 0;
      second = 0;
      break;
    case '/':
      first = (total != 0 ? total : first);
      lcd.print(" / ");
      second = secondNumber();
      second == 0 ? lcd.print("Invalid") : total = (float)first / (float)second;
      lcd.setCursor(0,1);
      lcd.print(total);
      first = 0;
      second = 0;
      break;
    case 'C':
      total = 0;
      first = 0;
      second = 0;
      lcd.clear();
      break;
  }
}

long secondNumber(){
  while(1){
    customKey = customKeypad.getKey();
    if(customKey >= '0' && customKey <= '9'){
      second = second * 10 + (customKey - '0');
      lcd.setCursor(String(first).length() + 3, 0);
      lcd.print(second);
    }
    if(customKey == '=')
      break;
  }
  return second;
}
