//
// Created by xilef on 10/27/2025.
//

#include "test_LedTests.h"

#include <Arduino.h>
#include <unity.h>
#include "../src/Allfunctions.h"

void test_redLedTurnsOn() {
    int state = 0;
    Serial.println("Please enter LED state (0 or 1): ");

    // Wait for user input
    while (Serial.available() == 0) {
        delay(10);
    }

    // Read the input
    char c = Serial.read();
    if (c == '0') state = 0;
    else if (c == '1') state = 1;
    else state = -1;  // invalid input

    Serial.print("LED state entered: ");
    Serial.println(state);

    // Assert
    TEST_ASSERT_EQUAL_MESSAGE(1, state, "LED test failed: state is not 1");
}

void test_redLedTurnsOff() {
}

void test_redLedTriggers() {
}

void test_randomColor() {
}
