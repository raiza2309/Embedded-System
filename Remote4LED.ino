#define LEDKuning 13
#define LEDHijau 12
#define LEDMerah 11
#define LEDBiru 10

String text;

void setup() {
  pinMode(LEDKuning, OUTPUT);
  pinMode(LEDHijau, OUTPUT);
  pinMode(LEDMerah, OUTPUT);
  pinMode(LEDBiru, OUTPUT);
  Serial.begin(9600);
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
    if(text == "kuning : on")
    { 
      Serial.println("LED Kuning : ON");
      digitalWrite(LEDKuning, HIGH);
    }
    else if(text == "kuning : off")
    {
      Serial.println("LED Kuning : OFF");
      digitalWrite(LEDKuning, LOW);
    }
    else if(text == "hijau : on")
    {
      Serial.println("LED Hijau : ON");
      digitalWrite(LEDHijau, HIGH);
    }
    else if(text == "hijau : off")
    {
      Serial.println("LED Hijau : OFF");
      digitalWrite(LEDHijau, LOW);
    }
    else if(text == "merah : on")
    {
      Serial.println("LED Merah : ON");
      digitalWrite(LEDMerah, HIGH);
    }
    else if(text == "merah : off")
    {
      Serial.println("LED Merah : OFF");
      digitalWrite(LEDMerah, LOW);
    }
    else if(text == "biru : on")
    {
      Serial.println("LED Biru : ON");
      digitalWrite(LEDBiru, HIGH);
    }
    else if(text == "biru : off")
    {
      Serial.println("LED Biru : OFF");
      digitalWrite(LEDBiru, LOW);
    }
    text = "";
  }
}
