#pragma once
#include "api.h"
extern pros::Controller master;
namespace apollo {
namespace util {
double slew(double target, double current, double maximum_change);
double radians_to_degrees(double radians);
double degrees_to_radians(double degrees);
double angle_error(double angle_1, double angle_2, bool is_radians = false);
double error(double input_1, double input_2);
double sign(double input);
double reverse(double input);
double average(std::vector<double> input);
double clip_number(double input, double minimum, double maximum);
bool is_negative(double input);
extern bool did_autonomous_run;
const bool is_sd_card_installed = pros::usd::is_installed();
const int delay_time = 10;
}; // namespace util
}; // namespace apollo