#include "main.h"

//Veriables for tweaking the drive train.
bool IsBreaking = false;
bool IsForward = true;

//Thread for all drive train controls.
void DriveTrain_fn(void* param) {
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
}
