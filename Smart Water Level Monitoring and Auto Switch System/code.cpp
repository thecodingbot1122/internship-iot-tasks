#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int waterLevelPin = A0; 
const int ledPin = 13;        
const int buzzerPin = 8;      

// Switch Threshold percentage mein (Yaani 35% se upar paani jayega toh ON hoga)
const int switchThresholdPercent = 35; 

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT); 

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    for(;;); 
  }
  
  display.clearDisplay();
  display.setTextSize(1);      
  display.setTextColor(WHITE); 
  
  display.setCursor(10, 20);
  display.print("OLED WATER SWITCH");
  display.setCursor(20, 40);
  display.print("System Ready...");
  display.display(); 
  delay(2000);
}

void loop() {
  int sensorValue = analogRead(waterLevelPin);
  
  // RAW VALUE KO 0-100% MEIN CONVERT KARNE KA FORMULA
  int waterPercent = (sensorValue / 1023.0) * 100;
  waterPercent = constrain(waterPercent, 0, 100); // Safety limit

  display.clearDisplay(); 

  // Header Title
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("--- WATER SYSTEM ---");

  // Show Percentage Value
  display.setCursor(0, 22);
  display.print("Water Level: ");
  display.setTextSize(2); 
  display.print(waterPercent);
  display.print("%");

  // Switch Status Logic (Ab percentage ke mutabiq chalega)
  display.setTextSize(1);
  display.setCursor(0, 48);
  
  if (waterPercent > switchThresholdPercent) {
    digitalWrite(ledPin, HIGH);
    digitalWrite(buzzerPin, HIGH); 
    
    display.print("SWITCH STATUS: ");
    display.setTextSize(2);
    display.print("ON");
  } 
  else {
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);  
    
    display.print("SWITCH STATUS: ");
    display.setTextSize(2);
    display.print("OFF");
  }

  display.display(); 
  delay(150);        
}
