#ifndef HELPER_H
#define HELPER_H

#include <Arduino.h>
#include <Servo.h>
#include "pins.h"

void stepperEnable();
void stepperDisable();

void setupPlatform();
void raisePlatform();
void lowerPlatform();

#endif
