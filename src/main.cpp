#include <Arduino.h>
#include <LEDTry.h>
#include <LEDMorse.h>

//byte LED_pin = 6;
//LEDTry LED1(LED_pin);
String input = "HELLO WORLD";
LEDMorse LED1(input, 6, 200);

void setup()
{
  Serial.begin(115200);
  //LED1.begin();
  LED1.begin();
}

void loop()
{
  /*
  LED1.dim(5);
  for (int i = 0; i < 5; i++)
  {
    LED1.flash(10);
    Serial.println("Hi there");
  }*/
  LED1.run();
  delay(1000);
}
