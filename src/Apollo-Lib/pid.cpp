#include "main.h"
using namespace apollo;

void PID::reset_variables() {
  output_value = 0;
  current_value = 0;
  target_value = 0;
  error = 0;
  previous_error = 0;
  integral = 0;
  derivative = 0;
  time = 0;
  previous_time = 0;
}
PID::PID() {
  reset_variables();
  set_gains(0, 0, 0, 0);
}
PID::Gains PID::get_gains() { return gains; }
PID::PID(double kP, double kI, double kD, double start_kI, std::string name) {
  reset_variables();
  set_gains(kP, kI, kP, start_kI);
  set_name(name);
}
void PID::set_gains(double kP, double kI, double kD, double start_kI) {
  gains.kP = kP;
  gains.kI = kI;
  gains.kD = kD;
  gains.start_kI = start_kI;
}
void PID::set_name(std::string input_name) {
  name = input_name;
  is_name_set = name == "" ? false : true;
}
void PID::set_target(double input_target) { target_value = input_target; }
double PID::get_target() { return target_value; }
double PID::compute_target(double current_value) {
  error = target_value - current_value;
  derivative = error - previous_error;
  if (gains.kI != 0) {
    if (fabs(error) < gains.start_kI) {
      integral += error;
    }
    if (util::sign(error) != util::sign(previous_error)) {
      integral = 0;
    }
  }
  output_value =
      (error * gains.kP) + (integral * gains.kI) + (derivative * gains.kD);
  previous_error = error;
  return output_value;
}