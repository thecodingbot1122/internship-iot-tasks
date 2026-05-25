# 🌱 Automated Smart Irrigation System

An Arduino-based **Automated Smart Irrigation System** that automatically monitors soil moisture and controls a water pump when the soil becomes dry.  
The system displays real-time soil moisture percentage and pump status on a 16x2 I2C LCD.

---

## 📌 Project Overview

This project helps in **smart farming** and **water conservation** by automating the irrigation process.  
The soil moisture sensor continuously checks the moisture level of the soil.

- If the soil becomes **dry**, the water pump turns **ON**
- If the soil is **wet enough**, the water pump turns **OFF**

The system also shows:

- Soil moisture percentage
- Pump status (ON/OFF)

on the LCD display.

---

## 🖼️ Circuit Diagram

![Circuit Diagram](circuit_diagram.png)

---

# 🛠️ Components Used

| Component                  | Quantity |
| -------------------------- | -------- |
| Arduino UNO                | 1        |
| Soil Moisture Sensor       | 1        |
| L298N Motor Driver         | 1        |
| DC Water Pump / DC Motor   | 1        |
| 16x2 I2C LCD Display       | 1        |
| 12V Battery / Power Supply | 1        |
| Jumper Wires               | As Required |

---

# ⚙️ Working Principle

1. The soil moisture sensor reads the moisture level from the soil.
2. Arduino converts the sensor value into moisture percentage.
3. The moisture percentage is displayed on the LCD.
4. If moisture level is below 30%:
   - Pump turns ON
   - Water starts irrigating the soil
5. If moisture level is above 30%:
   - Pump turns OFF

---

# 🔌 Pin Connections

## Soil Moisture Sensor

| Sensor Pin | Arduino Pin |
| ---------- | ------------ |
| VCC        | 5V           |
| GND        | GND          |
| SIG        | A0           |

---

## L298N Motor Driver

| L298N Pin | Arduino Pin |
| --------- | ------------ |
| IN1       | D2           |
| IN2       | D3           |
| ENA       | D5           |

---

## I2C LCD

| LCD Pin | Arduino Pin |
| -------- | ------------ |
| VCC      | 5V           |
| GND      | GND          |
| SDA      | A4           |
| SCL      | A5           |

---

# 💻 Features

- Automatic irrigation
- Real-time moisture monitoring
- LCD status display
- Water-saving system
- Easy to build
- Low-cost smart farming solution

---

# 🧠 Arduino Code Logic

The Arduino performs the following tasks:

- Reads analog value from moisture sensor
- Converts analog value into percentage
- Compares moisture percentage with threshold value
- Controls water pump using L298N motor driver
- Updates LCD every second

---

# 📊 Moisture Detection Formula

The moisture percentage is calculated using Arduino’s `map()` function:

```math
Moisture\ Percentage = map(Raw\ Value,\ 0,\ 1023,\ 0,\ 100)
```

---

# 🚀 Installation Steps

1. Connect all components according to the circuit diagram.
2. Install required Arduino libraries:
   - Wire.h
   - LiquidCrystal_I2C.h
3. Upload the code to Arduino UNO.
4. Power the circuit using 12V supply.
5. Insert moisture sensor into soil.
6. System will automatically monitor and irrigate.

---

# 📚 Required Libraries

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

Install the **LiquidCrystal_I2C** library from Arduino Library Manager.

---

# 🔮 Future Improvements

- IoT monitoring using ESP32
- Mobile App Control
- WiFi-based irrigation
- Weather prediction integration
- Solar-powered irrigation system
- Automatic water level monitoring

---

# 🎯 Applications

- Smart agriculture
- Home gardening
- Greenhouses
- Plant monitoring systems
- Water conservation projects

---

# 👨‍💻 Author

**Muhammad Zulqarnain**  
BS Intelligent Systems & Robotics

---

# 📄 License

This project is open-source and free to use for educational purposes.
