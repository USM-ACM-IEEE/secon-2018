#include "helpers.h"

void stepperEnable() {
  digitalWrite(STEPPER_ENABLE_PIN, LOW);
}

void stepperDisable() {
  digitalWrite(STEPPER_ENABLE_PIN, HIGH);
}

// Platform Stuff
Servo platformServo1;
Servo platformServo2;

void setupPlatform() {
  lowerPlatform();
  platformServo1.attach(PLATFORM_SERVO_1);
  platformServo2.attach(PLATFORM_SERVO_2);
}

void raisePlatform() {
  platformServo1.writeMicroseconds(100);
  platformServo2.writeMicroseconds(2500);
}

void lowerPlatform() {
  platformServo1.writeMicroseconds(2500);
  platformServo2.writeMicroseconds(100);
}
