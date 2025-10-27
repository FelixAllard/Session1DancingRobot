//
// Created by xilef on 10/27/2025.
//

#include "Rotation.h"

#include <Arduino.h>
#include <stddef.h>
#include <LibRobus.h>

#define ENCODER_PPR 3250.0f
#define WHEEL_DIAMETER 7.7f   // cm
#define WHEELBASE 18.0f       // cm
#define TURN_SPEED 0.10f      // constant turning speed


unsigned long tickTimer;

unsigned long timeSincePreviousTick;
unsigned long totalTimeBetweenTicks;
int numberOfTicksRequired;
int numberOfTicksSpent;

float rotationDegrees;
float currentRotation;

float currentAcceleration;
bool turningRight;
bool finishedMovement;


const float wheelCirc = M_PI * WHEEL_DIAMETER;
float turnDist;
float rotationsNeeded;
float pulsesTarget;

static inline float clampf(float v, float lo, float hi) {
    if (v < lo) return lo;
    if (v > hi) return hi;
    return v;
}


void InitializeMovement(float degree, int ticksRequired) {
    ReinitializeMovement();

    rotationDegrees = degree;
    if (rotationDegrees >=0)
        turningRight = true;
    else
        turningRight = false;

    numberOfTicksRequired = ticksRequired;


    // Reset encoders
    ENCODER_Reset(0);
    ENCODER_Reset(1);

    // Calculate pulses needed for a 90° turn
    turnDist  = (M_PI * WHEELBASE) / (360.0f / abs(rotationDegrees));
    rotationsNeeded = turnDist / wheelCirc;
    pulsesTarget = rotationsNeeded * ENCODER_PPR;
}

bool CheckIfMovementIsFinished() {
    long leftCount  = ENCODER_Read(0);
    long rightCount = ENCODER_Read(1);

    // Average distance moved
    float avgDist = (fabs(leftCount) + fabs(rightCount)) / 2.0f;

    if (avgDist >= pulsesTarget)
        return true;
    return false;
}


bool DoMovementIteration() {
    if (tickTimer!=0) {
        unsigned long currentTime = millis();
        timeSincePreviousTick = currentTime - tickTimer;

        totalTimeBetweenTicks += timeSincePreviousTick;
    }
    numberOfTicksSpent++;
    tickTimer = millis();

    long leftCount  = ENCODER_Read(0);
    long rightCount = ENCODER_Read(1);

    // Average distance moved
    float avgDist = (fabs(leftCount) + fabs(rightCount)) / 2.0f;

    if (avgDist >= pulsesTarget) {
        MOTOR_SetSpeed(0, 0.0f);
        MOTOR_SetSpeed(1, 0.0f);
        return true;
    }

    // Apply constant speed with small bias correction
    float leftSpeed  = (turningRight ?  TURN_SPEED : -TURN_SPEED); //* motorBias_Base[0];
    float rightSpeed = (turningRight ? -TURN_SPEED :  TURN_SPEED); //* motorBias_Base[1];

    MOTOR_SetSpeed(0, leftSpeed);
    MOTOR_SetSpeed(1, rightSpeed);

    return false;


}
long GetAverageTimeBetweenTicks() {
    return (
        totalTimeBetweenTicks
        /
        numberOfTicksSpent
    );
}

void ReinitializeMovement() {
    currentRotation = 0;
    currentAcceleration = 0;
    finishedMovement = false;
    timeSincePreviousTick = 0;
    totalTimeBetweenTicks = 0;
    numberOfTicksSpent= 0 ;

    tickTimer = 0 ;

}
