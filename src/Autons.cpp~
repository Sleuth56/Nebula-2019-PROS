#include "main.h"

//Auton for the red flag side of the field.
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

  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn();

  Drive(200, 200, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(-710, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(600, 600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(100);
  pros::delay(600);
  Intake.move(0);

  Drive(1300, 1300, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();

  Rotate(-850, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-900, -900, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(200);
  Arm.move(70);
  pros::delay(500);
  Arm.move(-100);
  pros::delay(500);
  Arm.move(0);

  FLMotor.move(127);
  FRMotor.move(15);
  BLMotor.move(127);
  BRMotor.move(15);
  pros::delay(1500);
  FLMotor.move(-50);
  FRMotor.move(-50);
  BLMotor.move(-50);
  BRMotor.move(-50);
  pros::delay(1000);
  FLMotor.move(0);
  FRMotor.move(0);
  BLMotor.move(0);
  BRMotor.move(0);
}

//Auton for the red cap side of the field.
void RedCap() {
  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn(160);
  Drive(200, 200, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(-530, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(1000, 1000, 80);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  // pros::delay(500);
  int a = 0;
  while (Shooter1.get_actual_velocity() < 100) {
    if (a > 150) {
      break;
    }
    a = a + 1;
    pros::delay(20);
  }
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();
  Rotate(-260, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-2800, -2800, 80);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(500);
  Drive(200, 200, 40);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(-820, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-2600, -2600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(200);
  Arm.move(100);
  pros::delay(500);
  Arm.move(-100);
  pros::delay(500);
  Arm.move(0);

  Intake.move(100);
  FLMotor.move(100);
  FRMotor.move(10);
  BLMotor.move(100);
  BRMotor.move(10);
  pros::delay(1500);

  FLMotor.move(100);
  FRMotor.move(100);
  BLMotor.move(100);
  BRMotor.move(100);
  pros::delay(600);

  FLMotor.move(-60);
  FRMotor.move(-60);
  BLMotor.move(-60);
  BRMotor.move(-60);
  pros::delay(1000);
  Intake.move(0);
  Drive(0, 0, 0);
}

//Auton for the blue flag side of the field.
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

  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn();

  Drive(200, 200, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(740, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(600, 600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(100);
  pros::delay(400);
  Intake.move(0);

  Drive(1500, 1500, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();

  Rotate(740, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-900, -900, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(200);
  Arm.move(70);
  pros::delay(500);
  Arm.move(-100);
  pros::delay(500);
  Arm.move(0);

  FLMotor.move(15);
  FRMotor.move(127);
  BLMotor.move(15);
  BRMotor.move(127);
  pros::delay(1500);
  FLMotor.move(-50);
  FRMotor.move(-50);
  BLMotor.move(-50);
  BRMotor.move(-50);
  pros::delay(1000);
  FLMotor.move(0);
  FRMotor.move(0);
  BLMotor.move(0);
  BRMotor.move(0);
}

//Auton for the blue cap side of the field.
void BlueCap() {
  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn(160);
  Drive(200, 200, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(560, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(1000, 1000, 80);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  // pros::delay(500);
  int a = 0;
  while (Shooter1.get_actual_velocity() < 100) {
    if (a > 150) {
      break;
    }
    a = a + 1;
    pros::delay(20);
  }
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();
  Rotate(260, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-2700, -2700, 80);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(500);
  Drive(200, 200, 40);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(800, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-2600, -2600, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(200);
  Arm.move(100);
  pros::delay(500);
  Arm.move(-100);
  pros::delay(500);
  Arm.move(0);

  Intake.move(100);
  FLMotor.move(10);
  FRMotor.move(100);
  BLMotor.move(10);
  BRMotor.move(100);
  pros::delay(1600);

  Drive(1000, 1000, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-1000, -1000, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Intake.move(0);
  Drive(0, 0, 0);
}

//Veriables and functions for the auton selector.
int selection = 4;
const char *titles[] = {"Red Flag", "Red Cap", "Blue Flag", "Blue Cap","Skills Auton"};
void (*scripts[])() = {&RedFlag, &RedCap, &BlueFlag, &BlueCap,  &SkillsAuton};
void LCDScriptExecute() { scripts[selection](); }
