#include "ArcPID.h"
#include <LibRobus.h>
#include <Arduino.h>

const float WHEEL_BASE_CM = 18.9;          // distance between wheels
const float ARC_WHEEL_DIAMETER_CM = 8.40;  // wheel diameter
const int ARC_PULSES_PER_ROTATION = 3200;
const float ARC_WHEEL_CIRCUMFERENCE_CM = ARC_WHEEL_DIAMETER_CM * M_PI;

const float ARC_SPEED = 0.35; // Base outer wheel speed (0–1 range)

// ---- RIGHT TURN ----
void RightTurnArc(float distance_cm) {
    ENCODER_Reset(0);
    ENCODER_Reset(1);

    // Calculate arc radii for each wheel
    float R_center = distance_cm / 2.0f;
    float R_left  = R_center + (WHEEL_BASE_CM / 2.0f);
    float R_right = R_center - (WHEEL_BASE_CM / 2.0f);

    // Calculate travel distances
    float leftDistance  = M_PI * R_left;
    float rightDistance = M_PI * R_right;

    // Convert to encoder pulses
    long targetLeft  = (leftDistance  / ARC_WHEEL_CIRCUMFERENCE_CM) * ARC_PULSES_PER_ROTATION;
    long targetRight = (rightDistance / ARC_WHEEL_CIRCUMFERENCE_CM) * ARC_PULSES_PER_ROTATION;

    // Determine speed ratio (inner/outer)
    float speedRatio = R_right / R_left;

    // Base speeds
    float leftSpeed  = ARC_SPEED;
    float rightSpeed = ARC_SPEED * speedRatio;

    // Set both motors forward
    MOTOR_SetSpeed(0, leftSpeed);
    MOTOR_SetSpeed(1, rightSpeed);

    // Wait until the outer wheel completes its arc
    while (true) {
        long left  = ENCODER_Read(0);
        long right = ENCODER_Read(1);

        if (fabs(left) >= targetLeft || fabs(right) >= targetRight)
            break;

        delay(5);
    }

    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);
}

// ---- LEFT TURN ----
void LeftTurnArc(float distance_cm) {
    ENCODER_Reset(0);
    ENCODER_Reset(1);

    // Calculate arc radii for each wheel
    float R_center = distance_cm / 2.0f;
    float R_left  = R_center - (WHEEL_BASE_CM / 2.0f);
    float R_right = R_center + (WHEEL_BASE_CM / 2.0f);

    // Calculate travel distances
    float leftDistance  = M_PI * R_left;
    float rightDistance = M_PI * R_right;

    // Convert to encoder pulses
    long targetLeft  = (leftDistance  / ARC_WHEEL_CIRCUMFERENCE_CM) * ARC_PULSES_PER_ROTATION;
    long targetRight = (rightDistance / ARC_WHEEL_CIRCUMFERENCE_CM) * ARC_PULSES_PER_ROTATION;

    // Determine speed ratio (inner/outer)
    float speedRatio = R_left / R_right;

    // Base speeds
    float rightSpeed = ARC_SPEED;
    float leftSpeed  = ARC_SPEED * speedRatio;

    // Set both motors forward
    MOTOR_SetSpeed(0, leftSpeed);
    MOTOR_SetSpeed(1, rightSpeed);

    // Wait until the outer wheel completes its arc
    while (true) {
        long left  = ENCODER_Read(0);
        long right = ENCODER_Read(1);

        if (fabs(left) >= targetLeft || fabs(right) >= targetRight)
            break;

        delay(5);
    }

    MOTOR_SetSpeed(0, 0);
    MOTOR_SetSpeed(1, 0);
}
