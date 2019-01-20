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
pros::Motor CFLMotor (FLMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor CBLMotor (BLMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor CFRMotor (FRMotorport, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor CBRMotor (BRMotorport, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor CIntake (Intakeport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor CArm (Armport, pros::E_MOTOR_GEARSET_36, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor CShooter1 (Shooter1port, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor CShooter2 (Shooter2port, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Controller Cmaster (CONTROLLER_MASTER);
pros::Controller Cpartner (CONTROLLER_PARTNER);

//------This veriable helps control the direction of the drive train.------
bool CisForward = true;

//------These map the joisticks to be used later for turning motors.------
int CLeftControls = Cmaster.get_analog(ANALOG_LEFT_Y);
int CRightControls = Cmaster.get_analog(ANALOG_RIGHT_Y);
int CArmControls = Cpartner.get_analog(ANALOG_LEFT_Y);
int CIntakeControls = Cpartner.get_analog(ANALOG_RIGHT_Y);

//------Function for setting the drive trian breaks.------
void CbrakeDriveTrain() {
  CFLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  CFRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  CBLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
  CBRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);
}


//------Function for releasing the drive train breaks.------
void CunBrakeDriveTrain() {
  CFLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  CFRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  CBLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  CBRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}


//------Function for seting the cap flipper side to be the front side.------
void CsetBackwords() {
  CFLMotor.set_reversed(true);
  CFRMotor.set_reversed(false);
  CBLMotor.set_reversed(true);
  CBRMotor.set_reversed(false);
  CisForward = false;
}


//------Function for seting the ball shooter side to be the front side.------
void CsetForwards() {
  CFLMotor.set_reversed(false);
  CFRMotor.set_reversed(true);
  CBLMotor.set_reversed(false);
  CBRMotor.set_reversed(true);
  CisForward = true;
}


//------Function for turning on the shoote.------
void CshooterOn(int velocity = 0) {
  CShooter1.move_velocity(velocity);
  CShooter2.move_velocity(velocity);
}


//------Function for turning off the shooter.------
void CshooterOff() {
  CshooterOn(0);
}
