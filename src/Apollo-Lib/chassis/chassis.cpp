#include "chassis/chassis.hpp"
#include "main.h"
#include "util.hpp"
namespace apollo {
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio) {
  left_encoder_tracking_wheel = nullptr;
  right_encoder_tracking_wheel = nullptr;
  center_encoder_tracking_wheel = nullptr;
  left_rotation_tracking_wheel = nullptr;
  right_rotation_tracking_wheel = nullptr;
  center_rotation_tracking_wheel = nullptr;
  inertial_sensor = nullptr;
  for (auto i : left_drivetrain_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i));
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
  drivetrain_wheel_circumference =
      calculate_wheel_circumference(drivetrain_wheel_diameter);
  tracker_wheel_diameter = drivetrain_wheel_diameter;
  tracker_wheel_circumference = drivetrain_wheel_circumference;
  tracker_gear_ratio = drivetrain_gear_ratio;
  tracker_tick_per_inch = calculate_tracker_tick_per_inch();
  tracker_tick_per_revolution = calculate_tracker_tick_per_revoution();
}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port) {}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 double tracker_gear_ratio, double tracker_wheel_diameter) {}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> center_encoder_tracking_wheel_ports,
                 double tracker_gear_ratio, double tracker_wheel_diameter) {}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 double tracker_gear_ratio, double tracker_wheel_diameter,
                 int expander_smart_port) {}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> center_encoder_tracking_wheel_ports,
                 double tracker_gear_ratio, double tracker_wheel_diameter,
                 int expander_smart_port) {}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 int left_rotation_tracking_wheel_ports,
                 int right_rotation_tracking_wheel_ports,
                 double tracker_gear_ratio, double tracker_wheel_diameter) {}
Chassis::Chassis(std::vector<int> left_drivetrain_motor_ports,
                 std::vector<int> right_drivetrain_motor_ports,
                 int chassis_cartidge_rpms, double chassis_wheel_diameter,
                 double chassis_gear_ratio, int inertial_sensor_port,
                 int left_rotation_tracking_wheel_ports,
                 int right_rotation_tracking_wheel_ports,
                 int center_rotation_tracking_wheel_ports,
                 double tracker_gear_ratio, double tracker_wheel_diameter) {}
void Chassis::initialize() {}
void Chassis::set_defaults() {}
void Chassis::set_tank_control() {}
void Chassis::set_arcade_standard_control() {}
void Chassis::set_arcade_flipped_control() {}
void Chassis::set_joystick_threshold(int threshold) {}
void Chassis::set_chassis_brake_mode(pros::motor_brake_mode_e_t brake_mode) {}
void Chassis::reset_drive_sensors() {}
void Chassis::reset_inertial_sensor(int heading) {}
double Chassis::get_inertial_sensor_heading() {
  return inertial_sensor->get_heading();
}
bool Chassis::is_inertial_sensor_calibrating() {
  inertial_sensor->reset();
  int time = 0;
  while (true) {
    time += util::delay_time;

    if (time >= 2000) {
      if (!(inertial_sensor->get_status() &
            pros::c::E_IMU_STATUS_CALIBRATING)) {
        break;
      }
      if (time >= 3000) {
        printf("No IMU plugged in, (took %d ms to realize that)\n", time);
        return false;
      }
    }
    pros::delay(util::delay_time);
  }
  master.rumble(".");
  printf("IMU is done calibrating (took %d ms)\n", time);
  return true;
}
int Chassis::left_sensor() {
  if (tracker_type == 2) {
    return left_encoder_tracking_wheel->get_value();
  } else if (tracker_type == 3) {
    return left_rotation_tracking_wheel->get_position();
  }
  return left_tank_drive_motors.front().get_position();
}
int Chassis::left_velocity() {
  return left_tank_drive_motors.front().get_actual_velocity();
}
double Chassis::left_mA() {
  return left_tank_drive_motors.front().get_current_draw();
}
bool Chassis::is_left_drive_over_current() {
  return left_tank_drive_motors.front().is_over_current();
}
int Chassis::right_sensor() {
  if (tracker_type == 2) {
    return right_encoder_tracking_wheel->get_value();
  } else if (tracker_type == 3) {
    return right_rotation_tracking_wheel->get_position();
  }
  return right_tank_drive_motors.front().get_position();
}
int Chassis::right_velocity() {
  return right_tank_drive_motors.front().get_actual_velocity();
}
double Chassis::right_mA() {
  return right_tank_drive_motors.front().get_current_draw();
}
bool Chassis::is_right_drive_over_current() {
  return right_tank_drive_motors.front().is_over_current();
}
double Chassis::calculate_wheel_circumference(int diameter) {
  return diameter * M_PI;
}
double Chassis::calculate_tracker_tick_per_revoution() {
  if (tracker_type == 2 || tracker_type == 3) {
    return tracker_tick_per_revolution =
               drivetrain_cartidge_rpms * tracker_gear_ratio;
  } else {
    return tracker_tick_per_revolution =
               ((50.0 * (3600.0 / drivetrain_cartidge_rpms)) *
                drivetrain_gear_ratio);
  }
}
double Chassis::calculate_tracker_tick_per_inch() {
  return tracker_tick_per_inch =
             tracker_tick_per_revolution / tracker_wheel_circumference;
}
}; // namespace apollo