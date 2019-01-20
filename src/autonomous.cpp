//------Importing stuff.------
#include "main.h"
#include "autonomous.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

void autonomous() {
	//------tells the user that the autonomous faze has started.------
  pros::lcd::set_text(0, "autonomous has started");

  pros::delay(10000);
  Intake.move_absolute(1000, 200);


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
