#include "behaviortree_cpp/action_node.h"


// ActionA has a different constructor than the default one
class ActionA: public BT::SyncActionNode
{
public:
  // Additional arguments passed to the constructor
  ActionA(const std::string& name, const BT::NodeConfig& config, int arg_int, std::string arg_str);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;


private:
  int _arg1;
  std::string _arg2;
};