# BT Training
This repo is to show my progress in my training to learn BehaviorTree.CPP. The tutorials I followed from the [BehaviorTree.CPP tutorials](https://www.behaviortree.dev/) can be found in `include/tutorials` and `src/tutorials`.

## Prerequisite
This project relies on the `behaviortree_cpp` package through ROS2. For the same setup used here, follow the installation instructions in [ROS2](https://docs.ros.org/en/humble/Installation/Ubuntu-Install-Debs.html) and run:
```
sudo apt install ros-<distro>-behaviortree-cpp # Use your distro
```

## Compile and Run
Clone and navigate to the repository:
```bash
git clone git@github.com:luisluna01/bt_training.git
cd bt_training/
```

Navigate to the `/build` directory and configure the project:
```bash
cd bt_training/build
cmake ..
```

Compile the project:
```bash
cmake --build .
```

Run any executable. Run the command below as an example:
```bash
./first_behavior_tree_exec
```