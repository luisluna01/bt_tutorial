# Behavior Tree Tutorial
This prokect hosts my implementation of the [BehaviorTree.CPP](https://www.behaviortree.dev/) tutorials.

## Setup
This project relies on the `behaviortree_cpp` package through ROS2. For the same setup used here, follow the installation instructions in [ROS2](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html) and install the`behaviortree_cpp` package:
```
sudo apt install ros-<distro>-behaviortree-cpp # Use your ROS2 distro
```

Clone the repository:
```bash
git clone git@github.com:luisluna01/bt_tutorial.git
```

## BehaviorTree.CPP Tutorials
The tutorials I followed from the [BehaviorTree.CPP](https://www.behaviortree.dev/docs/intro) without integrating ROS2 can be found under `bt_tutorial/bt_tutorial`. To compile and execute them, follow the instructions below:

Compile the project:
```bash
cd bt_tutorial/bt_tutorial/
mkdir build && cd build
cmake .. cmake --build . # Configure and compile the CMake project 
```

This command is an example showing how to run any executable in this directory:
```bash
./first_behavior_tree_exec
```

## BehaviorTree with ROS2 Tutorials
The tutorials I followed using the `BehaviorTree.ROS2` wrapper as shown in the `BehaviorTree.CPP` [Integration with ROS2](https://www.behaviortree.dev/docs/ros2_integration) page can be found under the `bt_tutorial/ros2_bt_tutorial` ROS2 workspace. This section assumes you have followed the [ROS2 Tutorials](https://docs.ros.org/en/humble/Tutorials.html) and have sourced the workspace used in those tutorials. Follow the instructions below to use the project:

Build the project:
```bash
cd bt_tutorial/ros2_bt_tutorial_ws/
colcon build --symlink-install # Build the ROS2 workspace
source install/setup.bash # Source the workspace
```

### Service Client Behavior Example
To test an example of a behavior acting as a service client, first run this service server:
```bash
ros2 run demo_nodes_cpp add_two_ints_server
```

In a separate terminal, run the Behavior Tree `TaskPlanner` executable. This will spin a ROS2 node and tick the `add_two_ints_tree.xml` tree. This tree has a behavior which uses the ROS2 node to add a ROS2 service client and send a request:
```bash
ros2 run ros2_bt_tutorial add_two_ints_bt_executer
```

### Action Client Behavior Example
To test an example of a behavior acting as an action client, first run this service server:
```bash
ros2 run action_tutorials_cpp fibonacci_action_server
```

In a separate terminal, run the Behavior Tree `TaskPlanner` executable. This will spin a ROS2 node and tick the `fibonacci_tree.xml` tree. This tree has a behavior which uses the ROS2 node to add a ROS2 action client and send a request:
```bash
ros2 run ros2_bt_tutorial fibonacci_bt_executer
```