#include "ros2_bt_tutorial/behaviors/simple_subscriber.hpp"


SimpleSubscriber::SimpleSubscriber(
  const std::string& name,
  const BT::NodeConfig& config,
  const BT::RosNodeParams params
):
  BT::RosTopicSubNode<String>(name, config, params)
{}


BT::PortsList SimpleSubscriber::providedPorts()
{
  return providedBasicPorts({
    BT::InputPort<std::string>("message", "message subscribed from Topic")
  });
}


BT::NodeStatus SimpleSubscriber::onTick(const String::SharedPtr& msg)
{
  getInput("message", msg->data);

  RCLCPP_INFO_STREAM(node_->get_logger(), "I heard: \"" << msg->data << "\"");

  return BT::NodeStatus::RUNNING;
}