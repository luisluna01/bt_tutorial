// This node shows an example for performing asynchronous actions using the StatefulActionNode
#pragma once

#include "behaviortree_cpp/action_node.h"
#include "pose_2d.hpp"

class MoveBase : public BT::StatefulActionNode
{
public:
  // Any TreeNode with ports must have a constructor with this signature
  MoveBase(const std::string& name, const BT::NodeConfig& config);

  // Mandatory to define as static method
  static BT::PortsList providedPorts();

  // Function runs on first tick
  BT::NodeStatus onStart() override;

  // If onStart() returned `RUNNING`, subsequent ticks will run this method until a SUCCESS or
  // FAILURE is returned
  BT::NodeStatus onRunning() override;

  // Callback to execute if the action was aborted by another node
  void onHalted() override;
  
private:
  Pose2D goal_;
  std::chrono::system_clock::time_point completion_time_;
};
