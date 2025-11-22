#include "behaviortree_cpp/action_node.h"

class ThinkWhatToSay : public BT::SyncActionNode
{
public:
  ThinkWhatToSay(const std::string& name, const BT::NodeConfig config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;
};