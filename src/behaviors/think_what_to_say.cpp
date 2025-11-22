#include "behaviors/think_what_to_say.hpp"

ThinkWhatToSay::ThinkWhatToSay(const std::string& name, const BT::NodeConfig config)
  : BT::SyncActionNode(name, config)
{}

BT::PortsList ThinkWhatToSay::providedPorts()
{
  return { BT::OutputPort<std::string>("text") };
}

// Action node writes a value into the port "text"
BT::NodeStatus ThinkWhatToSay::tick()
{
  // The output may change at each tick()
  setOutput("text", "The answer is 42");

  return BT::NodeStatus::SUCCESS;
}
