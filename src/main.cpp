#include <Arduino.h>
#include <Allfunctions.h>
#include <librobus.h>

unsigned long startTime = 0;

void setup() {
// write your initialization code here
    BoardInit();
    delay(300);
    InitServosArms();
    SetupLEDS();

}

void loop() {
    RArmHigh();
}


//Complete sequence FAIRE ATTENTION AUX DELAIS ET TOUT, JAI RIEN AJOUTÉ

void sequence() {


    //PREMIERE CHANSON----------------------------------------------------------

    startTime = millis();//Snapshot of current time, attente
    while (millis() - startTime < 8000) { //Current time - start time = time spent in milli seconds. SO here it is 5 seconds
        LArmLow();
        RArmLow();
        RedLEDOff();
        YellowLEDOff();
        GreenLEDOff();
        BlueLEDOff();

        delay(500);
    }

    startTime = millis();    // LArmHigh
    while (millis() - startTime < 2000) {
        LArmHigh();

        delay(500);
    }

    startTime = millis();    // LArmHigh + RArmHigh
    while (millis() - startTime < 2000) {
        RArmHigh();

        delay(500);
    }

    startTime = millis();    // LArmLow + RArmHigh
    while (millis() - startTime < 2000) {
        LArmLow();

        delay(500);
    }

    startTime = millis();    // LArmLow + RArmLow for 18 seconds
    while (millis() - startTime < 18000) {
        RArmLow();

        delay(500);
    }

    startTime = millis();    // RedLEDOn
    while (millis() - startTime < 2000) {
        RedLEDOn();

        delay(500);
    }

    startTime = millis();    // YellowLEDOn
    while (millis() - startTime < 2000) {
        RedLEDOff();

        YellowLEDOn();

        delay(500);
    }

    startTime = millis();    // GreenLEDOn
    while (millis() - startTime < 2000) {
        YellowLEDOff();

        GreenLEDOn();

        delay(500);
    }

    startTime = millis();    // BlueLEDOn
    while (millis() - startTime < 2000) {
        GreenLEDOff();

        BlueLEDOn();

        delay(500);
    }


    startTime = millis();    // RedLEDOn + LArmStraight + RArmStraight
    while (millis() - startTime < 2000) {
        BlueLEDOff();

        RedLEDOn();
        LArmStraight();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // YellowLEDOn + LArmHigh + RArmHigh
    while (millis() - startTime < 2000) {
        RedLEDOff();

        YellowLEDOn();
        LArmHigh();
        RArmHigh();

        delay(500);
    }

    startTime = millis();    // GreenLEDOn + LArmStraight + RArmStraight
    while (millis() - startTime < 2000) {
        YellowLEDOff();

        GreenLEDOn();
        LArmStraight();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // BlueLEDOn + LArmLow + RArmLow
    while (millis() - startTime < 2000) {
        GreenLEDOff();

        BlueLEDOn();
        LArmLow();
        RArmLow();

        delay(500);
    }

    startTime = millis();    // 360 horaire + RandomLEDs + LArmHigh + RArmHigh
    while (millis() - startTime < 4000) {
        // 360 horaire
        BlueLEDOff();

        RandomLEDs();
        LArmHigh();
        RArmHigh();

        delay(500);
    }

    RedLEDOff();
    YellowLEDOff();
    GreenLEDOff();
    BlueLEDOff();

    startTime = millis();     // Alternated RedLEDOn/YellowLEDOn + LArmLow + RArmLow
    while (millis() - startTime < 2000) {
        LArmLow();
        RArmLow();
        RedLEDOn();
        YellowLEDOff();

        delay(100);

        RedLEDOff();
        YellowLEDOn();

        delay(100);
    }

    startTime = millis();     // Alternated YellowLEDOn/GreenLEDOn
    while (millis() - startTime < 2000) {
        YellowLEDOn();
        GreenLEDOff();

        delay(100);

        YellowLEDOff();
        GreenLEDOn();

        delay(100);
    }


    startTime = millis();     // Alternated GreenLEDOn/BlueLEDOn
    while (millis() - startTime < 2000) {
        GreenLEDOn();
        BlueLEDOff();

        delay(100);

        GreenLEDOff();
        BlueLEDOn();

        delay(100);
    }

    startTime = millis();    // Alternated BlueLEDOn/RedLEDOn
    while (millis() - startTime < 2000) {
        BlueLEDOn();
        RedLEDOff();

        delay(100);

        BlueLEDOff();
        RedLEDOn();

        delay(100);
    }

    RedLEDOff();

    startTime = millis();    // 360 antihoraire + RandomLEDs + LArmStraight + RArmStraight
    while (millis() - startTime < 4000) {
        // 360 anti-horaire
        RandomLEDs();
        LArmStraight();
        RArmStraight();

        delay(500);
    }

    RedLEDOff();
    YellowLEDOff();
    GreenLEDOff();
    BlueLEDOff();


    //DEUXIEME CHANSON----------------------------------------------------------------

    startTime = millis();    // Position 1 + LArmLow + RArmLow
    while (millis() - startTime < 4000) {
        // POSITION 1;
        LArmLow();
        RArmLow();

        delay(500);
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

    startTime = millis();    // POSITION 1 + RedLEDOn
    while (millis() - startTime < 4000) {
        // POSITION 1;
        RedLEDOn();

        delay(500);
    }

    startTime = millis();    // POSITION 2 + YellowLEDOn
    while (millis() - startTime < 4000) {
        RedLEDOff();
        // POSITION 2;
        YellowLEDOn();

        delay(500);
    }

    startTime = millis();    // POSITION 3 + GreenLEDOn
    while (millis() - startTime < 4000) {
        YellowLEDOff();
        // POSITION 3;
        GreenLEDOn();

        delay(500);
    }

    startTime = millis();    // POSITION 4 + BlueLEDOn
    while (millis() - startTime < 4000) {
        GreenLEDOff();
        // POSITION 4;
        BlueLEDOn();

        delay(500);
    }

    startTime = millis();    // POSITION 0 +RedLEDOn+YellowLEDOn+GreenLEDOn+BlueLEDOn
    while (millis() - startTime < 4000) {
        // POSITION 0;
        RedLEDOn();
        YellowLEDOn();
        GreenLEDOn();

        delay(500);
    }

    startTime = millis();    // 720 horaire + RandomLEDs
    while (millis() - startTime < 4000) {
        // 720 horaire
        RandomLEDs();

        delay(500);
    }

    RedLEDOff();
    YellowLEDOff();
    GreenLEDOff();
    BlueLEDOff();


    //QUATRIEME CHANSON-------------------------------------------------------------------

    // Retour changement place en haut avk P-07 (+1) 8 sec

    startTime = millis();    // POSITION 1 + RedLEDOn
    while (millis() - startTime < 4000) {
        // POSITION 1;
        RedLEDOn();

        delay(500);
    }

    startTime = millis();    // POSITION 2 + YellowLEDOn
    while (millis() - startTime < 4000) {
        RedLEDOff();
        // POSITION 2;
        YellowLEDOn();

        delay(500);
    }

    startTime = millis();    // POSITION 3 + GreenLEDOn
    while (millis() - startTime < 4000) {
        YellowLEDOff();
        // POSITION 3;
        GreenLEDOn();

        delay(500);
    }

    startTime = millis();    // POSITION 4 + BlueLEDOn
    while (millis() - startTime < 4000) {
        GreenLEDOff();
        // POSITION 4;
        BlueLEDOn();

        delay(500);
    }

    startTime = millis();    // POSITION 0 + RandomLEDs
    while (millis() - startTime < 4000) {
        BlueLEDOff();
        // POSITION 0;
        RandomLEDs();

        delay(500);
    }

    RedLEDOff();
    YellowLEDOff();
    GreenLEDOff();
    BlueLEDOff();

    //CINQUIEME CHANSON-------------------------------------------------------------------
    startTime = millis();    // POSITION 1 + RedLEDOn + LArmStraight + RArmStraight
    while (millis() - startTime < 4000) {
        // POSITION 1;
        RedLEDOn();
        LArmStraight();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // POSITION 2 + YellowLEDOn + LArmHigh + RArmHigh
    while (millis() - startTime < 4000) {
        RedLEDOff();
        // POSITION 2;
        YellowLEDOn();
        LArmHigh();
        RArmHigh();

        delay(500);
    }

    startTime = millis();    // POSITION 3 + GreenLEDOn + LArmLow + RArmLow
    while (millis() - startTime < 4000) {
        YellowLEDOff();
        // POSITION 3;
        GreenLEDOn();
        LArmLow();
        RArmLow();

        delay(500);
    }

    startTime = millis();    // POSITION 4 + BlueLEDOn + LArmStraight + RArmStraight
    while (millis() - startTime < 4000) {
        GreenLEDOff();
        // POSITION 4;
        BlueLEDOn();
        LArmStraight();
        RArmStraight();

        delay(500);
    }

    startTime = millis();    // POSITION 1 + LArmHigh + RArmHigh
    while (millis() - startTime < 4000) {
        BlueLEDOff();
        // POSITION 1;
        LArmHigh();
        RArmHigh();

        delay(500);
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
