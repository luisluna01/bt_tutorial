cmake_minimum_required(VERSION 3.8)
project(ros2_bt_tutorial)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_index_cpp REQUIRED)
find_package(rclcpp REQUIRED)
find_package(behaviortree_cpp REQUIRED)
find_package(behaviortree_ros2 REQUIRED)
find_package(btcpp_ros2_interfaces REQUIRED)
find_package(action_tutorials_interfaces REQUIRED)
find_package(example_interfaces REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(add_two_ints_bt_executer
  src/add_two_ints_bt_executer.cpp
  src/behaviors/add_two_ints_service_client.cpp
)
target_include_directories(add_two_ints_bt_executer PUBLIC include)
ament_target_dependencies(add_two_ints_bt_executer
  ament_index_cpp
  rclcpp
  behaviortree_cpp
  behaviortree_ros2
  btcpp_ros2_interfaces
  example_interfaces
)

add_executable(fibonacci_bt_executer
  src/fibonacci_bt_executer.cpp
  src/behaviors/fibonacci_action_client.cpp
)
target_include_directories(fibonacci_bt_executer PUBLIC include)
ament_target_dependencies(fibonacci_bt_executer
  ament_index_cpp
  rclcpp
  behaviortree_cpp
  behaviortree_ros2
  btcpp_ros2_interfaces
  action_tutorials_interfaces
)

add_executable(simple_publisher_bt_executer
  src/simple_publisher_bt_executer.cpp
  src/behaviors/simple_publisher.cpp
)
target_include_directories(simple_publisher_bt_executer PUBLIC include)
ament_target_dependencies(simple_publisher_bt_executer
  ament_index_cpp
  rclcpp
  behaviortree_cpp
  behaviortree_ros2
  btcpp_ros2_interfaces
  std_msgs
)

install(TARGETS
  add_two_ints_bt_executer
  fibonacci_bt_executer
  simple_publisher_bt_executer
  
  DESTINATION lib/${PROJECT_NAME}
)

install(DIRECTORY trees
  DESTINATION share/${PROJECT_NAME}
)

ament_package()
