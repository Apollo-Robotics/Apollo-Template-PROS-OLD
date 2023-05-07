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
public:
  /**
   * @brief Current Brake Mode: The current brake mode of the motors on the
   * drivetrain;
   *
   */
  pros::motor_brake_mode_e_t current_brake_mode;
  /**
   * @brief Left Drivetrain Motors: A vector containing the ports of the motors
   * on the left side of the drive. Adding a - reverses the motor.
   *
   */
  std::vector<pros::Motor> left_drivetrain_motors;
  /**
   * @brief Right Drivetrain Motors: A vector containing the ports of the motors
   * on the right side of the drive. Adding a - reverses the motor.
   *
   */
  std::vector<pros::Motor> right_drivetrain_motors;
  /**
   * @brief Front-Left Drivetrain Motors: A vector containing the ports of the
   * motors on the front-left of the holonomic drive. Adding a - reverses the
   * motor.
   *
   */
  std::vector<pros::Motor> front_left_drivetrain_motors;
  /**
   * @brief Back-Left Drivetrain Motors: A vector containing the ports of the
   * motors on the back-left of the holonomic drive. Adding a - reverses the
   * motor.
   *
   */
  std::vector<pros::Motor> back_left_drivetrain_motors;
  /**
   * @brief Front-Right Drivetrain Motors: A vector containing the ports of the
   * motors on the front-right of the holonomic drive. Adding a - reverses the
   * motor.
   *
   */
  std::vector<pros::Motor> front_right_drivetrain_motors;
  /**
   * @brief Back-Right Drivetrain Motors: A vector containing the ports of the
   * motors on the back-right of the holonomic drive. Adding a - reverses the
   * motor.
   *
   */
  std::vector<pros::Motor> back_right_drivetrain_motors;
  /**
   * @brief Inertial Sesnor: The intertial sensor's port.
   *
   */
  pros::Imu inertial_sensor;
  /**
   * @brief Left Tracking Wheel: The ADI Encoder used for the left-side tracking
   * wheel
   *
   */
  pros::ADIEncoder left_encoder_wheel;
  /**
   * @brief Right Tracking Wheel: The ADI Encoder used for the right-side
   * tracking wheel
   *
   */
  pros::ADIEncoder right_encoder_wheel;
  /**
   * @brief Center Tracking Wheel: The ADI Encoder used for the center tracking
   * wheel
   *
   */
  pros::ADIEncoder center_encoder_wheel;
  /**
   * @brief Left Rotation Wheel: The V5 Rotation Sensor used for the left-side
   * tracking wheel.
   *
   */
  pros::Rotation left_rotation_wheel;
  /**
   * @brief Right Rotation Wheel: The V5 Rotation Sensor used for the right-side
   * tracking wheel.
   *
   */
  pros::Rotation right_rotation_wheel;
  /**
   * @brief Center Rotation Wheel: The V5 Rotation Sensor used for the cetner
   * tracking wheel.
   *
   */
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