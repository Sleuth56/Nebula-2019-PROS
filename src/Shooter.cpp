#include "main.h"

// Function for turning on the shooter
void ShooterOn(int power) {
  power = power / 1.2;
  Shooter1.move(power);
  Shooter2.move(power);
}

// Function for turning off the shooter
void ShooterOff() {
  ShooterOn(0);
}

// Function for shooting two balls at booth of the flags at the same time
// Not in use yet
void ShootTwice() {
  if (IsBreaking == false) {
    BrakeDriveTrain();
    pros::delay(100);
    Drive(-1200, -1200, 100);
    pros::delay(100);
    UnBrakeDriveTrain();
  }
}

// Thread for all shooter controls
void Shooter_fn(void* param) {
  // This veriable is true if a human turned on the shooter
  bool HumanTurnOn = false;
  while (true) {
    if (partner.get_digital(DIGITAL_R1)) {
      HumanTurnOn = true;
      ShooterOn(200);
    }
    else if (partner.get_digital(DIGITAL_Y)) {
      HumanTurnOn = true;
      ShooterOn(-50);
    }
    else if (HumanTurnOn == true) {
      ShooterOff();
      HumanTurnOn = false;
    }

    if (partner.get_digital_new_press(DIGITAL_L2)) {
      ShootTwice();
    }
  }
}
