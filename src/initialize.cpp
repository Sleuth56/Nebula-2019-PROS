#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

//Not used yet.
void on_center_button() {
}

//Cycles through the autons going to the left.
void on_left_button() {
  selection = (selection - 1 + 5) % 5;
  pros::lcd::set_text(2, titles[selection]);
}

//Cycles through the autons going to the left.
void on_right_button() {
  selection = (selection + 1) % 5;
  pros::lcd::set_text(2, titles[selection]);
}

void initialize() {
  //Setting the revering state of the motors.
  FLMotor.set_reversed(false);
  FRMotor.set_reversed(true);
  BLMotor.set_reversed(false);
  BRMotor.set_reversed(true);

  pros::lcd::initialize();

  // Sets a callback function for the buttons
  pros::lcd::register_btn1_cb(on_center_button);
  pros::lcd::register_btn0_cb(on_left_button);
  pros::lcd::register_btn2_cb(on_right_button);

  pros::lcd::set_text(1, "Initialized");

  pros::lcd::set_text(2, titles[selection]);

  printf("Init finished\n");
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {
  pros::lcd::set_text(1, "How rude you disabled me.");
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
