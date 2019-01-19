#include "main.h"
#include "opcontrol.h"

void opcontrol() {
  bool IsFlipping = false;
  int armStatus = 0;
  int ArmTarget = 0;
  CArm.set_zero_position(11);
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

    // if (partner.get_digital_new_press(DIGITAL_L1)) { // if button pressed to automaticly move and retract
    //   pros::lcd::set_text(0,"1");
    //   Arm.move_absolute(1000, 600);
    //   armStatus = 1;
    // }
    // else if (armStatus == 0 && abs(int(Arm.get_position() - 40) < 5)) {   //if currently under automatic control and effectively at target
    //   //Arm.move_absolute(0, 600);
    //   pros::lcd::set_text(0,"00");
    //   //armStatus = 0;
    // }
    // else if (armStatus == 1 && abs(int(Arm.get_position() - 40) < 5)) {    //if effectivly at home position, reset status to joystick control
      //Arm.move_absolute(0, 600);
    //   pros::lcd::set_text(0,"0");
    //   armStatus = 0;
    // }
    // ArmControls = ArmControls / 1.5;
    // Arm.move(ArmControls);

    pros::lcd::print(0, "%i", armStatus);
    pros::lcd::print(2,"%d" , abs(int(CArm.get_position())));
    pros::lcd::print(3, "%i", ArmTarget);

    //----------joysticks worked and the button works but is flaky moves different distances----------
    // if (partner.get_digital(DIGITAL_L1)) {
    //   Arm.set_zero_position(11);
    //   Arm.move_absolute(1000, 200);
    //   armStatus = 1;
    // }
    // if (armStatus == 1 && abs(int(Arm.get_position())) >= 350) {
    //   Arm.move(-20);
    // }
    // if (armStatus == 1 && abs(int(Arm.get_position())) <= 10) {
    //   Arm.set_zero_position(0);
    //   armStatus = 0;
    // }
    // if (armStatus == 0) {
    //   Arm.move(ArmControls);
    // }

    if (Cpartner.get_digital(DIGITAL_L1)) {
      armStatus = 1;
      ArmTarget = 650;
    }
    else if (abs(int(CArm.get_position())) >= (ArmTarget - 30)) {
      ArmTarget = 0;
    }
    if (abs(int(CArm.get_position())) <= 10 && armStatus == 1) {
      CArm.set_zero_position(11);
      armStatus = 0;
    }
    if (armStatus == 1) {
      CArm.move_absolute(ArmTarget, 200);
    }
    else {
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
