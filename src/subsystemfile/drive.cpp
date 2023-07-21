#include "main.h"

//funcs
void setMotorDriveVoltage(int left, int right) {

    backRightMotor.move_voltage(12000 * right / 100);
    middleRightMotor.move_voltage(12000 * right / 100);
    frontRightMotor.move_voltage(12000 * right / 100);
    backLeftMotor.move_voltage(12000 * left / 100);
    middleLeftMotor.move_voltage(12000 * left / 100);
    frontLeftMotor.move_voltage(12000 * left / 100);
}

void setMotors() {
    int leftJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    int rightJoystick = controller.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    
    // if(abs(leftJoystick) < 10) {
    //     leftJoystick = 0;
    // }
    // if(abs(rightJoystick) < 10) {
    //     rightJoystick = 0;
    // }

    setMotorDriveVoltage(leftJoystick - rightJoystick, leftJoystick + rightJoystick);
}