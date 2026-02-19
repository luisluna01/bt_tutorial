#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/tree_node.h"

#include "behaviors/action_a.hpp"
#include "behaviors/action_b.hpp"


int main()
{
  BT::BehaviorTreeFactory factory;

  factory.registerNodeType<ActionA>("ActionA", 42, "hello world");
  
  // Register as usual but still needs to be initialized
  factory.registerNodeType<ActionB>("ActionB");

  auto tree = factory.createTreeFromFile("./08_tree.xml");

  // Visitor initializes instances of ActionB
  auto visitor = [](BT::TreeNode* node)
  {
    if (auto action_b_node = dynamic_cast<ActionB*>(node))
    {
      action_b_node->initialize(69, "interesting_value");
    }
  };

  tree.applyVisitor(visitor);

  tree.tickWhileRunning();

  return 0;
}