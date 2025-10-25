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

}


//Complete sequence FAIRE ATTENTION AUX DELAIS ET TOUT, JAI RIEN AJOUTÉ

void sequence() {
    //PREMIERE CHANSON----------------------------------------------------------

    startTime = millis();//Snapshot of current time
    while (millis() - startTime < 5000) { //Current time - start time = time spent in milli seconds. SO here it is 5 seconds

        delay(500);
    }

    // LArmHigh
    // LArmHigh + RArmHigh
    // LArmLow + RArmHigh
    // LArmLow + RArmLow

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
    while (millis() - startTime < 2000) {
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

    // Changement place en bas avk P-07 (-1)
    // POSITION 1 + RedLEDOn
    // POSITION 2 + YellowLEDOn
    // POSITION 3 + GreenLEDOn
    // POSITION 4 + BlueLEDOn
    // POSITION 0 +RedLEDOn+YellowLEDOn+GreenLEDOn+BlueLEDOn
    // 720 horaire + RandomLEDs


    //QUATRIEME CHANSON-------------------------------------------------------------------

    // Retour changement place en haut avk P-07 (+1)
    // POSITION 1 + RedLEDOn
    // POSITION 2 + YellowLEDOn
    // POSITION 3 + GreenLEDOn
    // POSITION 4 + BlueLEDOn
    // POSITION 0 + RandomLEDs


    //CINQUIEME CHANSON-------------------------------------------------------------------

    // POSITION 1 + RedLEDOn + LArmStraight + RArmStraight
    // POSITION 2 + YellowLEDOn + LArmHigh + RArmHigh
    // POSITION 3 + GreenLEDOn + LArmLow + RArmLow
    //POSITION 4 + BlueLEDOn + LArmStraight + RArmStraight

    // POSITION 1 + LArmHigh + RArmHigh
    // POSITION 2 + LArmHigh + RArmStraight
    // POSITION 3 + LArmStraight + RArmStraight
    // POSITION 4 + LArmStraight + RArmHigh


    //SIXIEME CHANSON---------------------------------------------------------------------

    // POSITION 1 + RandomLEDs + LArmHigh + RArmHigh
    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
    // POSITION 3 + RandomLEDs + LArmStraight + RArmStraight
    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh

    for (int i=1;i<=2;i++) { // 2 fois la meme chose
        // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
        // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
        // POSITION 3 + RandomLEDs + LArmStraight + RArmStraight
        // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh
    }

    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
    // POSITION 2 + RandomLEDs + LArmHigh + RArmStraight
    // POSITION 3 + RandomLEDs + !!!360 horaire!!! + LArmStraight + RArmStraight
    // POSITION 4 + RandomLEDs + LArmStraight + RArmHigh

    // POSITION 1 + RandomLEDs + 360 horaire + LArmHigh + RArmHigh
    // POSITION 0 + RandomLEDs
    // 1080 horaire

}
