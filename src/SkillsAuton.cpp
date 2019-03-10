#include "main.h"

//Auton for skills.
void SkillsAuton() {
  //Intake on and drive out.
  Intake.move(100);
  Drive(3900, 3900, 110);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Backup.
  Drive(-500, -500, 20);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(500);
  Drive(-3360, -3360, 60);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(1000);

  //Drive Forwards to not turn into the wall.
  Drive(520, 520, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Intake off and Turn 90.
  Intake.move(0);
  Rotate(-740, 40);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Intake down, shooter on, and drive out to shoot the top flag.
  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn(170);
  Drive(3800, 3800, 80);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Shoot the top flag.
  pros::delay(1500);
  Intake.move(100);
  pros::delay(450);
  Intake.move(0);
  pros::delay(300);

  //Drive Forwards, shoot middle flag, and turn off the shooter.
  Drive(1700, 1700, 60);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(600);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();
  Intake.move(100);

  //Drive back, turn left, and flip the cap.
  Drive(-500, -500, 70);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(-770, 40);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-500, -500, 70);
  pros::delay(500);
  Arm.move(100);
  pros::delay(500);
  Arm.move(-100);
  pros::delay(500);
  Arm.move(0);

  //Drive forward, align on the wall, drive back, and turn right to face the flags.
  Drive(1500, 1500, 50);
  pros::delay(2000);
  Drive(-600, -600, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(750, 40);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Drive forwards and hit the bottom flag.
  Drive(2000, 2000, 60);
  pros::delay(2700);

  //Backup, turn, intake on, and drive forward to suck up the ball under the cap.
  Drive(-3600, -3600, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(800, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-1800, -1800, 80);
  pros::delay(1000);
  Intake.move(100);
  Drive(3700, 3700, 90);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  //Intake down and shooter on.
  Drive(-1000, -1000, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(600);
  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn(125);

  //Turn left to face the flag, wait for shooter to spin up and shoot the top flag.
  Rotate(-560, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  pros::delay(2500);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();

  //Turn right to face the red platform, drive up on alliance platform, turn left, and drive onto center platform.
  Rotate(-2000, 30);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(2000, 2000, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  BrakeDriveTrain();
  pros::delay(500);
  UnBrakeDriveTrain();
  Rotate(-740, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(2000, 2000, 100);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  BrakeDriveTrain();
}




//Old 11 point skills auton.
//Not in use.
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
  ShooterOn(170);
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
