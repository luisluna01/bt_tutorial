#include "behaviors/gripper_interface.hpp"

GripperInterface::GripperInterface()
: _open(true)
{}

BT::NodeStatus GripperInterface::open()
{
  _open = true;
  std::cout << "GripperInterface::open" << std::endl;

  return BT::NodeStatus::SUCCESS;
}

BT::NodeStatus GripperInterface::close()
{
  std::cout << "GripperInterface::close" << std::endl;
  _open = false;

  return BT::NodeStatus::SUCCESS;
}
