/**
 * @file hardwareControl.h
 * @author JakobL
 * @brief 
 * @version 0.1
 * @date 2020-10-09
 */

#ifndef HARDWARE_CONTROL_H_
#define HARDWARE_CONTROL_H_


#include "util/types.h"


#define RED_PIN 0       // GPIO 0
#define GREEN_PIN 2     // GPIO 2
#define BLUE_PIN 3      // GPIO 3


void HW_SetupRGBPins();
void HW_SetPWMToRGB(rgb_uint8_t values);


#endif // HARDWARE_CONTROL_H_