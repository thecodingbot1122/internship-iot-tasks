# Smart Digital Thermometer using LM35 and OLED Display

A simple Arduino-based digital thermometer project using the LM35 temperature sensor and a 128x64 I2C OLED display. The system reads room temperature and displays it in real-time on the OLED screen.

---

## Components Used

- Arduino UNO
- LM35 Temperature Sensor
- OLED 128x64 I2C Monochrome Display
- Breadboard
- Jumper Wires

---

## Features

- Real-time temperature monitoring
- OLED display output
- Simple and beginner-friendly project
- Compact and low-cost design

---

## Circuit Connections

### LM35 Sensor

| LM35 Pin | Arduino |
|----------|----------|
| VCC      | 5V       |
| GND      | GND      |
| OUT      | A0       |

---

### OLED Display (I2C)

| OLED Pin | Arduino |
|----------|----------|
| VCC      | 5V       |
| GND      | GND      |
| SDA      | A4       |
| SCL      | A5       |

---

## Required Libraries

Install the following libraries from Arduino IDE Library Manager:

- Adafruit GFX
- Adafruit SSD1306

---

## How It Works

1. The LM35 sensor measures temperature.
2. Arduino reads the analog value from the sensor.
3. The value is converted into Celsius.
4. Temperature is displayed on the OLED screen.
5. The display updates every second.

---

## Output

The OLED display shows:

```text
TEMP
28.5 C
```

---

## Applications

- Room temperature monitoring
- Weather station projects
- Home automation systems
- Electronics learning projects

---

## License

This project is open-source and free to use for educational purposes.
