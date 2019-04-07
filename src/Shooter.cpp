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
    ShooterOn(160);
    pros::delay(1100);
    Intake.move(100);
    pros::delay(300);
    Intake.move(0);
    ShooterOn(60);
    pros::delay(200);
    Intake.move(100);
    pros::delay(400);
    Intake.move(0);
    ShooterOff();
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
  }
}
