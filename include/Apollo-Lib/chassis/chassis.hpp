#pragma once
#include "api.h"
#include "chassis.hpp"
namespace apollo {
class Chassis {
  enum joystick_split_mode { SINGLE = 0, SPLIT = 1 };
  enum joystick_swing_mode { LEFT = 0, RIGHT = 1 };
  int joystick_threshold;
  pros::motor_brake_mode_e_t drive_current_brake_mode =
      pros::E_MOTOR_BRAKE_COAST;
  joystick_swing_mode drive_current_swing_mode;
  pros::ADIEncoder *left_encoder_tracking_wheel;
  pros::ADIEncoder *right_encoder_tracking_wheel;
  pros::ADIEncoder *center_encoder_tracking_wheel;
  pros::Rotation *left_rotation_tracking_wheel;
  pros::Rotation *right_rotation_tracking_wheel;
  pros::Rotation *center_rotation_tracking_wheel;
  pros::Imu *inertial_sensor;
  std::vector<pros::Motor> left_tank_drive_motors;
  std::vector<pros::Motor> right_tank_drive_motors;
  /*
   std::vector<pros::Motor> front_left_holonomic_drive_motors;
   std::vector<pros::Motor> front_right_holonomic_drive_motors;
   std::vector<pros::Motor> left_asterisk_drive_motors;
   std::vector<pros::Motor> right_asterisk_drive_motors;
   std::vector<pros::Motor> front_left_asterisk_drive_motors;
   std::vector<pros::Motor> front_right_asterisk_drive_motors;
   std::vector<pros::Motor> back_left_asterisk_drive_motors;
   std::vector<pros::Motor> back_right_asterisk_drive_motors;
   std::vector<pros::Motor> back_left_holonomic_drive_motors;
   std::vector<pros::Motor> back_right_holonomic_drive_motors;
   std::vector<pros::Motor> front_left_mechanum_drive_motors;
   std::vector<pros::Motor> front_right_mechanum_drive_motors;
   std::vector<pros::Motor> back_left_mechanum_drive_motors;
   std::vector<pros::Motor> back_right_mechanum_drive_motors;
   std::vector<pros::Motor> left_h_drive_motors;
   std::vector<pros::Motor> right_h_drive_motors;
   std::vector<pros::Motor> horizontal_h_drive_motors;
   */
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int drivetrain_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int drivetrain_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int drivetrain_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports,
          double tracker_gear_ratio, double tracker_wheel_diameter);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int drivetrain_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> center_encoder_tracking_wheel_ports,
          double tracker_gear_ratio, double tracker_wheel_diameter);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int drivetrain_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports,
          double tracker_gear_ratio, double tracker_wheel_diameter,
          int expander_smart_port);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int drivetrain_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> center_encoder_tracking_wheel_ports,
          double tracker_gear_ratio, double tracker_wheel_diameter,
          int expander_smart_port);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int drivetrain_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          int left_rotation_tracking_wheel_ports,
          int right_rotation_tracking_wheel_ports, double tracker_gear_ratio,
          double tracker_wheel_diameter);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int drivetrain_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          int left_rotation_tracking_wheel_ports,
          int right_rotation_tracking_wheel_ports,
          int center_rotation_tracking_wheel_ports, double tracker_gear_ratio,
          double tracker_wheel_diameter);
  void initialize();
  void set_defaults();
  void set_tank_control();
  void set_arcade_standard_control();
  void set_arcade_flipped_control();
  void set_joystick_threshold(int threshold);
  void set_chassis_brake_mode(pros::motor_brake_mode_e_t brake_mode);
  void reset_drive_sensors();
  void reset_inertial_sensor(int heading = 0);
  double get_inertial_sensor_heading();
  bool is_inertial_sensor_calibrating();
  int left_sensor();
  int left_velocity();
  double left_mA();
  bool is_left_drive_over_current();
  int right_sensor();
  int right_velocity();
  double right_mA();
  bool is_right_drive_over_current();
  double calculate_tracker_tick_per_inch();
  double calculate_tracker_tick_per_revoution();
  double calculate_wheel_circumference(int diameter);

private:
#define tracker_motor_integrated 1;
#define tracker_encoder_wheel 2;
#define tracker_rotation_wheel 3;
  int tracker_type = tracker_motor_integrated;
#define tank_drive 1;
#define holonomic_drive 2;
#define asterisk_drive 3;
#define mechanum_drive 4,
#define h_drive 5;
  int chassis_type = tank_drive;
  double drivetrain_cartidge_rpms;
  double drivetrain_gear_ratio;
  double drivetrain_wheel_diameter;
  double drivetrain_wheel_circumference;
  double tracker_tick_per_inch;
  double tracker_tick_per_revolution;
  double tracker_gear_ratio;
  double tracker_wheel_diameter;
  double tracker_wheel_circumference;
};
}; // namespace apollo