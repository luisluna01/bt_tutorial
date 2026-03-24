#include "behaviortree_cpp/bt_factory.h"

#include "behaviors/say_something.hpp"


enum Color
{
  RED = 1,
  BLUE = 2,
  GREEN = 3
};


int main()
{
  BT::BehaviorTreeFactory factory;

  factory.registerNodeType<SaySomething>("SaySomething");

  // These enums can be added to scripting language. Check limits of magic_enum
  factory.registerScriptingEnums<Color>();

  // Or can manually assign a number to label "THE_ANSWER". Not affected by range limitation
  factory.registerScriptingEnum("THE_ANSWER", 42);

  auto tree = factory.createTreeFromFile("./09_tree.xml");

  tree.tickWhileRunning();

  return 0;
}