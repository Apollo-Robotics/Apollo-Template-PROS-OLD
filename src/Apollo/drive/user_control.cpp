#include "main.h"
namespace apollo {
void Chassis::tank_control() {
  int left_stick = master.get_analog(ANALOG_LEFT_Y);
  int right_stick = master.get_analog(ANALOG_RIGHT_Y);
  if (abs(left_stick) > joystick_threshold) {
    for (auto i : left_tank_drive_motors) {
      i.move_voltage(left_stick * (12000 / 127));
    }
  }
  if (abs(right_stick) > joystick_threshold) {
    for (auto i : right_tank_drive_motors) {
      i.move_voltage(right_stick * (12000 / 127));
    }
  }
}
void Chassis::arcade_control(joystick_split_mode split_mode,
                             joystick_split split) {
  int forward_stick, turn_stick;
  if (split_mode == SINGLE) {
    if (split == LEFT) {
      forward_stick = master.get_analog(ANALOG_LEFT_Y);
      turn_stick = master.get_analog(ANALOG_LEFT_X);
    } else if (split == RIGHT) {
      forward_stick = master.get_analog(ANALOG_RIGHT_Y);
      turn_stick = master.get_analog(ANALOG_RIGHT_X);
    }
  }
  if (split_mode == SPLIT) {
    if (split == LEFT) {
      forward_stick = master.get_analog(ANALOG_RIGHT_Y);
      turn_stick = master.get_analog(ANALOG_LEFT_X);

    } else if (split == RIGHT) {
      forward_stick = master.get_analog(ANALOG_LEFT_Y);
      turn_stick = master.get_analog(ANALOG_RIGHT_X);
    }
  }
  if (abs(forward_stick) > joystick_threshold ||
      abs(turn_stick) > joystick_threshold) {
    for (auto i : left_tank_drive_motors) {
      i.move_voltage((forward_stick + turn_stick) * (12000 / 127));
    }
    for (auto i : right_tank_drive_motors) {
      i.move_voltage((forward_stick - turn_stick) * (12000 / 127));
    }
  }
}
} // namespace apollo