/**
 * @file util.cpp
 * @author Nikhil Gajjar
 * @brief Util namespace function definitions
 * @version 0.1.0
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);

namespace apollo {

int mode = DISABLE;
std::string exit_condition_to_string(pid_exit_output input) {
  switch ((int)input) {
  case RUNNING:
    return "Running";
  case SMALL_EXIT:
    return "Small";
  case BIG_EXIT:
    return "Big";
  case VELOCITY_EXIT:
    return "Velocity";
  case mA_EXIT:
    return "mA";
  case ERROR_NO_CONSTANTS:
    return "Error: Exit condition constants not set!";
  default:
    return "Error: Out of bounds!";
  }
  return "Error: Out of bounds!";
}
namespace util {
double slew(double target, double current, double maximum_change) {
  double change = target - current;
  if (maximum_change == 0) {
    return target;
  } else if (change > maximum_change) {
    change = maximum_change;
  } else if (change < -maximum_change) {
    change = -maximum_change;
  }
  return current + change;
}
double radians_to_degrees(double radians) { return radians * 180 / M_PI; }
double degrees_to_radians(double degrees) { return degrees * M_PI / 180; }
double angle_error(double angle_1, double angle_2, bool is_radians) {
  double maximum = is_radians ? 2 * M_PI : 360;
  double half = is_radians ? M_PI : 180;
  angle_1 = fmod(angle_1, maximum);
  angle_2 = fmod(angle_2, maximum);
  float error = angle_1 - angle_2;
  if (error > half) {
    error -= maximum;
  } else if (error < -half) {
    error += maximum;
  }
  return error;
}
double error(double input_1, double input_2) {
  double maximum, half;
  if (input_1 > input_1) {
    maximum = input_1;
    half = (input_1 + input_2) / 2;
  } else if (input_2 > input_1) {
    maximum = input_2;
    half = (input_1 + input_2) / 2;
  } else if (input_1 == input_1) {
    return (input_1 + input_2) / 2;
  }
  input_1 = fmod(input_1, maximum);
  input_2 = fmod(input_2, maximum);
  float error = input_1 - input_2;
  if (error > half) {
    error -= maximum;
  } else if (error < -half) {
    error += maximum;
  }
  return error;
}
double sign(double input) {
  if (input < 0) {
    return -1;
  } else if (input > 0) {
    return 1;
  } else {
    return 0;
  }
}
double reverse(double input) { return -input; }
double average(std::vector<double> inputs) {
  double sum = 0;
  for (float input : inputs) {
    sum += input;
  }
  return sum / inputs.size();
}
double clip_number(double input, double minimum, double maximum) {
  if (input > maximum) {
    return maximum;
  } else if (input < minimum) {
    return minimum;
  }
  return input;
}
bool is_negative(double input) {
  if (input < 0) {
    return true;
  }
  return false;
}
}; // namespace util
}; // namespace apollo