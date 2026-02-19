#include "behaviortree_cpp/action_node.h"


class ActionB: public BT::SyncActionNode
{
public:
  // Usual constructor
  ActionB(const std::string& name, const BT::NodeConfig& config);

  static BT::PortsList providedPorts();

  BT::NodeStatus tick() override;

  // Want this called once and before the first tick()
  void initialize(int arg_int, const std::string& arg_str);


private:
  int _arg1;
  std::string _arg2;
};