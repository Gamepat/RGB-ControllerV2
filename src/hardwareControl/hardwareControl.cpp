#include "hardwareControl.h"

#include <Arduino.h>
#include "util/types.h"


void setupHardwarePins() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}


void pwmControl(rgb_uint8_t values) {

  // red
  analogWrite(RED_PIN, map(values.r, 0, 255, 0, 1023));
  // green
  analogWrite(GREEN_PIN, map(values.g, 0, 255, 0, 1023));
  // blue
  analogWrite(BLUE_PIN, map(values.b, 0, 255, 0, 1023));
}