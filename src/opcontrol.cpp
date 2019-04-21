#include "main.h"

void opcontrol() {
  // Starts all the functions for opcontrol
  pros::Task Arm (Arm_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task Intake (Intake_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task Shooter (Shooter_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  pros::Task DriveTrain (DriveTrain_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  
  // Makes the master controller vibrate when the intake has two balls
  int count = 0;
  bool hasRun = false;
  while (true) {
    if (!(count % 25) && BottomIntakeSensor.get_value() == 1 && TopIntakeSensor.get_value() == 1 && hasRun == false) {
      // Only print every 50ms, the controller text update rate is slow
      hasRun = true;
      master.rumble("-");
    }
    count++;
    pros::delay(2);

    if (BottomIntakeSensor.get_value() == 0 && TopIntakeSensor.get_value() == 0 && hasRun == true) {
      hasRun = false;
    }
  }
}
