#include "main.h"

void setIntakeVoltage(int power) {
    intake.move(power);
}

bool setIntake() {
    bool L1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1);
    bool L2TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_L2);

    int intakePower = 127 * (L1TON - L2TON);
    
    setIntakeVoltage(intakePower);

    return L2TON;
}