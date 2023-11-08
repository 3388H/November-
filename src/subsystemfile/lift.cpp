#include "main.h"

void setLiftVoltage(int power) {
    lift.move(power);
}

void setLift() {
    bool L1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    bool L2TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

    int liftPower = 127 * (L1TON - L2TON);

    setLiftVoltage(liftPower);
}