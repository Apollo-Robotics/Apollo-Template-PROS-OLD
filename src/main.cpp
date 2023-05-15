#include "main.h"
using namespace apollo;
Chassis chassis(
    // Left Chassis Motor Ports:
    //     Ports of your left drivetrain Motors (- will reverse a motor's
    //     direction!)
    {1, 2, 3},
    // Right Chassis Motor Ports:
    //     Ports of your right drivetrain Motors (- will reverse a motor's
    //     direction!)
    {-4, -5, -6},
    // Cartridge RPM's:
    //     RPM's of your chassis!
    //     Red is 100 RPMs
    //     Green is 200 RPMs
    //     Blue is 600 RPMs
    600,
    // Wheel Diameter:
    //     Diameter of your drivetrain's wheels!
    //     (Remeber 4" wheels are actually 4.125")
    3.25,
    // Gear Ratio:
    //     Gear ratio of your drivetrain!
    //     (Remember gear ratio is ouptut/input)
    1.66,
    // Inertial Sensor Port:
    //     Port of your inertial sensor!
    7
    // Left Tracking Wheel Ports:
    //     Encoders used for odometry!
    //     Uncomment if using Encoders
    //       ,{1, 2},
    //     Uncomment if using Rotation Sensors
    //       8,
    // Left Tracking Wheel Ports:
    //     Encoders used for odometry!
    //     Uncomment if using Encoders
    //       {3,4},
    //     Uncomment if using Rotation Sensors
    //       9,
    // Left Tracking Wheel Ports:
    //     Encoders used for odometry!
    //     Uncomment if using Encoders
    //       {5, 6},
    //     Uncomment if using Rotation Sensors
    //       10,
    // Tracking Wheel Gear Ratio:
    //     Gear ratio used on the tracking wheels!
    //     Uncomment if using tracking wheels
    //      1
    // Tracking Wheel Diameter:
    //     Diameter of tracking wheels!
    //     Uncomment if using tracking wheels
    //      2.75,
    // Expander Smart Port:
    //     V5 smart port of the 3-wire expander, if 3-wire trackers are plugged
    //     into them
    //     Uncomment if using a 3-wire expander
    //      11
);

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
  while (true) {
    pros::delay(apollo::util::delay_time);
  }
}
