#include "behaviortree_cpp/bt_factory.h"
#include "behaviors/cross_door_nodes.hpp"

int main()
{
  BT::BehaviorTreeFactory factory;

  CrossDoor cross_door;
  cross_door.registerNodes(factory);

  // In this example a single XML contains multiple <BehaviorTree>
  // To determine which one is the "main one", first register the XML and then allocate a specific
  // tree, using its ID

  factory.registerBehaviorTreeFromFile("./05_tree.xml");
  auto tree = factory.createTree("MainTree");

  // Helper function to print the tree
  printTreeRecursively(tree.rootNode());

  tree.tickWhileRunning();

  return 0;
}