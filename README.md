# Project Nexus — SmartGuard Security System

A Wi-Fi-enabled safety and security alarm prototype built using an ESP8266 NodeMCU.

The system uses an IR sensor to detect nearby activity and automatically activates a warning LED and buzzer. A mobile-friendly web dashboard hosted directly by the ESP8266 allows the system status to be monitored from a phone connected to the NEXUS Wi-Fi network.

---

## Current Version

**Nexus v1 — SmartGuard Security System**

---

## Features

- ESP8266 NodeMCU based controller
- Wi-Fi connectivity
- Mobile-friendly security dashboard
- IR-based presence detection
- Automatic warning LED
- Automatic buzzer alarm
- Real-time security status
- Standalone ESP8266 web server
- No internet connection required for the local dashboard

---

## How It Works

The IR sensor continuously monitors the surroundings.

### When activity is detected

```text
IR Sensor
    ↓
ESP8266
    ↓
LED ON + Buzzer ON
    ↓
SmartGuard Status: ALERT
