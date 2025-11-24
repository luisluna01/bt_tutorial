#include "behaviors/calculate_goal.hpp"

CalculateGoal::CalculateGoal(const std::string& name, const BT::NodeConfig& config)
  : SyncActionNode(name, config)
{}

BT::PortsList CalculateGoal::providedPorts()
{
  return { BT::OutputPort<Position2D>("goal") };
}

BT::NodeStatus CalculateGoal::tick()
{
  Position2D mygoal = {1.1, 2.3};
  setOutput<Position2D>("goal", mygoal);

  return BT::NodeStatus::SUCCESS;
}