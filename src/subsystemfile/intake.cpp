#include "main.h"

//funcs
void setIntakeVoltage(float power) {
    intake = power;
}

void setIntake() {
    bool L1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    bool L2TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

    float intakePower = 127.0 * (L1TON - L2TON);

    setIntakeVoltage(intakePower);
}