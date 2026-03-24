#include "behaviortree_cpp/bt_factory.h"

// Custom behaviors
#include "behaviors/check_battery.hpp"
#include "behaviors/move_base.hpp"
#include "behaviors/say_something.hpp"

int main()
{
  BT::BehaviorTreeFactory factory;
  
  factory.registerNodeType<CheckBattery>("CheckBattery");
  factory.registerNodeType<MoveBase>("MoveBase");
  factory.registerNodeType<SaySomething>("SaySomething");

  // ---- Sequence control node ---- //
  std::cout << "Tree using ReactiveSequence control node:\n";
  auto sequence_tree = factory.createTreeFromFile("./04_tree_sequence.xml");

  std::cout << "Tree using Sequence control node:\n";
  std::cout << "--- ticking\n";
  auto status = sequence_tree.tickOnce();
  std::cout << "--- status: " << BT::toStr(status) << "\n\n";

  while(status == BT::NodeStatus::RUNNING) 
  {
    // Sleep to avoid busy loops.
    // do NOT use other sleep functions!
    // Small sleep time is OK, here we use a large one only to
    // have less messages on the console.
    sequence_tree.sleep(std::chrono::milliseconds(100));

    std::cout << "--- ticking\n";
    status = sequence_tree.tickOnce();
    std::cout << "--- status: " << toStr(status) << "\n\n";
  }

  // ---- ReactiveSequence control node ---- //
  std::cout << "Tree using ReactiveSequence control node:\n";
  auto reactive_sequence_tree = factory.createTreeFromFile("./04_tree_reactive_sequence.xml");

  std::cout << "--- ticking\n";
  status = reactive_sequence_tree.tickOnce();
  std::cout << "--- status: " << BT::toStr(status) << "\n\n";

  while(status == BT::NodeStatus::RUNNING) 
  {
    reactive_sequence_tree.sleep(std::chrono::milliseconds(100));

    std::cout << "--- ticking\n";
    status = reactive_sequence_tree.tickOnce();
    std::cout << "--- status: " << toStr(status) << "\n\n";
  }

  return 0;
}
