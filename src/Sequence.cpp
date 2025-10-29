//
// Created by dan23 on 28/10/2025.
//

#include "Sequence.h"
#include <Arduino.h>
#include <Allfunctions.h>
#include <librobus.h>
#include "ArcPID.h"
#include "Rotation.h"
#include "PIDStraight.h"

unsigned long sequenceStartTime = 0;
bool finished = false;

void ChangeStep() {
    RedLEDOn();
    BlueLEDOn();
    GreenLEDOn();
    YellowLEDOn();
    Serial.println("Change Step");
    delay(1000);
    CloseAllLeds();
}
void Sequence() {
    Song2();
}


void Song1() {
    //PREMIERE CHANSON----------------------------------------------------------
    sequenceStartTime = millis();//Snapshot of current time, attente
    LArmLow();
    RArmLow();
    RedLEDOff();
    YellowLEDOff();
    GreenLEDOff();
    BlueLEDOff();
    while (millis() - sequenceStartTime < 8000) { //Current time - start time = time spent in milli seconds. SO here it is 5 seconds

    }

    ChangeStep();


    sequenceStartTime = millis();    // LArmHigh
    LArmHigh();
    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    sequenceStartTime = millis();    // LArmHigh + RArmHigh
    CloseAllLeds();
    LArmHigh();
    RArmHigh();
    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    sequenceStartTime = millis();    // LArmLow + RArmHigh
    CloseAllLeds();
    LArmLow();
    RArmHigh();
    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    sequenceStartTime = millis();    // LArmLow + RArmLow for 18 seconds
    CloseAllLeds();
    RArmLow();
    LArmLow();
    while (millis() - sequenceStartTime < 18000) {}

    ChangeStep();

    sequenceStartTime = millis();
    CloseAllLeds();
    RedLEDOn();
    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    sequenceStartTime = millis();    // YellowLEDOn
    CloseAllLeds();
    YellowLEDOn();
    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    sequenceStartTime = millis();    // GreenLEDOn
    GreenLEDOn();
    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    sequenceStartTime = millis();    // BlueLEDOn
    CloseAllLeds();
    BlueLEDOn();
    while (millis() - sequenceStartTime < 2000) {}


    ChangeStep();

    sequenceStartTime = millis();    // RedLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    RedLEDOn();
    LArmStraight();
    RArmStraight();
    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    sequenceStartTime = millis();    // YellowLEDOn + LArmHigh + RArmHigh
    CloseAllLeds();
    YellowLEDOn();
    LArmHigh();
    RArmHigh();
    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    sequenceStartTime = millis();    // GreenLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    GreenLEDOn();
    LArmStraight();
    RArmStraight();

    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    sequenceStartTime = millis();    // BlueLEDOn + LArmLow + RArmLow
    CloseAllLeds();
    BlueLEDOn();
    LArmLow();
    RArmLow();
    while (millis() - sequenceStartTime < 2000) {}

    ChangeStep();

    //TODO 360
    sequenceStartTime = millis();    // 360 horaire + RandomLEDs + LArmHigh + RArmHigh
    CloseAllLeds();
    LArmHigh();
    RArmHigh();
    InitializeMovement(
        360,
        100,
        0.4f
    );
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        RandomLEDs();
        delay(10);
    }

    ChangeStep();


    sequenceStartTime = millis();     // Alternated RedLEDOn/YellowLEDOn + LArmLow + RArmLow
    CloseAllLeds();
    LArmLow();
    RArmLow();
    while (millis() - sequenceStartTime < 2000) {
        RedLEDOn();
        YellowLEDOff();
        delay(100);
        RedLEDOff();
        YellowLEDOn();
        delay(100);
    }

    ChangeStep();

    sequenceStartTime = millis();     // Alternated YellowLEDOn/GreenLEDOn
    CloseAllLeds();
    while (millis() - sequenceStartTime < 2000) {
        //---Yellow On---
        YellowLEDOn();
        GreenLEDOff();
        delay(100);
        //---Green On---
        YellowLEDOff();
        GreenLEDOn();
        delay(100);
    }

    ChangeStep();


    sequenceStartTime = millis();     // Alternated GreenLEDOn/BlueLEDOn
    CloseAllLeds();
    while (millis() - sequenceStartTime < 2000) {
        //---Green on---
        GreenLEDOn();
        BlueLEDOff();
        delay(100);
        //---Blue On---
        GreenLEDOff();
        BlueLEDOn();
        delay(100);
    }

    ChangeStep();

    sequenceStartTime = millis();    // Alternated BlueLEDOn/RedLEDOn
    CloseAllLeds();
    while (millis() - sequenceStartTime < 2000) {
        //---Blue on ---
        BlueLEDOn();
        RedLEDOff();
        delay(100);
        //---Red On---
        BlueLEDOff();
        RedLEDOn();
        delay(100);
    }

    ChangeStep();


    //TODO 360 AntiHoraire
    sequenceStartTime = millis();    // 360 antihoraire + RandomLEDs + LArmStraight + RArmStraight
    CloseAllLeds();
    LArmStraight();
    RArmStraight();
    InitializeMovement(-360,100, 0.4f);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        RandomLEDs();
        delay(10);
    }
}

