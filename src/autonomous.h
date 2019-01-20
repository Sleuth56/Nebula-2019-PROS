#include "main.h"


//------Defining the motor ports.------
#define FLMotorport 11
#define FRMotorport 20
#define BLMotorport 12
#define BRMotorport 19
#define Armport 13
#define Intakeport 8
#define Shooter1port 9
#define Shooter2port 10

//------Defining the motors.------
pros::Motor FLMotor (FLMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor BLMotor (BLMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor FRMotor (FRMotorport, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor BRMotor (BRMotorport, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Intake (Intakeport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Arm (Armport, pros::E_MOTOR_GEARSET_36, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Shooter1 (Shooter1port, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Shooter2 (Shooter2port, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Controller master (CONTROLLER_MASTER);
pros::Controller partner (CONTROLLER_PARTNER);

//------This veriable helps control the direction of the drive train.------
bool isForward = true;

//------These map the joisticks to be used later for turning motors.------
int LeftControls = master.get_analog(ANALOG_LEFT_Y);
int RightControls = master.get_analog(ANALOG_RIGHT_Y);
int ArmControls = partner.get_analog(ANALOG_LEFT_Y);
int IntakeControls = partner.get_analog(ANALOG_RIGHT_Y);


//------sets drive trains target, but does not wait for them to reach their target.------
void driveForDistance(double leftInches, double rightInches) {
  FLMotor.move_relative(leftInches, 140);
  BLMotor.move_relative(leftInches, 140);

  FRMotor.move_relative(rightInches, 140);
  BRMotor.move_relative(rightInches, 140);
}


//------Function for setting the drive trian breaks.------
void brakeDriveTrain() {
  FLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  FRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  BLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  BRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}


//------Function for releasing the drive train breaks.------
void unBrakeDriveTrain() {
  FLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  FRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}


//------Function for seting the cap flipper side to be the front side.------
void setBackwords() {
  FLMotor.set_reversed(true);
  FRMotor.set_reversed(false);
  BLMotor.set_reversed(true);
  BRMotor.set_reversed(false);
  isForward = false;
}


//------Function for seting the ball shooter side to be the front side.------
void setForwards() {
  FLMotor.set_reversed(false);
  FRMotor.set_reversed(true);
  BLMotor.set_reversed(false);
  BRMotor.set_reversed(true);
  isForward = true;
}


//------Function for turning on the shooter.------
void shooterOn(int velocity = 0) {
  Shooter1.move_velocity(velocity);
  Shooter2.move_velocity(velocity);
}


//------Function for turning off the shooter.------
void shooterOff() {
  shooterOn(0);
}
