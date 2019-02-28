#include "main.h"

//Veriables for controlling the shooter.
bool IsShooterHot = false;

//Function for turning on the shooter.
void ShooterOn(int velocity) {
  Shooter1.move_velocity(velocity);
  Shooter2.move_velocity(velocity);
}

//Function for turning off the shooter.
void ShooterOff() {
  ShooterOn(0);
}

//Function for shooting two balls at booth of the flags at the same time.
//Not in use yet.
void ShootTwice() {
  Intake.move_relative(1000, 50);
  do {
    pros::delay(20);
  } while (!AtDistanceDriveGoal(5));
  // pros::delay(300);
  // Intake.move(0);
  // ShooterOn();
  // pros::delay(2000);
  // Intake.move(100);
  // pros::delay(270);
  // Intake.move(0);
  // pros::delay(1000);
  // Intake.move(100);
  // pros::delay(270);
  // Intake.move(0);
  // pros::delay(400);
  // ShooterOff();
}

//Thread for all arm controls.
void Shooter_fn(void* param) {
  while (true) {
    //Prints the shooter temps to the brain screen.
    pros::lcd::print(5, "%d, %d", int(pros::c::motor_get_temperature(Shooter1port)), int(pros::c::motor_get_temperature(Shooter2port)));

    //Buttons for controlling the shooter.
    if (partner.get_digital(DIGITAL_R1)) {
      ShooterOn(160);
    }
    else if (partner.get_digital(DIGITAL_Y)) {
      ShooterOn(-10);
    }
    else {
      ShooterOff();
    }
  }
}
