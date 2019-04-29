#include "main.h"

void SkillsAuton() {
  pros::delay(500);
  Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  /*
    Intake on
    Drive Forward
    Get the ball from under the cap
    Drive Back to the starting wall
  */
  Intake.move(100);
  Drive(3400, 3400, 50);
  // pros::delay(200);
  Intake.move(0);
  pros::delay(100);
  // Drive(-3400, -3400, 120);
  FLMotor.move(-60);
  BLMotor.move(-60);
  pros::delay(10);
  FRMotor.move(-60);
  BRMotor.move(-60);
  pros::delay(4000);
  FLMotor.move(0);
  BLMotor.move(0);
  FRMotor.move(0);
  BRMotor.move(0);

  /*
    Ball down
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
  Rotate(-79, 50);


  /*
    Drive forward
    Shoot the top flag
    Drive forward
    Shoot the middle flag
    Shooter off
  */
  Drive(1250, 1250, 100);
  // Front_Ultrasonic_Drive(86, 50);

  pros::delay(600);
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
    A little correction turn
    Drive forward hit the bottom flag
    Drive Back
    Turn
    Back into wall
  */
  Rotate(-12, 30);
  Drive(1800, 1600, 100);

  Drive(-2000, -2000, 100);

  Rotate(-84, 50);

  FLMotor.move(60);
  BLMotor.move(60);
  pros::delay(10);
  FRMotor.move(60);
  BRMotor.move(60);
  pros::delay(1500);
  FLMotor.move(0);
  BLMotor.move(0);
  FRMotor.move(0);
  BRMotor.move(0);

  /*
    Drive back into cap
    Flip cap
  */
  Drive(-1500, -1500, 100);

  Arm.move_relative(800, 80);
  pros::delay(800);
  Arm.move_relative(-800, 80);


  /*
    Drive into wall slowly 
    Pull back off of the wall
    Turn
    Drive forwards
    Turn
    Back into the wall
  */
  FLMotor.move(60);
  BLMotor.move(60);
  pros::delay(10);
  FRMotor.move(60);
  BRMotor.move(60);
  pros::delay(1500);
  FLMotor.move(0);
  BLMotor.move(0);
  FRMotor.move(0);
  BRMotor.move(0);
  Drive(-500, -500, 30);
  Rotate(85, 50);

  Drive(-3250, -3250, 80);
  Rotate(85, 50);
  
  FLMotor.move(-60);
  BLMotor.move(-60);
  pros::delay(10);
  FRMotor.move(-60);
  BRMotor.move(-60);
  pros::delay(2000);
  FLMotor.move(0);
  BLMotor.move(0);
  FRMotor.move(0);
  BRMotor.move(0);


  /*
    Intake on just in case of a ball
    Drive forwards onto the center platform
    Intake off
  */
  Intake.move(100);
  Drive(3900, 3900, 150);
  pros::delay(500);
  Drive(2400, 2400, 150);
  Intake.move(0);
}


/*
  Auton for skills verry iffy
  only used if the other one works
*/
void IffySkillsAuton() {
  /*
    Shooter on
    Drive forward
    Turn to face the middle flag
    Shoot the top middle flag
    Shooter off
  */
  ShooterOn(130);
  Drive(400, 400, 60);
  Rotate(-60, 30);
  pros::delay(300);
  Intake.move(100);
  pros::delay(500);
  Intake.move(0);
  ShooterOff();


  /*
    Turn the arm twards the far cap
    Drive back
    Flip the cap
  */
  Rotate(-86, 50);
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
  Drive(-900, -900, 100);


  /*
    Turn 90 twards the platform
    Drive up onto the alliance platform
  */
  Rotate(-80, 50);
  Drive(2200, 2200, 100);
  Intake.move(0);

  Rotate(-80, 50);
  Front_Ultrasonic_Drive(9, 50);
  Front_Ultrasonic_Drive(12, -50);
  Rotate(80, 50);
  Back_Ultrasonic_Drive(185 , 50);
  Rotate(84, 50);
  Back_Ultrasonic_Drive(19, -50);

  FLMotor.move(-60);
  BLMotor.move(-60);
  pros::delay(10);
  FRMotor.move(-60);
  BRMotor.move(-60);
  pros::delay(2000);
  FLMotor.move(0);
  BLMotor.move(0);
  FRMotor.move(0);
  BRMotor.move(0);


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
  Rotate(-76, 50);


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

  Rotate(-10, 30);
  Drive(1200, 1200, 100);

  Front_Ultrasonic_Drive(65, -100);

  Rotate(-80, 50);

  Drive(-800, -800, 100);

  Arm.move_relative(900, 100);
  pros::delay(800);
  Arm.move_relative(-900, 100);

  Front_Ultrasonic_Drive(9, 50);
  Front_Ultrasonic_Drive(12, -50);
  Rotate(80, 50);
  
  Drive(-3200, -3200, 80);
  // Back_Ultrasonic_Drive(146, -80);
  Rotate(85, 50);
  
  FLMotor.move(-60);
  BLMotor.move(-60);
  pros::delay(10);
  FRMotor.move(-60);
  BRMotor.move(-60);
  pros::delay(2000);
  FLMotor.move(0);
  BLMotor.move(0);
  FRMotor.move(0);
  BRMotor.move(0);

  Drive(5500, 5500, 150);
}