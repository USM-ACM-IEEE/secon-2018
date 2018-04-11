#include "helpers.h"

void setup() {
  for(int i = 1; i <= 50; i++)
    pinMode(i, OUTPUT);

  // Setup Stuff
  stepperDisable();
  setupPlatform();

  delay(1000);

  // Run
  raisePlatform();
  delay(500);
  
  digitalWrite(22, HIGH);
  digitalWrite(26, HIGH);
  delay(2000);
  digitalWrite(22, LOW);
  digitalWrite(26, LOW);

  delay(500);
  lowerPlatform();
}

void loop() {}
