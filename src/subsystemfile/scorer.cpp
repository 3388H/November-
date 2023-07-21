#include "main.h"

pros::ADIDigitalIn Limit(1);

//funcs
void setPuncherVoltage(float power) {
    scorer = power;
}

//PUNCHER
void setPuncher() {
    bool LimitState = Limit.get_value();
    bool R1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    if(!LimitState || R1TON)
        setPuncherVoltage(127.0);
    else
        setPuncherVoltage(0.0);
}