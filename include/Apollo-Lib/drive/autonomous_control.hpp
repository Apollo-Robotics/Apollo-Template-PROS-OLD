#pragma once
#include "Apollo-Lib/drive/chassis.hpp"
#include "api.h"

namespace apollo {
class Autonomous : public Chassis {
  void set_drive_pid_(double target, int speed);
  void set_turn_pid(double angle, int speed);
};
}; // namespace apollo