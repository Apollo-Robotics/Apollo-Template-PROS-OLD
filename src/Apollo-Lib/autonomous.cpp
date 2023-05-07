#include "main.h"
Autonomous::Autonomous() {
  Name = "";
  call_autonomous = nullptr;
}
Autonomous::Autonomous(std::string autonomous_name, std::function<void()> autonomous_function) {
  Name = autonomous_name;
  call_autonomous = autonomous_function;
}