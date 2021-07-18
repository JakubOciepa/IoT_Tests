#include <Arduino.h>
#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, 4, 5);

void displayText(void)
{
  int16_t x = 0;
  int16_t y = 0;
   // Demonstrates the 3 included default sizes. The fonts come from SSD1306Fonts.h file
  // Besides the default fonts there will be a program to convert TrueType fonts into this format
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0 + x, 10 + y, "wilogtnosc:");

  display.setFont(ArialMT_Plain_24);
  display.drawString(10 + x, 24 + y, "84%");
  
  display.display();
}

void setup()
{
  display.init();

  display.setContrast(255);

  display.flipScreenVertically();

  displayText();
}

void loop()
{
  // put your main code here, to run repeatedly:
}