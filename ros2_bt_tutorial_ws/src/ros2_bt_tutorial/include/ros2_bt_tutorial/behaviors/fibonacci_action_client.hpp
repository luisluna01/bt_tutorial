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

  // Callback executed when there was an error at the level of communication between the client and
  // server. This will set this TreeNode to SUCCESS or FAILURE based on the return value. It will
  // return FAILURE by default
  virtual BT::NodeStatus onFailure(BT::ActionNodeErrorCode error) override;

  // Callback executed for each feedback. Typically used to set the TreeNode to RUNNING, but it can
  // be modified to abort the action based on the value of the feedback and set the TreeNode to
  // SUCCESS or FAILURE. The cancel request will be automatically sent to the server.
  BT::NodeStatus onFeedback(const std::shared_ptr<const Feedback> feedback) override;
};