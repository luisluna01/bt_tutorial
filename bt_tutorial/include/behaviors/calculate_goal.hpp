#pragma once

#include "behaviortree_cpp/action_node.h"
#include "position_2d_type.hpp"

class CalculateGoal : public BT::SyncActionNode
{
public:
  CalculateGoal(const std::string& name, const BT::NodeConfig& config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;
};