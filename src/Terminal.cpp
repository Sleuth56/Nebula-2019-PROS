#include "main.h"

// This thread is responsible for printing out diagnostic data to the terminal
void Diagnostics_fn(void* param) {
    while (true) {
        // Prints out the front ultrasonic, back ultrasonic, and gyro position to the terminal
        printf("Front:%d, Back:%d, Gyro Pos: %d\n", (front_ultrasonic.get_value()/10), (back_ultrasonic.get_value()/10), GyroPos());
    }
    pros::delay(100);
}