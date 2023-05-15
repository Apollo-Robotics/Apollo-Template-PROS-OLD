#include "main.h"
namespace apollo {
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port)
    : inertial_sensor(inertial_sensor_port),
      left_encoder_tracking_wheel(-1, -1, -1),
      right_encoder_tracking_wheel(-1, -1, -1),
      center_encoder_tracking_wheel(-1, -1, -1),
      left_rotation_tracking_wheel(-1, -1),
      right_rotation_tracking_wheel(-1, -1),
      center_rotation_tracking_wheel(-1, -1) {
  for (auto i : left_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    left_tank_drive_motors.push_back(temp);
  }
  for (auto i : right_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    right_tank_drive_motors.push_back(temp);
  }
  tracker_type = tracker_motor_integrated;
  chassis_type = tank_drive;
  drivetrain_cartidge_rpms = chassis_cartidge_rpms;
  drivetrain_gear_ratio = chassis_gear_ratio;
  drivetrain_wheel_diameter = chassis_wheel_diameter;
  drivetrain_wheel_circumference = drivetrain_wheel_diameter * M_PI;
  tracker_gear_ratio = drivetrain_gear_ratio;
  tracker_wheel_diameter = drivetrain_wheel_diameter;
  tracker_wheel_circumference = drivetrain_wheel_circumference;
  calculate_tracker_variables();
}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 double tracking_wheel_gear_ratio,
                 double tracking_wheel_diameter)
    : inertial_sensor(inertial_sensor_port),
      left_encoder_tracking_wheel(
          abs(left_encoder_tracking_wheel_ports[0]),
          abs(left_encoder_tracking_wheel_ports[1]),
          util::is_negative(left_encoder_tracking_wheel_ports[0])),
      right_encoder_tracking_wheel(
          abs(right_encoder_tracking_wheel_ports[0]),
          abs(right_encoder_tracking_wheel_ports[1]),
          util::is_negative(right_encoder_tracking_wheel_ports[0])),
      center_encoder_tracking_wheel(-1, -1, -1),
      left_rotation_tracking_wheel(-1, -1),
      right_rotation_tracking_wheel(-1, -1),
      center_rotation_tracking_wheel(-1, -1) {
  for (auto i : left_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    left_tank_drive_motors.push_back(temp);
  }
  for (auto i : right_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    right_tank_drive_motors.push_back(temp);
  }
  tracker_type = tracker_encoder_wheel;
  chassis_type = tank_drive;
  drivetrain_cartidge_rpms = chassis_cartidge_rpms;
  drivetrain_gear_ratio = chassis_gear_ratio;
  drivetrain_wheel_diameter = chassis_wheel_diameter;
  drivetrain_wheel_circumference = drivetrain_wheel_diameter * M_PI;
  tracker_gear_ratio = tracking_wheel_gear_ratio;
  tracker_wheel_diameter = tracking_wheel_diameter;
  tracker_wheel_circumference = tracking_wheel_diameter * M_PI;
  calculate_tracker_variables();
}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> center_encoder_tracking_wheel_ports,
                 double tracking_wheel_gear_ratio,
                 double tracking_wheel_diameter)
    : inertial_sensor(inertial_sensor_port),
      left_encoder_tracking_wheel(
          abs(left_encoder_tracking_wheel_ports[0]),
          abs(left_encoder_tracking_wheel_ports[1]),
          util::is_negative(left_encoder_tracking_wheel_ports[0])),
      right_encoder_tracking_wheel(
          abs(right_encoder_tracking_wheel_ports[0]),
          abs(right_encoder_tracking_wheel_ports[1]),
          util::is_negative(right_encoder_tracking_wheel_ports[0])),
      center_encoder_tracking_wheel(
          abs(center_encoder_tracking_wheel_ports[0]),
          abs(center_encoder_tracking_wheel_ports[1]),
          util::is_negative(center_encoder_tracking_wheel_ports[0])),
      left_rotation_tracking_wheel(-1, -1),
      right_rotation_tracking_wheel(-1, -1),
      center_rotation_tracking_wheel(-1, -1) {
  for (auto i : left_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    left_tank_drive_motors.push_back(temp);
  }
  for (auto i : right_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    right_tank_drive_motors.push_back(temp);
  }
  tracker_type = tracker_encoder_wheel;
  chassis_type = tank_drive;
  drivetrain_cartidge_rpms = chassis_cartidge_rpms;
  drivetrain_gear_ratio = chassis_gear_ratio;
  drivetrain_wheel_diameter = chassis_wheel_diameter;
  drivetrain_wheel_circumference = drivetrain_wheel_diameter * M_PI;
  tracker_gear_ratio = tracking_wheel_gear_ratio;
  tracker_wheel_diameter = tracking_wheel_diameter;
  tracker_wheel_circumference = tracking_wheel_diameter * M_PI;
  calculate_tracker_variables();
}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 double tracking_wheel_gear_ratio,
                 double tracking_wheel_diameter, int expander_smart_port)
    : inertial_sensor(inertial_sensor_port),
      left_encoder_tracking_wheel(
          {expander_smart_port, abs(left_encoder_tracking_wheel_ports[0]),
           abs(left_encoder_tracking_wheel_ports[1])},
          util::is_negative(left_encoder_tracking_wheel_ports[0])),
      right_encoder_tracking_wheel(
          {expander_smart_port, abs(right_encoder_tracking_wheel_ports[0]),
           abs(right_encoder_tracking_wheel_ports[1])},
          util::is_negative(right_encoder_tracking_wheel_ports[0])),
      center_encoder_tracking_wheel(-1, -1, -1),
      left_rotation_tracking_wheel(-1, -1),
      right_rotation_tracking_wheel(-1, -1),
      center_rotation_tracking_wheel(-1, -1) {
  for (auto i : left_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    left_tank_drive_motors.push_back(temp);
  }
  for (auto i : right_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    right_tank_drive_motors.push_back(temp);
  }
  tracker_type = tracker_encoder_wheel;
  chassis_type = tank_drive;
  drivetrain_cartidge_rpms = chassis_cartidge_rpms;
  drivetrain_gear_ratio = chassis_gear_ratio;
  drivetrain_wheel_diameter = chassis_wheel_diameter;
  drivetrain_wheel_circumference = drivetrain_wheel_diameter * M_PI;
  tracker_gear_ratio = tracking_wheel_gear_ratio;
  tracker_wheel_diameter = tracking_wheel_diameter;
  tracker_wheel_circumference = tracking_wheel_diameter * M_PI;
  calculate_tracker_variables();
}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> center_encoder_tracking_wheel_ports,
                 double tracking_wheel_gear_ratio,
                 double tracking_wheel_diameter, int expander_smart_port)
    : inertial_sensor(inertial_sensor_port),
      left_encoder_tracking_wheel(
          {expander_smart_port, abs(left_encoder_tracking_wheel_ports[0]),
           abs(left_encoder_tracking_wheel_ports[1])},
          util::is_negative(left_encoder_tracking_wheel_ports[0])),
      right_encoder_tracking_wheel(
          {expander_smart_port, abs(right_encoder_tracking_wheel_ports[0]),
           abs(right_encoder_tracking_wheel_ports[1])},
          util::is_negative(right_encoder_tracking_wheel_ports[0])),
      center_encoder_tracking_wheel(
          {expander_smart_port, abs(center_encoder_tracking_wheel_ports[0]),
           abs(center_encoder_tracking_wheel_ports[1])},
          util::is_negative(center_encoder_tracking_wheel_ports[0])),

      left_rotation_tracking_wheel(-1, -1),
      right_rotation_tracking_wheel(-1, -1),
      center_rotation_tracking_wheel(-1, -1) {
  for (auto i : left_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    left_tank_drive_motors.push_back(temp);
  }
  for (auto i : right_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    right_tank_drive_motors.push_back(temp);
  }
  tracker_type = tracker_encoder_wheel;
  chassis_type = tank_drive;
  drivetrain_cartidge_rpms = chassis_cartidge_rpms;
  drivetrain_gear_ratio = chassis_gear_ratio;
  drivetrain_wheel_diameter = chassis_wheel_diameter;
  drivetrain_wheel_circumference = drivetrain_wheel_diameter * M_PI;
  tracker_gear_ratio = tracking_wheel_gear_ratio;
  tracker_wheel_diameter = tracking_wheel_diameter;
  tracker_wheel_circumference = tracking_wheel_diameter * M_PI;
  calculate_tracker_variables();
}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 int left_rotation_tracking_wheel_ports,
                 int right_rotation_tracking_wheel_ports,
                 double tracking_wheel_gear_ratio,
                 double tracking_wheel_diameter)
    : inertial_sensor(inertial_sensor_port),
      left_encoder_tracking_wheel(-1, -1, -1),
      right_encoder_tracking_wheel(-1, -1, -1),
      center_encoder_tracking_wheel(-1, -1, -1),
      left_rotation_tracking_wheel(
          left_rotation_tracking_wheel_ports,
          util::is_negative(left_rotation_tracking_wheel_ports)),
      right_rotation_tracking_wheel(
          right_rotation_tracking_wheel_ports,
          util::is_negative(right_rotation_tracking_wheel_ports)),
      center_rotation_tracking_wheel(-1, -1) {
  for (auto i : left_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    left_tank_drive_motors.push_back(temp);
  }
  for (auto i : right_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    right_tank_drive_motors.push_back(temp);
  }
  tracker_type = tracker_rotation_wheel;
  chassis_type = tank_drive;
  drivetrain_cartidge_rpms = chassis_cartidge_rpms;
  drivetrain_gear_ratio = chassis_gear_ratio;
  drivetrain_wheel_diameter = chassis_wheel_diameter;
  drivetrain_wheel_circumference = drivetrain_wheel_diameter * M_PI;
  tracker_gear_ratio = tracking_wheel_gear_ratio;
  tracker_wheel_diameter = tracking_wheel_diameter;
  tracker_wheel_circumference = tracking_wheel_diameter * M_PI;
  calculate_tracker_variables();
}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 int left_rotation_tracking_wheel_ports,
                 int right_rotation_tracking_wheel_ports,
                 int center_rotation_tracking_wheel_ports,
                 double tracking_wheel_gear_ratio,
                 double tracking_wheel_diameter)
    : inertial_sensor(inertial_sensor_port),
      left_encoder_tracking_wheel(-1, -1, -1),
      right_encoder_tracking_wheel(-1, -1, -1),
      center_encoder_tracking_wheel(-1, -1, -1),
      left_rotation_tracking_wheel(
          left_rotation_tracking_wheel_ports,
          util::is_negative(left_rotation_tracking_wheel_ports)),
      right_rotation_tracking_wheel(
          right_rotation_tracking_wheel_ports,
          util::is_negative(right_rotation_tracking_wheel_ports)),
      center_rotation_tracking_wheel(
          center_rotation_tracking_wheel_ports,
          util::is_negative(center_rotation_tracking_wheel_ports)) {
  for (auto i : left_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    left_tank_drive_motors.push_back(temp);
  }
  for (auto i : right_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::is_negative(i));
    right_tank_drive_motors.push_back(temp);
  }
  tracker_type = tracker_rotation_wheel;
  chassis_type = tank_drive;
  drivetrain_cartidge_rpms = chassis_cartidge_rpms;
  drivetrain_gear_ratio = chassis_gear_ratio;
  drivetrain_wheel_diameter = chassis_wheel_diameter;
  drivetrain_wheel_circumference = drivetrain_wheel_diameter * M_PI;
  tracker_gear_ratio = tracking_wheel_gear_ratio;
  tracker_wheel_diameter = tracking_wheel_diameter;
  tracker_wheel_circumference = tracking_wheel_diameter * M_PI;
  calculate_tracker_variables();
}
void Chassis::calculate_tracker_variables() {
  if (tracker_type == 2 || tracker_type == 3) {
    tracker_tick_per_revolution = drivetrain_cartidge_rpms * tracker_gear_ratio;
  } else if (tracker_type == 1) {
    tracker_tick_per_revolution =
        ((50.0 * (3600.0 / drivetrain_cartidge_rpms)) * tracker_gear_ratio);
  }
  tracker_tick_per_revolution =
      (tracker_tick_per_inch / tracker_wheel_circumference);
}
}; // namespace apollo