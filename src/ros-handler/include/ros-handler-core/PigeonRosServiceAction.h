#ifndef PIGEON_ROS_SERVICE_ACTION_H
#define PIGEON_ROS_SERVICE_ACTION_H

#include "PigeonIMU.h"
#include "RosConcepts.h" // IWYU pragma: keep; required concepts
#include "ros-handler-core/RosServiceAction.h"

namespace RosHandler::RosHandlerCore {

using Hardware::PigeonIMU;

template <RosService T>
class PigeonRosServiceAction : public RosServiceAction<T> {
public:
    PigeonRosServiceAction(
        ros::NodeHandle &node,
        const std::shared_ptr<PigeonIMU> &pigeon,
        const std::string &serviceName,
        const ros::Duration &maxResponseTime)
        : RosServiceAction<T>{node, pigeon->getName() + "/" + serviceName, maxResponseTime},
          pigeon{pigeon} {}

protected:
    const std::shared_ptr<PigeonIMU> pigeon;
};

} // namespace RosHandler::RosHandlerCore

#endif
