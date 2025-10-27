//
// Created by dan23 on 21/10/2025.
//

#ifndef SESSION1DANCINGROBOT_ALLFUNCTIONSA_H
#define SESSION1DANCINGROBOT_ALLFUNCTIONSA_H

//Servomotors (ajouter num pins)
const int rightservo = 0;
const int leftservo = 1;

//LEDs (ajouter num pins)
const int redlight = 22 ;
const int yellowlight = 24;
const int greenlight = 26;
const int bluelight = 28;

/*
 *Line sensor
 *Gauche 30
 *Milieu 32
 *Droite 34
 */
extern bool redLedOn;
extern bool yellowLedOn;
extern bool greenLedOn;
extern bool blueLedOn;

// Setup
void SetupLEDS();
void InitServosArms();

// Servo control - Left arm
void LArmHigh();
void LArmStraight();
void LArmLow();

// Servo control - Right arm
void RArmHigh();
void RArmStraight();
void RArmLow();

// LED Control - Turn ON
void RedLEDOn();
void YellowLEDOn();
void GreenLEDOn();
void BlueLEDOn();

// LED Control - Turn OFF
void RedLEDOff();
void YellowLEDOff();
void GreenLEDOff();
void BlueLEDOff();

//Randomize LEDs
void RandomLEDs();

void CloseAllLeds();



#endif //SESSION1DANCINGROBOT_ALLFUNCTIONSA_H

