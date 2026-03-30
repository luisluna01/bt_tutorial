# Behavior Tree Tutorial
This prokect hosts my implementation of the [BehaviorTree.CPP](https://www.behaviortree.dev/)
tutorials.

## Setup
This project relies on the `behaviortree_cpp` package through ROS2. For the same setup used here,
follow the installation instructions in
[ROS2](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html) and install the
`behaviortree_cpp` package:
```
sudo apt install ros-<distro>-behaviortree-cpp # Use your ROS2 distro
```

Clone the repository:
```bash
git clone git@github.com:luisluna01/bt_tutorial.git
```

## BehaviorTree.CPP Tutorials
The code used to run the tutorials from the
[BehaviorTree.CPP](https://www.behaviortree.dev/docs/intro) without integrating ROS2 can be found
under `bt_tutorial/bt_tutorial`. To compile and execute them, follow the instructions below:

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
The code used to run the tutorials using the `BehaviorTree.ROS2` wrapper in the `BehaviorTree.CPP`
[Integration with ROS2](https://www.behaviortree.dev/docs/ros2_integration) page can be found under
the `bt_tutorial/ros2_bt_tutorial` ROS2 workspace. The tutorial examples only demonstrated how to
create Behavior Tree nodes that act as a service client and an action server. Here you will also
find examples for creating Tree nodes that act as a topic publisher and a topic subscriber. This
section assumes you have followed the
[ROS2 Tutorials](https://docs.ros.org/en/humble/Tutorials.html) and have sourced the workspace used
in those tutorials. Follow the instructions below to build the project. You'll also find :

Build the project:
```bash
cd bt_tutorial/ros2_bt_tutorial_ws/
colcon build --symlink-install # Build the ROS2 workspace
source install/setup.bash # Source the workspace
```

<details>
<summary><strong>Service Client Behavior Example</strong></summary>

To test an example of a behavior acting as a service client, first run this service server:

```bash
ros2 run demo_nodes_cpp add_two_ints_server
```

In a separate terminal, run the executable below. This will create a ROS2 node and tick the
`AddTwoIntsSample` tree. The tree has a behavior which uses the ROS2 node to add ROS2 service
client and send a request:

```bash
ros2 run ros2_bt_tutorial add_two_ints_bt_executer
```

</details>

<details>
<summary><strong>Action Client Behavior Example</summary></strong>

To test an example of a behavior acting as an action client, first run this service server:

```bash
ros2 run action_tutorials_cpp fibonacci_action_server
```

In a separate terminal, run the executable found below. This will create a ROS2 node and tick the
`FibonacciSample` tree. This tree has a behavior which uses the ROS2 node to add a ROS2 action
client and send a request:

```bash
ros2 run ros2_bt_tutorial fibonacci_bt_executer
```

</details>

<details>
<summary><strong>Topic Publisher and Subscriber Behavior Examples</summary></strong>

To test an example of a behavior acting as a topic publisher, run the executable below. This will
create a ROS2 node and tick the `SimplePublisherSample` tree. This tree has a behavior which uses
the ROS2 node to add a ROS2 topic publisher and publish a message: 

```bash
ros2 run ros2_bt_tutorial simpe_publisher_bt_executer
```

In a separate terminal, run the executable found below to test a behavior acting as a topic
subscriber. This will create a ROS2 node and tick the `SimpleSubscriberSample` tree. This tree has a
behavior which uses the ROS2 node to add a ROS2 topic subscriber that subscribes to a message:

```bash
ros2 run ros2_bt_tutorial fibonacci_bt_executer
```

Both executables must be run simultaneously to test communication between the publisher and
subscriber.
</details>