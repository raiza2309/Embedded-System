#define LED 13

String command;
void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available())
  {
    delay(10);
    char c = Serial.read();
    command += c;
  }
  if(command.length() > 0)
  {
    if(command == "turn on the light")
    {
      digitalWrite(LED, HIGH);
    } else if (command == "turn off the light")
    {
      digitalWrite(LED, LOW);
    }
  }
  command = "";
}
