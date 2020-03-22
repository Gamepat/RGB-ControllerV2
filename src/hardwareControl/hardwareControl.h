#pragma once

#include <Arduino.h>
#include <util/types.h>


#define RED_PIN 0       // GPIO 0
#define GREEN_PIN 2     // GPIO 2
#define BLUE_PIN 3      // GPIO 3


void pwmControl(rgb_uint8_t values);