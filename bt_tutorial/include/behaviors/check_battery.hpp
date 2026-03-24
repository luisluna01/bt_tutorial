// Example behavior is a SimpleCondition node and can be written as a simple function
#pragma once

#include "behaviortree_cpp/condition_node.h"

class CheckBattery : public BT::ConditionNode
{
public:
  CheckBattery(const std::string& name);

  BT::NodeStatus tick() override;
};
