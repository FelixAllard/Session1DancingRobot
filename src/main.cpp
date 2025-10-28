#include <Arduino.h>
#include <Allfunctions.h>
#include <librobus.h>
#include "ArcPID.h"
#include "Rotation.h"

#include "PIDStraight.h"

#include "Sequence.h"


void setup() {
// write your initialization code here
    BoardInit();
    Serial.begin(115200);
    delay(300);
    //InitializeLineSensor();
    InitServosArms();
    SetupLEDS();

    Sequence();
    /*InitializePIDStraight(100);
    while (true) {
        TickPidStraight();
        delay(10);
    }*/
}

void loop() {
    Serial.println(" Hello World ");
}


//Complete sequence FAIRE ATTENTION AUX DELAIS ET TOUT, JAI RIEN AJOUTÉ
