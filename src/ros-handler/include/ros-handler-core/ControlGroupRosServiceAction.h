#ifndef CONTROL_GROUP_ROS_SERVICE_ACTION_H
#define CONTROL_GROUP_ROS_SERVICE_ACTION_H

#include "ControlGroup.h"
#include "RosConcepts.h" // IWYU pragma: keep; required concepts
#include "ros-handler-core/RosServiceAction.h"

namespace RosHandler::RosHandlerCore {

using Hardware::ControlGroup;

template <RosService T>
class ControlGroupRosServiceAction : public RosServiceAction<T> {
public:
    ControlGroupRosServiceAction(
        const ros::NodeHandle &node,
        std::shared_ptr<ControlGroup> controlGroup,
        const std::string &serviceName,
        const ros::Duration &maxResponseTime)
        : RosServiceAction<T>{node, controlGroup->getName() + "/" + serviceName, maxResponseTime},
          controlGroup{std::move(controlGroup)} {}

protected:
    const std::shared_ptr<ControlGroup> controlGroup;
};

} // namespace RosHandler::RosHandlerCore

#endif