#include "main.h"

//Veriables for tweaking the drive train.
bool IsBreaking = false;
bool IsForward = true;


//Returns true or false as to whether the drive wheels have
//reached their position goal set by Drive.
//Used making the program wait for the drive to finish.
bool AtDistanceDriveGoal(int threshold) {
  return (abs(FLMotor.get_position() - FLMotor.get_target_position()) < threshold) &&(abs(FLMotor.get_position() - FLMotor.get_target_position()) < threshold);
}


int GyroPos() {
  return (int(gyro.get_value()) / 10);
}


//Sets drive trains target, but does not wait for them to reach their target.
void Drive(double leftInches, double rightInches, int speed) {
  FRMotor.move_relative(leftInches, speed);
  BRMotor.move_relative(rightInches, -speed);
  pros::delay(10);
  FLMotor.move_relative(rightInches, speed);
  BLMotor.move_relative(leftInches, -speed);
}


//Turns the robot to the target position.
// void RotateOld(double turn, int speed) {
//   FLMotor.move_relative(turn , speed);
//   FRMotor.move_relative(-turn, speed);
//   BLMotor.move_relative(turn, speed);
//   BRMotor.move_relative(-turn, speed);
// }


//Turns the robot to the target position
void Rotate(int turn, int speed) {
  if (turn > 0) {
  FLMotor.move(speed);
  FRMotor.move(-speed);
  BLMotor.move(speed);
  BRMotor.move(-speed);

  while (int(int(gyro.get_value()) / 25) != (turn / 2.5)) {
    pros::delay(20);
  }
  FLMotor.move(0);
  FRMotor.move(0);
  BLMotor.move(0);
  BRMotor.move(0);
  }
  else {
    FLMotor.move(-speed);
    FRMotor.move(speed);
    BLMotor.move(-speed);
    BRMotor.move(speed);

    while (int(int(gyro.get_value()) / 25) != (turn / 2.5)) {
      pros::delay(20);
    }
    FLMotor.move(0);
    FRMotor.move(0);
    BLMotor.move(0);
    BRMotor.move(0);
  }
}


//Function for setting the drive trian breaks.
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


//Function for releasing the drive train breaks.
void UnBrakeDriveTrain() {
  IsBreaking = false;
  FLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  FRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}


//Function for seting the cap flipper side to be the front side.
void SetBackwords() {
  FLMotor.set_reversed(true);
  FRMotor.set_reversed(false);
  BLMotor.set_reversed(true);
  BRMotor.set_reversed(false);
  IsForward = false;
}


//Function for seting the ball shooter side to be the front side.
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


  //Setting the revering state of the motors.
  FLMotor.set_reversed(false);
  FRMotor.set_reversed(true);
  BLMotor.set_reversed(false);
  BRMotor.set_reversed(true);

  while (true) {
    //Gets the joistics position and update it's veriable.
    LeftControls = master.get_analog(ANALOG_LEFT_Y);
    RightControls = master.get_analog(ANALOG_RIGHT_Y);

    //Controls how the motors move.
    if (IsBreaking != true) {
      if (IsForward == true) {
        if (int(pros::c::motor_get_temperature(FLMotorport)) == 2147483647 || int(pros::c::motor_get_temperature(FRMotorport)) == 2147483647) {
          BLMotor.move(LeftControls);
          BRMotor.move(RightControls);
        }
        else if (int(pros::c::motor_get_temperature(BLMotorport)) == 2147483647 || int(pros::c::motor_get_temperature(BRMotorport)) == 2147483647) {
          FLMotor.move(LeftControls);
          FRMotor.move(RightControls);
        }
        else {
          FLMotor.move(LeftControls);
          BLMotor.move(LeftControls);
          FRMotor.move(RightControls);
          BRMotor.move(RightControls);          
        }
        }
        else {
          if (int(pros::c::motor_get_temperature(FLMotorport)) == 2147483647 || int(pros::c::motor_get_temperature(FRMotorport)) == 2147483647) {
            BLMotor.move(RightControls);
            BRMotor.move(LeftControls);
          }
          else if (int(pros::c::motor_get_temperature(BLMotorport)) == 2147483647 || int(pros::c::motor_get_temperature(BRMotorport)) == 2147483647) {
            FLMotor.move(RightControls);
            FRMotor.move(LeftControls);
          }
          else {
          FLMotor.move(RightControls);
          BLMotor.move(RightControls);
          FRMotor.move(LeftControls);
          BRMotor.move(LeftControls);
          }
        }
    }

    //Drive train lock and unlock button.
    if (master.get_digital_new_press(DIGITAL_UP)) {
      if (IsBreaking == true) {
        UnBrakeDriveTrain();
      }
      else {
        BrakeDriveTrain();
      }
    }

    //Drive train break and Rotate 180 button.
    if (master.get_digital_new_press(DIGITAL_DOWN)) {
      if (IsBreaking == true) {
        UnBrakeDriveTrain();
        //Rotate(1580, 50);
      }
      else {
        BrakeDriveTrain();
        //Rotate(1580, 50);
      }
    }

    //Drive train directional controls.
    if (master.get_digital_new_press(DIGITAL_L1)) {
      SetBackwords();
    }
    if (master.get_digital_new_press(DIGITAL_R1)) {
      SetForwards();
    }

    //Rotate 90 to the left.
    if (master.get_digital_new_press(DIGITAL_LEFT)) {
        Rotate(-790, 50);
        pros::delay(1200);
    }
    //Rotate 90 to the right.
    else if (master.get_digital_new_press(DIGITAL_RIGHT)) {
      Rotate(790, 50);
      pros::delay(1200);
    }
  }
}
