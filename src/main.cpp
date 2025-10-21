#include <Arduino.h>
#include <Allfunctions.h>
#include <librobus.h>

void setup() {
// write your initialization code here
    BoardInit();
    delay(300);
    InitServosArms();
    SetupLEDS();


}

void loop() {

}
