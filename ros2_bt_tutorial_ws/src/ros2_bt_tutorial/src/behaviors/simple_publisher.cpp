#include "ros2_bt_tutorial/behaviors/simple_publisher.hpp"

SimplePublisher::SimplePublisher(
  const std::string& name,
  const BT::NodeConfig& config,
  const BT::RosNodeParams& params
):
  BT::RosTopicPubNode<String>(name, config, params), params_(params)
{}


// Specific ports of thie Derived class should be merged with the ports of the base class using
// RosServiceNode::providedBasicPorts()
BT::PortsList SimplePublisher::providedPorts()
{
  return providedBasicPorts({
    BT::InputPort<std::string>("message", "Topic message to be published")
  });
}


// Callback invoked in during the tick to pass the message to be published
bool SimplePublisher::setMessage(String& msg)
{
  getInput("message", msg.data);
  
  RCLCPP_INFO_STREAM(rclcpp::get_logger("Logger"), "Publishing: " << msg.data);

  return true;
}
