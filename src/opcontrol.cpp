#include "main.h"

void opcontrol() {
  // Starts all the functions for controlling the robot
  pros::Task Arm (Arm_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task Intake (Intake_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task Shooter (Shooter_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task DriveTrain (DriveTrain_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  
  // Loop to keep the main thread allive
  while (true) {
    // Delay for background code execution
    pros::delay(2);
  }
}
