#include "ros-handler-core/PigeonRosTimedAction.h"
#include "ros-handler-core/RosTimedAction.h"

namespace RosHandler::RosHandlerCore {

PigeonRosTimedAction::PigeonRosTimedAction(
    const ros::NodeHandle &node,
    const std::shared_ptr<PigeonIMU> &pigeon,
    const std::string &actionDescription,
    const ros::Rate &rate)
    : RosTimedAction(rate, node, "'" + pigeon->getName() + "' - " + actionDescription),
      pigeon{pigeon} {}

} // namespace RosHandler::RosHandlerCore
