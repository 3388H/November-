#include "main.h"

void setLoadVoltage(int power) {
    scorerleft.move(power);
    scorerright.move(power);
}

bool setLoad(bool past) {
    bool L1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_X);
    if(!past && L1TON) {
        setLoadVoltage(127);
    }
    else if(past && !L1TON) {
        setLoadVoltage(0);
    }

    setLiftVoltage(0);
    return L1TON;
}