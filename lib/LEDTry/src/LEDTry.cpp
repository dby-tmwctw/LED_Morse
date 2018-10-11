#include <LEDTry.h>

LEDTry::LEDTry(uint8_t pin_number)
{
  pin = pin_number;
}

void LEDTry::begin()
{
  pinMode(pin, OUTPUT);
}

void LEDTry::flash(int frequency)
{
  int delay_time = 1000 / frequency;
  digitalWrite(pin, HIGH);
  delay(delay_time / 2);
  digitalWrite(pin, LOW);
  delay(delay_time / 2);
}

void LEDTry::dim(int delay_time)
{
  for (int i = 0; i < 512; i++)
  {
    if (i < 256)
    {
      analogWrite(pin, i);
      delay(delay_time);
    }
    else
    {
      analogWrite(pin, 511 - i);
      delay(delay_time);
    }
  }
}
