//
// Created by xilef on 10/28/2025.
//

#include "PIDStraight.h"
#include <LibRobus.h>
#include <Arduino.h>
// Motor and encoder functions (as you described)

// Wheel and encoder constants
const float WHEEL_DIAMETER_CM = 7.35;
const int PULSES_PER_ROTATION = 3200;
const float WHEEL_CIRCUMFERENCE_CM = WHEEL_DIAMETER_CM * 3.14159;

// PID constants
float KpStraight = 0.005;  // Proportional gain
float KiStraight = 0.0001; // Integral gain
float KdStraight = 0.001;  // Derivative gain


const float integralMax = 50.0;
const long tolerance = 20;

unsigned long straightLastTime = millis();

long targetPulses = 0;

float maxSpeed = 0.6;
float minSpeed = 0.1;

long lastError = targetPulses;
float integral = 0;

void InitializePIDStraight(float distance_cm) {
    // Reset encoders
    ENCODER_Reset(0);
    ENCODER_Reset(1);

    targetPulses = (distance_cm / WHEEL_CIRCUMFERENCE_CM) * PULSES_PER_ROTATION;
    maxSpeed = 0.6;
    minSpeed = 0.1;

    lastError = targetPulses;
    integral = 0;

}
bool TickPidStraight() {
    unsigned long now = millis();
    float dt = (now - straightLastTime) / 1000.0;
    straightLastTime = now;

    long left = ENCODER_Read(0);
    long right = ENCODER_Read(1);

    // Main error = average to move forward
    long avgPos = (left + right) / 2;
    long error = targetPulses - avgPos;

    if (abs(error) <= tolerance) {
        MOTOR_SetSpeed(0, 0);
        MOTOR_SetSpeed(1, 0);
        return true;
    } // stop condition

    integral += error * dt;
    integral = constrain(integral, -integralMax, integralMax);

    float derivative = (error - lastError) / dt;
    lastError = error;

    float baseSpeed = KpStraight * error + KiStraight * integral + KdStraight * derivative;

    // Trapezoid deceleration near target
    if (abs(error) < targetPulses * 0.2) baseSpeed *= 0.5;
    baseSpeed = constrain(baseSpeed, -maxSpeed, maxSpeed);

    // Minimum speed threshold
    if (baseSpeed > 0 && baseSpeed < minSpeed) baseSpeed = minSpeed;
    if (baseSpeed < 0 && baseSpeed > -minSpeed) baseSpeed = -minSpeed;

    // Correction term to keep wheels equal
    float diff = left - right;
    float correction = 0.2 * diff / PULSES_PER_ROTATION; // small proportional correction

    MOTOR_SetSpeed(0, baseSpeed - correction); // left wheel
    MOTOR_SetSpeed(1, baseSpeed + correction); // right wheel
    return false;
}
