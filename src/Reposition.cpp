//
// Created by xilef on 10/28/2025.
//

#include "Reposition.h"
#include <Arduino.h>
#include <LibRobus.h>

// === CAPTEURS ===
#define LEFT_SENSOR    34
#define CENTER_SENSOR  40
#define RIGHT_SENSOR   8

// === MOTEURS ===
#define MOTOR_LEFT   0
#define MOTOR_RIGHT  1

// === PARAMÈTRES ===
#define SYNC_BASE_SPEED  0.12    // vitesse de base de rotation
#define SYNC_KP          0.12    // coefficient de correction (PID)
#define DEBOUNCE_DELAY   50
#define MAX_SPEED        0.25

void InitializeLineSensor() {
  pinMode(LEFT_SENSOR, INPUT);
  pinMode(CENTER_SENSOR, INPUT);
  pinMode(RIGHT_SENSOR, INPUT);

  Serial.println("Line Sensors initialized!");
}

// Fonction interne pour lire les capteurs
int readLineError() {
  bool left = digitalRead(LEFT_SENSOR);
  bool center = digitalRead(CENTER_SENSOR);
  bool right = digitalRead(RIGHT_SENSOR);

  // Calcule un "erreur directionnelle"
  if (center && !left && !right) return 0;   // ligne centrée
  if (left && !right)             return -1; // ligne à gauche
  if (right && !left)             return 1;  // ligne à droite
  if (left && center && !right)   return -1; // encore un peu à gauche
  if (right && center && !left)   return 1;  // encore un peu à droite
  if (!left && !center && !right) return 999; // rien détecté
  return 0;
}

void SynchronizeRight() {
  Serial.println("Synchronizing to the right...");

  while (true) {
    bool left = digitalRead(LEFT_SENSOR);
    bool center = digitalRead(CENTER_SENSOR);
    bool right = digitalRead(RIGHT_SENSOR);

    // --- Condition stricte : centre détecté ---
    // new
    if (center) { // stop as soon as center sees the line
      MOTOR_SetSpeed(MOTOR_LEFT, 0);
      MOTOR_SetSpeed(MOTOR_RIGHT, 0);
      Serial.println("✅ Center sensor on line (right sync complete).");
      delay(DEBOUNCE_DELAY);
      break;
    }

    // PID simplifié
    int error = readLineError();
    float correction = (error != 999) ? SYNC_KP * error : 0;

    float leftSpeed  = SYNC_BASE_SPEED + correction;
    float rightSpeed = -SYNC_BASE_SPEED - correction;

    leftSpeed  = constrain(leftSpeed, -MAX_SPEED, MAX_SPEED);
    rightSpeed = constrain(rightSpeed, -MAX_SPEED, MAX_SPEED);

    MOTOR_SetSpeed(MOTOR_LEFT, leftSpeed);
    MOTOR_SetSpeed(MOTOR_RIGHT, rightSpeed);

    delay(10);
  }
}

void SynchronizeLeft() {
  Serial.println("Synchronizing to the left...");

  while (true) {
    bool left = digitalRead(LEFT_SENSOR);
    bool center = digitalRead(CENTER_SENSOR);
    bool right = digitalRead(RIGHT_SENSOR);

    // --- Condition stricte : centre détecté ---
    if (center && !left && !right) {
      MOTOR_SetSpeed(MOTOR_LEFT, 0);
      MOTOR_SetSpeed(MOTOR_RIGHT, 0);
      Serial.println("✅ Center sensor on line (left sync complete).");
      delay(DEBOUNCE_DELAY);
      break;
    }

    // PID simplifié
    int error = readLineError();
    float correction = (error != 999) ? SYNC_KP * error : 0;

    float leftSpeed  = -SYNC_BASE_SPEED - correction;
    float rightSpeed = SYNC_BASE_SPEED + correction;

    leftSpeed  = constrain(leftSpeed, -MAX_SPEED, MAX_SPEED);
    rightSpeed = constrain(rightSpeed, -MAX_SPEED, MAX_SPEED);

    MOTOR_SetSpeed(MOTOR_LEFT, leftSpeed);
    MOTOR_SetSpeed(MOTOR_RIGHT, rightSpeed);

    delay(10);
  }
}
