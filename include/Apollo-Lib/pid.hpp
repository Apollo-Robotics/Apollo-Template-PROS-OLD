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
#include <string>

class PID {
public:
  PID();
  PID(double kP, double kI = 0, double kD = 0, double start_kI = 0,
      std::string name = "");
  void set_constants(double kP, double kI = 0, double kD = 0,
                     double start_kI = 0);
  struct Gains {
    double gains_kP;
    double gains_kI;
    double gains_kD;
    double gains_start_kI;
  };
  void set_target(double target);
  void set_name(std::string name);
  double compute_target(double current_value);
  double get_target();
  Gains get_constants();
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
};