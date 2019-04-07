#include "main.h"

// This Thread is responsible for printing out diagnostic data to the terminal
void Diagnostics_fn(void* param) {
    while (true) {
        printf("%d\n", GyroPos());
    }
}