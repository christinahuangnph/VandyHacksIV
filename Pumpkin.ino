#include <Servo.h>

Servo myservo; //create a servo object

const double CLEAN = 2;
const double  WAIT = 5;
const double DIST = 5;
const int inPin = 7; //echo
const int outPin = 8; //trigger
const int buttonPin = 11;
const int LEDPin = 4;
const int servoPin = 12;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  // initialize the LEDpin as an output.
  pinMode(LEDPin, OUTPUT);

  myservo.attach(servoPin); //attach servo object to pin
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
  if(cm >= DIST && cm <= 60) {
    digitalWrite(LEDPin, HIGH);
    delay(5000); //keep lit for 10 seconds
    digitalWrite(LEDPin, LOW);

    //trigger sound file
    Serial.print("test");
  }

  if(cm >= 0 && cm <= DIST) {
    digitalWrite(LEDPin, HIGH);
    delay(5000); //keep lit for 10 seconds
    digitalWrite(LEDPin, LOW);

    //trigger motor
    myservo.write(170);//goes to 15 degrees 
    delay(3000);//wait for a second
    myservo.write(130);//goes to 30 degrees 
    delay(500);//wait for a second.33
  }
  
  delay(1000); //1 seconds

}

long msToCm(long ms) {
  return ms / 29 /2;
}
