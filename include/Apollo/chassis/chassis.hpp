#pragma once
#include "api.h"
namespace apollo {
class Chassis {
public:
  pros::motor_brake_mode_e_t drive_current_brake_mode =
      pros::E_MOTOR_BRAKE_COAST;
  pros::ADIEncoder left_encoder_tracking_wheel;
  pros::ADIEncoder right_encoder_tracking_wheel;
  pros::ADIEncoder center_encoder_tracking_wheel;
  pros::Rotation left_rotation_tracking_wheel;
  pros::Rotation right_rotation_tracking_wheel;
  pros::Rotation center_rotation_tracking_wheel;
  pros::Imu inertial_sensor;
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
          int chassis_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int chassis_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports,
          double tracking_wheel_gear_ratio, double tracking_wheel_diameter);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int chassis_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> center_encoder_tracking_wheel_ports,
          double tracking_wheel_gear_ratio, double tracking_wheel_diameter);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int chassis_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports,
          double tracking_wheel_gear_ratio, double tracking_wheel_diameter,
          int expander_smart_port);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int chassis_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          std::vector<int> left_encoder_tracking_wheel_ports,
          std::vector<int> right_encoder_tracking_wheel_ports,
          std::vector<int> center_encoder_tracking_wheel_ports,
          double tracking_wheel_gear_ratio, double tracking_wheel_diameter,
          int expander_smart_port);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int chassis_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          int left_rotation_tracking_wheel_ports,
          int right_rotation_tracking_wheel_ports,
          double tracking_wheel_gear_ratio, double tracking_wheel_diameter);
  Chassis(std::vector<int> left_drivetrain_motor_ports,
          std::vector<int> right_drivetrain_motor_ports,
          int drivetrain_cartidge_rpms, double chassis_wheel_diameter,
          double chassis_gear_ratio, int inertial_sensor_port,
          int left_rotation_tracking_wheel_ports,
          int right_rotation_tracking_wheel_ports,
          int center_rotation_tracking_wheel_ports,
          double tracking_wheel_gear_ratio, double tracking_wheel_diameter);
  void calculate_tracker_variables();
  enum joystick_split_mode { SINGLE = 0, SPLIT = 1 };
  enum joystick_split { LEFT = 0, RIGHT = 1 };
  int joystick_threshold;
  void arcade_control(joystick_split_mode split_mode,
                      joystick_split split);
  void tank_control();

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