#include "main.h"

void opcontrol() {
  //------Init------
    //prints "opcontrol has started" on the brain screen.
	  pros::lcd::set_text(0, "opcontrol has started");

    //Setting the right motors to be reversed
    FLMotor.set_reversed(false);
    FRMotor.set_reversed(true);
    BLMotor.set_reversed(false);
    BRMotor.set_reversed(true);

    //------Tells the arm to hold it's position.------
    Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  //------Variables------
      bool IsShooterHot = false;
      bool IsFlipping = false;
      bool IsOverHeigh = false;
      int flipTarget = 350;
      int flipingSpeed = 100;
      int ArmCeiling = 1250;


  pros::Task Arm (Arm_fn, (void*)"PROS", TASK_PRIORITY_DEFAULT, TASK_STACK_DEPTH_DEFAULT, "My Task");
  while (true) {
    //------Monitoring code------
      //Prints the shooter temps to the brain screen.
      pros::lcd::print(5, "%d, %d", int(pros::c::motor_get_temperature(Shooter1port)), int(pros::c::motor_get_temperature(Shooter2port)));

      //if the motors are starting to over heat rumble the controllers.
      if (pros::c::motor_is_over_temp(Shooter1port) || pros::c::motor_is_over_temp(Shooter2port) && IsShooterHot == false) {
        partner.rumble("- - -");
        partner.rumble("");
        IsShooterHot = true;
      }

    //------Joistics------
      //Gets the joistics position and maps them to a veriable.
      LeftControls = master.get_analog(ANALOG_LEFT_Y);
      RightControls = master.get_analog(ANALOG_RIGHT_Y);
      ArmControls = partner.get_analog(ANALOG_LEFT_Y);
      IntakeControls = partner.get_analog(ANALOG_RIGHT_Y);

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
    //------Master Controller------

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
        Rotate(1580);
      }
      else {
        BrakeDriveTrain();
        Rotate(1580);
      }
    }


      //Drive train directional controls.
      if (master.get_digital_new_press(DIGITAL_L1)) {
        SetBackwords();
      }
      if (master.get_digital_new_press(DIGITAL_R1)) {
        SetForwards();
      }

      //Intake button for the master controller.
      if (master.get_digital(DIGITAL_R2)) {
        Intake.move(200);
      }
      else if (partner.get_digital_new_press(DIGITAL_LEFT)) {
        Intake.move(100);
        pros::delay(300);
        Intake.move(0);
      }
      else {
        //Makes the motor move if the joistic moves and the button isn't being pressed.
        Intake.move(IntakeControls);
      }

      //Rotate 90
      if (master.get_digital_new_press(DIGITAL_LEFT)) {
          Rotate(790);
          pros::delay(1200);
      }
      else if (master.get_digital_new_press(DIGITAL_RIGHT)) {
        Rotate(-790);
        pros::delay(1200);
      }

    //------Partner Controller------
      //Shooter controls.
      if (partner.get_digital(DIGITAL_R1)) {
        ShooterOn(200);
      }
      else {
        ShooterOff();
      }

    //delay for background code execution.
    pros::delay(2);
  }
}
