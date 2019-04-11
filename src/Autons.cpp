#include "main.h"

/**
  Code for all the game autons.
  Skills has it's own file.
 */

void RedFlag() {
  Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  /*
    Intake on
    Drive Forward
    Get the ball from under the cap
    Drive Back to the starting wall
  */
  Intake.move(200);
  Drive(3500, 3500, 120);
  Intake.move(0);
  pros::delay(500);
  FRMotor.move_relative(-3600, 120);
  BRMotor.move_relative(-3600, -120);
  pros::delay(10);
  FLMotor.move_relative(-3600, 120);
  BLMotor.move_relative(-3600, -120);

  // while(BottomIntakeSensor.get_value() == 0 && TopIntakeSensor.get_value() == 0) {
  //   pros::delay(20);
  // }
  // Intake.move(0);

  do {
  pros::delay(20);
  } while (!AtDistanceDriveGoal(5));


  /*
    Shooter on full power
    Drive forward off the wall
    Turn to face the flags
  */
  ShooterOn(200);
  pros::delay(600);

  Drive(200, 200, 30);
  Rotate(-77, 50);


  /*
    Drive forward
    Shoot the top flag
    Drive forward
    Shoot the middle flag
    Shooter off
  */
  Drive(1650, 1650, 100);

  pros::delay(300);
  Intake.move(100);
  pros::delay(300);
  Intake.move(0);

  Drive(1050, 1050, 100);

  pros::delay(300);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();


  /*
    Turn
    Raise the arm to flag level
    Turn and hit the bottom flag
    Arm down
  */
  Rotate(80, 100);

  Arm.move_relative(1100, 100);
  pros::delay(800);
  Rotate(40, 50);

  Arm.move_relative(-1100, 100);
  pros::delay(500);


  /*
    Turn face the cap with two balls on it
    Drive forward
    Arm up to flip the cap
    Arm up to flag level
  */
  Rotate(96, 100);

  Drive(-900, -900, 100);
  Arm.move_relative(800, 80);
  pros::delay(500);
  Arm.move_relative(350, 50);
  pros::delay(150);


  /*
    Turn to face the center bottom flag
    Drive forwards
    Hit the bottom flag
    Arm down
  */
  Rotate(-50, 50);
  Drive(-2200, -2200, 150);
  Arm.move_relative(-1000, 200);
  Arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

void RedCap() {
  /*
    Shooter on
    Drive forward
    Turn to face the middle flag
    Shoot the top middle flag
    Shooter off
  */
  ShooterOn(150);
  Drive(400, 400, 60);
  Rotate(-58, 30);
  Intake.move(100);
  pros::delay(500);
  Intake.move(0);
  ShooterOff();


  /*
    Turn the arm twords the far cap
    Drive forwards
    Flip the cap
  */
  Rotate(-90, 50);
  Drive(-3000, -3000, 130);
  Arm.move_relative(1100, 100);
  pros::delay(800);
  Arm.move_relative(-1100, 100);


  /*
    Turn a little
    Drive forwards
    Turn to face the cap with the ball under it
  */
  Rotate(20, 50);
  Drive(1500, 1500, 100);
  Rotate(125, 50);


  /*
    Intake on
    Drive forwards
    Get the ball from under the cap
    Drive back to prepare to park on the platform
  */
  Intake.move(100);
  Drive(1400, 1400, 100);
  Intake.move(100);
  Drive(-1000, -1000, 100);
  Intake.move(0);


  /*
    If IsParking is true
    Turn 90 twords the platform
    Drive up onto the alliance platform
  */
  if (IsParking == true) {
    Rotate(-80, 50);
    Drive(2100, 2100, 100);
  }
}

void BlueFlag() {
  Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  /*
    Intake on
    Drive Forward
    Get the ball from under the cap
    Drive Back to the starting wall
  */
  Intake.move(600);
  Drive(3500, 3500, 120);

  FRMotor.move_relative(-3700, 120);
  BRMotor.move_relative(-3700, -120);
  pros::delay(10);
  FLMotor.move_relative(-3700, 120);
  BLMotor.move_relative(-3700, -120);

  while(BottomIntakeSensor.get_value() == 0 && TopIntakeSensor.get_value() == 0) {
    pros::delay(20);
  }
  Intake.move(0);

  do {
  pros::delay(20);
  } while (!AtDistanceDriveGoal(5));


  /*
    Shooter on full power
    Drive forward off the wall
    Turn to face the flags
  */
  Intake.move(-200);
  pros::delay(100);
  Intake.move(0);
  ShooterOn(200);
  pros::delay(400);

  Drive(200, 200, 30);
  Rotate(80, 50);


  /*
    Drive forward
    Shoot the top flag
    Drive forward
    Shoot the middle flag
    Shooter off
  */
  Drive(1300, 1300, 100);

  pros::delay(300);
  Intake.move(100);
  pros::delay(300);
  Intake.move(0);

  Drive(1100, 1100, 100);

  pros::delay(300);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();


  /*
    Turn
    Raise the arm to flag level
    Turn and hit the bottom flag
    Arm down
  */
  Rotate(-75, 100);

  Arm.move_relative(1100, 100);
  pros::delay(800);
  Rotate(-70, 50);

  Arm.move_relative(-1100, 100);
  pros::delay(500);


  /*
    Turn face the cap with two balls on it
    Drive forward
    Arm up to flip the cap
    Arm up to flag level
  */
  Rotate(-86, 100);

  Drive(-800, -800, 100);
  Arm.move_relative(1200, 80);
  pros::delay(800);
  // Arm.move_relative(400, 50);
  // pros::delay(150);


  /*
    Turn to face the center bottom flag
    Drive forwards
    Hit the bottom flag
    Arm down
  */
  Rotate(45, 50);
  Drive(-2200, -2200, 200);
  Arm.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  Arm.move_relative(-1000, 200);
}

void BlueCap() {
  /*
    Shooter on
    Drive forward
    Turn to face the middle flag
    Shoot the top middle flag
    Shooter off
  */
  ShooterOn(150);
  Drive(400, 400, 60);
  Rotate(63, 30);
  Intake.move(100);
  pros::delay(500);
  Intake.move(0);
  ShooterOff();


  /*
    Turn the arm twords the far cap
    Drive forwards
    Flip the cap
  */
  Rotate(77, 50);
  Drive(-3000, -3000, 130);
  Arm.move_relative(1100, 100);
  pros::delay(800);
  Arm.move_relative(-1100, 100);


  /*
    Turn a little
    Drive forwards
    Turn to face the cap with the ball under it
  */
  Rotate(-20, 50);
  Drive(1500, 1500, 100);
  Rotate(-115, 50);


  /*
    Intake on
    Drive forwards
    Get the ball from under the cap
    Drive back to prepare to park on the platform
  */
  Intake.move(100);
  Drive(1400, 1400, 100);
  Drive(-1000, -1000, 100);
  Intake.move(0);


  /*
    If IsParking is true
    Turn 90 twords the platform
    Drive up onto the alliance platform
  */
  if (IsParking == true) {
    Rotate(80, 50);
    Drive(2100, 2100, 100);
  }
}

//Veriables and functions for the auton selector
int selection = 4;
const char *titles[] = {"                     Red Flag", "                     Red Cap", "                     Blue Flag", "                     Blue Cap","                   Skills Auton"};
void (*scripts[])() = {&RedFlag, &RedCap, &BlueFlag, &BlueCap,  &SkillsAuton};
void LCDScriptExecute() { scripts[selection](); }
