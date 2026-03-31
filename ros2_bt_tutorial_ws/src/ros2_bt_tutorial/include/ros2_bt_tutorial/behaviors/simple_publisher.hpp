
#include "behaviortree_ros2/bt_topic_pub_node.hpp"

#include "std_msgs/msg/string.hpp"

using String = std_msgs::msg::String;

class SimplePublisher: public BT::RosTopicPubNode<String>
{
public:
  SimplePublisher(
    const std::string& name,
    const BT::NodeConfig& config,
    const BT::RosNodeParams& params);

  static BT::PortsList providedPorts();

  bool setMessage(String& msg) override;

private:
};