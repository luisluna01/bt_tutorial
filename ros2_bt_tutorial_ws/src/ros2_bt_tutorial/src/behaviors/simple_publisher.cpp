#include "ros2_bt_tutorial/behaviors/simple_publisher.hpp"

SimplePublisher::SimplePublisher(
  const std::string& name,
  const BT::NodeConfig& config,
  const BT::RosNodeParams& params
):
  BT::RosTopicPubNode<String>(name, config, params)
{}


// Specific ports of thie Derived class should be merged with the ports of the base class using
// RosServiceNode::providedBasicPorts()
BT::PortsList SimplePublisher::providedPorts()
{
  return providedBasicPorts({
    BT::InputPort<std::string>("message", "Topic message to be published")
  });
}


// Callback invoked in during the tick to pass the message to be published. Must return either true
// or false
bool SimplePublisher::setMessage(String& msg)
{
  getInput("message", msg.data);
  
  // The ROS2 node is a protected class and can be accessed
  RCLCPP_INFO_STREAM(node_->get_logger(), "Publishing: " << msg.data);

  return true;
}
