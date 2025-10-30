//
// Created by xilef on 10/30/2025.
//

#include "BumperStart.h"
#include <LibRobus.h>

void WaitForBumperStart() {
    while (true) {
        if (ROBUS_IsBumper(0)) {
            return;
        }
    }
}
