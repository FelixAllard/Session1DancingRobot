//
// Created by dan23 on 21/10/2025.
//

#include "Allfunctions.h"
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


//Random LEDs
void RandomLEDs() {
    long RanNum = random(0,9);

    RedLEDOff(); //Toutes les turn off
    YellowLEDOff();
    GreenLEDOff();
    BlueLEDOff();

    if (RanNum == 0){ //Fcts pour randomize
        RedLEDOn();}

    if (RanNum == 1){
        YellowLEDOn();}

    if (RanNum == 2){
        GreenLEDOn();}

    if (RanNum == 3){
        BlueLEDOn();}

    if (RanNum == 4){
        RedLEDOn();
        YellowLEDOn();}

    if (RanNum == 5){
        RedLEDOn();
        GreenLEDOn();}

    if (RanNum == 6){
        RedLEDOn();
        BlueLEDOn();}

    if (RanNum == 7){
        YellowLEDOn();
        GreenLEDOn();}

    if (RanNum == 8){
        YellowLEDOn();
        BlueLEDOn();}

    if (RanNum == 9){
        GreenLEDOn();
        BlueLEDOn();}
}