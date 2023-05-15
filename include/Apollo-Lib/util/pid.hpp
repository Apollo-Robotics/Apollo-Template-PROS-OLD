#pragma once
#include "api.h"
namespace apollo {
class PID {
public:
  PID();
  PID(double kP, double kI, double kD, std::string name);
  struct Gains {
    double kP;
    double kI;
    double kD;
  };
  Gains gains;
  void reset_variables();
  void set_gains(double kP, double kI, double kD);
  void set_target(double desired_target_input);
  void set_name(std::string name);
  double get_target();
  std::string get_name();
  Gains get_gains();
  double compute_target(double current_value);

private:
  double output_value;
  double target_value;
  double error;
  double previous_error;
  double integral;
  double derivative;
  long time;
  long previous_time;
  std::string pid_name;
};
}; // namespace apollo