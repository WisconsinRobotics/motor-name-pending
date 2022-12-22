#include "PowerSubscribedAction.h"

namespace RosHandler {

PowerSubscribedAction::PowerSubscribedAction(ros::NodeHandle &node, const std::shared_ptr<ControlGroup> &controlGroup)
    : ControlGroupRosSubscribedAction<std_msgs::Float64>{node,
                                                         controlGroup,
                                                         "power",
                                                         ros::Duration{POWER_MAX_RESPONSE_DELAY_SECONDS},
                                                         POWER_SUBSCRIBER_QUEUE_SIZE} {}

void PowerSubscribedAction::onMessageReceived(const std_msgs::Float64::ConstPtr &msg) {
    if (std::abs(msg->data) > 1) {
        ROS_ERROR_STREAM( // NOLINT(hicpp-no-array-decay, cppcoreguidelines-pro-bounds-array-to-pointer-decay); required for ROS logging
            "Control Group '" << controlGroup->getName() << "' received illegal power " << msg->data);
        return;
    }

    controlGroup->setPower(msg->data);
}

} // namespace RosHandler