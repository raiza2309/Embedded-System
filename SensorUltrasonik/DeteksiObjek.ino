#define echoPin 7
#define trigPin 8
#define LEDPin 13

const int maximumRange = 300;
const int minimumRange = 0;
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 29 / 2;
  if(distance <= minimumRange || distance >= maximumRange){
    Serial.println("Out of Range");
    digitalWrite(LEDPin, HIGH);
  } else {
    Serial.println("Distance : " + String(distance));
    digitalWrite(LEDPin, LOW);
  }
  delay(1000);
}
