#include "main.h"

// Controls wether our autons park or not
bool IsParking = true;

/**
  Code for all in game autons.
  Skills auton is in SkillsAuton.cpp.
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
  Drive(3400, 3400, 120);
  pros::delay(200);
  Intake.move(0);
  pros::delay(100);
  Drive(-3500, -3500, 120);

  /*
    Intake down
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
  Rotate(-80, 50);


  /*
    Drive forward
    Shoot the top flag
    Drive forward
    Shoot the middle flag
    Shooter off
  */
  Drive(1500, 1500, 100);

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
    Turn to miss the bottom flag
    Drive Forwards
    Drive Back
    Turn to allign with the cap
    Drive back
    Flip the cap
  */
  Rotate(-8, 30);
  Drive(1400, 1200, 100);

  Drive(-2000, -2000, 100);

  Rotate(-84, 50);

  Drive(-1000, -1000, 100);

  Arm.move_relative(900, 100);
  pros::delay(800);
  Arm.move_relative(-900, 100);
}

void RedCap() {
  /*
    Shooter on
    Drive forward
    Turn to face the middle flags
    Shoot the one of the middle flags
    Shooter off
  */
  ShooterOn(130);
  Drive(400, 400, 60);
  Rotate(-58, 30);
  pros::delay(300);
  Intake.move(100);
  pros::delay(500);
  Intake.move(0);
  ShooterOff();


  /*
    Turn the arm towards the far cap
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
    Turn 90 towards the platform
    Drive up onto the alliance platform
  */
  if (IsParking == true) {
    Rotate(-80, 50);
    Drive(2200, 2200, 100);
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
  Intake.move(200);
  Drive(3400, 3400, 120);
  pros::delay(200);
  Intake.move(0);
  pros::delay(100);
  Drive(-3500, -3500, 120);

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

  Drive(1300, 1300, 100);

  pros::delay(300);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();

  /*
    Turn to miss the bottom flag
    Drive Forwards
    Drive Back
    Turn to allign with the cap
    Drive back
    Flip the cap
  */
  Rotate(8, 30);
  Drive(1400, 1300, 100);

  Drive(-2000, -2000, 100);

  Rotate(82, 50);

  Drive(-1000, -1000, 100);

  Arm.move_relative(900, 100);
  pros::delay(800);
  Arm.move_relative(-900, 100);
}

void BlueCap() {
  /*
    Shooter on
    Drive forward
    Turn to face the middle flag
    Shoot the top middle flag
    Shooter off
  */
  ShooterOn(120);
  Drive(400, 400, 60);
  Rotate(63, 30);
  Intake.move(100);
  pros::delay(500);
  Intake.move(0);
  ShooterOff();


  /*
    Turn the arm towards the far cap
    Drive forwards
    Flip the cap
  */
  Rotate(77, 50);
  Drive(-3000, -3000, 130);
  Arm.move_relative(1100, 100);
  pros::delay(800);
  Arm.move_relative(-1100, 100);
  pros::delay(500);


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
  Drive(-1100, -1100, 100);
  Intake.move(0);


  /*
    If IsParking is true
    Turn 90 towards the platform
    Drive up onto the alliance platform
  */
  if (IsParking == true) {
    Rotate(80, 50);
    Drive(2200, 2200, 100);
  }
}

//Veriables and functions for the auton selector
int selection = 1;
const char *titles[] = {"                     Red Flag", "                     Red Cap", "                   Skills Auton", "                     Blue Cap","                     Blue Flag"};
void (*scripts[])() = {&RedFlag, &RedCap, &SkillsAuton, &BlueCap,  &BlueFlag};
void LCDScriptExecute() { scripts[selection](); }
