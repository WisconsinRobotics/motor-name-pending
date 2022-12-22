#ifndef ZERO_POWER_BEHAVIOR_SERVICE_ACTION_H
#define ZERO_POWER_BEHAVIOR_SERVICE_ACTION_H

#include "ros-handler-core/ControlGroupRosServiceAction.h"
#include "wrevolution/ZeroPowerBehavior.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::ControlGroupRosServiceAction;

class ZeroPowerBehaviorServiceAction : public ControlGroupRosServiceAction<wrevolution::ZeroPowerBehavior> {
public:
    ZeroPowerBehaviorServiceAction(ros::NodeHandle &node, const std::shared_ptr<ControlGroup> &controlGroup);

private:
    auto onServiceRequest(const wrevolution::ZeroPowerBehavior::Request &req, wrevolution::ZeroPowerBehavior::Response &resp) -> bool override;

    static constexpr double ZERO_POWER_MAX_RESPONSE_DELAY_SECONDS{0.5};
};

} // namespace RosHandler

#endif