#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int lm35Pin = A0;

void setup() {

  Serial.begin(9600);

  // OLED Start
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(1);
  }

  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {

  int sensorValue = analogRead(lm35Pin);

  float voltage = sensorValue * (5.0 / 1023.0);

  float temperatureC = voltage * 100;

  // OLED Display
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(10, 10);
  display.println("TEMP");

  display.setTextSize(3);
  display.setCursor(10, 35);
  display.print(temperatureC);
  display.print("C");

  display.display();

  delay(1000);
}
