#include "main.h"

void Intake_fn(void* param) {
  IntakeControls = partner.get_analog(ANALOG_RIGHT_Y);

  while (true) {
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
  }
}