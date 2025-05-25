# Smart Robotic Car with Gesture, Voice, and Obstacle Detection (ESP32)

This project is a multi-mode smart robotic car that can be controlled using **hand gestures**, **voice commands** (via Google Assistant), and **autonomously avoid obstacles** using ultrasonic sensors. It utilizes ESP32 microcontrollers, ESP-NOW communication, and the MPU6050 motion sensor for an intuitive and responsive user experience.

---

## 🚀 Features

- **Gesture Control** using MPU6050 accelerometer + ESP-NOW.
- **Voice Control** through Google Assistant (via IFTTT + Adafruit IO).
- **Obstacle Detection** with front and back ultrasonic sensors.
- **Bluetooth Manual Control** (via mobile).
- **Modular** design with 2WD/4WD support.
- **Real-time Directional Feedback** via serial monitor.

---

## 📦 Hardware Components

| Component         | Quantity | Description |
|------------------|----------|-------------|
| ESP32            | 2        | Wi-Fi + Bluetooth microcontroller |
| MPU6050 Sensor   | 1        | 3-axis Accelerometer + Gyroscope |
| L298N Motor Driver | 1      | Dual H-Bridge for DC motor control |
| DC Motors        | 2-4      | Based on 2WD or 4WD configuration |
| Ultrasonic Sensors | 2      | Obstacle detection (front and back) |
| Servo Motor      | 1        | Mounted for ultrasonic scanning |
| LiPo Battery Pack | 1        | 7.4V recommended for motor power |
| Jumper Wires     | -        | For all connections |
| Breadboard       | 1        | Optional for prototyping |

---

## ⚙️ System Overview

### 🧠 Transmitter
- **MPU6050** reads hand movement (pitch/roll).
- **ESP32** interprets the gesture and transmits it using **ESP-NOW**.
- Directional codes:  
  - `F` = Forward  
  - `B` = Backward  
  - `L` = Left  
  - `R` = Right  
  - `S` = Stop

### 🚗 Receiver
- **ESP32** receives gesture or voice commands via ESP-NOW.
- **L298N** drives the motors accordingly.
- Obstacle is detected using **ultrasonic sensors**, and motion is stopped automatically.

### 🗣️ Voice Control
- Google Assistant triggers IFTTT webhook.
- Adafruit IO sends command to ESP32 over the internet.

---


## 🛠️ Setup Instructions

1. **Install Libraries in Arduino IDE:**
   - `ESP32 Board` by Espressif (via Board Manager)
   - `ESP32Servo`
   - `ESP-NOW`
   - `MPU6050`
   - `BluetoothSerial`

2. **Configure Receiver:**
   - Upload `motor_receiver.ino` to ESP32.
   - Note down the **MAC address** (printed in Serial Monitor).
   - Enter this MAC in `gesture_transmitter.ino`.

3. **Configure Transmitter:**
   - Connect MPU6050 to ESP32.
   - Upload `gesture_transmitter.ino`.
   - Ensure gestures are stable (Pitch >10 → Forward, etc.)

4. **Enable Voice Control:**
   - Follow `google_ifttt_setup.md` for IFTTT + Adafruit IO setup.
   - Connect ESP32 to Adafruit MQTT via Wi-Fi.

5. **Enable Bluetooth Mode (Optional):**
   - Upload `bluetooth_obstacle_control.ino` to ESP32.
   - Use a Bluetooth terminal app to send `F`, `B`, `L`, `R`, `S`.

---

## ⚡ Pin Configuration (Receiver)

| ESP32 GPIO | Connected To    |
|------------|-----------------|
| GPIO16     | L298N IN1       |
| GPIO17     | L298N IN2       |
| GPIO18     | L298N IN3       |
| GPIO19     | L298N IN4       |
| GPIO4      | L298N ENA       |
| GPIO5      | L298N ENB       |
| GPIO22     | Ultrasonic TRIG |
| GPIO23     | Ultrasonic ECHO |

---

## 📷 Screenshots

> Add images or wiring diagrams here if needed.

---

## 🧪 Testing

- Test gestures individually.
- Monitor motor response in serial.
- Use `Serial.println()` to debug sensor values.
- Check obstacle detection range by placing objects in front and behind.

---

## 🧩 Limitations

- Gesture control requires steady motion.
- Voice commands depend on internet latency.
- Obstacle detection range is limited (<4m).
- No return feedback from robot to controller.

---

## 🔮 Future Improvements

- Offline voice recognition with ESP-Skainet.
- Bi-directional MQTT dashboard.
- Use mecanum wheels for full-direction motion.
- Add camera (ESP32-CAM) for vision tracking.

---

## 👥 Authors

- Kaleem Ullah  
- Dawood Ali Khan  
- Syed Faqih Ali Zamin  
- Muhammad Hassan Ali  

---

## 📜 License

This project is open-source and available under the [MIT License](LICENSE).

