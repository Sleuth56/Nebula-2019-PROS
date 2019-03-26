#include "main.h"

//This function is responsible for printing out diagnostic data to a terminal.
void Diagnostics_fn(void* param) {
    int AutoTime;
    while (true) {
        //Prints the shooter temps to the terminal.
        // printf("Shooter1 Temp: %d, Shooter2 Temp: %d\n", int(pros::c::motor_get_temperature(Shooter1port)), int(pros::c::motor_get_temperature(Shooter2port)));
        
        // if (int(pros::c::motor_get_temperature(FLMotorport)) == 2147483647 || int(pros::c::motor_get_temperature(FRMotorport)) == 2147483647) {
        //     printf("true");
        // }
        // else {
        //     printf("false");
        // }
        AutoTime = (master.get_analog(ANALOG_LEFT_Y) + master.get_analog(ANALOG_RIGHT_Y) / 2);
            if (AutoTime < 0) {
                AutoTime = AutoTime*-1;
            }
        printf("%d\n", ((AutoTime-300)*-1));
    }
}