void Song2() {
    //DEUXIEME CHANSON----------------------------------------------------------------


    //TODO Position 1
    sequenceStartTime = millis();    // Position 1 + LArmLow + RArmLow
    CloseAllLeds();
    LArmLow();
    RArmLow();
    InitializePIDStraight(20, 0.3);
    while (millis() - sequenceStartTime < 4000) {
        TickPidStraight() ; // POSITION 1
        // Advance 20cm
        delay(10);

    }

    ChangeStep();
    sequenceStartTime = millis() ;
    InitializeMovement(-135, 100);
    InitializePIDStraight(28.28427, 0.3);
    while (millis() - sequenceStartTime < 4000) {   // POSITION 2 + Turn 135 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
        delay(10);
    }
    ChangeStep();


    sequenceStartTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427, 0.3);
    while (millis() - sequenceStartTime < 4000) { // POSITION 3 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
        delay(10);
    }

    ChangeStep();

    sequenceStartTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427,0.3);
    while (millis() - sequenceStartTime < 4000) { // POSITION 4 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
        delay(10);
    }

    ChangeStep();

    sequenceStartTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427, 0.3);
    while (millis() - sequenceStartTime < 4000) { // POSITION 1 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
        delay(10);
    }

    ChangeStep();

    sequenceStartTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427, 0.3);
    while (millis() - sequenceStartTime < 4000) { // POSITION 2 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
        delay(10);

    }

    ChangeStep();

    sequenceStartTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427, 0.3);
    while (millis() - sequenceStartTime < 4000) { // POSITION 3 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
        delay(10);
    }
    ChangeStep();

    sequenceStartTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427, 0.6);
    while (millis() - sequenceStartTime < 4000) { // POSITION 4 + Turn 90 antihoraire + Advance 28,28427cm
        //unsigned long temporary = millis();
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
        delay(10);
        //delay(10-(millis()-temporary));
    }

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

void Song3() {
    //TROISIEME CHANSON-----------------------------------------------------------------

    sequenceStartTime = millis(); // Changement place en bas avk P-07 (-1) 8sec
    InitializeMovement(180,100);
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration(); // Turn 180 ho ou anti
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }


    //TODO POSITION 1
    sequenceStartTime = millis();    // POSITION 1 + RedLEDOn
    RedLEDOn();
    InitializePIDStraight(20);
    while (millis() - sequenceStartTime < 4000) { // POSITION 1 // Advance 20cm
        TickPidStraight();
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 2 + YellowLEDOn
    CloseAllLeds();
    YellowLEDOn();
    InitializeMovement(-135,100); // POSITION 2: // Turn 135 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 3 + GreenLEDOn
    CloseAllLeds();
    GreenLEDOn();
    InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 4 + BlueLEDOn
    CloseAllLeds();
    BlueLEDOn();
    InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 0 +RedLEDOn+YellowLEDOn+GreenLEDOn+BlueLEDOn
    CloseAllLeds();
    RedLEDOn();
    YellowLEDOn();
    GreenLEDOn();
    InitializeMovement(-135,100);
    InitializePIDStraight(28.28427);
    finished = false;
    while (millis() - sequenceStartTime < 4000) {   // POSITION 0 + Turn 135 antihoraire + Advance 28,28427cm + Turn90
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            if (TickPidStraight()) {
                if (finished){}
                else if (CheckIfMovementIsFinished()) {
                    InitializeMovement(90, 100);
                }else {
                    finished = DoMovementIteration();
                }
            }
    }


    //TODO 720 horaire
    sequenceStartTime = millis();    // 720 horaire + RandomLEDs
    CloseAllLeds();
    InitializeMovement(720,100);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        RandomLEDs();

        delay(100);
    }
    CloseAllLeds();
}

