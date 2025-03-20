#define BUZZER 3
const int sensor = A1;
float sm;
float vout;
#include <Servo.h>

Servo myservo1;
Servo myservo2;
int pos = 0;

void setup() {
  pinMode(sensor, INPUT);        // Configuring pin A1 as input
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);

  myservo1.attach(6);            // Corrected variable name from "myservol" to "myservo1"
  myservo2.attach(7);

  myservo1.write(0);
  myservo2.write(90);
}

void loop() {
  vout = analogRead(sensor);    // Fixed assignment
  vout = (vout * 100) / 1023;   // Corrected calculation with '=' instead of '-'

  sm = vout;                    // Storing value in degree Celsius

  if (sm > 50) {
    digitalWrite(BUZZER, HIGH);  // Fixed "digitalkrite" typo
    myservo1.write(90);
    myservo2.write(0);
    delay(500);
  } else {
    digitalWrite(BUZZER, LOW);   // Fixed "digitallerite" typo
    myservo1.write(0);
    myservo2.write(90);
    delay(500);
  }

  delay(10);
}
