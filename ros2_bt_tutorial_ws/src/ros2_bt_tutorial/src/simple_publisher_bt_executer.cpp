#include "ros2_bt_tutorial/behaviors/simple_publisher.hpp"

#include <ament_index_cpp/get_package_share_directory.hpp>


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  // Create a ROS2 node the behaviors will use to communicate with the ROS2 ecosystem
  rclcpp::Node::SharedPtr node = std::make_shared<rclcpp::Node>("simple_publisher_bt_executer");

  BT::BehaviorTreeFactory factory;

  // Register node with desired ROS2 params
  BT::RosNodeParams simple_publisher_params;
  simple_publisher_params.nh = node;
  simple_publisher_params.default_port_value = "topic"; // Set name of topic to publish to

  // Register the Simple Publisher behavior
  factory.registerNodeType<SimplePublisher>("SimplePublisher", simple_publisher_params);

  // Find the package share directory
  std::string share_dir = ament_index_cpp::get_package_share_directory("ros2_bt_tutorial");
  
  auto tree = factory.createTreeFromFile(share_dir + "/trees/simple_publisher_tree.xml");

  // Run the behavior tree and ensure ^C kills the node
  while (rclcpp::ok()) {
    BT::NodeStatus status = tree.tickOnce();

    if (status != BT::NodeStatus::RUNNING) {
      break;
    }
    
    tree.sleep(std::chrono::milliseconds(10));
  }

  rclcpp::shutdown();

  return 0;
}