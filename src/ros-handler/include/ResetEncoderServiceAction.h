#ifndef RESET_ENCODER_SERVICE_ACTION_H
#define RESET_ENCODER_SERVICE_ACTION_H

#include "ros-handler-core/ControlGroupRosServiceAction.h"
#include "wrevolution/ResetEncoder.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::ControlGroupRosServiceAction;

class ResetEncoderServiceAction : public ControlGroupRosServiceAction<wrevolution::ResetEncoder> {
public:
    ResetEncoderServiceAction(ros::NodeHandle &node, const std::shared_ptr<ControlGroup> &controlGroup);

private:
    auto onServiceRequest(const wrevolution::ResetEncoder::Request &req, wrevolution::ResetEncoder::Response &resp) -> bool override;

    static constexpr double RESET_ENCODER_MAX_RESPONSE_DELAY_SECONDS{0.5};
};

} // namespace RosHandler

#endif