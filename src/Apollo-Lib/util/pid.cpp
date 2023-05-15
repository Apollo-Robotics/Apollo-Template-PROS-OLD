#include "main.h"
namespace apollo {
PID::PID() {
  reset_variables();
  set_gains(0, 0, 0);
}
PID::PID(double kP, double kI, double kD, std::string name) {
  reset_variables();
  set_gains(kP, kI, kD);
  set_name(name);
}
void PID::reset_variables() {
  output_value = 0;
  target_value = 0;
  error = 0;
  previous_error = 0;
  integral = 0;
  time = 0;
  previous_time = 0;
}
void PID::set_gains(double kP, double kI, double kD) {
  gains.kP = kP;
  gains.kI = kI;
  gains.kD = kD;
}
void PID::set_target(double desired_target_input) {}
void PID::set_name(std::string name) { pid_name = name; }
double PID::get_target() { return target_value; }
std::string PID::get_name() { return pid_name; }
PID::Gains PID::get_gains() { return gains; }
double PID::compute_target(double current_value) {
  error = target_value - current_value;
  derivative = error - previous_error;
  output_value =
      (error * gains.kP) + (integral * gains.kI) + (derivative * gains.kD);
  previous_error = error;
  return output_value;
}
}; // namespace apollo