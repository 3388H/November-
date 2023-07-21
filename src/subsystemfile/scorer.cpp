#include "main.h"

//pros::ADIDigitalIn Limit(1);

void setPuncherVoltage(int power) {
    scorer.move(power);
}

void setPuncher() {
    int LineSensorState = LineSensor.get_value();
    bool R1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    if(LineSensorState > 1000 || R1TON)//if(!LimitState || R1TON)
        setPuncherVoltage(127);
    else
        setPuncherVoltage(0);
}