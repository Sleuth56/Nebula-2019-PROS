#include "main.h"

//Veriables and funstions for auton selector
bool IsForward = true;
bool IsBreaking = false;

//These map the joisticks to be used later for turning motors
int LeftControls = master.get_analog(ANALOG_LEFT_Y);
int RightControls = master.get_analog(ANALOG_RIGHT_Y);
int ArmControls = partner.get_analog(ANALOG_LEFT_Y);
int IntakeControls = partner.get_analog(ANALOG_RIGHT_Y);

//Returns true/false as to wheter the drive wheels have
//reached their position goal set by driveForDistance
bool AtDistanceDriveGoal(int threshold) {
  return (abs(FLMotor.get_position() - FLMotor.get_target_position()) < threshold) &&(abs(FLMotor.get_position() - FLMotor.get_target_position()) < threshold);
}

//Sets drive trains target, but does not wait for them to reach their target
void Drive(double leftInches, double rightInches) {
  FRMotor.move_relative(leftInches, 100);
  BRMotor.move_relative(rightInches, -100);
  pros::delay(25);
  FLMotor.move_relative(rightInches, 100);
  BLMotor.move_relative(leftInches, -100);
}

//Turns the robot to the target position
void Rotate(double turn) {
  FLMotor.move_relative(-turn , 50);
  FRMotor.move_relative(turn, 50);
  BLMotor.move_relative(-turn, 50);
  BRMotor.move_relative(turn, 50);
}

//Function for setting the drive trian breaks
void BrakeDriveTrain() {
  IsBreaking = true;
  FLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  FRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  BLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  BRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  FLMotor.move_relative(0,200);
  FRMotor.move_relative(0,200);
  BLMotor.move_relative(0,200);
  BRMotor.move_relative(0,200);
}

//Function for releasing the drive train breaks
void UnBrakeDriveTrain() {
  IsBreaking = false;
  FLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  FRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}

//Function for seting the cap flipper side to be the front side
void SetBackwords() {
  FLMotor.set_reversed(true);
  FRMotor.set_reversed(false);
  BLMotor.set_reversed(true);
  BRMotor.set_reversed(false);
  IsForward = false;
}

//Function for seting the ball shooter side to be the front side
void SetForwards() {
  FLMotor.set_reversed(false);
  FRMotor.set_reversed(true);
  BLMotor.set_reversed(false);
  BRMotor.set_reversed(true);
  IsForward = true;
}

//Function for turning on the shooter
void ShooterOn(int velocity) {
  Shooter1.move_velocity(velocity);
  Shooter2.move_velocity(velocity);
}

//Function for turning off the shooter
void ShooterOff() {
  ShooterOn(0);
}

//Function for the red flag side of the field
void RedFLag() {
  Intake.move(100);
  Drive(3500, 3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-3500,-3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(770);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn();
  Drive(3500,3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-1300,-2000);
  pros::delay(1500);

  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  Drive(-1300, -1300);
  pros::delay(1500);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();
}

//Function for the red cap side of the field
void RedCap() {
  Intake.move(100);
  Drive(3500, 3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-600, -600);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(700);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-800, -800);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Arm.move_relative(350, 200);
}

//Function for the blue flag side of the field
void BlueFlag() {
  Intake.move(100);
  Drive(3500, 3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-3500,-3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(-770);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn();
  Drive(3500,3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-1300,-2000);
  pros::delay(1500);

  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  Drive(-1300, -1300);
  pros::delay(1500);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();
}

//Function for the blue cap side of the field
void BlueCap() {
  Intake.move(100);
  Drive(3500, 3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-600, -600);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Rotate(-900);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Drive(-800, -800);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  Arm.move_relative(500, 200);
  pros::delay(600);
  Intake.move(0);
}

//Function for skills auton
void SkillsAuton() {
  Intake.move(100);
  Drive(3500, 3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-3500,-3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Rotate(770);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Intake.move(-100);
  pros::delay(300);
  Intake.move(0);
  ShooterOn();
  Drive(3500,3500);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));

  Drive(-1300,-2000);
  pros::delay(1500);

  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  Drive(-1300, -1300);
  pros::delay(1500);
  Intake.move(100);
  pros::delay(600);
  Intake.move(0);
  ShooterOff();
}

//Veriables and funstions for auton selector
int selection = 0;
const char *titles[] = {"Red Flag", "Red Cap", "Blue Flag", "Blue Cap","Skills Auton"};
void (*scripts[])() = {&RedFLag, &RedCap, &BlueFlag, &BlueCap,  &SkillsAuton};
void LCDScriptExecute() { scripts[selection](); }
