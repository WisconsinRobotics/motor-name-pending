#ifndef REVERSE_SERVICE_ACTION_H
#define REVERSE_SERVICE_ACTION_H

#include "ros-handler-core/ControlGroupRosServiceAction.h"
#include "wrevolution/Reverse.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::ControlGroupRosServiceAction;

class ReverseServiceAction : public ControlGroupRosServiceAction<wrevolution::Reverse> {
public:
    ReverseServiceAction(ros::NodeHandle &node, const std::shared_ptr<ControlGroup> &controlGroup);

private:
    auto onServiceRequest(const wrevolution::Reverse::Request &req, wrevolution::Reverse::Response &resp) -> bool override;

    static constexpr double REVERSE_MAX_RESPONSE_DELAY_SECONDS{0.5};
};

} // namespace RosHandler

#endif