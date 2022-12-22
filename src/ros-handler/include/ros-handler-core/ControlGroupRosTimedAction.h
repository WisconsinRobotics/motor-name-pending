#ifndef CONTROL_GROUP_ROS_TIMED_ACTION_H
#define CONTROL_GROUP_ROS_TIMED_ACTION_H

#include "ControlGroup.h"
#include "RosTimedAction.h"
#include <memory>

namespace RosHandler::RosHandlerCore {

using Hardware::ControlGroup;

class ControlGroupRosTimedAction : public RosTimedAction {
public:
    ControlGroupRosTimedAction(
        const ros::NodeHandle &node,
        const std::shared_ptr<ControlGroup> &controlGroup,
        const std::string &actionDescription,
        const ros::Rate &rate);

protected:
    const std::shared_ptr<ControlGroup> controlGroup;
};

} // namespace RosHandler::RosHandlerCore

#endif