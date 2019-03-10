#include "main.h"

void opcontrol() {
  //Prints "opcontrol has started" on the brain screen.
  pros::lcd::set_text(0, "opcontrol has started");

  //starts all the functions for controlling the robot.
  pros::Task Arm (Arm_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task Intake (Intake_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task Shooter (Shooter_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task DriveTrain (DriveTrain_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  while (true) {
    pros::lcd::initialize();
    //Delay for background code execution.
    pros::delay(2);
  }
}
