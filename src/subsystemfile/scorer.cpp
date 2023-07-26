#include "main.h"

void setPuncherVoltage(int power) {
    scorer.move(power);
}

vector<int> setPuncher(bool intaking, bool senseStart, int past, int counter) {
    int LineSensorState = LineSensor.get_value();
    bool R1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);

    if(LineSensorState <= 1500 && past > 1500)
        senseStart = true;
    if(counter > 200) {//250 milliseconds
        senseStart = false;
        counter = 0;
    }
    if(LineSensorState > 1500 || senseStart || (R1TON && intaking))
        setPuncherVoltage(127);
    else
        setPuncherVoltage(0);

    return {senseStart, LineSensorState, counter};
}