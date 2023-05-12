#pragma once
#include "Apollo-Lib/util.hpp"
#include "api.h"
#include "pros/motors.h"
namespace apollo {
class Chassis {
public:
  int joystick_threshold;
  enum joystick_swing_type { LEFT = 0, RIGHT = 1 };
  enum joystick_split_type { SINGLE = 0, SPLIT = 1 };
  enum chassis_type {
    TANK_DRIVE,
    X_DRIVE,
    ASTERISK_DRIVE,
    MECCANUM_DRIVE,
    H_DRIVE,
  };
  pros::motor_brake_mode_e_t chassis_brake_type =
      pros::motor_brake_mode_e_t::E_MOTOR_BRAKE_COAST;
  std::vector<pros::Motor> left_drive_motors;
  std::vector<pros::Motor> right_drive_motors;
  std::vector<pros::Motor> front_left_drive_motors;
  std::vector<pros::Motor> back_left_drive_motors;
  std::vector<pros::Motor> front_right_drive_motors;
  std::vector<pros::Motor> back_right_drive_motors;
  pros::IMU *inertial_sensor;
  pros::ADIEncoder *left_encoder_tracking_wheel = nullptr;
  pros::ADIEncoder *right_encoder_tracking_wheel = nullptr;
  pros::ADIEncoder *center_encoder_tracking_wheel = nullptr;
  pros::Rotation *left_rotation_tracking_wheel = nullptr;
  pros::Rotation *right_rotation_tracking_wheel = nullptr;
  pros::Rotation *center_rotation_tracking_wheel = nullptr;
  Chassis(std::vector<int> left_drive_motor_ports,
          std::vector<int> right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms);
  Chassis(std::vector<int> left_drive_motor_ports,
          std::vector<int> right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port);
  Chassis(std::vector<int> left_drive_motor_ports,
          std::vector<int> right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports);
  Chassis(std::vector<int> left_drive_motor_ports,
          std::vector<int> right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> center_encoder_tracking_wheel_ports);
  Chassis(std::vector<int> left_drive_motor_ports,
          std::vector<int> right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          int expander_port,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> left_encoder_tracking_wheel_ports);
  Chassis(std::vector<int> left_drive_motor_ports,
          std::vector<int> right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          int expander_port,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> center_encoder_tracking_wheel_ports);
  Chassis(std::vector<int> left_drive_motor_ports,
          std::vector<int> right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          int right_rotation_tracking_wheel_port,
          int left_rotation_tracking_wheel_port);
  Chassis(std::vector<int> left_drive_motor_ports,
          std::vector<int> right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          int right_rotation_tracking_wheel_port,
          int left_rotation_tracking_wheel_port,
          int center_rotation_tracking_wheel_port);
  Chassis(std::vector<int> front_left_drive_motor_ports,
          std::vector<int> back_left_drive_motor_ports,
          std::vector<int> front_right_drive_motor_ports,
          std::vector<int> back_right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms);
  Chassis(std::vector<int> front_left_drive_motor_ports,
          std::vector<int> back_left_drive_motor_ports,
          std::vector<int> front_right_drive_motor_ports,
          std::vector<int> back_right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port);
  Chassis(std::vector<int> front_left_drive_motor_ports,
          std::vector<int> back_left_drive_motor_ports,
          std::vector<int> front_right_drive_motor_ports,
          std::vector<int> back_right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> left_encoder_tracking_wheel_ports);
  Chassis(std::vector<int> front_left_drive_motor_ports,
          std::vector<int> back_left_drive_motor_ports,
          std::vector<int> front_right_drive_motor_ports,
          std::vector<int> back_right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> center_encoder_tracking_wheel_ports);
  Chassis(std::vector<int> front_left_drive_motor_ports,
          std::vector<int> back_left_drive_motor_ports,
          std::vector<int> front_right_drive_motor_ports,
          std::vector<int> back_right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          int expander_port,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> left_encoder_tracking_wheel_ports);
  Chassis(std::vector<int> front_left_drive_motor_ports,
          std::vector<int> back_left_drive_motor_ports,
          std::vector<int> front_right_drive_motor_ports,
          std::vector<int> back_right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          int expander_port,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> center_encoder_tracking_wheel_ports);
  Chassis(std::vector<int> front_left_drive_motor_ports,
          std::vector<int> back_left_drive_motor_ports,
          std::vector<int> front_right_drive_motor_ports,
          std::vector<int> back_right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          int right_rotation_tracking_wheel_port,
          int left_rotation_tracking_wheel_port);
  Chassis(std::vector<int> front_left_drive_motor_ports,
          std::vector<int> back_left_drive_motor_ports,
          std::vector<int> front_right_drive_motor_ports,
          std::vector<int> back_right_drive_motor_ports, double wheel_diameter,
          double gear_ratio, int cartidge_rpms, int inertial_sensor_port,
          int right_rotation_tracking_wheel_port,
          int left_rotation_tracking_wheel_port,
          int center_rotation_tracking_wheel_port);
  void set_tank_control();
  void set_arcade_standard_control(joystick_split_type split_type);
  void set_arcade_flipped_control(joystick_split_type split_type);
  void set_joystick_threshold(int threshold);
  void reset_drive_sensors();
  void set_tank(int left_voltage, int right_voltage);
  void set_drive_brake(pros::motor_brake_mode_e_t brake_type);
  void reset_right_chassis_sensor();
  int right_chassis_sensor();
  int get_right_chassis_velocity();
  double get_right_chassis_power();
  bool is_right_chassis_over_current();
  void reset_left_chassis_sensor();
  int left_chassis_sensor();
  int get_left_chassis_velocity();
  double get_left_chassis_power();
  bool is_left_chassis_over_current();
  void reset_gyro(double heading = 0);
  double get_gyro();
  bool caliblrate_inertial();
  double calculate_tracker_wheel_diameter();
  double calculate_tick_per_inch();
  double calculate_tick_per_revolution();

private:
  bool drive_toggle = true;
  bool print_toggle = true;
  double active_brake_kp = 0;
  double tracker_tick_per_revolution;
  double tracker_tick_per_inch;
  double tracker_wheel_diameter;
  double drive_cartridge_rpms;
  double drive_gear_ratio;
  double drive_wheel_diameter;
  bool is_tank;
#define motor_integrated 1
#define tracking_encoder 2
#define tracking_rotation 3
  int tracker_type = motor_integrated;
};
}; // namespace apollo