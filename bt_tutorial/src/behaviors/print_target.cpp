#include "behaviors/print_target.hpp"

PrintTarget::PrintTarget(const std::string& name, const BT::NodeConfig& config)
  : SyncActionNode(name, config)
{}

BT::PortsList PrintTarget::providedPorts()
{
  // A port can have human readable description
  const char* description = "Simply print the goal on console...";

  return { BT::InputPort<Position2D>("target", description) };
}

BT::NodeStatus PrintTarget::tick()
{
  auto res = getInput<Position2D>("target");
  if(!res)
  {
    throw BT::RuntimeError("error reading port [target]:", res.error());
  }
  Position2D target = res.value();
  printf("Target positions: [ %.1f, %.1f ]\n", target.x, target.y );
  
  return BT::NodeStatus::SUCCESS;
}