#include "ros2_bt_tutorial/behaviors/fibonacci_action_client.hpp"
#include "ros2_bt_tutorial/behaviors/add_two_ints_service_client.hpp"
#include <ament_index_cpp/get_package_share_directory.hpp>

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  BT::BehaviorTreeFactory factory;

  auto node = std::make_shared<rclcpp::Node>("bt_executer");
  
  std::string share_dir = ament_index_cpp::get_package_share_directory("ros2_bt_tutorial");

  // --- BT Node Registration --- //
  // Nodes can be registered even if they are unused in the tree. Trees are created at runtime
  // Register FibonacciAction
  BT::RosNodeParams fibonacci_params;
  fibonacci_params.nh = node;
  fibonacci_params.default_port_value = "fibonacci";
  factory.registerNodeType<FibonacciAction>("Fibonacci", fibonacci_params);

  // Register AddTwoIntsNode
  BT::RosNodeParams add_two_ints_params;
  add_two_ints_params.nh = node;
  add_two_ints_params.default_port_value = "add_two_ints";
  factory.registerNodeType<AddTwoIntsNode>("AddTwoInts", add_two_ints_params);

  // Change to tree desired from /trees subdirectory
  auto tree = factory.createTreeFromFile(share_dir + "/trees/fibonacci_tree.xml");
  tree.tickWhileRunning();

  rclcpp::shutdown();
}
