#include "behaviors/approach_object.hpp"

ApproachObject::ApproachObject(const std::string& name)
: BT::SyncActionNode(name, {})
{}

BT::NodeStatus ApproachObject::tick()
{
  std::cout << "ApproachObject::" << this->name() << std::endl;

  return BT::NodeStatus::SUCCESS;
}
