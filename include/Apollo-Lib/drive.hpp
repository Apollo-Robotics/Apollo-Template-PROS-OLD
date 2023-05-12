/**
 * @file drive.hpp
 * @author Nikhil Gajjar
 * @brief Drivetrain class and definitions
 * @version 0.1
 * @date 2023-05-06
 *
 * @copyright Copyright (c) 2023
 *
 */
#pragma once
#include "Apollo-Lib/pid.hpp"
#include "Apollo-Lib/util.hpp"
#include "api.h"

namespace apollo {
class Drivetrain {
  enum joystick_swing_type { LEFT = 0, RIGHT = 1 };
  enum joystick_split_type { SINGLE = 0, SPLIT = 1 };
  enum chassis_type {
    TANK_DRIVE = 0,
    X_DRIVE = 1,
    ASTERISK_DRIVE = 2,
    MECCANUM_DRIVE = 3,
    H_DRIVE = 4,
  };
  pros::motor_brake_mode_e_t current_brake_mode;
  std::vector<pros::Motor> left_drivetrain_motors;
  std::vector<pros::Motor> right_drivetrain_motors;
  std::vector<pros::Motor> front_left_drivetrain_motors;
  std::vector<pros::Motor> back_left_drivetrain_motors;
  std::vector<pros::Motor> front_right_drivetrain_motors;
  std::vector<pros::Motor> back_right_drivetrain_motors;
  pros::Imu inertial_sensor;
  pros::ADIEncoder left_encoder_wheel;
  pros::ADIEncoder right_encoder_wheel;
  pros::ADIEncoder center_encoder_wheel;
  pros::Rotation left_rotation_wheel;
  pros::Rotation right_rotation_wheel;
  pros::Rotation center_rotation_wheel;
  Drivetrain(std::vector<int> left_motor_ports,
             std::vector<int> right_motor_ports, int inertial_sensor_port,
             double wheel_diameter, int cartidge_rpm, double gear_ratio);

  Drivetrain(std::vector<int> left_motor_ports,
             std::vector<int> right_motor_ports, int inertial_sensor_port,
             double wheel_diameter, int cartidge_rpm, double gear_ratio,
             std::vector<int> left_encoder_ports,
             std::vector<int> right_encoder_ports, double ticks,
             double encoder_ratio);
  Drivetrain(std::vector<int> left_motor_ports,
             std::vector<int> right_motor_ports, int inertial_sensor_port,
             double wheel_diameter, int cartidge_rpm, double gear_ratio,
             std::vector<int> left_encoder_ports,
             std::vector<int> right_encoder_ports,
             std::vector<int> center_encoder_ports, double ticks,
             double encoder_ratio);

  Drivetrain(std::vector<int> left_motor_ports,
             std::vector<int> right_motor_ports, int inertial_sensor_port,
             double wheel_diameter, int cartidge_rpm, double gear_ratio,
             int expander_smart_port, std::vector<int> left_encoder_ports,
             std::vector<int> right_encoder_ports, double ticks,
             double encoder_ratio);
  Drivetrain(std::vector<int> left_motor_ports,
             std::vector<int> right_motor_ports, int inertial_sensor_port,
             double wheel_diameter, int cartidge_rpm, double gear_ratio,
             int expander_smart_port, std::vector<int> left_encoder_ports,
             std::vector<int> right_encoder_ports,
             std::vector<int> center_encoder_ports, double ticks,
             double encoder_ratio);

  Drivetrain(std::vector<int> left_motor_ports,
             std::vector<int> right_motor_ports, int inertial_sensor_port,
             double wheel_diameter, int cartidge_rpm, double gear_ratio,
             int left_rotation_ports, int right_rotation_ports, double ticks,
             double encoder_ratio);
  Drivetrain(std::vector<int> left_motor_ports,
             std::vector<int> right_motor_ports, int inertial_sensor_port,
             double wheel_diameter, int cartidge_rpm, double gear_ratio,
             int left_rotation_ports, int right_rotation_ports,
             int center_rotation_ports, double ticks, double encoder_ratio);

  Drivetrain(std::vector<pros::Motor> front_left_motor_ports,
             std::vector<pros::Motor> back_left_motor_ports,
             std::vector<pros::Motor> front_right_motor_ports,
             std::vector<pros::Motor> back_right_motor_ports,
             int inertial_sensor_port, double wheel_diameter, int cartidge_rpm,
             double gear_ratio);

  Drivetrain(std::vector<pros::Motor> front_left_motor_ports,
             std::vector<pros::Motor> back_left_motor_ports,
             std::vector<pros::Motor> front_right_motor_ports,
             std::vector<pros::Motor> back_right_motor_ports,
             int inertial_sensor_port, double wheel_diameter, int cartidge_rpm,
             double gear_ratio, std::vector<int> left_encoder_ports,
             std::vector<int> right_encoder_ports, double ticks,
             double encoder_ratio);
  Drivetrain(std::vector<pros::Motor> front_left_motor_ports,
             std::vector<pros::Motor> back_left_motor_ports,
             std::vector<pros::Motor> front_right_motor_ports,
             std::vector<pros::Motor> back_right_motor_ports,
             int inertial_sensor_port, double wheel_diameter, int cartidge_rpm,
             double gear_ratio, std::vector<int> left_encoder_ports,
             std::vector<int> right_encoder_ports,
             std::vector<int> center_encoder_ports, double ticks,
             double encoder_ratio);

  Drivetrain(std::vector<pros::Motor> front_left_motor_ports,
             std::vector<pros::Motor> back_left_motor_ports,
             std::vector<pros::Motor> front_right_motor_ports,
             std::vector<pros::Motor> back_right_motor_ports,
             int inertial_sensor_port, double wheel_diameter, int cartidge_rpm,
             double gear_ratio, int expander_smart_port,
             std::vector<int> left_encoder_ports,
             std::vector<int> right_encoder_ports, double ticks,
             double encoder_ratio);
  Drivetrain(std::vector<pros::Motor> front_left_motor_ports,
             std::vector<pros::Motor> back_left_motor_ports,
             std::vector<pros::Motor> front_right_motor_ports,
             std::vector<pros::Motor> back_right_motor_ports,
             int inertial_sensor_port, double wheel_diameter, int cartidge_rpm,
             double gear_ratio, int expander_smart_port,
             std::vector<int> left_encoder_ports,
             std::vector<int> right_encoder_ports,
             std::vector<int> center_encoder_ports, double ticks,
             double encoder_ratio);

  Drivetrain(std::vector<pros::Motor> front_left_motor_ports,
             std::vector<pros::Motor> back_left_motor_ports,
             std::vector<pros::Motor> front_right_motor_ports,
             std::vector<pros::Motor> back_right_motor_ports,
             int inertial_sensor_port, double wheel_diameter, int cartidge_rpm,
             double gear_ratio, int left_rotation_ports,
             int right_rotation_ports, double ticks, double encoder_ratio);
  Drivetrain(std::vector<pros::Motor> front_left_motor_ports,
             std::vector<pros::Motor> back_left_motor_ports,
             std::vector<pros::Motor> front_right_motor_ports,
             std::vector<pros::Motor> back_right_motor_ports,
             int inertial_sensor_port, double wheel_diameter, int cartidge_rpm,
             double gear_ratio, int left_rotation_ports,
             int right_rotation_ports, int center_rotation_ports, double ticks,
             double encoder_ratio);
};
} // namespace apollo