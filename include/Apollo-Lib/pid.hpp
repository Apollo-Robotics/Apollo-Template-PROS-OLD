/**
 * @file pid.hpp
 * @author PID Class
 * @brief
 * @version 0.1
 * @date 2023-05-05
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include "Apollo-Lib/util.hpp"
#include "api.h"

class PID {
public:
  PID();
  PID(double kP, double kI = 0, double kD = 0, double start_kI = 0,
      std::string name = "");
  void set_gains(double kP, double kI = 0, double kD = 0, double start_kI = 0);
  void set_exit_conditions(int small_exit_time, double small_error,
                           int big_exit_time = 0, double big_error = 0,
                           int velocity_exit_time = 0, int mA_timeout = 0);
  struct Gains {
    double kP;
    double kI;
    double kD;
    double start_kI;
  };
  struct Exit_Conditions {
    int small_time = 0;
    double small_error = 0;
    int big_time = 0;
    double big_error = 0;
    int velocity_timeout = 0;
    int mA_timeout = 0;
  };
  Gains get_gains();
  Gains gains;
  Exit_Conditions exit_conditions;
  void set_target(double input_target);
  void set_name(std::string input_name);
  double compute_target(double current_value);
  double get_target();
  void reset_variables();
  apollo::pid_exit_output exit_condition(bool print = false);
  apollo::pid_exit_output exit_condition(pros::Motor sensor,
                                         bool print = false);
  apollo::pid_exit_output exit_condition(std::vector<pros::Motor> sensor,
                                         bool print = false);
  double output_value;
  double current_value;
  double target_value;
  double error;
  double previous_error;
  double integral;
  double derivative;
  long time;
  long previous_time;

private:
  int timer_i = 0, timer_j = 0, timer_k = 0, timer_l = 0;
  bool is_overcurrent = false;
  void reset_timers();
  std::string name;
  bool is_name_set = false;
  void print_exit_condition(apollo::pid_exit_output exit_condition_type);
};