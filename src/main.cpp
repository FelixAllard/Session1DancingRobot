#include <Arduino.h>
#include <Allfunctions.h>
#include <librobus.h>

unsigned long startTime = 0;

void setup() {
// write your initialization code here
    BoardInit();
    Serial.begin(115200);
    delay(300);
    InitServosArms();
    SetupLEDS();

}

void loop() {
    Serial.println(" Hello World ");
}


//Complete sequence FAIRE ATTENTION AUX DELAIS ET TOUT, JAI RIEN AJOUTÉ

void sequence() {


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

    startTime = millis();    // LArmHigh
    LArmHigh();
    while (millis() - startTime < 2000) {}

    startTime = millis();    // LArmHigh + RArmHigh
    CloseAllLeds();
    LArmHigh();
    RArmHigh();
    while (millis() - startTime < 2000) {}

    startTime = millis();    // LArmLow + RArmHigh
    CloseAllLeds();
    LArmLow();
    RArmHigh();
    while (millis() - startTime < 2000) {}

    startTime = millis();    // LArmLow + RArmLow for 18 seconds
    CloseAllLeds();
    RArmLow();
    LArmLow();
    while (millis() - startTime < 18000) {}

    startTime = millis();
    CloseAllLeds();
    RedLEDOn();
    while (millis() - startTime < 2000) {}

    startTime = millis();    // YellowLEDOn
    CloseAllLeds();
    YellowLEDOn();
    while (millis() - startTime < 2000) {}

    startTime = millis();    // GreenLEDOn
    GreenLEDOn();
    while (millis() - startTime < 2000) {}

    startTime = millis();    // BlueLEDOn
    CloseAllLeds();
    BlueLEDOn();
    while (millis() - startTime < 2000) {}


    startTime = millis();    // RedLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    RedLEDOn();
    LArmStraight();
    RArmStraight();
    while (millis() - startTime < 2000) {}

    startTime = millis();    // YellowLEDOn + LArmHigh + RArmHigh
    CloseAllLeds();
    YellowLEDOn();
    LArmHigh();
    RArmHigh();
    while (millis() - startTime < 2000) {}

    startTime = millis();    // GreenLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    GreenLEDOn();
    LArmStraight();
    RArmStraight();

    while (millis() - startTime < 2000) {}

    startTime = millis();    // BlueLEDOn + LArmLow + RArmLow
    CloseAllLeds();
    BlueLEDOn();
    LArmLow();
    RArmLow();
    while (millis() - startTime < 2000) {}

    //TODO 360
    startTime = millis();    // 360 horaire + RandomLEDs + LArmHigh + RArmHigh
    CloseAllLeds();
    LArmHigh();
    RArmHigh();
    while (millis() - startTime < 4000) {
        RandomLEDs();
        delay(100);
    }


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


    //TODO 360 AntiHoraire
    startTime = millis();    // 360 antihoraire + RandomLEDs + LArmStraight + RArmStraight
    CloseAllLeds();
    LArmStraight();
    RArmStraight();
    while (millis() - startTime < 4000) {
        // 360 anti-horaire
        RandomLEDs();
        delay(100);
    }

    //DEUXIEME CHANSON----------------------------------------------------------------

    //TODO Position 1
    startTime = millis();    // Position 1 + LArmLow + RArmLow
    CloseAllLeds();
    LArmLow();
    RArmLow();
    while (millis() - startTime < 4000) {
        // POSITION 1;
    }

    // POSITION 2
    // POSITION 3
    // POSITION 4

    // POSITION 1
    // POSITION 2
    // POSITION 3
    // POSITION 4

    // POSITION 0


    //TROISIEME CHANSON-----------------------------------------------------------------

    // Changement place en bas avk P-07 (-1) 8sec
    //TODO Position 1;
    startTime = millis();    // POSITION 1 + RedLEDOn
    RedLEDOn();
    while (millis() - startTime < 4000) {
        // POSITION 1;


        delay(500);
    }

    startTime = millis();    // POSITION 2 + YellowLEDOn
    CloseAllLeds();
    YellowLEDOn();
    while (millis() - startTime < 4000) {
        // POSITION 2;
        delay(500);
    }

    startTime = millis();    // POSITION 3 + GreenLEDOn
    CloseAllLeds();
    GreenLEDOn();
    while (millis() - startTime < 4000) {
        // POSITION 3;
        delay(500);
    }

    startTime = millis();    // POSITION 4 + BlueLEDOn
    CloseAllLeds();
    BlueLEDOn();
    while (millis() - startTime < 4000) {
        // POSITION 4;
        delay(500);
    }

    startTime = millis();    // POSITION 0 +RedLEDOn+YellowLEDOn+GreenLEDOn+BlueLEDOn
    CloseAllLeds();
    RedLEDOn();
    YellowLEDOn();
    GreenLEDOn();
    while (millis() - startTime < 4000) {
        // POSITION 0;
        delay(500);
    }

    //TODO 720 horaire
    startTime = millis();    // 720 horaire + RandomLEDs
    CloseAllLeds();
    while (millis() - startTime < 4000) {
        // 720 horaire
        RandomLEDs();

        delay(500);
    }
    CloseAllLeds();

    //QUATRIEME CHANSON-------------------------------------------------------------------

    // Retour changement place en haut avk P-07 (+1) 8 sec

    startTime = millis();    // POSITION 1 + RedLEDOn
    CloseAllLeds();
    RedLEDOn();
    while (millis() - startTime < 4000) {
        // POSITION 1;
        delay(500);
    }

    startTime = millis();    // POSITION 2 + YellowLEDOn
    CloseAllLeds();
    YellowLEDOn();
    while (millis() - startTime < 4000) {
        // POSITION 2;
        delay(500);
    }

    startTime = millis();    // POSITION 3 + GreenLEDOn
    CloseAllLeds();
    GreenLEDOn();
    while (millis() - startTime < 4000) {
        // POSITION 3;
        delay(500);
    }

    startTime = millis();    // POSITION 4 + BlueLEDOn
    CloseAllLeds();
    BlueLEDOn();
    while (millis() - startTime < 4000) {
        // POSITION 4;

        delay(500);
    }

    startTime = millis();    // POSITION 0 + RandomLEDs
    CloseAllLeds();
    while (millis() - startTime < 4000) {
        // POSITION 0;
        RandomLEDs();

        delay(100);
    }

    CloseAllLeds();

    //CINQUIEME CHANSON-------------------------------------------------------------------
    startTime = millis();    // POSITION 1 + RedLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    RedLEDOn();
    LArmStraight();
    RArmStraight();
    while (millis() - startTime < 4000) {
        // POSITION 1;
        delay(100);
    }

    startTime = millis();    // POSITION 2 + YellowLEDOn + LArmHigh + RArmHigh
    CloseAllLeds();
    YellowLEDOn();
    LArmHigh();
    RArmHigh();
    while (millis() - startTime < 4000) {
        // POSITION 2;
        delay(500);
    }

    startTime = millis();    // POSITION 3 + GreenLEDOn + LArmLow + RArmLow
    CloseAllLeds();
    GreenLEDOn();
    LArmLow();
    RArmLow();
    while (millis() - startTime < 4000) {
        // POSITION 3;
        delay(500);
    }

    startTime = millis();    // POSITION 4 + BlueLEDOn + LArmStraight + RArmStraight
    CloseAllLeds();
    BlueLEDOn();
    LArmStraight();
    RArmStraight();
    while (millis() - startTime < 4000) {
        // POSITION 4;
        delay(100);
    }

    startTime = millis();    // POSITION 1 + LArmHigh + RArmHigh
    CloseAllLeds();
    LArmHigh();
    RArmHigh();
    while (millis() - startTime < 4000) {
        // POSITION 1;
        delay(100);
    }

    startTime = millis();    // POSITION 2 + LArmHigh + RArmStraight
    while (millis() - startTime < 4000) {
        // POSITION 2;
        LArmHigh();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // POSITION 3 + LArmStraight + RArmStraight
    while (millis() - startTime < 4000) {
        // POSITION 3;
        LArmStraight();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // POSITION 4 + LArmStraight + RArmHigh
    while (millis() - startTime < 4000) {
        // POSITION 4;
        LArmStraight();
        RArmHigh();

        delay(500);
    }

    //SIXIEME CHANSON- FAIRE ATTENTION AUX DÉLAIS CAR CEST PAS LES BONS!!!--------------------------------------------------------------------

    startTime = millis();    // POSITION 1 + RandomLEDs + LArmHigh + RArmHigh
    while (millis() - startTime < 2000) {
        // POSITION 1;
        RandomLEDs();
        LArmHigh();
        RArmHigh();

        delay(500);
    }

    startTime = millis();    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
    while (millis() - startTime < 2000) {
        // POSITION 2;
        RandomLEDs();
        LArmHigh();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // POSITION 3 + RandomLEDs + LArmStraight + RArmStraight
    while (millis() - startTime < 2000) {
        // POSITION 3;
        RandomLEDs();
        LArmStraight();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
    while (millis() - startTime < 2000) {
        // POSITION 4;
        RandomLEDs();
        LArmStraight();
        RArmHigh();

        delay(500);
    }

    for (int i=1;i<=2;i++) { // 2 fois la meme chose
        startTime = millis();    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
        while (millis() - startTime < 2000) {
            // POSITION 1;
            //360 horaire;
            RandomLEDs();
            LArmHigh();
            RArmHigh();

            delay(500);
        }

        startTime = millis();    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
        while (millis() - startTime < 2000) {
            // POSITION 2;
            RandomLEDs();
            LArmHigh();
            RArmStraight();

            delay(500);
        }

        startTime = millis();    // POSITION 3 + RandomLEDs + LArmStraight + RArmStraight
        while (millis() - startTime < 2000) {
            // POSITION 3;
            RandomLEDs();
            LArmStraight();
            RArmStraight();

            delay(500);
        }

        startTime = millis();    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
        while (millis() - startTime < 2000) {
            // POSITION 4;
            RandomLEDs();
            LArmStraight();
            RArmHigh();

            delay(500);
        }

    }

    startTime = millis();    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
    while (millis() - startTime < 2000) {
        // POSITION 1;
        //360 horaire;
        RandomLEDs();
        LArmHigh();
        RArmHigh();

        delay(500);
    }

    startTime = millis();    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
    while (millis() - startTime < 2000) {
        // POSITION 2;
        RandomLEDs();
        LArmHigh();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // POSITION 3 + RandomLEDs + 360 horaire + LArmStraight + RArmStraight
    while (millis() - startTime < 2000) {
        // POSITION 3;
        // 360 horaire
        RandomLEDs();
        LArmStraight();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
    while (millis() - startTime < 2000) {
        // POSITION 4;
        RandomLEDs();
        LArmStraight();
        RArmHigh();

        delay(500);
    }

    startTime = millis();    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
    while (millis() - startTime < 2000) {
        // POSITION 1;
        //360 horaire;
        RandomLEDs();
        LArmHigh();
        RArmHigh();

        delay(500);
    }

    startTime = millis();    // POSITION 0 + RandomLEDs
    while (millis() - startTime < 2000) {
        LArmLow();
        RArmLow();
        // POSITION 0;
        RandomLEDs();

        delay(500);
    }

    startTime = millis();    // 1080 horaire
    while (millis() - startTime < 2000) {
        // 1080 horaire;

        delay(500);
    }

    RedLEDOff();
    YellowLEDOff();
    GreenLEDOff();
    BlueLEDOff();

}
