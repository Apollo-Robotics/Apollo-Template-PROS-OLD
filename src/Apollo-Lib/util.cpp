#include "main.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);

int mode = apollo::DISABLE;
double apollo::util::slew(double target, double current,
                          double maximum_change) {
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
double apollo::util::radians_to_degrees(double radians) {
  return radians * 180 / M_PI;
}
double apollo::util::degrees_to_radians(double degrees) {
  return degrees * M_PI / 180;
}
double apollo::util::angle_error(double angle_1, double angle_2,
                                 bool is_radians) {
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
double apollo::util::error(double input_1, double input_2) {
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
double apollo::util::sign(double input) {
  if (input < 0) {
    return -1;
  } else if (input > 0) {
    return 1;
  } else {
    return 0;
  }
}
double apollo::util::reverse(double input) { return -input; }
double apollo::util::average(std::vector<double> inputs) {
  double sum = 0;
  for (float input : inputs) {
    sum += input;
  }
  return sum / inputs.size();
}
double apollo::util::clip_number(double input, double minimum, double maximum) {
  if (input > maximum) {
    return maximum;
  } else if (input < minimum) {
    return minimum;
  }
  return input;
}
bool apollo::util::is_negative(double input) {
  if (input < 0) {
    return true;
  }
  return false;
}