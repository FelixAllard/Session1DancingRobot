#include <Arduino.h>
#include <Allfunctions.h>
#include <librobus.h>

#include "BumperStart.h"
#include "Sequence.h"


void setup() {
// write your initialization code here
    BoardInit();
    Serial.begin(115200);
    delay(300);
    //InitializeLineSensor();
    InitServosArms();
    SetupLEDS();

    WaitForBumperStart();
    MOTOR_SetSpeed(1,1.0);
    Sequence();
    /*InitializePIDStraight(100);
    while (true) {
        TickPidStraight();
        delay(10);
    }*/
}

void loop() {
    Serial.println("Goodbye World ");
}


//Complete sequence FAIRE ATTENTION AUX DELAIS ET TOUT, JAI RIEN AJOUTÉ
