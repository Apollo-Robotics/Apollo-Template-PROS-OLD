#pragma once
#include "api.h"
namespace apollo {
class Autonomous {
public:
  Autonomous();
  Autonomous(std::string autonomous_name,
             std::function<void()> autonomous_function);
  std::string Name;
  std::function<void()> call_autonomous;
};
}; // namespace apollo