#pragma once

#include <behaviortree_ros2/bt_action_node.hpp>
#include "action_tutorials_interfaces/action/fibonacci.hpp"

using Fibonacci = action_tutorials_interfaces::action::Fibonacci;
using GoalHandleFibonacci = rclcpp_action::ServerGoalHandle<Fibonacci>;

class FibonacciAction: public BT::RosActionNode<Fibonacci>
{
public:
  FibonacciAction(
    const std::string& name,
    const BT::NodeConfig& config,
    const BT::RosNodeParams& params);


  static BT::PortsList providedPorts();

  bool setGoal(RosActionNode::Goal& goal) override;

  BT::NodeStatus onResultReceived(const RosActionNode::WrappedResult& wr) override;

  virtual BT::NodeStatus onFailure(BT::ActionNodeErrorCode error) override;

  BT::NodeStatus onFeedback(const std::shared_ptr<const Feedback> feedback) override;
};