#include "ResetEncoderServiceAction.h"
#include "ControlGroup.h"
#include "wrevolution/ResetEncoder.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::ControlGroupRosServiceAction;
using wrevolution::ResetEncoder;

ResetEncoderServiceAction::ResetEncoderServiceAction(ros::NodeHandle &node, const std::shared_ptr<ControlGroup> &controlGroup)
    : ControlGroupRosServiceAction<ResetEncoder>(node,
                                                  controlGroup,
                                                  "reset_encoder",
                                                  ros::Duration{RESET_ENCODER_MAX_RESPONSE_DELAY_SECONDS}) {}

auto ResetEncoderServiceAction::onServiceRequest(const ResetEncoder::Request &req,
                                                  ResetEncoder::Response &resp) -> bool {
    controlGroup->resetEncoder();
    return true;
}

} // namespace RosHandler
