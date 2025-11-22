#include "behaviortree_cpp/bt_factory.h"

// Behaviors
#include "behaviors/think_what_to_say.hpp"
#include "behaviors/say_something.hpp"

int main()
{  
  BT::BehaviorTreeFactory factory;

  factory.registerNodeType<SaySomething>("SaySomething");
  factory.registerNodeType<ThinkWhatToSay>("ThinkWhatToSay");

  auto tree = factory.createTreeFromFile("./02_tree.xml");

  tree.tickWhileRunning();
  
  return 0;
}