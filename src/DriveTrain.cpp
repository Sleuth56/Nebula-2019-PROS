#include "main.h"

//Veriables for tweaking the drive train.
bool IsBreaking = false;
bool IsForward = true;


//Returns true/false as to wheter the drive wheels have
//reached their position goal set by driveForDistance
bool AtDistanceDriveGoal(int threshold) {
  return (abs(FLMotor.get_position() - FLMotor.get_target_position()) < threshold) &&(abs(FLMotor.get_position() - FLMotor.get_target_position()) < threshold);
}


//Sets drive trains target, but does not wait for them to reach their target
void Drive(double leftInches, double rightInches, int speed) {
  FRMotor.move_relative(leftInches, speed);
  BRMotor.move_relative(rightInches, -speed);
  pros::delay(10);
  FLMotor.move_relative(rightInches, speed);
  BLMotor.move_relative(leftInches, -speed);
}


//Turns the robot to the target position
void Rotate(double turn, int speed) {
  FLMotor.move_relative(turn , speed);
  FRMotor.move_relative(-turn, speed);
  BLMotor.move_relative(turn, speed);
  BRMotor.move_relative(-turn, speed);
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


//Thread for all drive train controls.
void DriveTrain_fn(void* param) {
  int LeftControls = master.get_analog(ANALOG_LEFT_Y);
  int RightControls = master.get_analog(ANALOG_RIGHT_Y);


  //Setting the right motors to be reversed
  FLMotor.set_reversed(false);
  FRMotor.set_reversed(true);
  BLMotor.set_reversed(false);
  BRMotor.set_reversed(true);

  while (true) {
    //Gets the joistics position and maps them to a veriable.
    LeftControls = master.get_analog(ANALOG_LEFT_Y);
    RightControls = master.get_analog(ANALOG_RIGHT_Y);

    //Switches the motor sides if the drive train is reversed.
    if (IsBreaking != true) {
      if (IsForward == true) {
          FLMotor.move(LeftControls);
          BLMotor.move(LeftControls);
          FRMotor.move(RightControls);
          BRMotor.move(RightControls);
        }
        else {
          FLMotor.move(RightControls);
          BLMotor.move(RightControls);
          FRMotor.move(LeftControls);
          BRMotor.move(LeftControls);
        }
    }

    if (master.get_digital_new_press(DIGITAL_UP)) {
      if (IsBreaking == true) {
        UnBrakeDriveTrain();
      }
      else {
        BrakeDriveTrain();
      }
    }

    //Drive train break controls.
    if (master.get_digital_new_press(DIGITAL_DOWN)) {
      if (IsBreaking == true) {
        UnBrakeDriveTrain();
        Rotate(1580, 50);
      }
      else {
        BrakeDriveTrain();
        Rotate(1580, 50);
      }
    }

    //Drive train directional controls.
    if (master.get_digital_new_press(DIGITAL_L1)) {
      SetBackwords();
    }
    if (master.get_digital_new_press(DIGITAL_R1)) {
      SetForwards();
    }

    if (IsForward == true) {
      //Rotate 90
      if (master.get_digital_new_press(DIGITAL_LEFT)) {
          Rotate(790, 50);
          pros::delay(1200);
      }
      else if (master.get_digital_new_press(DIGITAL_RIGHT)) {
        Rotate(-790, 50);
        pros::delay(1200);
      }
    }
    else {
      //Rotate 90
      if (master.get_digital_new_press(DIGITAL_LEFT)) {
          Rotate(-790, 50);
          pros::delay(1200);
      }
      else if (master.get_digital_new_press(DIGITAL_RIGHT)) {
        Rotate(790, 50);
        pros::delay(1200);
      }
    }
  }
}
