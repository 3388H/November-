#include "main.h"

void setIntakeVoltage(int power) {
    intake.move(power);
}

void setIntake() {
    bool R1TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R1);
    bool R2TON = controller.get_digital(pros::E_CONTROLLER_DIGITAL_R2);

    int intakePower = 127 * (R1TON - R2TON);
    
    setIntakeVoltage(intakePower);
}