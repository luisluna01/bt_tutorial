#include "ros2_bt_tutorial/behaviors/simple_subscriber.hpp"

#include <ament_index_cpp/get_package_share_directory.hpp>


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  rclcpp::Node::SharedPtr node = std::make_shared<rclcpp::Node>("simple_subscriber_bt_executer");
  
  BT::BehaviorTreeFactory factory;

  BT::RosNodeParams simple_subscriber_params;
  simple_subscriber_params.default_port_value = "/topic"; // Name of topic to subscribe to
  simple_subscriber_params.nh = node; // Node to create subscriber

  // Register simple subscriber behavior
  factory.registerNodeType<SimpleSubscriber>("SimpleSubscriber", simple_subscriber_params);

  // Find package share directory
  std::string share_dir = ament_index_cpp::get_package_share_directory("ros2_bt_tutorial");
  
  BT::Tree tree = factory.createTreeFromFile(share_dir + "/trees/simple_subscriber_tree.xml");

  // Ensure tree runs slow enough for ^C to work
  while(rclcpp::ok()) {
    BT::NodeStatus status = tree.tickOnce();

    if (status != BT::NodeStatus::RUNNING) {
      break;
    }

    tree.sleep(std::chrono::milliseconds(10));
  }

  rclcpp::shutdown();
  
  return 0;
}