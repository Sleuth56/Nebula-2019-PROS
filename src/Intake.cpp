#include "main.h"

// Thread for all intake controls
void Intake_fn(void* param) {
  int IntakeControls = partner.get_analog(ANALOG_RIGHT_Y);

  while (true) {
    IntakeControls = partner.get_analog(ANALOG_RIGHT_Y);
    /*
      Stops the intake from running up when two balls are at the top of the intake
      except for the single shot button
    */
    if (BottomIntakeSensor.get_value() == 1 && TopIntakeSensor.get_value() == 1) {
      if (master.get_digital(DIGITAL_B)) {
        Intake.move(-100);
      }
      else if (partner.get_digital_new_press(DIGITAL_LEFT)) {
        Intake.move(100);
        pros::delay(260);
        Intake.move(0);
      }
      else if (partner.get_digital_new_press(DIGITAL_R2)) {
        ShootTwice();
      }
      else {
        if (IntakeControls <= 0) {
          Intake.move(IntakeControls);
        }
        else {
          Intake.move(0);
        }
      }
    }
    else {
      if (master.get_digital(DIGITAL_R2)) {
        Intake.move(100);
      }
      else if (master.get_digital(DIGITAL_B)) {
        Intake.move(-100);
      }
      else if (partner.get_digital_new_press(DIGITAL_LEFT)) {
        Intake.move(100);
        pros::delay(260);
        Intake.move(0);
      }
      else if (partner.get_digital_new_press(DIGITAL_R2)) {
        ShootTwice();
      }
      else {
          Intake.move(IntakeControls);
      }
    }
  }
}