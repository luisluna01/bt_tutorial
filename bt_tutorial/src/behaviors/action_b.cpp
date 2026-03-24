#include "behaviors/action_b.hpp"


ActionB::ActionB(
  const std::string& name, const BT::NodeConfig& config
):
  SyncActionNode(name, config)
{}


BT::PortsList ActionB::providedPorts()
{
  return {};
}


BT::NodeStatus ActionB::tick()
{
  std::cout << "[ActionB]:\n" << " Arg1: " << _arg1 << "\n Arg2: " << _arg2 << std::endl;

  return BT::NodeStatus::SUCCESS;
}


void ActionB::initialize(int arg_int, const std::string& arg_str)
{
  _arg1 = arg_int;
  _arg2 = arg_str;
}