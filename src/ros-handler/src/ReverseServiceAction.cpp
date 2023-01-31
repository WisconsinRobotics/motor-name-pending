#include "ReverseServiceAction.h"
#include "ControlGroup.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::ControlGroupRosServiceAction;
using wrevolution::Reverse;

ReverseServiceAction::ReverseServiceAction(ros::NodeHandle &node, const std::shared_ptr<ControlGroup> &controlGroup)
    : ControlGroupRosServiceAction<Reverse>(node,
                                            controlGroup,
                                            "reverse",
                                            ros::Duration{REVERSE_MAX_RESPONSE_DELAY_SECONDS}) {}

auto ReverseServiceAction::onServiceRequest(const Reverse::Request &req,
                                            Reverse::Response &resp) -> bool {
    controlGroup->setReversal(req.inverted != 0); // Req'd due to how ROS generates bool messages
    return true;
}

} // namespace RosHandler
