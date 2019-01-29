#include "main.h"

//Veriables for controlling the shooter.
bool IsShooterHot = false;


//Function for turning on the shooter
void ShooterOn(int velocity) {
  Shooter1.move_velocity(velocity);
  Shooter2.move_velocity(velocity);
}


//Function for turning off the shooter
void ShooterOff() {
  ShooterOn(0);
}


void ShootTwice() {
  ShooterOn(200);
  pros::delay(600);
  Intake.move(100);
  pros::delay(300);
  Intake.move(0);
  
  pros::delay(500);
  
  Intake.move(100);
  pros::delay(300);
  Intake.move(0);
  ShooterOff();
}


//thread for all arm controls.
void Shooter_fn(void* param) {
  while (true) {
    //Prints the shooter temps to the brain screen.
    pros::lcd::print(5, "%d, %d", int(pros::c::motor_get_temperature(Shooter1port)), int(pros::c::motor_get_temperature(Shooter2port)));

    //if the motors are starting to over heat rumble the controllers.
    if (pros::c::motor_is_over_temp(Shooter1port) || pros::c::motor_is_over_temp(Shooter2port) && IsShooterHot == false) {
      partner.rumble("- - -");
      partner.rumble("");
      IsShooterHot = true;
    }

    //buttons for the shooter.
    if (partner.get_digital(DIGITAL_R1)) {
      ShooterOn(200);
    }
    else {
      ShooterOff();
    }
    //Shoot booth top flags.
    if (partner.get_digital_new_press(DIGITAL_R2)) {
      ShootTwice();
    }
  }
}
