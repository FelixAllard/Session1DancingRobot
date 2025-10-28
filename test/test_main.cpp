//
// Created by xilef on 10/27/2025.
//
#include <Arduino.h>
#include <unity.h>
#include "librobus.h"

#include "unity.h"
#include "Advance.h"
#include "Allfunctions.h"
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
}

int runUnityTests(void) {
    UNITY_BEGIN();

    //Test Leds
    RUN_TEST(test_AllLEDs);
    //RUN_TEST(test_TurnRobot);


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