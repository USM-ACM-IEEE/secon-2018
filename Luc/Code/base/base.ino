#include <Servo.h>

#define STEPPER_ENABLE_PIN 8

#define REAR_STEP 2
#define REAR_DIR 5

#define LEFT_STEP 3
#define LEFT_DIR 6

#define RIGHT_STEP 4
#define RIGHT_DIR 7

#define FRONT_STEP 34
#define FRONT_DIR 35

#define PLATFORM_SERVO_1 9
#define PLATFORM_SERVO_2 10

/***********************************************************
************************************************************
***********************************************************/
// Helper functions

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
  delay(500); // Wait for action to complete
}

void lowerPlatform() {
  platformServo1.writeMicroseconds(2500);
  platformServo2.writeMicroseconds(100);
  delay(500); // Wait for action to complete
}

void xTravel(bool dir, int pulseCount, int pulseLength, bool carryMomentum) {
  stepperEnable();
  
  // Select direction
  digitalWrite(REAR_DIR, dir);
  digitalWrite(FRONT_DIR, dir);
  
  for(int i = 0; i < pulseCount; i++) {
    // 50us pulse to stepper driver
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    
    // Wait to control speed
    delayMicroseconds(pulseLength);
  }

  if(carryMomentum)
    stepperDisable();

  // Wait for momentum to subside
  delay(250);
}

void yTravel(bool dir, int pulseCount, int pulseLength, bool carryMomentum) {
  stepperEnable();
  
  // Select direction
  digitalWrite(LEFT_DIR, dir);
  digitalWrite(RIGHT_DIR, dir);
  
  for(int i = 0; i < pulseCount; i++) {
    // 50us pulse to stepper driver
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    
    // Wait to control speed
    delayMicroseconds(pulseLength);
  }

  if(carryMomentum)
    stepperDisable();

  // Wait for momentum to subside
  delay(250);
}

/***********************************************************
************************************************************
***********************************************************/
// Stage functional blocks

void stageA(bool dir) {
  xTravel(dir, 20000, 50, false);  // Go to side to hit button
  xTravel(!dir, 15000, 50, false); // Return to center
  stepperDisable();                // Disable stepper motors
}

void crossGangplank() {
  // Back up to align with field
  yTravel(LOW, 5000, 100, true);
  
  raisePlatform();

  // Turn the DC motors on
  digitalWrite(22, HIGH);
  digitalWrite(26, HIGH);
  delay(1500);

  // Turn the DC motors off
  digitalWrite(22, LOW);
  digitalWrite(26, LOW);
  delay(500);
  
  lowerPlatform();

  // Back up to align with field
  yTravel(LOW, 15000, 100, true);
}

void climbGangplank() {
  // Back up to align with field
  yTravel(LOW, 17500, 50, true);
  
  raisePlatform();

  // Turn the DC motors on
  digitalWrite(24, HIGH);
  digitalWrite(28, HIGH);
  delay(1750);
  
  // Turn the DC motors off
  digitalWrite(24, LOW);
  digitalWrite(28, LOW);
  delay(500);
  
  lowerPlatform();

  // Back up to align with field
  yTravel(LOW, 15000, 50, true);

  // Go back to where we started (hopefully)
  yTravel(HIGH, 3500, 50, false);
  stepperDisable();
}

/***********************************************************
************************************************************
***********************************************************/
// Main program setup and loop

// Run our program once
void setup() {
  for(int i = 1; i <= 50; i++)
    pinMode(i, OUTPUT);

  // Setup Stuff
  setupPlatform();
  stepperDisable();

  // Wait for setup
  delay(1000);

  // Run the subroutines
  stageA(HIGH);
  crossGangplank();
  climbGangplank();
}

void loop() {}
