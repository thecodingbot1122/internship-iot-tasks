# Object Counter using VL53L0X and OLED Display

An Arduino-based object counting system using the VL53L0X laser distance sensor and a 128x64 I2C OLED display. The system detects nearby objects and increases the counter automatically.

---

## Components Used

- Arduino UNO
- VL53L0X Distance Sensor
- OLED 128x64 I2C Monochrome Display
- Breadboard
- Jumper Wires

---

## Features

- Real-time object detection
- Automatic object counting
- OLED display output
- Accurate laser distance sensing
- Beginner-friendly project

---

## Circuit Connections

### VL53L0X Sensor

| VL53L0X Pin | Arduino |
|-------------|----------|
| VCC         | 5V       |
| GND         | GND      |
| SDA         | A4       |
| SCL         | A5       |

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
- VL53L0X by Pololu

---

## How It Works

1. The VL53L0X sensor continuously measures distance.
2. When an object comes within the detection range, the counter increases.
3. The system avoids double counting by waiting until the object moves away.
4. The OLED display shows:
   - Total object count
   - Current distance reading

---

## Output

The OLED display shows:

```text
Counter
Count: 5
Dist: 85 mm
```

---

## Applications

- Industrial object counting
- Smart conveyor systems
- Entry/exit monitoring
- Production line automation
- Robotics projects

---

## License

This project is open-source and free to use for educational purposes.
