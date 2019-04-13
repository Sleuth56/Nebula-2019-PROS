#include "main.h"

// Status veriables for the drive train
bool IsBreaking = false;
bool IsForward = true;


/*
    Blocks the program from continuing until the drive train has
    reached its target position set by the Drive function
*/
bool AtDistanceDriveGoal(int threshold) {
  return (abs(FLMotor.get_position() - FLMotor.get_target_position()) < threshold) &&(abs(FLMotor.get_position() - FLMotor.get_target_position()) < threshold);
}

// Returns the gyro's current position in degrees
int GyroPos() {
  return (int(gyro.get_value()) / 10);
}


// Moves the drive train forwards and backwards
void Drive(double leftInches, double rightInches, int speed) {
  FRMotor.move_relative(leftInches, speed);
  BRMotor.move_relative(rightInches, -speed);
  pros::delay(10);
  FLMotor.move_relative(rightInches, speed);
  BLMotor.move_relative(leftInches, -speed);
  do {
  pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
}


void Front_Ultrasonic_Drive(int distance, int speed) {
  double ddistance = distance / 2;
  FRMotor.move(speed);
  BRMotor.move(speed);
  pros::delay(10);
  FLMotor.move(speed);
  BLMotor.move(speed);
  if (speed < 0) {
    while ((front_ultrasonic.get_value()/20) <= ddistance) {
      pros::delay(20);
    }    
  }
  else {
    while ((front_ultrasonic.get_value()/20) >= ddistance) {
      pros::delay(20);
    }
  }
  FLMotor.move(0);
  FRMotor.move(0);
  BLMotor.move(0);
  BRMotor.move(0);
}


void Back_Ultrasonic_Drive(int distance, int speed) {
  double ddistance = distance / 2;
  FRMotor.move(speed);
  BRMotor.move(speed);
  pros::delay(10);
  FLMotor.move(speed);
  BLMotor.move(speed);
  if (speed < 0) {
    while ((back_ultrasonic.get_value()/20) >= ddistance) {
      pros::delay(20);
    }
  }
  else {
    while ((back_ultrasonic.get_value()/20) <= ddistance) {
      pros::delay(20);
    }
  }
  FLMotor.move(0);
  FRMotor.move(0);
  BLMotor.move(0);
  BRMotor.move(0);
}


/*
  Turns the robot to the target position
  not gyro assisted
*/
void Driver_Rotate(double turn, int speed) {
  FLMotor.move_relative(turn , speed);
  FRMotor.move_relative(-turn, speed);
  BLMotor.move_relative(turn, speed);
  BRMotor.move_relative(-turn, speed);
}


/*
  Turns the robot to the target position
  is gyro assisted
*/
void Rotate(int TargetPos, int speed) {
  bool IsLeft;
  // Figures out whitch way the robot needs to turn
  if (TargetPos > 0) {
    FLMotor.move(speed);
    FRMotor.move(-speed);
    BLMotor.move(speed);
    BRMotor.move(-speed);
    IsLeft = true;
  }
  else {
    FLMotor.move(-speed);
    FRMotor.move(speed);
    BLMotor.move(-speed);
    BRMotor.move(speed);
    IsLeft = false;
  }

  /* 
    Lowers the resolution of the gyro and devides the turn in half
    This gives use some padding so we don't spin indefinitely if we over shoot
  */
  TargetPos = TargetPos / 2;
  TargetPos = TargetPos + (GyroPos() / 2);

  /* 
    Keeps use within 180 and -180
    Remember we divided everything in half so we are working in 180 not 360
  */
  if (TargetPos > 180) {
    TargetPos = TargetPos - 180;
  }
  if (TargetPos < -180) {
    TargetPos = TargetPos + 180;
  }

  /* 
    We are waiting for our gyro position to equal or surpass our turn
    then stopping the motors
  */
  if (IsLeft == true) {
    while (TargetPos >= (GyroPos() / 2)) {
      pros::delay(20);
    }
    FLMotor.move(0);
    FRMotor.move(0);
    BLMotor.move(0);
    BRMotor.move(0);
  }
  else {
    while (TargetPos <= (GyroPos() / 2)) {
      pros::delay(20);
    }
    FLMotor.move(0);
    FRMotor.move(0);
    BLMotor.move(0);
    BRMotor.move(0);
  }
}

// Function for setting the drive trian breaks
void BrakeDriveTrain() {
  // Keeps the joistics from over writing the target positions of the motors
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


// Function for releasing the drive train breaks
void UnBrakeDriveTrain() {
  // Re-enables the drive train joistics
  IsBreaking = false;
  FLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  FRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BLMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
  BRMotor.set_brake_mode(pros::E_MOTOR_BRAKE_COAST);
}


// Function for seting the cap flipper side to be the front side
void SetBackwords() {
  FLMotor.set_reversed(true);
  FRMotor.set_reversed(false);
  BLMotor.set_reversed(true);
  BRMotor.set_reversed(false);
  IsForward = false;
}


// Function for seting the ball shooter side to be the front side
void SetForwards() {
  FLMotor.set_reversed(false);
  FRMotor.set_reversed(true);
  BLMotor.set_reversed(false);
  BRMotor.set_reversed(true);
  IsForward = true;
}


// Thread for all drive train controls
void DriveTrain_fn(void* param) {
  int LeftControls = master.get_analog(ANALOG_LEFT_Y);
  int RightControls = master.get_analog(ANALOG_RIGHT_Y);


  // Setting the revering state of the motors
  FLMotor.set_reversed(false);
  FRMotor.set_reversed(true);
  BLMotor.set_reversed(false);
  BRMotor.set_reversed(true);

  while (true) {
    // Gets the joistics position and update it's veriable
    LeftControls = master.get_analog(ANALOG_LEFT_Y);
    RightControls = master.get_analog(ANALOG_RIGHT_Y);

    //Controls how the motors move
    if (IsBreaking != true) {
      if (IsForward == true) {
        /* 
          Checking if the motors are plugged in 
          if not then dissabling the oposite one to keep the drive train equal
        */
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
        /* 
          Checking if the motors are plugged in 
          if not then dissabling the oposite one to keep the drive train equal
        */
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

    // Drive train lock and unlock button
    if (master.get_digital_new_press(DIGITAL_UP) || master.get_digital_new_press(DIGITAL_DOWN)) {
      if (IsBreaking == true) {
        UnBrakeDriveTrain();
      }
      else {
        BrakeDriveTrain();
      }
    }

    // Drive train directional control buttons
    if (master.get_digital_new_press(DIGITAL_L1)) {
      SetBackwords();
    }
    if (master.get_digital_new_press(DIGITAL_R1)) {
      SetForwards();
    }

    // Rotate 90 to the left
    if (master.get_digital_new_press(DIGITAL_LEFT)) {
        Driver_Rotate(-770, 50);
        pros::delay(1200);
    }
    // Rotate 90 to the right
    else if (master.get_digital_new_press(DIGITAL_RIGHT)) {
      Driver_Rotate(770, 50);
      pros::delay(1200);
    }
  }
}
