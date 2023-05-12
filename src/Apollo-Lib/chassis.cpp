#include "main.h"
namespace apollo {
Chassis::Chassis(std::vector<int> left_drive_motor_ports,
                 std::vector<int> right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms) {
  chassis_type = tank_drive;
  for (auto i : left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    left_drive_motors.push_back(temp);
  }
  for (auto i : right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    right_drive_motors.push_back(temp);
  }
  inertial_sensor = nullptr;
}
Chassis::Chassis(std::vector<int> left_drive_motor_ports,
                 std::vector<int> right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port) {
  chassis_type = tank_drive;
  for (auto i : left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    left_drive_motors.push_back(temp);
  }
  for (auto i : right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
}
Chassis::Chassis(std::vector<int> left_drive_motor_ports,
                 std::vector<int> right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports) {
  chassis_type = tank_drive;
  for (auto i : left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    left_drive_motors.push_back(temp);
  }
  for (auto i : right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_encoder_tracking_wheel =
      pros::ADIEncoder(abs(left_encoder_tracking_wheel_ports[0]),
                       abs(left_encoder_tracking_wheel_ports[1]),
                       util::is_negative(left_encoder_tracking_wheel_ports[0]));
  left_encoder_tracking_wheel = &temp_left_encoder_tracking_wheel;
  auto temp_right_encoder_tracking_wheel = pros::ADIEncoder(
      abs(right_encoder_tracking_wheel_ports[0]),
      abs(right_encoder_tracking_wheel_ports[1]),
      util::is_negative(right_encoder_tracking_wheel_ports[0]));
  right_encoder_tracking_wheel = &temp_right_encoder_tracking_wheel;
}
Chassis::Chassis(std::vector<int> left_drive_motor_ports,
                 std::vector<int> right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> center_encoder_tracking_wheel_ports) {
  chassis_type = tank_drive;
  for (auto i : left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    left_drive_motors.push_back(temp);
  }
  for (auto i : right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_encoder_tracking_wheel =
      pros::ADIEncoder(abs(left_encoder_tracking_wheel_ports[0]),
                       abs(left_encoder_tracking_wheel_ports[1]),
                       util::is_negative(left_encoder_tracking_wheel_ports[0]));
  left_encoder_tracking_wheel = &temp_left_encoder_tracking_wheel;
  auto temp_right_encoder_tracking_wheel = pros::ADIEncoder(
      abs(right_encoder_tracking_wheel_ports[0]),
      abs(right_encoder_tracking_wheel_ports[1]),
      util::is_negative(right_encoder_tracking_wheel_ports[0]));
  right_encoder_tracking_wheel = &temp_right_encoder_tracking_wheel;
  auto temp_center_encoder_tracking_wheel = pros::ADIEncoder(
      abs(center_encoder_tracking_wheel_ports[0]),
      abs(center_encoder_tracking_wheel_ports[1]),
      util::is_negative(center_encoder_tracking_wheel_ports[0]));
  center_encoder_tracking_wheel = &temp_center_encoder_tracking_wheel;
}
Chassis::Chassis(std::vector<int> left_drive_motor_ports,
                 std::vector<int> right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port, int expander_port,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> left_encoder_tracking_wheel_ports) {
  chassis_type = tank_drive;
  for (auto i : left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    left_drive_motors.push_back(temp);
  }
  for (auto i : right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(left_encoder_tracking_wheel_ports[0]),
       abs(left_encoder_tracking_wheel_ports[1])},
      util::is_negative(left_encoder_tracking_wheel_ports[0]));
  left_encoder_tracking_wheel = &temp_left_encoder_tracking_wheel;
  auto temp_right_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(right_encoder_tracking_wheel_ports[0]),
       abs(right_encoder_tracking_wheel_ports[1])},
      util::is_negative(right_encoder_tracking_wheel_ports[0]));
  right_encoder_tracking_wheel = &temp_right_encoder_tracking_wheel;
}
Chassis::Chassis(std::vector<int> left_drive_motor_ports,
                 std::vector<int> right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port, int expander_port,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> center_encoder_tracking_wheel_ports) {
  chassis_type = tank_drive;
  for (auto i : left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    left_drive_motors.push_back(temp);
  }
  for (auto i : right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(left_encoder_tracking_wheel_ports[0]),
       abs(left_encoder_tracking_wheel_ports[1])},
      util::is_negative(left_encoder_tracking_wheel_ports[0]));
  left_encoder_tracking_wheel = &temp_left_encoder_tracking_wheel;
  auto temp_right_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(right_encoder_tracking_wheel_ports[0]),
       abs(right_encoder_tracking_wheel_ports[1])},
      util::is_negative(right_encoder_tracking_wheel_ports[0]));
  right_encoder_tracking_wheel = &temp_right_encoder_tracking_wheel;
  auto temp_center_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(center_encoder_tracking_wheel_ports[0]),
       abs(center_encoder_tracking_wheel_ports[1])},
      util::is_negative(center_encoder_tracking_wheel_ports[0]));
  center_encoder_tracking_wheel = &temp_center_encoder_tracking_wheel;
}
Chassis::Chassis(std::vector<int> left_drive_motor_ports,
                 std::vector<int> right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port,
                 int right_rotation_tracking_wheel_port,
                 int left_rotation_tracking_wheel_port) {
  chassis_type = tank_drive;
  for (auto i : left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    left_drive_motors.push_back(temp);
  }
  for (auto i : right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_rotation_tracking_wheel =
      pros::Rotation(left_rotation_tracking_wheel_port);
  left_rotation_tracking_wheel = &temp_left_rotation_tracking_wheel;
  auto temp_right_rotation_tracking_wheel =
      pros::Rotation(right_rotation_tracking_wheel_port);
  right_rotation_tracking_wheel = &temp_right_rotation_tracking_wheel;
}
Chassis::Chassis(std::vector<int> left_drive_motor_ports,
                 std::vector<int> right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port,
                 int right_rotation_tracking_wheel_port,
                 int left_rotation_tracking_wheel_port,
                 int center_rotation_tracking_wheel_port) {
  chassis_type = tank_drive;
  for (auto i : left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    left_drive_motors.push_back(temp);
  }
  for (auto i : right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_rotation_tracking_wheel =
      pros::Rotation(left_rotation_tracking_wheel_port);
  left_rotation_tracking_wheel = &temp_left_rotation_tracking_wheel;
  auto temp_right_rotation_tracking_wheel =
      pros::Rotation(right_rotation_tracking_wheel_port);
  right_rotation_tracking_wheel = &temp_right_rotation_tracking_wheel;
  auto temp_center_rotation_tracking_wheel =
      pros::Rotation(center_rotation_tracking_wheel_port);
  center_rotation_tracking_wheel = &temp_center_rotation_tracking_wheel;
}
Chassis::Chassis(std::vector<int> front_left_drive_motor_ports,
                 std::vector<int> back_left_drive_motor_ports,
                 std::vector<int> front_right_drive_motor_ports,
                 std::vector<int> back_right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms) {
  chassis_type = holonomic_drive;
  for (auto i : front_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_left_drive_motors.push_back(temp);
  }
  for (auto i : back_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_left_drive_motors.push_back(temp);
  }
  for (auto i : front_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_right_drive_motors.push_back(temp);
  }
  for (auto i : back_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_right_drive_motors.push_back(temp);
  }
  inertial_sensor = nullptr;
}
Chassis::Chassis(std::vector<int> front_left_drive_motor_ports,
                 std::vector<int> back_left_drive_motor_ports,
                 std::vector<int> front_right_drive_motor_ports,
                 std::vector<int> back_right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port) {
  chassis_type = holonomic_drive;
  for (auto i : front_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_left_drive_motors.push_back(temp);
  }
  for (auto i : back_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_left_drive_motors.push_back(temp);
  }
  for (auto i : front_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_right_drive_motors.push_back(temp);
  }
  for (auto i : back_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
}
Chassis::Chassis(std::vector<int> front_left_drive_motor_ports,
                 std::vector<int> back_left_drive_motor_ports,
                 std::vector<int> front_right_drive_motor_ports,
                 std::vector<int> back_right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> left_encoder_tracking_wheel_ports) {
  chassis_type = holonomic_drive;
  for (auto i : front_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_left_drive_motors.push_back(temp);
  }
  for (auto i : back_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_left_drive_motors.push_back(temp);
  }
  for (auto i : front_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_right_drive_motors.push_back(temp);
  }
  for (auto i : back_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_encoder_tracking_wheel =
      pros::ADIEncoder(abs(left_encoder_tracking_wheel_ports[0]),
                       abs(left_encoder_tracking_wheel_ports[1]),
                       util::is_negative(left_encoder_tracking_wheel_ports[0]));
  left_encoder_tracking_wheel = &temp_left_encoder_tracking_wheel;
  auto temp_right_encoder_tracking_wheel = pros::ADIEncoder(
      abs(right_encoder_tracking_wheel_ports[0]),
      abs(right_encoder_tracking_wheel_ports[1]),
      util::is_negative(right_encoder_tracking_wheel_ports[0]));
  right_encoder_tracking_wheel = &temp_right_encoder_tracking_wheel;
}
Chassis::Chassis(std::vector<int> front_left_drive_motor_ports,
                 std::vector<int> back_left_drive_motor_ports,
                 std::vector<int> front_right_drive_motor_ports,
                 std::vector<int> back_right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> center_encoder_tracking_wheel_ports) {
  chassis_type = holonomic_drive;
  for (auto i : front_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_left_drive_motors.push_back(temp);
  }
  for (auto i : back_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_left_drive_motors.push_back(temp);
  }
  for (auto i : front_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_right_drive_motors.push_back(temp);
  }
  for (auto i : back_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_encoder_tracking_wheel =
      pros::ADIEncoder(abs(left_encoder_tracking_wheel_ports[0]),
                       abs(left_encoder_tracking_wheel_ports[1]),
                       util::is_negative(left_encoder_tracking_wheel_ports[0]));
  left_encoder_tracking_wheel = &temp_left_encoder_tracking_wheel;
  auto temp_right_encoder_tracking_wheel = pros::ADIEncoder(
      abs(right_encoder_tracking_wheel_ports[0]),
      abs(right_encoder_tracking_wheel_ports[1]),
      util::is_negative(right_encoder_tracking_wheel_ports[0]));
  right_encoder_tracking_wheel = &temp_right_encoder_tracking_wheel;
  auto temp_center_encoder_tracking_wheel = pros::ADIEncoder(
      abs(center_encoder_tracking_wheel_ports[0]),
      abs(center_encoder_tracking_wheel_ports[1]),
      util::is_negative(center_encoder_tracking_wheel_ports[0]));
  center_encoder_tracking_wheel = &temp_center_encoder_tracking_wheel;
}
Chassis::Chassis(std::vector<int> front_left_drive_motor_ports,
                 std::vector<int> back_left_drive_motor_ports,
                 std::vector<int> front_right_drive_motor_ports,
                 std::vector<int> back_right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port, int expander_port,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> left_encoder_tracking_wheel_ports) {
  chassis_type = holonomic_drive;
  for (auto i : front_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_left_drive_motors.push_back(temp);
  }
  for (auto i : back_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_left_drive_motors.push_back(temp);
  }
  for (auto i : front_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_right_drive_motors.push_back(temp);
  }
  for (auto i : back_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(left_encoder_tracking_wheel_ports[0]),
       abs(left_encoder_tracking_wheel_ports[1])},
      util::is_negative(left_encoder_tracking_wheel_ports[0]));
  left_encoder_tracking_wheel = &temp_left_encoder_tracking_wheel;
  auto temp_right_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(right_encoder_tracking_wheel_ports[0]),
       abs(right_encoder_tracking_wheel_ports[1])},
      util::is_negative(right_encoder_tracking_wheel_ports[0]));
  right_encoder_tracking_wheel = &temp_right_encoder_tracking_wheel;
}
Chassis::Chassis(std::vector<int> front_left_drive_motor_ports,
                 std::vector<int> back_left_drive_motor_ports,
                 std::vector<int> front_right_drive_motor_ports,
                 std::vector<int> back_right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port, int expander_port,
                 std::vector<int> right_encoder_tracking_wheel_ports,
                 std::vector<int> left_encoder_tracking_wheel_ports,
                 std::vector<int> center_encoder_tracking_wheel_ports) {
  chassis_type = holonomic_drive;
  for (auto i : front_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_left_drive_motors.push_back(temp);
  }
  for (auto i : back_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_left_drive_motors.push_back(temp);
  }
  for (auto i : front_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_right_drive_motors.push_back(temp);
  }
  for (auto i : back_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(left_encoder_tracking_wheel_ports[0]),
       abs(left_encoder_tracking_wheel_ports[1])},
      util::is_negative(left_encoder_tracking_wheel_ports[0]));
  left_encoder_tracking_wheel = &temp_left_encoder_tracking_wheel;
  auto temp_right_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(right_encoder_tracking_wheel_ports[0]),
       abs(right_encoder_tracking_wheel_ports[1])},
      util::is_negative(right_encoder_tracking_wheel_ports[0]));
  right_encoder_tracking_wheel = &temp_right_encoder_tracking_wheel;
  auto temp_center_encoder_tracking_wheel = pros::ADIEncoder(
      {expander_port, abs(center_encoder_tracking_wheel_ports[0]),
       abs(center_encoder_tracking_wheel_ports[1])},
      util::is_negative(center_encoder_tracking_wheel_ports[0]));
  center_encoder_tracking_wheel = &temp_center_encoder_tracking_wheel;
}
Chassis::Chassis(std::vector<int> front_left_drive_motor_ports,
                 std::vector<int> back_left_drive_motor_ports,
                 std::vector<int> front_right_drive_motor_ports,
                 std::vector<int> back_right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port,
                 int right_rotation_tracking_wheel_port,
                 int left_rotation_tracking_wheel_port) {
  for (auto i : front_left_drive_motor_ports) {
    chassis_type = holonomic_drive;
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_left_drive_motors.push_back(temp);
  }
  for (auto i : back_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_left_drive_motors.push_back(temp);
  }
  for (auto i : front_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_right_drive_motors.push_back(temp);
  }
  for (auto i : back_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_rotation_tracking_wheel =
      pros::Rotation(left_rotation_tracking_wheel_port);
  left_rotation_tracking_wheel = &temp_left_rotation_tracking_wheel;
  auto temp_right_rotation_tracking_wheel =
      pros::Rotation(right_rotation_tracking_wheel_port);
  right_rotation_tracking_wheel = &temp_right_rotation_tracking_wheel;
}
Chassis::Chassis(std::vector<int> front_left_drive_motor_ports,
                 std::vector<int> back_left_drive_motor_ports,
                 std::vector<int> front_right_drive_motor_ports,
                 std::vector<int> back_right_drive_motor_ports,
                 double wheel_diameter, double gear_ratio, int cartidge_rpms,
                 int inertial_sensor_port,
                 int right_rotation_tracking_wheel_port,
                 int left_rotation_tracking_wheel_port,
                 int center_rotation_tracking_wheel_port) {
  chassis_type = holonomic_drive;
  for (auto i : front_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_left_drive_motors.push_back(temp);
  }
  for (auto i : back_left_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_left_drive_motors.push_back(temp);
  }
  for (auto i : front_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    front_right_drive_motors.push_back(temp);
  }
  for (auto i : back_right_drive_motor_ports) {
    pros::Motor temp = pros::Motor(abs(i), util::reverse(i));
    back_right_drive_motors.push_back(temp);
  }
  pros::Imu temp_inertial(inertial_sensor_port);
  inertial_sensor = &temp_inertial;
  auto temp_left_rotation_tracking_wheel =
      pros::Rotation(left_rotation_tracking_wheel_port);
  left_rotation_tracking_wheel = &temp_left_rotation_tracking_wheel;
  auto temp_right_rotation_tracking_wheel =
      pros::Rotation(right_rotation_tracking_wheel_port);
  right_rotation_tracking_wheel = &temp_right_rotation_tracking_wheel;
  auto temp_center_rotation_tracking_wheel =
      pros::Rotation(center_rotation_tracking_wheel_port);
  center_rotation_tracking_wheel = &temp_center_rotation_tracking_wheel;
}

}; // namespace apollo