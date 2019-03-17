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
  if (BottomIntakeSensor.get_value() == 1 && TopIntakeSensor.get_value() == 1) {
    ShooterOn(160);
    pros::delay(3000);
    Intake.move(100);
    while (BottomIntakeSensor.get_value() == 1) {
      pros::delay(200);
    }
    Intake.move(0);
    ShooterOn(100);
    pros::delay(300);
    Intake.move(100);
    while (TopIntakeSensor.get_value() == 1) {
      pros::delay(200);
    }
    Intake.move(0);
    ShooterOff();
    
  }
  
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
    else if (partner.get_digital(DIGITAL_Y)) {
      HumanTurnOn = true;
      ShooterOn(-10);
    }
    else if (HumanTurnOn == true) {
      ShooterOff();
      HumanTurnOn = false;
    }
  }
}
