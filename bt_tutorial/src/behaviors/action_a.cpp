#include "behaviors/action_a.hpp"


ActionA::ActionA(
  const std::string& name, const BT::NodeConfig& config, int arg_int, std::string arg_str
):
  BT::SyncActionNode(name, config), _arg1(arg_int), _arg2(arg_str)
{}


BT::PortsList ActionA::providedPorts()
{
  return {};
}


BT::NodeStatus ActionA::tick()
{
  std::cout << "[ActionA]:\n" << " Arg1: " << _arg1 << "\n Arg2: " << _arg2 << std::endl;

  return BT::NodeStatus::SUCCESS;
}