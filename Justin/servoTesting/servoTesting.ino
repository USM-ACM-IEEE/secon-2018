#include <Servo.h>

Servo myServo;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  myServo.writeMicroseconds(900);
  delay(6750);
  myServo.writeMicroseconds(1450);
  delay(5000);
}
