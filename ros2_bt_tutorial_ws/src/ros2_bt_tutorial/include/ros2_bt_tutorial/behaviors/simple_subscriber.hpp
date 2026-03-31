#pragma once
#include "behaviortree_ros2/bt_topic_sub_node.hpp"

#include "std_msgs/msg/string.hpp"


using String = typename std_msgs::msg::String;

class SimpleSubscriber : public BT::RosTopicSubNode<String>
{
public:
  SimpleSubscriber(const std::string& name, const BT::NodeConfig& config, const BT::RosNodeParams);

  BT::NodeStatus onTick(const String::SharedPtr& msg);
};