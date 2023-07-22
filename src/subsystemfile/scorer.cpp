#include "main.h"

void setPuncherVoltage(int power) {
    scorer.move(power);
}

pair<int, int> setPuncher(bool senseStart, int past) {
    int LineSensorState = LineSensor.get_value();
    bool R1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);

    if(LineSensorState > 1000 && past <= 1000)
        senseStart = true;
    if(LineSensorState < 500)
        senseStart = false;

    if(LineSensorState > 1000 || senseStart || R1TON)//if(!LimitState || R1TON)
        setPuncherVoltage(127);
    else
        setPuncherVoltage(0);

    return {senseStart, LineSensorState};
}