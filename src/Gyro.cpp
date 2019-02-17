#include "main.h"

int GyroPos() {
  return (int(gyro.get_value()) / 10);
}
