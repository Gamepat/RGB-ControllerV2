#include "utils.h"

#include <Arduino.h>
#include "types.h"


//* converts a hex value into three 8-Bit RGB values 
void hexToRGBConverter(uint32_t hex_val, rgb_uint8_t *rgb_val) {
  
  rgb_val->r = hex_val >> 16;
  rgb_val->g = (hex_val & 0x00FF00) >> 8;
  rgb_val->b = (hex_val & 0x0000FF);
}

void append(char* s, char c) {
  int len = strlen(s);
  s[len] = c;
  s[len+1] = '\0';
}