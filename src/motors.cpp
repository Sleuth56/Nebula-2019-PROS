#include "main.h"

// Defining motors
pros::Motor FLMotor (FLMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor BLMotor (BLMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor FRMotor (FRMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor BRMotor (BRMotorport, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Intake (Intakeport, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Arm (Armport, pros::E_MOTOR_GEARSET_36, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Shooter1 (Shooter1port, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_DEGREES);
pros::Motor Shooter2 (Shooter2port, pros::E_MOTOR_GEARSET_18, pros::E_MOTOR_ENCODER_DEGREES);

// Defining Controllers
pros::Controller master (CONTROLLER_MASTER);
pros::Controller partner (CONTROLLER_PARTNER);

// Defining Sensors
pros::ADIGyro gyro (GYRO_PORT);
pros::ADIDigitalIn TopIntakeSensor(TopIntakeSensorPort);
pros::ADIDigitalIn BottomIntakeSensor(BottomIntakeSensorPort);
pros::ADIUltrasonic back_ultrasonic (1, 2);
pros::ADIUltrasonic front_ultrasonic (3, 4);

// Defining the IsParking veriable
bool IsParking = true;