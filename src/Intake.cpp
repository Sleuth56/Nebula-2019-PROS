#include "main.h"

void Intake_fn(void* param) {
  int IntakeControls = partner.get_analog(ANALOG_RIGHT_Y);

  while (true) {
    IntakeControls = partner.get_analog(ANALOG_RIGHT_Y);

    //Intake button for the master controller.
    if (master.get_digital(DIGITAL_R2)) {
      Intake.move(200);
    }
    else if (master.get_digital(DIGITAL_B)) {
      Intake.move(-200);
    }
    else if (partner.get_digital_new_press(DIGITAL_LEFT)) {
      Intake.move(100);
      //was 300
      pros::delay(260);
      Intake.move(0);
    }
    else if (partner.get_digital_new_press(DIGITAL_R2)) {
      ShootTwice();
    }
    else {
      //Makes the motor move if the joistic moves and the button isn't being pressed.
      Intake.move(IntakeControls);
    }
  }
}
