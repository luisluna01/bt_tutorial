// This example behavior shows how methods can be wrapped into an action node.
// This example behavior also uses a SimpleActionNode and can be written as a simple funciton
#pragma once

#include "behaviortree_cpp/action_node.h"

class GripperInterface
{
public:
  GripperInterface();

  BT::NodeStatus open();

  BT::NodeStatus close();

private:
  bool _open;
};