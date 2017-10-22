
#include <Servo.h>

Servo myservo; //create a servo object

const double CLEAN = 2;
const double  WAIT = 5;
const double DIST = 15;
const int inPin = 7; //echo
const int outPin = 8; //trigger
const int buttonPin = 11;
const int LEDPin = 4;
const int servoPin = 12;
int count = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  pinMode(outPin, OUTPUT);
  // initialize the LEDpin as an output.
  pinMode(LEDPin, OUTPUT);
  digitalWrite(LEDPin, HIGH); //keeps LEDs on

  myservo.attach(servoPin); //attach servo object to pin
  myservo.write(170);//goes to 15 degrees 
}

void loop() {
  // outPin setup & cleaning
  long duration, cm = 0;
  digitalWrite(outPin, LOW);
  delayMicroseconds(CLEAN);
  digitalWrite(outPin, HIGH);
  delayMicroseconds(WAIT);
  digitalWrite(outPin, LOW);

  // read sensor data 
  duration = pulseIn(inPin, HIGH);
  cm = msToCm(duration);

  // long distance
  if((cm >= DIST) && (cm <= 90)) {
      Serial.println("#S|CANDY|[]#");
      digitalWrite(LEDPin, LOW);
      delay(300);
      digitalWrite(LEDPin, HIGH);
      delay(100);
  } else if((cm > 2) && (cm < DIST)) { // close distance
      digitalWrite(LEDPin, LOW);
      delay(100);
      digitalWrite(LEDPin, HIGH);

      // trigger motor
      myservo.write(130);//goes to 15 degrees 
      delay(500);//wait for 3 seconds
      myservo.write(170);//goes to 30 degrees 
      if(count%2 == 0) { // even
        Serial.println("#S|COCO|[]#");
        delay(4000);
      } else { // odd
        Serial.println("#S|LAUGH|[]#");
        delay(4000);
        
      }
      ++count;
   
  }
  
  delay(8000); //8 seconds
}

//converts microseconds to distance
long msToCm(long ms) {
  return (ms/29/2);
}


