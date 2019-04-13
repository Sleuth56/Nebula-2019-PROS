#include "main.h"

//Auton for skills.
void SkillsAuton() {
  /*
    Shooter on
    Drive forward
    Turn to face the middle flag
    Shoot the top middle flag
    Shooter off
  */
  ShooterOn(150);
  Drive(400, 400, 60);
  Rotate(-60, 30);
  pros::delay(300);
  Intake.move(100);
  pros::delay(500);
  Intake.move(0);
  ShooterOff();


  /*
    Turn the arm twords the far cap
    Drive forwards
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
    Turn 90 twords the platform
    Drive up onto the alliance platform
  */
  Rotate(-80, 50);
  Drive(2200, 2200, 100);
  Intake.move(0);

  Rotate(-80, 50);
  Front_Ultrasonic_Drive(9, 50);
  Front_Ultrasonic_Drive(12, -50);
  Rotate(80, 50);
  Back_Ultrasonic_Drive(190 , 50);
  Rotate(82, 50);
  Back_Ultrasonic_Drive(19, -50);


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

  Front_Ultrasonic_Drive(73, -100);

  Rotate(-80, 50);

  Drive(-800, -800, 100);

  Arm.move_relative(900, 100);
  pros::delay(800);
  Arm.move_relative(-900, 100);

  Front_Ultrasonic_Drive(9, 50);
  Front_Ultrasonic_Drive(12, -50);
  Rotate(80, 50);
}