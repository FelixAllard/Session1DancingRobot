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

unsigned long startTime = 0;
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
    //PREMIERE CHANSON----------------------------------------------------------

    startTime = millis();//Snapshot of current time, attente
    LArmLow();
    RArmLow();
    RedLEDOff();
    YellowLEDOff();
    GreenLEDOff();
    BlueLEDOff();
    while (millis() - startTime < 8000) { //Current time - start time = time spent in milli seconds. SO here it is 5 seconds

    }

    
ChangeStep();

    
    startTime = millis();    // LArmHigh
    LArmHigh();
    while (millis() - startTime < 2000) {}
    
ChangeStep();

    startTime = millis();    // LArmHigh + RArmHigh
    CloseAllLeds();
    LArmHigh();
    RArmHigh();
    while (millis() - startTime < 2000) {}
    
ChangeStep();

    startTime = millis();    // LArmLow + RArmHigh
    CloseAllLeds();
    LArmLow();
    RArmHigh();
    while (millis() - startTime < 2000) {}
    
ChangeStep();

    startTime = millis();    // LArmLow + RArmLow for 18 seconds
    CloseAllLeds();
    RArmLow();
    LArmLow();
    while (millis() - startTime < 18000) {}
    
ChangeStep();

    startTime = millis();
    CloseAllLeds();
    RedLEDOn();
    while (millis() - startTime < 2000) {}
    
ChangeStep();

    startTime = millis();    // YellowLEDOn
    CloseAllLeds();
    YellowLEDOn();
    while (millis() - startTime < 2000) {}
    
ChangeStep();

    startTime = millis();    // GreenLEDOn
    GreenLEDOn();
    while (millis() - startTime < 2000) {}
    
ChangeStep();

    startTime = millis();    // BlueLEDOn
    CloseAllLeds();
    BlueLEDOn();
    while (millis() - startTime < 2000) {}

    
ChangeStep();

    startTime = millis();    // RedLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    RedLEDOn();
    LArmStraight();
    RArmStraight();
    while (millis() - startTime < 2000) {}
    
ChangeStep();

    startTime = millis();    // YellowLEDOn + LArmHigh + RArmHigh
    CloseAllLeds();
    YellowLEDOn();
    LArmHigh();
    RArmHigh();
    while (millis() - startTime < 2000) {}
    
ChangeStep();

    startTime = millis();    // GreenLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    GreenLEDOn();
    LArmStraight();
    RArmStraight();

    while (millis() - startTime < 2000) {}
    
ChangeStep();

    startTime = millis();    // BlueLEDOn + LArmLow + RArmLow
    CloseAllLeds();
    BlueLEDOn();
    LArmLow();
    RArmLow();
    while (millis() - startTime < 2000) {}
    
ChangeStep();

    //TODO 360
    startTime = millis();    // 360 horaire + RandomLEDs + LArmHigh + RArmHigh
    CloseAllLeds();
    LArmHigh();
    RArmHigh();
    InitializeMovement(360,100);
    while (millis() - startTime < 4000) {
        DoMovementIteration();
        RandomLEDs();
        delay(100);
    }
    
ChangeStep();


    startTime = millis();     // Alternated RedLEDOn/YellowLEDOn + LArmLow + RArmLow
    CloseAllLeds();
    LArmLow();
    RArmLow();
    while (millis() - startTime < 2000) {
        RedLEDOn();
        YellowLEDOff();
        delay(100);
        RedLEDOff();
        YellowLEDOn();
        delay(100);
    }
    
