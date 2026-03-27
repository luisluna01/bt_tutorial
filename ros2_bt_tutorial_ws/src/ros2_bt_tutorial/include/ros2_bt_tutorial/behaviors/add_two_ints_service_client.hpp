#pragma once

#include <behaviortree_ros2/bt_service_node.hpp>
#include "example_interfaces/srv/add_two_ints.hpp"

using AddTwoInts = example_interfaces::srv::AddTwoInts;

class AddTwoIntsNode : public BT::RosServiceNode<AddTwoInts>
{
public:
  AddTwoIntsNode(
    const std::string& name,
    const BT::NodeConfig& config,
    const BT::RosNodeParams& params);

  static BT::PortsList providedPorts();

  bool setRequest(Request::SharedPtr& request) override;

  BT::NodeStatus onResponseReceived(const Response::SharedPtr& response) override;

  virtual BT::NodeStatus onFailure(BT::ServiceNodeErrorCode error) override;
};
