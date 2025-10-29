//
// Created by xilef on 10/27/2025.
//
#include <Arduino.h>
#include <unity.h>
#include "librobus.h"
#include "Advance.h"
#include "Allfunctions.h"
#include "PIDStraight.h"
#include "Rotation.h"

void setUp(void) {
    // set stuff up here

}

void tearDown(void) {

}

void test_AllLEDs(void) {
    // Red LED
    RedLEDOn();
    delay(1000);           // see it turn on
    RedLEDOff();

    // Yellow LED
    YellowLEDOn();
    delay(1000);
    YellowLEDOff();

    // Blue LED
    BlueLEDOn();
    delay(1000);
    BlueLEDOff();

    // Green LED
    GreenLEDOn();
    delay(1000);
    GreenLEDOff();

    // Random LEDs
    for (int i = 0; i < 50; i++) {
        RandomLEDs();
        delay(50);
    }

    // Close all LEDs at the end
    CloseAllLeds();
    delay(200);

    // Assertion always passes (just a visual test)
    TEST_ASSERT_TRUE(true);
}
void test_TurnRobot(void) {
    InitializeMovement(90, 50);

    for (int i = 0; i < 30; i++) {
        DoMovementIteration();
        delay(100);
    }
    delay(200);
    InitializeMovement(-90, 50);

    for (int i = 0; i < 30; i++) {
        DoMovementIteration();
        delay(100);
    }
    delay(200);
    InitializeMovement(-360, 50);

    for (int i = 0; i < 70; i++) {
        DoMovementIteration();
        delay(100);
    }

    InitializePIDStraight(20);
    for (int i=0;i<30;i++) {
        TickPidStraight();
        delay(100);
    }
    delay(200);

    InitializePIDStraight(30);
    for (int i=0;i<30;i++) {
        TickPidStraight();
        delay(100);
    }
    delay(200);

    InitializePIDStraight(60);
    for (int i=0;i<30;i++) {
        TickPidStraight();
        delay(100);
    }
    delay(200);

}
void test_Movement() {
    unsigned long sequenceStartTime = 0;
    int stepsStep=0;
    sequenceStartTime = millis() ;
    InitializeMovement(-135, 100);
    InitializePIDStraight(20.28427,0.8);

    while (millis() - sequenceStartTime < 4000) {   // POSITION 0 + Turn 135 antihoraire + Advance 28,28427cm
        Serial.println(stepsStep);
        switch (stepsStep) {
            case 0:
                DoMovementIteration();
                if (CheckIfMovementIsFinished()) {
                    stepsStep++;
                    InitializeMovement(90, 100);
                    delay(100);
                    ENCODER_Reset(0);
                    ENCODER_Reset(1);
                }
                break;
            case 1:
                if (TickPidStraight()) {
                    stepsStep++;
                    delay(100);
                    ENCODER_Reset(0);
                    ENCODER_Reset(1);
                }

                break;
            case 2:
                DoMovementIteration();
                if (CheckIfMovementIsFinished()) {
                    stepsStep++;
                    delay(100);
                    ENCODER_Reset(0);
                    ENCODER_Reset(1);
                }
                break;
            default:
                break;
        }
        delay(5);
    }
}
void test_Turn() {
    while (true) {
        InitializeMovement(360, 100);
        while (!DoMovementIteration()) {
            delay(10);
        }
        delay(3000);
        InitializeMovement(-360,100);
        while (!DoMovementIteration()) {

            delay(10);
        }
        delay(3000);
    }
}


int runUnityTests(void) {
    UNITY_BEGIN();

    //Test Leds
    //RUN_TEST(test_AllLEDs);
    //RUN_TEST(test_TurnRobot);
    //RUN_TEST(test_Turn);


    return UNITY_END();
}

// WARNING!!! PLEASE REMOVE UNNECESSARY MAIN IMPLEMENTATIONS //

/*
/**
  * For native dev-platform or for some embedded frameworks
  #1#
int main(void) {
    return runUnityTests();
}
*/

/**
  * For Arduino framework
  */
void setup() {
    BoardInit();

    Serial.begin(115200);
    delay(300);
    SetupLEDS();
    InitServosArms();
    // Wait ~2 seconds before the Unity test runner
    // establishes connection with a board Serial interface
    delay(2000);
    Serial.println("Starting Unit Tests");

    runUnityTests();
}
void loop() {}

/**
  * For ESP-IDF framework
  */
void app_main() {
    runUnityTests();
}