ChangeStep();

    startTime = millis();     // Alternated YellowLEDOn/GreenLEDOn
    CloseAllLeds();
    while (millis() - startTime < 2000) {
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


    startTime = millis();     // Alternated GreenLEDOn/BlueLEDOn
    CloseAllLeds();
    while (millis() - startTime < 2000) {
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

    startTime = millis();    // Alternated BlueLEDOn/RedLEDOn
    CloseAllLeds();
    while (millis() - startTime < 2000) {
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
    startTime = millis();    // 360 antihoraire + RandomLEDs + LArmStraight + RArmStraight
    CloseAllLeds();
    LArmStraight();
    RArmStraight();
    InitializeMovement(-360,100);
    while (millis() - startTime < 4000) {
        DoMovementIteration();
        RandomLEDs();
        delay(100);
    }
    
ChangeStep();

    
ChangeStep();

    
ChangeStep();

    
ChangeStep();

    
ChangeStep();

    
ChangeStep();

    //DEUXIEME CHANSON----------------------------------------------------------------

    //TODO Position 1
    startTime = millis();    // Position 1 + LArmLow + RArmLow
    CloseAllLeds();
    LArmLow();
    RArmLow();
    InitializePIDStraight(20);
    while (millis() - startTime < 4000) {
        TickPidStraight() ; // POSITION 1
        // Advance 20cm

    }

    startTime = millis() ;
    InitializeMovement(-135, 100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) {   // POSITION 2 + Turn 135 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }


    startTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) { // POSITION 3 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }

    startTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) { // POSITION 4 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }

    startTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) { // POSITION 1 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }

    startTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) { // POSITION 2 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }

    startTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) { // POSITION 3 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }


    startTime = millis() ;
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) { // POSITION 4 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }


    startTime = millis() ;
    InitializeMovement(-135, 100);
    InitializePIDStraight(28.28427);
    bool finished = false;
    while (millis() - startTime < 4000) {   // POSITION 0 + Turn 135 antihoraire + Advance 28,28427cm
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


    //TROISIEME CHANSON-----------------------------------------------------------------

    startTime = millis(); // Changement place en bas avk P-07 (-1) 8sec
    InitializeMovement(180,100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) {
        DoMovementIteration(); // Turn 180 ho ou anti
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }


    //TODO POSITION 1
    startTime = millis();    // POSITION 1 + RedLEDOn
    RedLEDOn();
    InitializePIDStraight(20);
    while (millis() - startTime < 4000) { // POSITION 1 // Advance 20cm
        TickPidStraight();
        delay(100);
    }

    startTime = millis();    // POSITION 2 + YellowLEDOn
    CloseAllLeds();
    YellowLEDOn();
    InitializeMovement(-135,100); // POSITION 2: // Turn 135 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    startTime = millis();    // POSITION 3 + GreenLEDOn
    CloseAllLeds();
    GreenLEDOn();
    InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    startTime = millis();    // POSITION 4 + BlueLEDOn
    CloseAllLeds();
    BlueLEDOn();
    InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    startTime = millis();    // POSITION 0 +RedLEDOn+YellowLEDOn+GreenLEDOn+BlueLEDOn
    CloseAllLeds();
    RedLEDOn();
    YellowLEDOn();
    GreenLEDOn();
    InitializeMovement(-135,100);
    InitializePIDStraight(28.28427);
    finished = false;
    while (millis() - startTime < 4000) {   // POSITION 0 + Turn 135 antihoraire + Advance 28,28427cm + Turn90
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
    startTime = millis();    // 720 horaire + RandomLEDs
    CloseAllLeds();
    InitializeMovement(720,100);
    while (millis() - startTime < 4000) {
        DoMovementIteration();
        RandomLEDs();

        delay(100);
    }
    CloseAllLeds();

    // QUATRIEME CHANSON-------------------------------------------------------------------

    // Retour changement place en haut avk P-07 (+1) 8 sec

    startTime = millis();    // POSITION 1 + RedLEDOn
    CloseAllLeds();
    RedLEDOn();
    InitializePIDStraight(20);
    while (millis() - startTime < 4000) {    // POSITION 1 // Advance 20cm
        TickPidStraight();
        delay(100);
    }

    startTime = millis();    // POSITION 2 + YellowLEDOn
    CloseAllLeds();
    YellowLEDOn();
    InitializeMovement(-135,100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    startTime = millis();    // POSITION 3 + GreenLEDOn
    CloseAllLeds();
    GreenLEDOn();
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) { // POSITION 3 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }

    startTime = millis();    // POSITION 4 + BlueLEDOn
    CloseAllLeds();
    BlueLEDOn();
    InitializeMovement(-90, 100);
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 4000) { // POSITION 4 + Turn 90 antihoraire + Advance 28,28427cm
        DoMovementIteration();
        if (CheckIfMovementIsFinished())
            TickPidStraight();
    }

    startTime = millis();    // POSITION 0 + RandomLEDs
    CloseAllLeds();
    InitializeMovement(-135, 100);
    InitializePIDStraight(28.28427);
    finished = false;
    while (millis() - startTime < 4000) {   // POSITION 0 : Turn 135 antihoraire + Advance 28,28427cm + 90 hor
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

        CloseAllLeds();

        //CINQUIEME CHANSON-------------------------------------------------------------------
        startTime = millis();    // POSITION 1 + RedLEDOn + LArmStraight + RArmStraight
        CloseAllLeds();
        RedLEDOn();
        LArmStraight();
        RArmStraight();
        InitializePIDStraight(20);
        while (millis() - startTime < 4000) {    // POSITION 1 // Advance 20cm
            TickPidStraight();
            delay(100);
        }

        startTime = millis();    // POSITION 2 + YellowLEDOn + LArmHigh + RArmHigh
        CloseAllLeds();
        YellowLEDOn();
        LArmHigh();
        RArmHigh();
        InitializeMovement(-135,100); // POSITION 2: // Turn 135 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 4000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        startTime = millis();    // POSITION 3 + GreenLEDOn + LArmLow + RArmLow
        CloseAllLeds();
        GreenLEDOn();
        LArmLow();
        RArmLow();
        InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 4000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        startTime = millis();    // POSITION 4 + BlueLEDOn + LArmStraight + RArmStraight
        CloseAllLeds();
        BlueLEDOn();
        LArmStraight();
        RArmStraight();
        InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 4000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }


        startTime = millis();    // POSITION 1 + LArmHigh + RArmHigh
        CloseAllLeds();
        LArmHigh();
        RArmHigh();
        InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 4000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }


        startTime = millis();    // POSITION 2 + LArmHigh + RArmStraight
        LArmHigh();
        RArmStraight();
        InitializeMovement(-90,100); // POSITION 2: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 4000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }


        startTime = millis();    // POSITION 3 + LArmStraight + RArmStraight
        LArmStraight();
        RArmStraight();
        InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 4000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        startTime = millis();    // POSITION 4 + LArmStraight + RArmHigh
        LArmStraight();
        RArmHigh();
        InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 4000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        //SIXIEME CHANSON- FAIRE ATTENTION AUX DÉLAIS CAR CEST PAS LES BONS!!!--------------------------------------------------------------------

        startTime = millis();    // POSITION 1 + RandomLEDs + LArmHigh + RArmHigh
        RandomLEDs();
        LArmHigh();
        RArmHigh();
        InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        startTime = millis();    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
        RandomLEDs();
        LArmHigh();
        RArmStraight();
        InitializeMovement(-90,100); // POSITION 2: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        startTime = millis();    // POSITION 3 + RandomLEDs + LArmStraight + RArmStraight
        RandomLEDs();
        LArmStraight();
        RArmStraight();
        InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }
        startTime = millis();    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
        RandomLEDs();
        LArmStraight();
        RArmHigh();
        InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }
    }

    for (int i=1;i<=2;i++) { // 2 fois la meme chose
        startTime = millis();    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
        LArmHigh();
        RArmHigh();
        InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        startTime = millis();    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
        LArmHigh();
        RArmStraight();
        InitializeMovement(-90,100); // POSITION 2: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        startTime = millis();    // POSITION 3 + RandomLEDs + LArmStraight + RArmStraight
        LArmStraight();
        RArmStraight();
        InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

        startTime = millis();    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
        LArmStraight();
        RArmHigh();
        InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
        InitializePIDStraight(28.28427);
        while (millis() - startTime < 2000) {
            DoMovementIteration();
            if (CheckIfMovementIsFinished()) {
                TickPidStraight();
            }
            delay(100);
        }

    }

    startTime = millis();    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
    LArmHigh();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    startTime = millis();    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
    LArmHigh();
    RArmStraight();
    InitializeMovement(-90,100); // POSITION 2: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    startTime = millis();    // POSITION 3 + RandomLEDs + 360 horaire + LArmStraight + RArmStraight
    LArmStraight();
    RArmStraight();
    InitializeMovement(-90,100); // POSITION 3: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    startTime = millis();    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
    LArmStraight();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 4: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }
    startTime = millis();    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
    LArmHigh();
    RArmHigh();
    InitializeMovement(-90,100); // POSITION 1: // Turn 90 antihoraire // Advance 28,28427cm
    InitializePIDStraight(28.28427);
    while (millis() - startTime < 2000) {
        DoMovementIteration();
        if (CheckIfMovementIsFinished()) {
            TickPidStraight();
        }
        delay(100);
    }

    startTime = millis();    // POSITION 0 + RandomLEDs
    LArmLow();
    RArmLow();
    InitializeMovement(-135, 100);
    InitializePIDStraight(28.28427);
    finished = false;
    while (millis() - startTime < 2000) {   // POSITION 0 : Turn 135 antihoraire + Advance 28,28427cm + 90 hor
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

        startTime = millis();    // 1080 horaire
        InitializeMovement(1080,100);
        while (millis() - startTime < 2000) {
            DoMovementIteration();

            delay(100);
        }

        CloseAllLeds();

    }
}
