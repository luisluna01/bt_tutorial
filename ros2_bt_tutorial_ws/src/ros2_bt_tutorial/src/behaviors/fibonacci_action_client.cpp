#include "ros2_bt_tutorial/behaviors/fibonacci_action_client.hpp"


FibonacciAction::FibonacciAction(
  const std::string& name,
  const BT::NodeConfig& config,
  const BT::RosNodeParams& params
):
  RosActionNode<Fibonacci>(name, config, params)
{}


// The specific ports of this Derived class should be merged with the ports of the base class, using
// RosActionNode::providedBasicPorts() 
BT::PortsList FibonacciAction::providedPorts()
{
  return providedBasicPorts({BT::InputPort<unsigned>("order")});
}


// Called when this TreeNode is ticked . It should send a request to the action server
bool FibonacciAction::setGoal(RosActionNode::Goal& goal)
{
  getInput("order", goal.order);

  // return true if the goal was set correctly
  return true;
}


// Callback invoked when action reply is received. This will set this TreeNode to either
// SUCCESS or FAILURE depending on the reply
BT::NodeStatus FibonacciAction::onResultReceived(const RosActionNode::WrappedResult& wr)
{
  std::stringstream ss;

  ss << "Result received: ";
  for (auto number : wr.result->sequence) {
    ss << number << " ";
  }
  RCLCPP_INFO(logger(), ss.str().c_str());

  return BT::NodeStatus::SUCCESS;
}


// Callback executed when there was an error at the level of communication between the client and
// server. This will set this TreeNode to SUCCESS or FAILURE based on the return value. It will
// return FAILURE by default
BT::NodeStatus FibonacciAction::onFailure(BT::ActionNodeErrorCode error)
{
  RCLCPP_ERROR(logger(), "Error: %d", error);
  return BT::NodeStatus::FAILURE;
}


// Callback executed for each feedback. Typically used to set the TreeNode to RUNNING, but it can
// be modified to abort the action based on the value of the feedback and set the TreeNode to
// SUCCESS or FAILURE. The cancel request will be automatically sent to the server.
BT::NodeStatus FibonacciAction::onFeedback(const std::shared_ptr<const Feedback> feedback)
{
  std::stringstream ss;

  ss << "Next number in sequence received: ";
  for (auto number : feedback->partial_sequence) {
    ss << number << " ";
  }
  RCLCPP_INFO(logger(), ss.str().c_str());

  return BT::NodeStatus::RUNNING;
}
