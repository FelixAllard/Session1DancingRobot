//
// Created by dan23 on 20/10/2025.
//
#include "allfunctions.h"

#include <librobus.h>


void SetupLEDS() {
    pinMode(lumrouge, OUTPUT);
    pinMode(lumjaune, OUTPUT);
    pinMode(lumverte, OUTPUT);
    pinMode(lumbleue, OUTPUT);
}

void InitServosArms() {
    SERVO_Enable(0);
    SERVO_Enable(1);}

//Arms high
void LArmHigh() {
    SERVO_SetAngle(0, 180);}
void RArmHigh() {
    SERVO_SetAngle(1, 180);}

//Arms straight
void LArmStraight() {
    SERVO_SetAngle(0, 90);}
void RArmStraight() {
    SERVO_SetAngle(1, 90);}

//Arms low
void LArmLow() {
    SERVO_SetAngle(0, 0);}
void RArmLow() {
    SERVO_SetAngle(1, 0);}

//Allumer LEDS
void RedLEDOn() {
    digitalWrite(lumrouge,HIGH);}
void YellowLEDOn() {
    digitalWrite(lumjaune,HIGH);}
void GreenLEDOn() {
    digitalWrite(lumverte,HIGH);}
void BlueLEDOn() {
    digitalWrite(lumbleue,HIGH);}

//Éteindre LEDS
void RedLEDOff() {
    digitalWrite(lumrouge,LOW);}
void YellowLEDOff() {
    digitalWrite(lumjaune,LOW);}
void GreenLEDOff() {
    digitalWrite(lumverte,LOW);}
void BlueLEDOff() {
    digitalWrite(lumbleue,LOW);}


