
# 💧 Smart Water Level Monitoring and Auto Switch System

An Arduino-based smart water level monitoring system that measures water level percentage and automatically controls a switch (LED + buzzer) based on a defined threshold. The system also displays real-time water level status on an OLED display.

---

## 📌 Project Overview

This project is designed to monitor water levels in real time and automatically trigger alerts when a specific level is reached. It helps in preventing overflow and dry running conditions in water tanks and can be extended for smart home or IoT applications.

---

## ⚙️ Features

- 📊 Real-time water level monitoring
- 💡 Automatic ON/OFF switching based on threshold
- 🔔 Buzzer alert system for indication
- 📺 OLED display (SSD1306) for live status
- 📈 Water level shown in percentage (0–100%)
- ⚡ Simple and low-cost hardware design

---

## 🧠 Working Principle

1. The analog water sensor reads water level values.
2. The Arduino converts raw values into percentage (0–100%).
3. If water level is **above 35%**, the system:
   - Turns ON LED
   - Activates buzzer
   - Displays "ON" on OLED
4. If water level is **below 35%**, the system:
   - Turns OFF LED
   - Turns OFF buzzer
   - Displays "OFF" on OLED

---

## 🔧 Components Used

- Arduino UNO / Nano
- Water Level Sensor (Analog)
- OLED Display (SSD1306)
- LED
- Buzzer
- Resistors & connecting wires

---

## 📌 Circuit Connections

- Water Sensor → A0
- LED → Pin 13
- Buzzer → Pin 8
- OLED → I2C (SDA, SCL)

---

## 💻 Code

Upload the provided Arduino code using Arduino IDE with the following libraries installed:

- Adafruit GFX Library  
- Adafruit SSD1306 Library  

---

## 🚀 Future Improvements

- Add WiFi (ESP32) for remote monitoring
- Mobile app integration
- Water pump automation
- Cloud data logging (IoT dashboard)

---

## 👨‍💻 Author

Developed by **[Muhammad Zulqarnain]**  
For academic and smart system development purposes.

---

## 📜 License

This project is open-source and free to use for educational purposes.
