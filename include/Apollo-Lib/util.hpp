/**
 * @file util.hpp
 * @author Nikhil Gajjar
 * @brief Util namespace
 * @version 0.1.0
 * @date 2023-05-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include "api.h"
#include <vector>
/**
 * @brief Controller Master: Global instance of the V5 Controller.
 *
 */
extern pros::Controller master;
/**
 * @brief Apollo: The main namespace for the template.
 *
 */
namespace apollo {
/**
 * @brief Joystick Split Type: Defines if the joystick control is split between
 * both joysticks or not.
 *
 */
enum joystick_split_type { SINGLE = 0, SPLIT };
/**
 * @brief Joystick Swing Type: Defines if the y-axis (forwards and backwards) is
 * on the left or right joystick. The x-axis will take the other joystick when
 * the type is split or will be on the same joystick when the type is single.
 *
 */
enum joystick_swing_type { LEFT_SWING = 0, RIGHT_SWING = 1 };
/**
 * @brief Drivetrain Mode: Defines the drive mode of the drivetrain when in
 * autonomous.
 *
 */
enum drivetrain_mode { DISABLE = 0, SWING = 1, TURN = 2, DRIVE = 3 };
/**
 * @brief Util: The main namespace for utility functions and variables.
 *
 */
namespace util {
double slew(double target, double current, double maximum_change);
double radians_to_degrees(double radians);
double degrees_to_radians(double degrees);
double angle_error(double angle_1, double angle_2, bool is_radians);
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