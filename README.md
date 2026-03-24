# BT Training
This repo is to show my progress in my learning of BehaviorTree.CPP.

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
The tutorials I followed from the [BehaviorTree.CPP](https://www.behaviortree.dev/docs/intro) can be found under `bt_tutorial/bt_tutorial`. To compile and execute them, follow the instructions below:

Compile the project:
```bash
cd bt_tutorial/bt_tutorial/tutorial directory
mkdir build && cd build
cmake .. cmake --build . # Configure and compile the CMake project 
```

This command is an example showing how to run any executable in this directory:
```bash
./first_behavior_tree_exec
```

<!-- ## BehaviorTree with ROS2 Tutorials -->