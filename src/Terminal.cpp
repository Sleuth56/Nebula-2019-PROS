#include "main.h"

// This Thread is responsible for printing out diagnostic data to the terminal
void Diagnostics_fn(void* param) {
    while (true) {
        printf("Front:%d, Back:%d\n", (front_ultrasonic.get_value()/10), (back_ultrasonic.get_value()/10));
    }
    pros::delay(100);
}