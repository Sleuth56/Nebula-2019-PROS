#include "main.h"


void opcontrol() {
  FLMotor.set_reversed(false);
  FRMotor.set_reversed(true);
  BLMotor.set_reversed(false);
  BRMotor.set_reversed(true);
  //------tells the user that the opcontrol faze has started.------
	pros::lcd::set_text(0, "opcontrol has started");

	bool IsShooterHot = false;
  //------Tells if the auto cap flip button is running.------
  bool IsFlipping = false;
  //------Tells the arm to hold it's position.------
  Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true) {
    //------Shooter motor temps read out.------
    pros::lcd::print(5, "%d, %d", int(pros::c::motor_get_temperature(Shooter1port)), int(pros::c::motor_get_temperature(Shooter2port)));

    if (pros::c::motor_is_over_temp(Shooter1port) || pros::c::motor_is_over_temp(Shooter2port) && IsShooterHot == true) {
      master.rumble("- - -");
      master.rumble("");
      partner.rumble("- - -");
      partner.rumble("");
    }


    //------Gets the joistics position and sets it to a veriable.------
    LeftControls = master.get_analog(ANALOG_LEFT_Y);
    RightControls = master.get_analog(ANALOG_RIGHT_Y);
    ArmControls = partner.get_analog(ANALOG_LEFT_Y);
    IntakeControls = partner.get_analog(ANALOG_RIGHT_Y);


    //------Shooter controls.------
    if (partner.get_digital(DIGITAL_R1)) {
      ShooterOn(200);
    }
    else {
      ShooterOff();
    }


    //------Drive train break controls.------
    if (master.get_digital_new_press(DIGITAL_UP)) {
      if (isBreaking == true) {
        UnBrakeDriveTrain();
      }
      else {
        BrakeDriveTrain();
      }
    }


    //------Drive train directional controls.------
    if (master.get_digital_new_press(DIGITAL_L1)) {
      SetBackwords();
    }
    if (master.get_digital_new_press(DIGITAL_R1)) {
      SetForwards();
    }


    //------Sets the Arm's starting position for the auto cap flip button.------
    if (partner.get_digital(DIGITAL_DOWN)) {
      Arm.set_zero_position(0);
    }


    //------Sets the target position for the auto cap flip button------
    //650 sometimes double flipped
    int flipTarget = 350;
    //------Sets how fast the arm will flip the cap------
    int flipingSpeed = 100;
    //------If the L2 button on the master controller is pressed------
    //------move the arm to the fliping target and set the IsFlipping veriable to true------
    //------so the arm will lower after it reaches the target height.------
    if (master.get_digital(DIGITAL_L2)) {
      Arm.move_absolute(flipTarget, flipingSpeed);
      IsFlipping = true;
    }
    //------Does the same thing as the other one except this the L1 button on the partner controller.------
    if (partner.get_digital(DIGITAL_L1)) {
      Arm.move_absolute(flipTarget, flipingSpeed);
      IsFlipping = true;
    }
    //------Checks for if we pushed either of the buttons and if the arm has reached it's target.------
    //------If it has it moves it back down and sets the IsFlipping veriable to false telling allowing the joistic to control the arm again.------
    if (IsFlipping == true && abs(int(Arm.get_position())) >= (flipTarget - 20)) {
      Arm.move_absolute(0, flipingSpeed);
      pros::delay(flipingSpeed + 100);
      IsFlipping = false;
    }
    //------If the auto cap flipping buttons arn't active maps the arm motor to the joistics.------
    if (IsFlipping == false) {
      Arm.move(ArmControls);
    }


    //------Intake button for the master controller.------
    if (master.get_digital(DIGITAL_R2)) {
      Intake.move(200);
    }
    else {
      //------Maps the intake motor to the intake joistic if the master controllers button isn't being pressed.------
      Intake.move(IntakeControls);
    }


    //------Switches the motor sides if the drive train is reversed.------
    if (isBreaking != true) {
          if (isForward == true) {
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
    pros::delay(2);
  }
}
