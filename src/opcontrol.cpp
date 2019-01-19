#include "main.h"
#include "opcontrol.h"

void opcontrol() {
  bool IsFlipping = false;
  CArm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true) {
    CLeftControls = Cmaster.get_analog(ANALOG_LEFT_Y);
    CRightControls = Cmaster.get_analog(ANALOG_RIGHT_Y);
    CArmControls = Cpartner.get_analog(ANALOG_LEFT_Y);
    CIntakeControls = Cpartner.get_analog(ANALOG_RIGHT_Y);

    //------Shooter controls------
    if (Cpartner.get_digital(DIGITAL_R1)) {
      CshooterOn(200);
    }
    else {
      CshooterOff();
    }

    //------Drive train break controls------
    if (Cmaster.get_digital(DIGITAL_UP)) {
      CbrakeDriveTrain();
    }
    else {
      CunBrakeDriveTrain();
    }

    CIntake.move(CIntakeControls);

    //------Drive train directional controls------
    if (Cmaster.get_digital_new_press(DIGITAL_L1)) {
      CsetBackwords();
    }
    if (Cmaster.get_digital_new_press(DIGITAL_R1)) {
      CsetForwards();
    }

    if (Cpartner.get_digital(DIGITAL_DOWN)) {
      CArm.set_zero_position(0);
    }

    if (Cmaster.get_digital(DIGITAL_L2)) {
      CArm.move_absolute(650, 200);
      IsFlipping = true;
    }
    if (Cpartner.get_digital(DIGITAL_L1)) {
      CArm.move_absolute(650, 200);
      IsFlipping = true;
    }
    if (IsFlipping == true && abs(int(CArm.get_position())) >= 630) {
      CArm.move_absolute(0, 200);
      pros::delay(200);
      IsFlipping = false;
    }
    if (IsFlipping == false) {
      CArm.move(CArmControls);
    }

    if (isForward == true) {
      CFLMotor.move(CLeftControls);
      CBLMotor.move(CLeftControls);
      CFRMotor.move(CRightControls);
      CBRMotor.move(CRightControls);
    }
    else {
      CFLMotor.move(CRightControls);
      CBLMotor.move(CRightControls);
      CFRMotor.move(CLeftControls);
      CBRMotor.move(CLeftControls);
    }
    pros::delay(2);
  }
}
