#include "main.h"
apollo::Selector::Selector() {
  total_auton = 0;
  selected_auton = 0;
  default_auton = 0;
  all_autons = {};
}
apollo::Selector::Selector(std::vector<Autonomous> Autons) {
  total_auton = Autons.size();
  selected_auton = default_auton;
  all_autons = {};
  all_autons.assign(Autons.begin(), Autons.end());
}
void apollo::Selector::print_selected_autonomous() {
  if (total_auton == 0)
    return;
  for (int i = 0; i < 8; i++)
    pros::lcd::clear_line(i);
  // ez::print_to_screen("Page " + std::to_string(selected_autonomous + 1) +
  // "\n" + Autons[selected_autonomous].Name);
}
void apollo::Selector::call_selected_autonomous() {
  if (total_auton == 0) {
    return;
  }
  all_autons[selected_auton].call_autonomous();
}
void apollo::Selector::add_autons(std::vector<Autonomous> Autons) {
  total_auton += Autons.size();
  selected_auton = 0;
  Autons.assign(Autons.begin(), Autons.end());
}