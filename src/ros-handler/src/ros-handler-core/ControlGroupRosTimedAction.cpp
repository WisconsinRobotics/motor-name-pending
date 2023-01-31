#include "ros-handler-core/ControlGroupRosTimedAction.h"
#include "ros-handler-core/RosTimedAction.h"

namespace RosHandler::RosHandlerCore {

ControlGroupRosTimedAction::ControlGroupRosTimedAction(
    const ros::NodeHandle &node,
    const std::shared_ptr<ControlGroup> &controlGroup,
    const std::string &actionDescription,
    const ros::Rate &rate)
    : RosTimedAction(rate, node, "'" + controlGroup->getName() + "' - " + actionDescription),
      controlGroup{controlGroup} {}

} // namespace RosHandler::RosHandlerCore