#include "main.h"

//pros::ADIDigitalIn Limit(1);

void setPuncherVoltage(int power) {
    scorer.move(power);
}

void setPuncher() {
    //bool LimitState = Limit.get_value();
    bool R1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    if(R1TON)//if(!LimitState || R1TON)
        setPuncherVoltage(127);
    else
        setPuncherVoltage(0);
}