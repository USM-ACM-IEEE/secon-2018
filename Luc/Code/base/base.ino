#include "helpers.h"

/** stageA()
 *  
 *  start: centered directly inbetween two sides of stage A
 *  end: centered directly inbetween two sides of stage A
 */
void stageA(bool dir) {
  stepperEnable();
  
  // Select direction
  // TODO: Check if needs inverting
  digitalWrite(REAR_DIR, dir);
  digitalWrite(FRONT_DIR, dir);
  
  // Hit Button
  for(int i = 0; i < 17500; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }

  // Wait a Second
  delay(250);
  
  // Reverse direction
  digitalWrite(REAR_DIR, !dir);
  digitalWrite(FRONT_DIR, !dir);
  
  // Return to Center
  for(int i = 0; i < 15000; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }

  delay(250);

  stepperDisable();
}

/** crossGangplank()
 *  
 *  start: centered directly inbetween two sides of stage A
 *  end: centered at bottom of gangplank
 */
void crossGangplank() {
  // Back up for alignment
  stepperEnable();
  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 5000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(100);
  }
  stepperDisable();
  delay(250);
  
  // Go down gangplank
  raisePlatform();
  delay(500);
  digitalWrite(22, HIGH);
  digitalWrite(26, HIGH);
  delay(1500);
  digitalWrite(22, LOW);
  digitalWrite(26, LOW);
  delay(500);
  lowerPlatform();
  delay(500);
  
  // Back up again for alignment
  stepperEnable();
  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 15000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(50);
  }
  stepperDisable();
  delay(250);
}

/** stageB()
 *
 *  Start: Centered on bottom of gangplank
 *  End: Centered, directly inbetween stage B sides
 */
void stageB(bool dir) {
  // Go forwards
  stepperEnable();
  digitalWrite(LEFT_DIR, HIGH);
  digitalWrite(RIGHT_DIR, HIGH);
  for(int i = 0; i < 12500; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(250);
  
  // Select direction
  // TODO: Check if needs inverting
  digitalWrite(REAR_DIR, dir);
  digitalWrite(FRONT_DIR, dir);
  
  // Hit Button
  for(int i = 0; i < 17500; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }

  // Wait a Second
  delay(250);
  
  // Reverse direction
  digitalWrite(REAR_DIR, !dir);
  digitalWrite(FRONT_DIR, !dir);
  
  // Return to Center
  for(int i = 0; i < 15000; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }

  delay(250);

  stepperDisable();
}

void setup() {
  Serial.begin(115200);
  
  for(int i = 1; i <= 50; i++)
    pinMode(i, OUTPUT);

  pinMode(30, INPUT);

  // Setup Stuff
  setupPlatform();
  stepperDisable();

  delay(1000);

  // Do the things
  //stageA(digitalRead(30));
  //crossGangplank();
  stageB(digitalRead(30));
  //climbGangplank();
  //stageC(digitalRead(30));
}

// 200 + 50 + 100 + 200 + 150 + 100 + 100       = 550 + 150 + 200 = 900
// 200 + 50 + 100 + 200 + 150 + 300 + 200 + 100 = 550 + 150 + 600 = 1500


void loop() {}
