#include "behaviors/say_something.hpp"

SaySomething::SaySomething(const std::string& name, const BT::NodeConfig& config)
  : BT::SyncActionNode(name, config)
{}

BT::PortsList SaySomething::providedPorts()
{
  return {BT::InputPort<std::string>("message")};
}

BT::NodeStatus SaySomething::tick()
{
  // Recommended to call getInput() in tick() and not constructor
  BT::Expected<std::string> msg = getInput<std::string>("message");

  // Check if expected is valid
  if (!msg)
  {
    throw BT::RuntimeError("missing required input [message]: ", msg.error());
  }

  // Use value() method to extract valid message
  std::cout << "Robot says: " << msg.value() << std::endl;

  return BT::NodeStatus::SUCCESS;
}

