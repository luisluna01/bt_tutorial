#include "behaviors/move_base.hpp"

MoveBase::MoveBase(const std::string& name, const BT::NodeConfig& config)
  : BT::StatefulActionNode(name, config)
{}


BT::PortsList MoveBase::providedPorts()
{
  return { BT::InputPort<Pose2D>("goal") };
}


BT::NodeStatus MoveBase::onStart()
{
  if ( !getInput<Pose2D>("goal", goal_) )
  {
    throw BT::RuntimeError("missing required input [goal]");
  }
  printf("[ MoveBase: SEND REQUEST ] - goal: x=%f y=%f theta=%f\n",
    goal_.x, goal_.y, goal_.theta);

  // Simulate an action that takes a certain amount of time to be completed (200 ms)
  completion_time_ = std::chrono::system_clock::now() + std::chrono::milliseconds(220);

  return BT::NodeStatus::RUNNING;
}


BT::NodeStatus MoveBase::onRunning()
{
  // Pretend to check if the reply has been recieved
  // Note: Don't block this function for too long
  std::this_thread::sleep_for(std::chrono::milliseconds(10));

  // Pretend that, after a certain amount of time, we have completed the operation
  if(std::chrono::system_clock::now() >= completion_time_)
  {
    std::cout << "[ MoveBase: FINISHED ]" << std::endl;
    
    return BT::NodeStatus::SUCCESS;
  }
  return BT::NodeStatus::RUNNING;
}


void MoveBase::onHalted()
{
  printf("[ MoveBase: ABORTED] ");
}