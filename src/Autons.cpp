#include "main.h"

/**
  Code for all the game autons.
  Skills has it's own file.
 */

void RedFlag() {
  /*
    Intake on
    Drive Forward
    get the ball from the cap
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
}

void RedCap() {
  /*
    Intake on
    Drive Forward
    get the ball from the cap
  */
  Intake.move(600);
  Drive(3500, 3500, 100);

  while(BottomIntakeSensor.get_value() == 0 && TopIntakeSensor.get_value() == 0) {
    pros::delay(20);
  }
  Intake.move(0);


  /*
    Turn 45
    Drive back
    Turn to face the cap with the arm
  */
  Rotate(-50, 50);
  Drive(-1000, -1000, 100);
  Rotate(-75, 50);


  /*
    Arm up
    Flip the cap
    Arm down
  */
  Arm.move_relative(1140, 100);
  pros::delay(800);
  Arm.move_relative(-1140, 100);


  /*
    Turn to face the alliance platform
    Drive forward
    align with the aliance platform
    Pull back the back right motor to align with the far flags
  */
  Rotate(35, 50);
  
  BLMotor.move_relative(1500, 50);
  pros::delay(20);
  BRMotor.move_relative(1500, 50);
  pros::delay(2500);

  BRMotor.move_relative(-570, 40);
  pros::delay(2000);


  /*
    Shooter on
    Wait for the flywheel to spin up
    Shoot the top flag
    Wait for the flywheel to spin up
    Shoot the middle flag
    Shooter off
  */
  ShooterOn(140);
  pros::delay(1300);
  Intake.move(100);
  pros::delay(400);
  Intake.move(0);
  pros::delay(1000);
  Intake.move(100);
  pros::delay(400);
  Intake.move(0);
  ShooterOff();

  /*
    If IsParking is true
    Turn to face the alliance platform
    Drive up on to the alliance platform
  */
  if (IsParking == true) {
    Rotate(-20, 40);
    Drive(2000, 2000, 100);
  }
}

void BlueFlag() {
  /*
    Intake on
    Drive Forward
    get the ball from the cap
    Drive Back to the starting wall
  */
  Intake.move(600);
  Drive(3500, 3500, 120);

  FRMotor.move_relative(-3600, 120);
  BRMotor.move_relative(-3600, -120);
  pros::delay(10);
  FLMotor.move_relative(-3600, 120);
  BLMotor.move_relative(-3600, -120);

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
  ShooterOn(200);
  pros::delay(600);

  Drive(200, 200, 30);
  Rotate(78, 50);


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
  Rotate(-60, 100);

  Arm.move_relative(1100, 100);
  pros::delay(800);
  Rotate(-55, 50);

  Arm.move_relative(-1100, 100);
  pros::delay(500);


  /*
    Turn face the cap with two balls on it
    Drive forward
    Arm up to flip the cap
    Arm up to flag level
  */
  Rotate(-93, 100);

  Drive(-900, -900, 100);
  Arm.move_relative(800, 80);
  pros::delay(500);
  Arm.move_relative(400, 50);
  pros::delay(150);


  /*
    Turn to face the center bottom flag
    Drive forwards
    Hit the bottom flag
    Arm down
  */
  Rotate(50, 50);
  Drive(-2200, -2200, 150);
  Arm.move_relative(-1000, 200);
}

void BlueCap() {
  /*
    Intake on
    Drive Forward
    get the ball from the cap
    Drive Back to the starting wall
  */
  Intake.move(600);
  Drive(3500, 3500, 100);

  while(BottomIntakeSensor.get_value() == 0 && TopIntakeSensor.get_value() == 0) {
    pros::delay(20);
  }
  Intake.move(0);


  /*
    Turn 45
    Drive back
    Turn to face the cap with the arm
  */
  Rotate(50, 50);
  Drive(-1000, -1000, 100);
  Rotate(75, 50);


  /*
    Arm up
    Flip the cap
    Arm down
  */
  Arm.move_relative(1140, 100);
  pros::delay(800);
  Arm.move_relative(-1140, 100);


  /*
    Turn to face the alliance platform
    Drive forward
    align with the aliance platform
    Pull back the back left motor to align with the far flags
  */
  Rotate(-35, 50);
  
  BLMotor.move_relative(1500, 50);
  pros::delay(20);
  BRMotor.move_relative(1500, 50);
  pros::delay(2500);

  BLMotor.move_relative(-570, 40);
  pros::delay(2000);


  /*
    Shooter on
    Wait for the flywheel to spin up
    Shoot the top flag
    Wait for the flywheel to spin up
    Shoot the middle flag
    Shooter off
  */
  ShooterOn(140);
  pros::delay(1300);
  Intake.move(100);
  pros::delay(400);
  Intake.move(0);
  pros::delay(1000);
  Intake.move(100);
  pros::delay(400);
  Intake.move(0);
  ShooterOff();


  /*
    If IsParking is true
    Turn to face the alliance platform
    Drive up on to the alliance platform
  */
  if (IsParking == true) {
    Rotate(20, 40);
    Drive(2000, 2000, 100);
  }
}

//Veriables and functions for the auton selector.
int selection = 0;
const char *titles[] = {"                     Red Flag", "                     Red Cap", "                     Blue Flag", "                     Blue Cap","                   Skills Auton"};
void (*scripts[])() = {&RedFlag, &RedCap, &BlueFlag, &BlueCap,  &SkillsAuton};
void LCDScriptExecute() { scripts[selection](); }
