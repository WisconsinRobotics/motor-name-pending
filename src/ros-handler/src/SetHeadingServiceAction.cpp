#include "SetHeadingServiceAction.h"
#include "PigeonIMU.h"
#include "ros-handler-core/PigeonRosServiceAction.h"
#include "wrevolution/SetHeading.h"

namespace RosHandler {

using Hardware::PigeonIMU;
using RosHandlerCore::PigeonRosServiceAction;
using wrevolution::SetHeading;

SetHeadingServiceAction::SetHeadingServiceAction(ros::NodeHandle &node, const std::shared_ptr<PigeonIMU> &pigeon)
    : PigeonRosServiceAction<SetHeading>(node,
                                         pigeon,
                                         "set_heading",
                                         ros::Duration{SET_HEADING_MAX_RESPONSE_DELAY_SECONDS}) {}

auto SetHeadingServiceAction::onServiceRequest(const SetHeading::Request &req,
                                               SetHeading::Response &resp) -> bool {
    pigeon->setYaw(req.heading);
    return true;
}

} // namespace RosHandler
