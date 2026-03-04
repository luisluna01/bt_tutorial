// Skipped visualizing custom types in blackboard. Only available for pro version of groot2
#include "behaviortree_cpp/bt_factory.h"
#include "behaviortree_cpp/xml_parsing.h"
#include "behaviortree_cpp/loggers/groot2_publisher.h"

#include "behaviors/cross_door_nodes.hpp"

int main()
{
  BT::BehaviorTreeFactory factory;

  // Register CrossDoor Nodes
  CrossDoor cross_door;
  cross_door.registerNodes(factory);

  // Groot2 editor requires a model of registered nodes. Can be automatically generated using the
  // following command
  std::string xml_models = BT::writeTreeNodesModelXML(factory);

  factory.registerBehaviorTreeFromFile("./11_tree.xml");
  auto tree = factory.createTree("MainTree");

  // Connect Groot2Publisher. Allows Groot2 to visualize the behavior tree and status updates
  BT::Groot2Publisher publisher(tree);

  // Run indefinitely to show example
  while(1)
  {
    std::cout << "Start" << std::endl;
    cross_door.reset();
    tree.tickWhileRunning();
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  }

  return 0;
}