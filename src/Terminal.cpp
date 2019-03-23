#include "main.h"

//This function is responsible for printing out diagnostic data to a terminal.
void Diagnostics_fn(void* param) {
    while (true) {
    //Prints the shooter temps to the terminal.
    printf("Shooter1 Temp: %d, Shooter2 Temp: %d\n", int(pros::c::motor_get_temperature(Shooter1port)), int(pros::c::motor_get_temperature(Shooter2port)));
    }
}
