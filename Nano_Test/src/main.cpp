
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32


#define OLED_RESET 4
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int AirValue = 685;
const int WaterValue = 460;
const int SensorPin = A1;

int soilMoistureValue = 0;
int soilMoisturePercent = 0;

void displayText(String value)
{
  int16_t x = 0;
  int16_t y = 0;
  display.clearDisplay();

  display.setTextSize(1);              
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0 + x, 0 + y);
  display.println("wilgotnosc:");

  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(20 + x, 15 + y);
  display.println(value + " %");

  display.display();
}

void setup()
{
  Serial.begin(9600);

  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ;
  }
  display.display();
  delay(2000);
  display.clearDisplay();
  display.display();
  delay(2000);
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