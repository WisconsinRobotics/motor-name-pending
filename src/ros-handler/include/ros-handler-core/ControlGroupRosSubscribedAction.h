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
        ros::NodeHandle &node,
        const std::shared_ptr<ControlGroup> &controlGroup,
        const std::string &subscriptionName,
        const ros::Duration &maxResponseTime,
        uint32_t queueSize)
        : RosSubscribedAction<T>{node, controlGroup->getName() + "/" + subscriptionName, queueSize, maxResponseTime},
          controlGroup{controlGroup} {}

protected:
    const std::shared_ptr<ControlGroup> controlGroup;
};

} // namespace RosHandler::RosHandlerCore

#endif