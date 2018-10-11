#include <LEDMorse.h>

LEDMorse::LEDMorse(String code, uint8_t pin_number, int time1)
{
  initial_code = code;
  pin = pin_number;
  standard_time = time1;
}

void LEDMorse::begin()
{
  pinMode(pin, OUTPUT);
}

void LEDMorse::run()
{
  int string_length = initial_code.length();
  for (int i = 0; i < string_length; i++)
  {
    LEDMorse::parse(initial_code.charAt(i));
  }
}

void LEDMorse::short_flash()
{
  for (int i = 0; i < 16; i++)
  {
    analogWrite(pin, i * 16);
    delay(standard_time / (4 * 16));
  }
  digitalWrite(pin, HIGH);
  delay(standard_time / 2);
  for (int i = 0; i < 16; i++)
  {
    analogWrite(pin, 255 - i * 16);
    delay(standard_time / (4 * 16));
  }
  digitalWrite(pin, LOW);
  delay(standard_time);
}

void LEDMorse::long_flash()
{
  for (int i = 0; i < 16; i++)
  {
    analogWrite(pin, i * 16);
    delay(standard_time / (4 * 16));
  }
  digitalWrite(pin, HIGH);
  delay((standard_time / 2) * 5);
  for (int i = 0; i < 16; i++)
  {
    analogWrite(pin, 255 - i * 16);
    delay(standard_time / (4 * 16));
  }
  digitalWrite(pin, LOW);
  delay(standard_time);
}

void LEDMorse::parse(char character)
{
  if (character == 'A' || character == 'a')
  {
    LEDMorse::short_flash();
    LEDMorse::long_flash();
  } else if (character == 'B' || character == 'b')
  {
    LEDMorse::long_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
  } else if (character == 'C' || character == 'c')
  {
    LEDMorse::long_flash();
    LEDMorse::short_flash();
    LEDMorse::long_flash();
    LEDMorse::short_flash();
  } else if (character == 'D' || character == 'd')
  {
    LEDMorse::long_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
  } else if (character == 'E' || character == 'e')
  {
    LEDMorse::short_flash();
  } else if (character == 'F' || character == 'f')
  {
    LEDMorse::short_flash();
    LEDMorse::short_flash();
    LEDMorse::long_flash();
    LEDMorse::short_flash();
  } else if (character == 'G' || character == 'g')
  {
    LEDMorse::long_flash();
    LEDMorse::long_flash();
    LEDMorse::short_flash();
  } else if (character == 'H' || character == 'h')
  {
    LEDMorse::short_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
  } else if (character == 'I' || character == 'i')
  {
    LEDMorse::short_flash();
    LEDMorse::short_flash();
  } else if (character == 'J' || character == 'j')
  {
    LEDMorse::short_flash();
    LEDMorse::long_flash();
    LEDMorse::long_flash();
    LEDMorse::long_flash();
  } else if (character == 'K' || character == 'k')
  {
    LEDMorse::long_flash();
    LEDMorse::short_flash();
    LEDMorse::long_flash();
  } else if (character == 'L' || character == 'l')
  {
    LEDMorse::short_flash();
    LEDMorse::long_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
  } else if (character == 'M' || character == 'm')
  {
    LEDMorse::long_flash();
    LEDMorse::long_flash();
  } else if (character == 'N' || character == 'n')
  {
    LEDMorse::long_flash();
    LEDMorse::short_flash();
  } else if (character == 'O' || character == 'o')
  {
    LEDMorse::long_flash();
    LEDMorse::long_flash();
    LEDMorse::long_flash();
  } else if (character == 'P' || character == 'p')
  {
    LEDMorse::short_flash();
    LEDMorse::long_flash();
    LEDMorse::long_flash();
    LEDMorse::short_flash();
  } else if (character == 'Q' || character == 'q')
  {
    LEDMorse::long_flash();
    LEDMorse::long_flash();
    LEDMorse::short_flash();
    LEDMorse::long_flash();
  } else if (character == 'R' || character == 'r')
  {
    LEDMorse::short_flash();
    LEDMorse::long_flash();
    LEDMorse::short_flash();
  } else if (character == 'S' || character == 's')
  {
    LEDMorse::short_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
  } else if (character == 'T' || character == 't')
  {
    LEDMorse::long_flash();
  } else if (character == 'U' || character == 'u')
  {
    LEDMorse::short_flash();
    LEDMorse::short_flash();
    LEDMorse::long_flash();
  } else if (character == 'V' || character == 'v')
  {
    LEDMorse::short_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
    LEDMorse::long_flash();
  } else if (character == 'W' || character == 'w')
  {
    LEDMorse::short_flash();
    LEDMorse::long_flash();
    LEDMorse::long_flash();
  } else if (character == 'X' || character == 'x')
  {
    LEDMorse::long_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
    LEDMorse::long_flash();
  } else if (character == 'Y' || character == 'y')
  {
    LEDMorse::long_flash();
    LEDMorse::short_flash();
    LEDMorse::long_flash();
    LEDMorse::long_flash();
  } else if (character == 'Z' || character == 'z')
  {
    LEDMorse::long_flash();
    LEDMorse::long_flash();
    LEDMorse::short_flash();
    LEDMorse::short_flash();
  } else if (character == ' ')
  {
    digitalWrite(pin, LOW);
    delay(standard_time * 4);
  }
  digitalWrite(pin, LOW);
  delay(standard_time * 2);
}
