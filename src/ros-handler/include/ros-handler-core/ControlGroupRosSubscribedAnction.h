#ifndef CONTROL_GROUP_ROS_SUBSCRIBED_ACTION_H
#define CONTROL_GROUP_ROS_SUBSCRIBED_ACTION_H

#include "ControlGroup.h"
#include "RosConcepts.h" // IWYU pragma: keep; required concepts
#include "ros-handler-core/RosSubscribedAction.h"

namespace RosHandler::RosHandlerCore {

using Hardware::ControlGroup;

template <RosMessage T>
class ControlGroupRosSubscribedAction : public RosSubscribedAction<T> {
public:
    ControlGroupRosSubscribedAction(
        const ros::NodeHandle &node,
        std::shared_ptr<ControlGroup> controlGroup,
        const std::string &subscriptionName,
        const ros::Duration &maxResponseTime)
        : RosSubscribedAction<T>{node, controlGroup->getName() + "/" + subscriptionName, maxResponseTime},
          controlGroup{std::move(controlGroup)} {}

protected:
    const std::shared_ptr<ControlGroup> controlGroup;
};

} // namespace RosHandler::RosHandlerCore

#endif