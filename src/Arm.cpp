#include "main.h"

bool IsFlipping = false;
bool IsOverHeigh = false;
int flipTarget = 350;
int flipingSpeed = 100;
int ArmCeiling = 1250;

//
void Arm_fn(void* param) {
  Arm.set_brake_mode(pros::E_MOTOR_BRAKE_HOLD);

  while (true) {
    //Resets the arm's starting position for the auto cap flip button if the button is pressed.
    if (partner.get_digital(DIGITAL_DOWN)) {
      Arm.set_zero_position(0);
    }

    if (partner.get_digital(DIGITAL_L1)) {
      Arm.move(100);
      pros::delay(300);
      Arm.move(-100);
      pros::delay(300);
      Arm.move(0);
    }
    else if (master.get_digital(DIGITAL_L2)) {
      Arm.move(100);
      pros::delay(300);
      Arm.move(-100);
      pros::delay(300);
      Arm.move(0);
    }
    else {
      Arm.move(ArmControls);
    }

    //doesn't let the arm to go over the 18 inches expantion limit unless a button is pressed on the partner controller.
    if(abs(int(Arm.get_position() >= ArmCeiling && partner.get_digital(DIGITAL_A) == false))) {
      IsOverHeigh = true;
      Arm.move(-50);
    }
    else {
      IsOverHeigh = false;
    }

    //Resets the arm's starting position for the auto cap flip button if the button is pressed.
    if (partner.get_digital(DIGITAL_DOWN)) {
      Arm.set_zero_position(0);
    }
  }
}
