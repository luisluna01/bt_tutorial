#include "ros2_bt_tutorial/behaviors/add_two_ints_service_client.hpp"
#include <ament_index_cpp/get_package_share_directory.hpp>


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  BT::BehaviorTreeFactory factory;

  // Create a ROS2 node the behaviors will use to communicate with the ROS2 ecosystem
  auto node = std::make_shared<rclcpp::Node>("add_two_ints_bt_executer");
  
  std::string share_dir = ament_index_cpp::get_package_share_directory("ros2_bt_tutorial");

  // Register node with desired ROS2 params
  BT::RosNodeParams add_two_ints_params;
  add_two_ints_params.nh = node;
  add_two_ints_params.default_port_value = "add_two_ints";
  factory.registerNodeType<AddTwoIntsNode>("AddTwoInts", add_two_ints_params);

  auto tree = factory.createTreeFromFile(share_dir + "/trees/add_two_ints_tree.xml");

  // Tick the Tree
  tree.tickWhileRunning();

  rclcpp::shutdown();
}
