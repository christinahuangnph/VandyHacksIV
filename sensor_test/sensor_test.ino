
const double CLEAN = 2;
const double  WAIT = 5;
const int inPin = 7; //echo
const int outPin = 8; //trigger
const int buttonPin = 11;
const int LEDPin = 4;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);

}

void loop() {
  // outPin setup
  long duration, cm;
  digitalWrite(outPin, LOW);
  delayMicroseconds(CLEAN);
  digitalWrite(outPin, HIGH);
  delayMicroseconds(WAIT);
  digitalWrite(outPin, LOW);

  // read sensor data 
  duration = pulseIn(inPin, HIGH);
  cm = msToCm(duration);
  if(cm >= 0 && cm <= 60) {
    digitalWrite(LEDPin, HIGH);
    delay(100);
    digitalWrite(LEDPin, LOW);
    Serial.println("#S|PLAY|[]#");
    delay(6000);  
  }
  delay(100);

}

long msToCm(long ms) {
  return ms / 29 /2;
}

