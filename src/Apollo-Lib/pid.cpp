#include "main.h"
#include <iostream>
#include <vector>
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
void PID::reset_timers() {
  timer_i = 0;
  timer_j = 0;
  timer_k = 0;
  timer_l = 0;
  is_overcurrent = false;
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

void PID::print_exit_condition(apollo::pid_exit_output exit_condition_type) {
  std::cout << " ";
  if (is_name_set) {
    std::cout << name << "PID" << exit_condition_to_string(exit_condition_type)
              << "Exit.\n";
  } else {
    std::cout << exit_condition_to_string(exit_condition_type) << "Exit.\n";
  }
}
pid_exit_output PID::exit_condition(bool print) {
  if (!(exit_conditions.small_time && exit_conditions.small_error &&
        exit_conditions.big_time && exit_conditions.big_error &&
        exit_conditions.velocity_timeout && exit_conditions.mA_timeout)) {
    print_exit_condition(apollo::ERROR_NO_CONSTANTS);
    return ERROR_NO_CONSTANTS;
  }
  if (exit_conditions.small_error != 0) {
    if (std::abs(error) < exit_conditions.small_error) {
      timer_j += util::delay_time;
      timer_i = 0;
      if (timer_j > exit_conditions.small_time) {
        reset_timers();
        if (print) {
          print_exit_condition(apollo::SMALL_EXIT);
        }
        return SMALL_EXIT;
      } else {
        timer_j = 0;
      }
    }
  }
  if (exit_conditions.big_error != 0 && exit_conditions.big_time != 0) {
    if (std::abs(error) < exit_conditions.big_error) {
      timer_i += util::delay_time;
      if (timer_i > exit_conditions.big_time) {
        reset_timers();
        if (print)
          print_exit_condition(BIG_EXIT);
        return BIG_EXIT;
      }
    } else {
      timer_i = 0;
    }
  }
  if (exit_conditions.velocity_timeout != 0) {
    if (std::abs(derivative) <= 0.05) {
      timer_k += util::delay_time;
      if (timer_k > exit_conditions.velocity_timeout) {
        reset_timers();
        if (print)
          print_exit_condition(VELOCITY_EXIT);
        return VELOCITY_EXIT;
      }
    } else {
      timer_k = 0;
    }
  }

  return RUNNING;
}
pid_exit_output PID::exit_condition(pros::Motor sensored_motor, bool print) {
  if (exit_conditions.mA_timeout != 0) {
    if (sensored_motor.is_over_current()) {
      timer_l += util::delay_time;
      if (timer_l > exit_conditions.mA_timeout) {
        reset_timers();
        if (print) {
          print_exit_condition(apollo::mA_EXIT);
        }
        return mA_EXIT;
      } else {
        timer_l = 0;
      }
    }
  }
  return exit_condition(print);
}
pid_exit_output PID::exit_condition(std::vector<pros::Motor> sensored_motor,
                                    bool print) {
  if (exit_conditions.mA_timeout != 0) {
    for (auto i : sensored_motor) {
      if (i.is_over_current()) {
        is_overcurrent = true;
        break;
      } else {
        is_overcurrent = false;
      }
    }
    if (is_overcurrent) {
      timer_l += util::delay_time;
      if (timer_l > exit_conditions.mA_timeout) {
        reset_timers();
        if (print) {
          print_exit_condition(apollo::mA_EXIT);
        }
        return mA_EXIT;
      } else {
        timer_l = 0;
      }
    }
  }
  return exit_condition(print);
}