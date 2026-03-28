#include "ros2_bt_tutorial/behaviors/add_two_ints_service_client.hpp"


AddTwoIntsNode::AddTwoIntsNode(
  const std::string& name,
  const BT::NodeConfig& config,
  const BT::RosNodeParams& params
):
  RosServiceNode<AddTwoInts>(name, config, params)
{}

// Specific ports of thie Derived class should be merged with the ports of the base class using
// RosServiceNode::providedBasicPorts()
BT::PortsList AddTwoIntsNode::providedPorts()
{
  return providedBasicPorts({
    BT::InputPort<unsigned>("A"),
    BT::InputPort<unsigned>("B")});
}


// Called when the TreeNode is ticked. It sends a request to the service provider
bool AddTwoIntsNode::setRequest(Request::SharedPtr& request)
{
  getInput("A", request->a);
  getInput("B", request->b);

  // Must return true if ready to send request
  return true;
}


// Callback invoked when answer is received. Must be either SUCCESS or FAILURE
BT::NodeStatus AddTwoIntsNode::onResponseReceived(const Response::SharedPtr& response)
{
  RCLCPP_INFO(logger(), "Sum: %ld", response->sum);
  return BT::NodeStatus::SUCCESS;
}


// Callback invoked when there was an error at the level of communication between client and server.
// This will set the statuf of this TreeNode to either SUCCESS or FAILURE, based on return value.
// If not overridden it will return FAILURE by default.
BT::NodeStatus AddTwoIntsNode::onFailure(BT::ServiceNodeErrorCode error)
{
  RCLCPP_ERROR(logger(), "Error: %d", error);
  return BT::NodeStatus::FAILURE;
}
