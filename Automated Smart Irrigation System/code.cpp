#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD setting: 0x27 address aur 16x2 size
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pins definition
const int moisturePin = A0;   // Soil Moisture Sensor Analog Pin
const int motorPin1 = 2;      // Motor Driver IN1
const int motorPin2 = 3;      // Motor Driver IN2
const int enaPin = 5;         // Motor Driver ENA

// Calibration values (Inko humne flip kar diya hai taake simulation sahi chale)
const int AirValue = 1023;    // Dry value (Maximum analog input)
const int WaterValue = 0;     // Wet value (Minimum analog input - simulation me mostly 0 hoti hai)

// Threshold percentage (Agar nami 30% se kam hogi toh pump chalega)
const int dryThreshold = 30; 

void setup() {
  // Motor driver aur speed pins ko OUTPUT set karein
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(enaPin, OUTPUT);
  
  // Shuru me pump aur speed dono ko OFF/0 rakhein
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, LOW);
  analogWrite(enaPin, 0);

  // LCD Initialize aur Backlight ON
  lcd.init();
  lcd.backlight();
  
  // Welcome Screen
  lcd.setCursor(0, 0);
  lcd.print("Smart Irrigation");
  lcd.setCursor(0, 1);
  lcd.print("System Ready...");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Sensor se raw analog value read karein
  int rawValue = analogRead(moisturePin);
  
  // CRITICAL FIX: Map function ko sahi kiya hai
  // Jab rawValue = AirValue (1023) hogi -> 0% dikhayega
  // Jab rawValue = WaterValue (0) hogi -> 100% dikhayega
  int moisturePercent = map(rawValue, WaterValue , AirValue, 0, 100);
  
  // Constrain taake value 0% se 100% ke darmiyan hi rahe
  moisturePercent = constrain(moisturePercent, 0, 100);

  // LCD Line 1: Moisture Level Display
  lcd.setCursor(0, 0);
  lcd.print("Moisture: ");
  lcd.print(moisturePercent);
  lcd.print("%   "); // Extra spaces purani digits ko clear karne ke liye

  // LCD Line 2 & Motor Logic
  lcd.setCursor(0, 1);
  if (moisturePercent < dryThreshold) {
    // Agar nami threshold se kam hai (Mitti khushk hai) -> Pump ON
    digitalWrite(motorPin1, HIGH);
    digitalWrite(motorPin2, LOW);
    analogWrite(enaPin, 180); // Speed set to 180
    lcd.print("Pump: ON        ");
  } else {
    // Agar nami kaafi hai (Mitti geeli hai) -> Pump OFF
    digitalWrite(motorPin1, LOW);
    digitalWrite(motorPin2, LOW);
    analogWrite(enaPin, 0); // Speed 0
    lcd.print("Pump: OFF       ");
  }

  delay(1000); // Har 1 second baad update hoga
}
