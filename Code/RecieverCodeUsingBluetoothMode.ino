#include <ESP32Servo.h>
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
// Motor Connections
#define IN1 16
#define IN2 17
#define IN3 18
#define IN4 19
#define ENA 4
#define ENB 5
// Ultrasonic Sensor Connections
int frontTrigPin = 22;
int frontEchoPin = 23;
int backTrigPin = 12;
int backEchoPin = 14;
Servo myServo;
int motor_speed = 150;
char t;
void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_4WD");  // Bluetooth device name
  // Initializing motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
