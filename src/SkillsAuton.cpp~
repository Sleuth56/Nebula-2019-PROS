#include "main.h"

void SkillsAuton() {
  Intake.move(50);
  Drive(3500, 3500, 60);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Intake.move(0);
  Drive(-3400, -3400, 60);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(730, 40);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn();
  Drive(3500, 3500, 60);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  pros::delay(300);

  Drive(1500, 1500, 60);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);

  Drive(500, 500, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(730, 40);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(500, 500, 50);
  pros::delay(500);
  Arm.move(100);
  pros::delay(300);
  Arm.move(-100);
  pros::delay(300);
  Arm.move(0);

  Drive(1000, 1000, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-400, -400, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(730, 40);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(2000, 2000, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
}




//Function for skills auton
void OldSkillsAuton() {
  Intake.move(600);
  Drive(3500, 3500, 75);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-3400,-3400, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(0);
  pros::delay(300);
  Rotate(730, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn();
  Drive(3300,3300, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-1200,-1200, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(-90, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);

  Rotate(120, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-1400, -1600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(800);
  Intake.move(100);
  pros::delay(300);
  Intake.move(0);
  ShooterOff();
  pros::delay(400);

  //Turn strait and backup to allign with the platform.
  Rotate(150, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-2600, -2600, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Rotate to face the platform.
  Rotate(-800, 50); //if the rotate command doesn't work past this after it. pros::delay(1200);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Drive Up to the center platform.
  Drive(5000, 5000, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Lock drive train just incase.
  BrakeDriveTrain();
}
