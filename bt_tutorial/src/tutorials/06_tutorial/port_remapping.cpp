#include "behaviortree_cpp/bt_factory.h"

#include "behaviors/say_something.hpp"
#include "behaviors/move_base.hpp"

int main()
{
  BT::BehaviorTreeFactory factory;

  factory.registerNodeType<SaySomething>("SaySomething");
  factory.registerNodeType<MoveBase>("MoveBase");
  
  factory.registerBehaviorTreeFromFile("./06_tree.xml");

  auto tree = factory.createTree("MainTree");

  // Keep ticking until the end
  tree.tickWhileRunning();

  // Visualize some information about the current state of the blackboards (The main tree and
  // subtree have separate blackboards)
  std::cout << "\n------ First BB ------" << std::endl;
  tree.subtrees[0]->blackboard->debugMessage();
  std::cout << "\n------ Second BB------" << std::endl;
  tree.subtrees[1]->blackboard->debugMessage();

  return 0;
}