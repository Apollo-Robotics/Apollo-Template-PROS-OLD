#pragma once
#include "Apollo-Lib/autonomous.hpp"
#include "api.h"

namespace apollo {
class Selector {
public:
  std::vector<Autonomous> all_autons;
  int selected_auton;
  int total_auton;
  int default_auton;
  Selector();
  Selector(std::vector<Autonomous> Autons);
  void initialize();
  void call_selected_autonomous();
  void print_selected_autonomous();
  void add_autons(std::vector<Autonomous> Autons);
};
}; // namespace apollo