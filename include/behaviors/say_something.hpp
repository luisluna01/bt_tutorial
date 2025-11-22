#include "behaviortree_cpp/action_node.h"

// Synchronous action node example with an input port
class SaySomething : public BT::SyncActionNode
{
public:
  // If your Node has ports, you must use this constructor signature
  SaySomething(const std::string& name, const BT::NodeConfig& config);

  // Mandatory to define this static method
  static BT::PortsList providedPorts();

  // Override virtual function tick()
  BT::NodeStatus tick() override;
};