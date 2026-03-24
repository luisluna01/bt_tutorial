// Example of custom synchronous action node without ports. Only returns SUCCESS or FAILURE
#pragma once

#include "behaviortree_cpp/action_node.h"

class ApproachObject : public BT::SyncActionNode
{
public:
  ApproachObject(const std::string& name);

  // Must override virtual function tick()
  BT::NodeStatus tick() override;
};