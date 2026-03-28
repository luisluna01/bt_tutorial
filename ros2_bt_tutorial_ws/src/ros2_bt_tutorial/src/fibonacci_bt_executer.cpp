#include "ros2_bt_tutorial/behaviors/fibonacci_action_client.hpp"
#include <ament_index_cpp/get_package_share_directory.hpp>


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  BT::BehaviorTreeFactory factory;

  // Create a ROS2 node the behaviors will use to communicate with the ROS2 ecosystem
  auto node = std::make_shared<rclcpp::Node>("fibonacci_bt_executer");
  
  std::string share_dir = ament_index_cpp::get_package_share_directory("ros2_bt_tutorial");

  // Register node with desired ROS2 params
  BT::RosNodeParams fibonacci_params;
  fibonacci_params.nh = node;
  fibonacci_params.default_port_value = "fibonacci";
  factory.registerNodeType<FibonacciAction>("Fibonacci", fibonacci_params);

  auto tree = factory.createTreeFromFile(share_dir + "/trees/fibonacci_tree.xml");

  // Tick the Tree
  tree.tickWhileRunning();

  rclcpp::shutdown();
}