void Song4() {
    // QUATRIEME CHANSON-------------------------------------------------------------------

    // Retour changement place en haut avk P-07 (+1) 8 sec

    sequenceStartTime = millis();    // POSITION 1 + RedLEDOn
    CloseAllLeds();
    RedLEDOn();
    InitializePIDStraight(20);
    while (millis() - sequenceStartTime < 4000) {    // POSITION 1 // Advance 20cm
        TickPidStraight();
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 2 + YellowLEDOn
    CloseAllLeds();
    YellowLEDOn();
    InitializeMovement(-135,100);
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 3 + GreenLEDOn
    CloseAllLeds();
    GreenLEDOn();
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) { // POSITION 3 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }

    sequenceStartTime = millis();    // POSITION 4 + BlueLEDOn
    CloseAllLeds();
    BlueLEDOn();
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) { // POSITION 4 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }

    sequenceStartTime = millis();    // POSITION 0 + RandomLEDs
    CloseAllLeds();
    InitializeMovement(-135, 100);
    InitializePIDStraight(28.28427);
    finished = false;
    while (millis() - sequenceStartTime < 4000) {
        // POSITION 0 : Turn 135 antihoraire + Advance 28,28427cm + 90 hor
        DoMovementIteration();
        RandomLEDs();
        if (CheckIfMovementIsFinished())
            if (TickPidStraight()) {
                if (finished){}
                else if (CheckIfMovementIsFinished()) {
                    InitializeMovement(90, 100);
                }else {
                    finished = DoMovementIteration();
                }
                delay(100);
            }
    }
}

void Song5() {
    //CINQUIEME CHANSON-------------------------------------------------------------------
    sequenceStartTime = millis();    // POSITION 1 + RedLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    RedLEDOn();
    LArmStraight();
    RArmStraight();
    InitializePIDStraight(20);
    while (millis() - sequenceStartTime < 4000) {    // POSITION 1 // Advance 20cm
        TickPidStraight();
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 2 + YellowLEDOn + LArmHigh + RArmHigh
    CloseAllLeds();
    YellowLEDOn();
    LArmHigh();
    RArmHigh();
    InitializeMovement(-135,100); // POSITION 2: // Turn 135 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 3 + GreenLEDOn + LArmLow + RArmLow
    CloseAllLeds();
    GreenLEDOn();
    LArmLow();
    RArmLow();
    InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 4 + BlueLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    BlueLEDOn();
    LArmStraight();
    RArmStraight();
    InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }


    sequenceStartTime = millis();    // POSITION 1 + LArmHigh + RArmHigh
    CloseAllLeds();
    LArmHigh();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }


    sequenceStartTime = millis();    // POSITION 2 + LArmHigh + RArmStraight
    LArmHigh();
    RArmStraight();
    InitializeMovement(-90,100); // POSITION 2: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }


    sequenceStartTime = millis();    // POSITION 3 + LArmStraight + RArmStraight
    LArmStraight();
    RArmStraight();
    InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 4 + LArmStraight + RArmHigh
    LArmStraight();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    //SIXIEME CHANSON- FAIRE ATTENTION AUX DÉLAIS CAR CEST PAS LES BONS!!!--------------------------------------------------------------------

    sequenceStartTime = millis();    // POSITION 1 + RandomLEDs + LArmHigh + RArmHigh
    RandomLEDs();
    LArmHigh();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
    RandomLEDs();
    LArmHigh();
    RArmStraight();
    InitializeMovement(-90,100); // POSITION 2: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 3 + RandomLEDs + LArmStraight + RArmStraight
    RandomLEDs();
    LArmStraight();
    RArmStraight();
    InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }
    sequenceStartTime = millis();    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
    RandomLEDs();
    LArmStraight();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }
}

void Song6() {
    for (int i=1;i<=2;i++) { // 2 fois la meme chose
        sequenceStartTime = millis();    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
        LArmHigh();
        RArmHigh();
        InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - sequenceStartTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        sequenceStartTime = millis();    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
        LArmHigh();
        RArmStraight();
        InitializeMovement(-90,100); // POSITION 2: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - sequenceStartTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        sequenceStartTime = millis();    // POSITION 3 + RandomLEDs + LArmStraight + RArmStraight
        LArmStraight();
        RArmStraight();
        InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - sequenceStartTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        sequenceStartTime = millis();    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
        LArmStraight();
        RArmHigh();
        InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - sequenceStartTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

    }

    sequenceStartTime = millis();    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
    LArmHigh();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
    LArmHigh();
    RArmStraight();
    InitializeMovement(-90,100); // POSITION 2: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 3 + RandomLEDs + 360 horaire + LArmStraight + RArmStraight
    LArmStraight();
    RArmStraight();
    InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
    LArmStraight();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }
    sequenceStartTime = millis();    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
    LArmHigh();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - sequenceStartTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    sequenceStartTime = millis();    // POSITION 0 + RandomLEDs
    LArmLow();
    RArmLow();
    InitializeMovement(-135, 100);
    InitializePIDStraight(28.28427);
    finished = false;
    while (millis() - sequenceStartTime < 2000) {   // POSITION 0 : Turn 135 antihoraire + Advance 28,28427cm + 90 hor
        DoMovementIteration();
        RandomLEDs();
        if (CheckIfMovementIsFinished())
            if (TickPidStraight()) {
                if (finished){}
                else if (CheckIfMovementIsFinished()) {
                    InitializeMovement(90, 100);
                }else {
                    finished = DoMovementIteration();
                }
                delay(100);
            }

        sequenceStartTime = millis();    // 1080 horaire
        InitializeMovement(1080,100);
        while (millis() - sequenceStartTime < 2000) {
            DoMovementIteration();

            delay(100);
        }

        CloseAllLeds();

    }
}
