# Arduino Water Level Sensor Project

A simple Arduino-based Water Level Indicator project using a Water Level Sensor Module, LEDs, buzzer, and optional I2C LCD display.

This project monitors the water level in a tank or container and alerts the user when the water reaches a certain level.

---

## 📌 Features

- Real-time water level monitoring
- Analog water level sensing
- LED level indication
- Buzzer alert for high water level
- Optional I2C LCD support
- Beginner-friendly Arduino project
---

# 🔍 How Water Level Sensor Works

![Water Level Sensor](https://playwithcircuit.com/wp-content/uploads/2024/09/Water-level-sensor-hardware-overview.webp)

The water level sensor detects water using exposed conductive traces present on the sensor board.

When water comes in contact with these traces:

- Conductivity increases
- Resistance decreases
- Output voltage changes proportionally

The sensor generates an analog voltage based on the detected water level. Arduino reads this voltage through an analog input pin and determines the water level.

---

## Project Overview

The water level sensor continuously measures the water level and sends analog data to the Arduino UNO. The Arduino processes these readings and determines the percentage of water present inside the container.

Depending on the measured water level, the RGB LED changes color according to the following conditions:

- 🔴 **Red LED** → Water level below 10%
- 🔵 **Blue LED** → Water level between 10% and 99%
- 🟢 **Green LED** → Water level reaches 99% or above

When the water level reaches the maximum threshold, the Arduino activates the buzzer to alert the user that the container is full and filling should be stopped.

At the same time, the LCD display continuously updates the water level percentage, where:

- **0%** indicates an empty container
- **100%** indicates a full container

This provides a clear and real-time indication of the tank status.

---

# 🧰 Hardware Requirements

| Component | Quantity |
|---|---|
| Arduino UNO R3 | 1 |
| Water Level Sensor | 1 |
| LCD 16x2 with I2C | 1 |
| RGB LED (Common Cathode) | 1 |
| Buzzer | 1 |
| Breadboard | 1 |
| Jumper Wires | 10 |
| 220Ω Resistor | 1 |
| USB Cable | 1 |
| 12V Adapter | 1 |

---

# 💻 Software Requirement

- Arduino IDE (Version 2.1.1 or above)

---

# 🔌 Circuit Connections

The water level sensor connections remain the same as the basic sensor interfacing circuit.
![Water Level Sensor](https://playwithcircuit.com/wp-content/uploads/2024/09/Water-Level-Indicator-Circuit-Diagram.webp)

## Water Level Sensor Connections

| Water Level Sensor | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| OUT | A0 |

The sensor sends analog voltage data to Arduino analog pin A0.

---

## LCD I2C Connections

| LCD Pin | Arduino UNO |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | SDA |
| SCL | SCL |

The LCD display shows the water level percentage in real time.

---

## RGB LED Connections

The RGB LED used in this project is a common cathode type LED.

| RGB LED Pin | Arduino UNO |
|---|---|
| Red Pin | 10 |
| Blue Pin | 9 |
| Green Pin | 8 |
| Cathode | GND |

The Arduino controls each color channel independently to display different water level states.

---

## Buzzer Connection

| Buzzer | Arduino UNO |
|---|---|
| Positive Pin | Digital Pin 2 |
| Negative Pin | GND |

The buzzer turns ON when the water tank becomes full.

---

# ▶️ Working Principle

1. The water level sensor detects water using conductive traces.
2. Arduino reads the analog voltage from the sensor.
3. When the water level crosses a predefined threshold:
   - LED turns ON
   - Buzzer activates
4. LCD can optionally display live readings.

---

# 📚 Applications

- Water tank monitoring
- Overflow prevention systems
- Smart irrigation
- Liquid level monitoring
- Home automation projects

---

# 🛠️ Future Improvements

You can enhance this project further by adding:

- Relay module for automatic motor control
- ESP32 for IoT monitoring
- Mobile app notifications
- OLED display
- Wireless monitoring system

---

# 📖 Complete Tutorial

Read the complete tutorial here:

[How does a Water Level Sensor Work and Interface it with Arduino?](https://playwithcircuit.com/water-level-sensor-arduino-tutorial/)


# 🙌 Credits

Project tutorial and explanation by **Play with Circuit**__.
