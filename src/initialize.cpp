#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

// Toggle button for parking in auton
void on_center_button() {
  if (IsParking == true) {
    pros::lcd::set_text(7, "                   Not Parking");
    IsParking = false;
  }
  else {
    IsParking = true;
    pros::lcd::set_text(7, "                     Parking");
  }
}

// Cycles through the autons going to the left
void on_left_button() {
  selection = (selection - 1 + 5) % 5;
  pros::lcd::set_text(6, titles[selection]);
}

// Cycles through the autons going to the left
void on_right_button() {
  selection = (selection + 1) % 5;
  pros::lcd::print(6, titles[selection]);
}

void initialize() {
  // Initializing lcd screen and printing Initial text
  pros::lcd::initialize();
  if (IsParking == true) {
    pros::lcd::set_text(7, "                     Parking");
  }
  else {
    pros::lcd::set_text(7, "                   Not Parking");
  }
  pros::lcd::set_text(6, titles[selection]);

  // Sets a callback function for the buttons
  pros::lcd::register_btn1_cb(on_center_button);
  pros::lcd::register_btn0_cb(on_left_button);
  pros::lcd::register_btn2_cb(on_right_button);

  // Sets Initial revering states for the motors
  FLMotor.set_reversed(false);
  FRMotor.set_reversed(true);
  BLMotor.set_reversed(false);
  BRMotor.set_reversed(true);

  pros::Task Diagnostics(Diagnostics_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");

  // Tells the arm to hold it's position
  // Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  // Prints to the consol that Init has finished
  printf("Init finished\n");
}

/*
  Runs while the robot is in the disabled state of Field Management System or
  the VEX Competition Switch, following either autonomous or opcontrol. 
  When the robot is enabled, this task will exit
*/
void disabled() {
  pros::lcd::set_text(1, "How rude you disabled me.");
}

/*
  Runs after initialize(), and before autonomous when connected to the Field
  Management System or the VEX Competition Switch. This is intended for
  competition-specific initialization routines, such as an autonomous selector on the LCD.
  This task will exit when the robot is enabled and autonomous or opcontrol starts.
*/
void competition_initialize() {}
