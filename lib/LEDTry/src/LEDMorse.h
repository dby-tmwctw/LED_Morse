#include <Arduino.h>

#ifndef LEDMORSE_H
#define LEDMORSE_H

class LEDMorse
{
public:
  uint8_t pin; // Pin number
  LEDMorse(String code, uint8_t pin_number, int time1); // Initialiser
  void begin(); // Setting up the pin
  void run(); // Run the programme
private:
  String initial_code;
  int standard_time; // Time for a standard unit in Morse Code
  void long_flash();
  void short_flash();
  void parse(char character); // Take in a character and do Morse code
};

#endif
