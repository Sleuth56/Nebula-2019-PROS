#include "main.h"

//Function for the red flag side of the field
void RedFlag() {
  Intake.move(600);
  Drive(3500, 3500, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-3600,-3600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(0);
  pros::delay(300);
  Drive(200, 200, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(750, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn();
  Drive(3400,3400, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-1100,-1900, 100);
  pros::delay(1600);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);

  Rotate(80, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-1200, -1300, 100);
  pros::delay(2400);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();
}

//Function for the red cap side of the field
void RedCap() {
  Intake.move(50);
  Drive(3500, 3500, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-600, -600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(900, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-800, -800, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Arm.move_relative(600, 227);
  pros::delay(600);
  Intake.move(0);
}

//Function for the blue flag side of the field
void BlueFlag() {
  Intake.move(600);
  Drive(3500, 3500, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-3600,-3600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(200, 200, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(0);
  pros::delay(300);
  Rotate(-800, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn();
  Drive(3600,3600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-2000,-1350, 100);
  pros::delay(1500);
  Intake.move(100);
  pros::delay(500);
  Intake.move(0);

  Drive(-1400, -1400, 100);
  pros::delay(2400);
  Intake.move(100);
  pros::delay(370);
  Intake.move(0);
  ShooterOff();
}

//Function for the blue cap side of the field
void BlueCap() {
  Intake.move(50);
  Drive(3500, 3500, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-600, -600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(-900, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-840, -840, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Arm.move_relative(600, 227);
  pros::delay(600);
  Intake.move(0);
}

//Veriables and funstions for auton selector
int selection = 0;
const char *titles[] = {"Red Flag", "Red Cap", "Blue Flag", "Blue Cap","Skills Auton"};
void (*scripts[])() = {&RedFlag, &RedCap, &BlueFlag, &BlueCap,  &SkillsAuton};
void LCDScriptExecute() { scripts[selection](); }
