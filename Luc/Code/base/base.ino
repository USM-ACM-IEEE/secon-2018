#include "helpers.h"
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x3F, 16, 2);
Servo servo1;
Servo servo2;


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
  for(int i = 0; i < 20000; i++) {
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
  for(int i = 0; i < 13500; i++) {
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
  for(int i = 0; i < 12000; i++) {
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

void treasureChest() {
  stepperEnable();

  digitalWrite(LEFT_DIR, HIGH);
  digitalWrite(RIGHT_DIR, HIGH);
  for(int i = 0; i < 15000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(250);

  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 15000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(250);

  stepperDisable();
}

void align() {
  stepperEnable();
  digitalWrite(LEFT_DIR, HIGH);
  digitalWrite(RIGHT_DIR, HIGH);
  for(int i = 0; i < 7500; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(250);

  digitalWrite(REAR_DIR, HIGH);
  digitalWrite(FRONT_DIR, HIGH);
  for(int i = 0; i < 25000; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }
  delay(250);

  digitalWrite(REAR_DIR, LOW);
  digitalWrite(FRONT_DIR, LOW);
  for(int i = 0; i < 15000; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }
  delay(250);
  
  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 7500; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(250);
  
  stepperDisable();
}

void climbGangplank() {
  stepperEnable();

  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 17500; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(250);

  stepperDisable();
  
  // Go down gangplank
  raisePlatform();
  delay(500);
  digitalWrite(24, HIGH);
  digitalWrite(28, HIGH);
  delay(1750);
  digitalWrite(24, LOW);
  digitalWrite(28, LOW);
  delay(500);
  lowerPlatform();
  delay(500);

  // Back up for alignment
  stepperEnable();
  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 15000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(100);
  }
  stepperDisable();
  delay(250);

  // Go Forwards
  stepperEnable();
  digitalWrite(LEFT_DIR, HIGH);
  digitalWrite(RIGHT_DIR, HIGH);
  for(int i = 0; i < 3500; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(100);
  }
  delay(250);
  stepperDisable();
}

void climbGangplankBackwards() {  
  // Go down gangplank
  raisePlatform();
  delay(500);
  digitalWrite(24, HIGH);
  digitalWrite(28, HIGH);
  delay(3000);
  digitalWrite(24, LOW);
  digitalWrite(28, LOW);
  delay(500);
  lowerPlatform();
  delay(500);
}

void raiseFlag() {
  stepperEnable();
  
  digitalWrite(LEFT_DIR, HIGH);
  digitalWrite(RIGHT_DIR, HIGH);
  for(int i = 0; i < 10000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(50);
  }
  delay(500);
  
  digitalWrite(REAR_DIR, HIGH);
  digitalWrite(FRONT_DIR, HIGH);
  for(int i = 0; i < 15000; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }
  delay(500);
  
  digitalWrite(LEFT_DIR, HIGH);
  digitalWrite(RIGHT_DIR, HIGH);
  for(int i = 0; i < 25000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(50);
  }
  delay(500);
  
  digitalWrite(REAR_DIR, HIGH);
  digitalWrite(FRONT_DIR, HIGH);
  for(int i = 0; i < 2000; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }
  delay(500);
  
  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 2500; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(50);
  }
  
  delay(500);
  digitalWrite(REAR_DIR, LOW);
  digitalWrite(FRONT_DIR, LOW);
  for(int i = 0; i < 13350; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }
  delay(500);
  
  digitalWrite(LEFT_DIR, HIGH);
  digitalWrite(RIGHT_DIR, HIGH);
  for(int i = 0; i < 5000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(50);
  }
  delay(500);
  stepperDisable();

  servo2.write(170);
  delay(500);
  //servo1.write(70);
  servo1.writeMicroseconds(900);
  delay(6750);
  
  servo1.write(90);
  delay(500);
  servo2.write(160);
  
  stepperEnable();
  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 5000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(50);
  }
  
  delay(500);
  
  digitalWrite(REAR_DIR, HIGH);
  digitalWrite(FRONT_DIR, HIGH);
  for(int i = 0; i < 13350; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }
  
  delay(500);
  
  digitalWrite(LEFT_DIR, HIGH);
  digitalWrite(RIGHT_DIR, HIGH);
  for(int i = 0; i < 2500; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(50);
  }
  
  delay(500);
  
  digitalWrite(REAR_DIR, LOW);
  digitalWrite(FRONT_DIR, LOW);
  for(int i = 0; i < 2000; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }
  
  delay(500);
  
  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 25000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(50);
  }
  
  delay(500);
  
  digitalWrite(REAR_DIR, LOW);
  digitalWrite(FRONT_DIR, LOW);
  for(int i = 0; i < 15000; i++) {
    digitalWrite(REAR_STEP, HIGH);
    digitalWrite(FRONT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(REAR_STEP, LOW);
    digitalWrite(FRONT_STEP, LOW);
    delayMicroseconds(50);
  }
  
  delay(500);
  
  digitalWrite(LEFT_DIR, LOW);
  digitalWrite(RIGHT_DIR, LOW);
  for(int i = 0; i < 10000; i++) {
    digitalWrite(LEFT_STEP, HIGH);
    digitalWrite(RIGHT_STEP, HIGH);
    delayMicroseconds(50);
    digitalWrite(LEFT_STEP, LOW);
    digitalWrite(RIGHT_STEP, LOW);
    delayMicroseconds(50);
  }
  
  delay(500);

  stepperDisable();
}

void setup() {
  pinMode(BIT_0_IN, INPUT); // Bit 0 (1's place)
  pinMode(BIT_1_IN, INPUT); // Bit 1 (2's place)
  pinMode(BIT_2_IN, INPUT); // Bit 2 (4's place)
  pinMode(READY_IN, INPUT); // Ready (High if signal is treasure map)

  // Initialize LCD
  lcd.begin();
  
  Serial.begin(115200);
  
  for(int i = 1; i <= 50; i++)
    pinMode(i, OUTPUT);

  pinMode(30, INPUT);
  pinMode(40, INPUT);
  pinMode(41, INPUT);
  pinMode(42, INPUT);
  pinMode(43, INPUT);

  servo1.attach(FLAG_TURNER);
  servo2.attach(FLAG_TURNER_ARM);

  servo1.write(90);
  servo2.write(160);

  // Setup Stuff
  setupPlatform();
  stepperDisable();

  delay(1000);

  int value;
  bool done = false;
  bool bits[3];

  do {
    bits[0] = digitalRead(BIT_2_IN); // Stage A
    bits[1] = digitalRead(BIT_1_IN); // Stage B
    bits[2] = digitalRead(BIT_0_IN); // Stage C

    value = 4*bits[0] + 2*bits[1] + bits[2];

    // Print value
    if(digitalRead(READY_IN)) {
      lcd.setCursor(0, 0);
      lcd.print(value+1);
      lcd.print(".");
      done = true;
    }
    
    // Print alignment status
    lcd.setCursor(0, 1);
    if(!digitalRead(READY_IN) && value == 7) {
      lcd.print("Aligned!");
    } else {
      lcd.print("        ");
    }
  } while(!done);

  // Do the things
  stageA(bits[0]);
  crossGangplank();
  stageB(bits[1]);
  raiseFlag();
  climbGangplank();
  stageA(bits[2]);

  // Testing
  //climbGangplankBackwards();
}

void loop() {
}
