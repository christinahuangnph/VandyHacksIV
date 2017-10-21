void setup() {
  const double CLEAN = 2;
  const double  WAIT = 5;
  const int motionPin = 7;
  const int buttonPin = 11;
  const int LEDPin = 4;

}

void loop() {
  // motionPin setup
  long duration, cm;
  pinMode(motionPin, OUTPUT);
  digitalWrite(motionPin, LOW);
  delayMicroseconds(CLEAN);
  digitalWrite(motionPin, HIGH);
  delayMicroseconds(WAIT);
  digitalWrite(motionPIn, LOW);

  // read sensor data
  pinMode(motionPin, INPUT);
  
  duration = pulseIn(motionPin HIGH);
  cm = msToCm(duration);
  if(cm >= 0 && cm <= 60) {
    digitalWrite(LEDPin, HIGH);
    delay(100);
    digitalWrite(LEDPin, LOW);
  }
  delay(100);

}

long msToCm(long ms) {
  return ms / 29 /2;
}

