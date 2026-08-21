# 🛡️ Project Nexus — SmartGuard Security System

A Wi-Fi-enabled safety and security alarm prototype built using an **ESP8266 NodeMCU**.

The system uses an IR sensor to detect nearby activity and automatically activates a warning LED and buzzer. A mobile-friendly web dashboard hosted directly by the ESP8266 allows the system status to be monitored from a phone connected to the NEXUS Wi-Fi network.

## 🚀 Current Version

**Nexus v1 — SmartGuard Security System**

### ✨ Features

- 📡 ESP8266-based controller
- 📱 Wireless phone connectivity
- 🌐 Built-in web dashboard
- 👁️ IR-based presence detection
- 🔴 Automatic warning LED
- 🚨 Automatic buzzer alarm
- 📊 Real-time security status
- 📱 Mobile-friendly SmartGuard interface

## ⚙️ How It Works

The IR sensor continuously monitors the surroundings.

### When activity is detected:

**IR Sensor → ESP8266 → LED ON + Buzzer ON**

The SmartGuard dashboard displays:

**SYSTEM STATUS: ALERT**

**PRESENCE: ACTIVITY DETECTED**

**WARNING LIGHT: ON**

**ALARM: ACTIVE**

### When the area is clear:

**IR Sensor → ESP8266 → LED OFF + Buzzer OFF**

The dashboard displays:

**SYSTEM STATUS: PROTECTED**

**PRESENCE: NO ACTIVITY**

**WARNING LIGHT: OFF**

**ALARM: STANDBY**

## 🔌 Hardware

| Component | Purpose |
|---|---|
| NodeMCU ESP8266 | Main controller |
| IR Sensor | Presence/object detection |
| LED | Visual warning |
| 220Ω resistor | LED current limiting |
| 2-pin buzzer | Audible alarm |
| Jumper wires | Connections |
| USB cable | Programming and power |

## 🔗 Pin Connections

| Component | NodeMCU |
|---|---|
| IR VCC | 3V3 |
| IR GND | GND |
| IR OUT | D2 |
| LED | D1 through resistor |
| LED GND | GND |
| Buzzer + | D5 |
| Buzzer − | GND |

## 📱 SmartGuard Dashboard

The ESP8266 creates its own Wi-Fi network:

**Network:** `NEXUS`

The phone connects directly to the ESP8266 and opens the SmartGuard dashboard at:

**192.168.4.1**

The dashboard displays the current security condition of the system.

## 🧠 Technology

- **Microcontroller:** ESP8266 NodeMCU
- **Programming:** Arduino C/C++
- **Communication:** Wi-Fi
- **Web Server:** ESP8266WebServer
- **Interface:** HTML + CSS
- **Sensor:** IR detection module

## 📂 Project Structure

```text
Project-Nexus/
│
├── Nexus_Security_Alarm/
│   └── Nexus_Security_Alarm.ino
│
├── images/
│   ├── circuit-diagram.png
│   └── smartguard-dashboard.jpg
│
└── README.md
