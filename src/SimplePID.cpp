//
// Created by xilef on 10/28/2025.
//

#include "SimplePID.h"

#include <Arduino.h>
#include <LibRobus.h>

// Motor and encoder functions (as you described)

// Wheel and encoder constants
const float WHEEL_DIAMETER_CM = 7.35;
const int PULSES_PER_ROTATION = 3200;
const float WHEEL_CIRCUMFERENCE_CM = WHEEL_DIAMETER_CM * 3.14159;

// PID constants
float Kp = 0.005;  // Proportional gain
float Ki = 0.0001; // Integral gain
float Kd = 0.001;  // Derivative gain

// Function to move a wheel a certain distance in cm
void moveDistance(int wheel, float distance_cm) {
    long targetPulses = (distance_cm / WHEEL_CIRCUMFERENCE_CM) * PULSES_PER_ROTATION;

    long currentPulses = ENCODER_ReadReset(wheel); // reset encoder to 0
    long error = targetPulses - currentPulses;
    long lastError = error;
    long integral = 0;

    float maxSpeed = 0.6; // max motor speed
    float minSpeed = 0.1; // minimum motor speed for low speeds
    float speed = 0;

    unsigned long lastTime = millis();

    while (abs(error) > 5) { // tolerance of 5 pulses
        unsigned long now = millis();
        float dt = (now - lastTime) / 1000.0; // seconds
        lastTime = now;

        currentPulses = ENCODER_ReadReset(wheel); // read current pulses
        error = targetPulses - currentPulses;
        integral += error * dt;
        float derivative = (error - lastError) / dt;

        // PID output
        float output = Kp * error + Ki * integral + Kd * derivative;

        // Trapezoidal profile (accelerate and decelerate)
        if (abs(error) < targetPulses * 0.2) { // deceleration zone
            output = constrain(output, -maxSpeed * 0.5, maxSpeed * 0.5);
        } else { // acceleration zone
            output = constrain(output, -maxSpeed, maxSpeed);
        }

        // Apply minimum speed threshold to overcome static friction
        if (output > 0 && output < minSpeed) output = minSpeed;
        if (output < 0 && output > -minSpeed) output = -minSpeed;

        MOTOR_SetSpeed(wheel, output);

        lastError = error;
        delay(10); // loop every 10ms
    }

    MOTOR_SetSpeed(wheel, 0); // stop motor
}
void moveDistanceBoth(float distance_cm) {
    // Reset encoders
    ENCODER_Reset(0);
    ENCODER_Reset(1);

    long targetPulses = (distance_cm / WHEEL_CIRCUMFERENCE_CM) * PULSES_PER_ROTATION;

    float maxSpeed = 0.6;
    float minSpeed = 0.1;

    long lastError = targetPulses;
    float integral = 0;
    const float integralMax = 50.0;
    const long tolerance = 20;

    unsigned long lastTime = millis();

    while (true) {
        unsigned long now = millis();
        float dt = (now - lastTime) / 1000.0;
        lastTime = now;

        long left = ENCODER_Read(0);
        long right = ENCODER_Read(1);

        // Main error = average to move forward
        long avgPos = (left + right) / 2;
        long error = targetPulses - avgPos;

        if (abs(error) <= tolerance) break; // stop condition

        integral += error * dt;
        integral = constrain(integral, -integralMax, integralMax);

        float derivative = (error - lastError) / dt;
        lastError = error;

        float baseSpeed = Kp * error + Ki * integral + Kd * derivative;

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

        delay(10);
    }

    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);
}




// Example usage:
// moveDistance(0, 50); // move left wheel 50 cm
// moveDistance(1, 50); // move right wheel 50 cm
