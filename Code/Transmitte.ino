// Transmitter code

#include <Wire.h>
#include <esp_now.h>
#include <WiFi.h>
#include <MPU6050.h>

MPU6050 mpu;

uint8_t receiverMAC[] = {0xA0, 0xB7, 0x65, 0x04, 0x4D, 0x5C};  // Replace with Receiver MAC Address

typedef struct struct_message {
  char direction;
} struct_message;

struct_message message;

void setup() {
  Serial.begin(115200);
  Wire.begin();
  mpu.initialize();

  WiFi.mode(WIFI_STA);
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverMAC, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  float pitch = atan2(ax, sqrt(ay * ay + az * az)) * 180.0 / PI;
  float roll = atan2(ay, sqrt(ax * ax + az * az)) * 180.0 / PI;

  // Determine direction
  if (pitch > 10) {
    message.direction = 'F';  // Forward
  } else if (pitch < -10) {
    message.direction = 'B';  // Backward
  } else if (roll > 10) {
    message.direction = 'R';  // Right
  } else if (roll < -10) {
    message.direction = 'L';  // Left
  } else {
    message.direction = 'S';  // Stop
  }

  esp_now_send(receiverMAC, (uint8_t *)&message, sizeof(message));
  delay(200);
}
