#include <Arduino.h>
#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, 4, 5);

void displayText(void)
{
  display.setLogBuffer(1, 30);

  display.clear();

  display.println("Hello World!!");

  display.drawLogBuffer(0,0);

  display.display();
}

void setup()
{
  display.init();

  display.setContrast(255);

  displayText();
}

void loop()
{
  // put your main code here, to run repeatedly:
}