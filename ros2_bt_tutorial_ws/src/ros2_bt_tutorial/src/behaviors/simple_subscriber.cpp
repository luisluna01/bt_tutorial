#include "ros2_bt_tutorial/behaviors/simple_subscriber.hpp"


SimpleSubscriber::SimpleSubscriber(
  const std::string& name,
  const BT::NodeConfig& config,
  const BT::RosNodeParams params
):
  BT::RosTopicSubNode<String>(name, config, params)
{}


// Required callback invoked in tick to allow the user to pass the message to be published. Must
// Must return either true or false
BT::NodeStatus SimpleSubscriber::onTick(const String::SharedPtr& msg)
{
  if (msg) {
    RCLCPP_INFO_STREAM(node_.lock()->get_logger(), "I heard: \"" << msg->data << "\"");
    return BT::NodeStatus::SUCCESS;
  }
  else {
    RCLCPP_WARN_STREAM(node_.lock()->get_logger(), "No message provided...");
    return BT::NodeStatus::SUCCESS;
  }
}