#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "SSD1306Wire.h"

SSD1306Wire display(0x3c, 4, 5);

const int AirValue = 3500;
const int WaterValue = 1320;
const int SensorPin = 15;

int soilMoistureValue = 0;
int soilMoisturePercent = 0;

void displayText(String value)
{

  display.clear();

  int16_t x = 0;
  int16_t y = 0;

  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_10);
  display.setFont(ArialMT_Plain_10);
  display.drawString(0 + x, 10 + y, "wilogtnosc:");

  display.setFont(ArialMT_Plain_24);
  display.drawString(10 + x, 24 + y, value + " %");

  display.display();
}

void setup()
{

  Serial.begin(9600);

  display.init();

  display.setContrast(255);

  display.flipScreenVertically();
}

void loop()
{
  soilMoistureValue = analogRead(SensorPin);
  Serial.println(soilMoistureValue, DEC);
  
  soilMoisturePercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);

  if (soilMoisturePercent > 100)
  {
    displayText("100");
  }
  else if (soilMoisturePercent <= 0)
  {
    displayText("0");
  }
  else if (soilMoisturePercent >= 0 && soilMoisturePercent <= 100)
  {
    String myString = String(soilMoisturePercent);
    displayText(myString);
  }

  delay(1000);
}