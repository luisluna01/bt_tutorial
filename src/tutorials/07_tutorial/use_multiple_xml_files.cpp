#include "behaviortree_cpp/bt_factory.h"

#include "behaviors/say_something.hpp"

int main()
{
  BT::BehaviorTreeFactory factory;

  factory.registerNodeType<SaySomething>("SaySomething");

  // Register the XML files for this tutorial
  factory.registerBehaviorTreeFromFile("./07_tree.xml");
  factory.registerBehaviorTreeFromFile("./subtree_A.xml");
  factory.registerBehaviorTreeFromFile("./subtree_B.xml");

  // Create MainTree and subtrees will be added automatically
  std::cout << "----- MainTree -----" << std::endl;
  auto main_tree = factory.createTree("MainTree");
  main_tree.tickWhileRunning();
  
  // ... or you can create only one of the subtrees
  std::cout << "----- SubA tick ----" << std::endl;
  auto subA_tree = factory.createTree("SubTreeA");
  subA_tree.tickWhileRunning();
  return 0;
}