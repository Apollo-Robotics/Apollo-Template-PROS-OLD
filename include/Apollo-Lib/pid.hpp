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
    double gains_kP;
    double gains_kI;
    double gains_kD;
    double gains_start_kI;
  };
  struct PID_exit_conditions {
    int exit_small_exit_time = 0;
    double exit_small_error = 0;
    int exit_big_exit_time = 0;
    double exit_big_error = 0;
    int exit_velocity_exit_time = 0;
    int exit_mA_timeout = 0;
  };
  Gains get_gains();
  Gains gains;
  PID_exit_conditions exit_conditions;
  void set_target(double input_target);
  void set_name(std::string input_name);
  double compute_target(double current_value);
  double get_target();
  void reset_variables();
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
  std::string name;
  bool is_name_set;
};