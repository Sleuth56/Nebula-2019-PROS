#include "main.h"

void autonomous() {
  LCDScriptExecute();

  while (abs(int(FLMotor.get_position() - FLMotor.get_target_position())) > 5) {
    pros::delay(2);
  }
  while (abs(int(FRMotor.get_position() - FRMotor.get_target_position())) > 5) {
    pros::delay(2);
  }
  while (abs(int(BLMotor.get_position() - BLMotor.get_target_position())) > 5) {
    pros::delay(2);
  }
  while (abs(int(BRMotor.get_position() - BRMotor.get_target_position())) > 5) {
    pros::delay(2);
  }
  while (abs(int(Arm.get_position() - Arm.get_target_position())) > 5) {
    pros::delay(2);
  }
  while (abs(int(Intake.get_position() - Intake.get_target_position())) > 5) {
    pros::delay(2);
  }
  while (abs(int(Shooter1.get_position() - Shooter1.get_target_position())) > 5) {
    pros::delay(2);
  }
  while (abs(int(Shooter2.get_position() - Shooter2.get_target_position())) > 5) {
    pros::delay(2);
  }
}
