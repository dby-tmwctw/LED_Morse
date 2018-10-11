#include <Arduino.h>

#ifndef LEDTRY_H
#define TEDTRY_H

class LEDTry
{
public:
  uint8_t pin;
  LEDTry(uint8_t pin_number);
  void begin();
  void flash(int frequency);
  void dim(int delay_time);
};

#endif
