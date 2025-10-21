//
// Created by dan23 on 21/10/2025.
//

#ifndef SESSION1DANCINGROBOT_ALLFUNCTIONSA_H
#define SESSION1DANCINGROBOT_ALLFUNCTIONSA_H

//Servomotors (ajouter num pins)
const int rightservo = x;
const int leftservo = x;

//LEDs (ajouter num pins)
const int redlight = x;
const int yellowlight = x;
const int greenlight = x;
const int bluelight = x;

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



#endif //SESSION1DANCINGROBOT_ALLFUNCTIONSA_H

