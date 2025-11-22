#include "behaviors/check_battery.hpp"

CheckBattery::CheckBattery(const std::string& name)
: ConditionNode(name, {})
{}

BT::NodeStatus CheckBattery::tick()
{
  std::cout << "[ Battery: OK ]" << std::endl;

  return BT::NodeStatus::SUCCESS;
}