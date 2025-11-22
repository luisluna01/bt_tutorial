#include "behaviors/check_battery.hpp"

BT::NodeStatus CheckBattery()
{
  std::cout << "[ Battery: OK ]" << std::endl;

  return BT::NodeStatus::SUCCESS;
}
