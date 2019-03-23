#include "main.h"

//Veriables for controlling the shooter.
bool IsShooterHot = false;

//Function for turning on the shooter.
void ShooterOn(int power) {
  power = power / 1.2;
  Shooter1.move(power);
  Shooter2.move(power);
}

//Function for turning off the shooter.
void ShooterOff() {
  ShooterOn(0);
}

//Function for shooting two balls at booth of the flags at the same time.
//Not in use yet.
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

//Thread for all arm controls.
void Shooter_fn(void* param) {
  bool HumanTurnOn = false;
  while (true) {
    //Prints the shooter temps to the brain screen.
    pros::lcd::print(5, "%d, %d", int(pros::c::motor_get_temperature(Shooter1port)), int(pros::c::motor_get_temperature(Shooter2port)));

    //Buttons for controlling the shooter.
    if (partner.get_digital(DIGITAL_R1)) {
      HumanTurnOn = true;
      // 160
      ShooterOn(200);
    }
    else if (partner.get_digital(DIGITAL_A)) {
      HumanTurnOn = true;
      ShooterOn(-50);
    }
    else if (HumanTurnOn == true) {
      ShooterOff();
      HumanTurnOn = false;
    }
  }
}
