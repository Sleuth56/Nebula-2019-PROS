#include "main.h"

//Defining the motors.
pros::Motor FLMotor (FLMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor BLMotor (BLMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor FRMotor (FRMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor BRMotor (BRMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Intake (Intakeport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Arm (Armport, pros::E_MOTOR_GEARSET_36, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Shooter1 (Shooter1port, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Shooter2 (Shooter2port, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Controller master (CONTROLLER_MASTER);
pros::Controller partner (CONTROLLER_PARTNER);
pros::ADIGyro gyro (GYRO_PORT);
