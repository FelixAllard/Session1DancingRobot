//
// Created by dan23 on 21/10/2025.
//

#ifndef SESSION1DANCINGROBOT_ALLFUNCTIONSA_H
#define SESSION1DANCINGROBOT_ALLFUNCTIONSA_H

//Servomotors (ajouter nb pins)
const int servogauche = x;
const int servodroit = x;

//LEDs (ajouter nb pins)
const int lumrouge = x;
const int lumjaune = x;
const int lumverte = x;
const int lumbleue = x;

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


#endif //SESSION1DANCINGROBOT_ALLFUNCTIONSA_H

