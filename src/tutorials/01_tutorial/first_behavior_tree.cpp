#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/tree_node.h"

// Behaviors
#include "behaviors/check_battery.hpp"
#include "behaviors/approach_object.hpp"
#include "behaviors/gripper_interface.hpp"

int main()
{
  // Registers behaviors and creates trees
  BT::BehaviorTreeFactory factory;

  // Recommended way to create a node
  factory.registerNodeType<ApproachObject>("ApproachObject");

  // Registering SimpleActionNode using a function pointer
  // can be lambdas or binders
  factory.registerSimpleCondition("CheckBattery", [&](BT::TreeNode&) { return CheckBattery(); });

  // You can also create SimpleActionNodes using methods of a class
  GripperInterface gripper;
  factory.registerSimpleAction("OpenGripper", [&](BT::TreeNode&){ return gripper.open(); });
  factory.registerSimpleAction("CloseGripper", [&](BT::TreeNode&){ return gripper.close(); });

  // When the Tree goes out of scope, all the TreeNodes are destroyed
  auto tree = factory.createTreeFromFile("./01_tree.xml");

  tree.tickWhileRunning();

  return 0;
}