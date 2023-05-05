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
/**
 * @brief Slew: idk rlly what it does i was just told to add it :/
 *
 * @param target no clue!
 * @param current whats this!
 * @param maximum_change yeaaa!
 * @return double triple!!!!!!!
 */
double slew(double target, double current, double maximum_change);
/**
 * @brief Radians to Degrees: Converts radians to degrees.
 *
 * @param radians The value in radians that you want to convert to degrees.
 * @return double Returns a double with the converted number in degrees.
 */
double radians_to_degrees(double radians);
/**
 * @brief Degrres to Radians: Converts degrees to radians.
 *
 * @param degrees The value in degrees that you want to convert to radians.
 * @return double Returns a double with the converted number in radians.
 */
double degrees_to_radians(double degrees);
/**
 * @brief  Angle Error: Finds the error between 2 angles.
 *
 * @param angle_1 The first angle, the "starting" angle.
 * @param angle_2 The second angle, the "ending" angle.
 * @param is_radians Are the angles in radians? True for yes, false (the
 * default) if not.
 * @return double Returns a double with the angle error.
 */
double angle_error(double angle_1, double angle_2, bool is_radians = false);
/**
 * @brief Error: Finds the error between 2 given values.
 *
 * @param input_1 The first value.
 * @param input_2 The second value.
 * @return double Returns a double with the error.
 */
double error(double input_1, double input_2);
/**
 * @brief Sign: Gives you the sign of a value.
 *
 * @param input The value needed to be checked.
 * @return double Returns a double with the sign (-1 for negatives or 1 for
 * positives) or 0 if neither condition is satisfied.
 */
double sign(double input);
/**
 * @brief Reverse: Reverses a value.
 *
 * @param input The value needed to be reversed.
 * @return double Returns a double with the reversed value.
 */
double reverse(double input);
/**
 * @brief Average: Gives the average of a vector of values.
 *
 * @param input The input as a vector. The vector can be intialized in the
 * function or externally.
 * @return double Returns a double of the average of the numbers in the vector.
 */
double average(std::vector<double> input);
/**
 * @brief Clip: "Clips" or restricts a value between 2 other constrained values.
 *
 * @param input The value needed to be restricted.
 * @param minimum The bottom of the range of passable values.
 * @param maximum The ceiling of the range of possible values.
 * @return double Returns a double of the original input if the number was in
 * the range, or 0 if not.
 */
double clip_number(double input, double minimum, double maximum);
/**
 * @brief Is Negative: Checks whether or not a value is negative or not.
 *
 * @param input The value wanting to be checked.
 * @return true Returns true if the value is negative.
 * @return false Returns false if the value is postive
 */
bool is_negative(double input);
/**
 * @brief Did Autonomous Run?: A global variable to check whether or not the
 * autonomous ran on the competition template. Used for internal PID functions.
 *@param true Returns true if autonomous has ran.
 * @param false Returns false if the autonomous has not ran yet.
 *the card.
 */
extern bool did_autonomous_run;
/**
 * @brief Is SD Card Installed?: A constant global variable to check whether or
 * not the MicroSD Card is insatlled. Intiallized when starting the program.
 * @param true Returns true if installed. Allows writing and reading from the
 * card.
 * @param false Returns false if not installed. Disables reading and writing to
 * the card.
 */
const bool is_sd_card_installed = pros::usd::is_installed();
/**
 * @brief Delay Time: A global delay time for tasks and other loops needing a
 * buffer.
 *
 */
const int delay_time = 10;
}; // namespace util
}; // namespace apollo