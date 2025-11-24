#include "behaviortree_cpp/bt_factory.h"
#include "behaviors/calculate_goal.hpp"
#include "behaviors/print_target.hpp"

int main()
{
  BT::BehaviorTreeFactory factory;

  factory.registerNodeType<CalculateGoal>("CalculateGoal");
  factory.registerNodeType<PrintTarget>("PrintTarget");

  auto tree = factory.createTreeFromFile("./03_tree.xml");

  tree.tickWhileRunning();

  return 0;
}