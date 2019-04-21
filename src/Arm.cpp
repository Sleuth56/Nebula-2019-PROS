#include "main.h"

// Veriables for keeping the arm below 18in
bool IsOverHeigh = false;
int ArmCeiling = 1250;

// Thread for all arm controls
void Arm_fn(void* param) {
  int ArmControls = partner.get_analog(ANALOG_LEFT_Y);
  
  // Takes the average of the two drive train joysticks
  int AutoTime = (master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_Y) / 2);

  while (true) {
    // The arm moves proportionately to how fast the drive train is driving
    AutoTime = (master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_Y) / 2);
    ArmControls = partner.get_analog(ANALOG_LEFT_Y);
    if (AutoTime < 0) {
      AutoTime = AutoTime*-1;
    }

    // Resets the arm's starting position for the auto cap flip button
    if (partner.get_digital(DIGITAL_DOWN)) {
      Arm.set_zero_position(0);
    }

    // Buttons for automaticly flipping caps.
    if (partner.get_digital(DIGITAL_L1) || master.get_digital(DIGITAL_L2)) {
      Arm.move(100);
      pros::delay(((AutoTime-330)*-1));
      Arm.move(-100);
      pros::delay(((AutoTime-330)*-1));
      Arm.move(0);
      Arm.set_zero_position(0);
    }
    else {
      Arm.move(ArmControls);
    }

    // Doesn't let the arm to go over the 18 inches expantion limit unless the A button is pressed.
    if(abs(int(Arm.get_position() >= ArmCeiling && partner.get_digital(DIGITAL_A) == false))) {
      IsOverHeigh = true;
      Arm.move(-50);
    }
    else {
      IsOverHeigh = false;
    }
  }
}
