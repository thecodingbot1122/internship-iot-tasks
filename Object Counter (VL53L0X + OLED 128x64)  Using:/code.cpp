#include <Wire.h>
#include <VL53L0X.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

VL53L0X sensor;

int objectCount = 0;
bool objectDetected = false;

void setup() {

  Serial.begin(9600);

  Wire.begin();

  // OLED Start
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED not found");
    while(1);
  }

  // VL53L0X Start
  sensor.init();
  sensor.setTimeout(500);

  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {

  int distance = sensor.readRangeSingleMillimeters();

  // Detect object
  if(distance < 100 && !objectDetected) {

    objectCount++;
    objectDetected = true;
  }

  // Reset detection
  if(distance > 150) {
    objectDetected = false;
  }

  // OLED Display
  display.clearDisplay();

  display.setTextSize(2);
  display.setCursor(0, 0);
  display.println("Counter");

  display.setTextSize(2);
  display.setCursor(0, 25);
  display.print("Count:");
  display.println(objectCount);

  display.setTextSize(1);
  display.setCursor(0, 55);
  display.print("Dist:");
  display.print(distance);
  display.print(" mm");

  display.display();

  delay(100);
}
