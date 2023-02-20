#include "WatchdogTimedSubscribedAction.h"

namespace RosHandler {

WatchdogTimedSubscriberAction::WatchdogTimedSubscriberAction(
    ros::NodeHandle &node,
    const std::shared_ptr<Hardware::ControlGroup> &controlGroup)
    : RosTimedAction{ros::Rate{100},
                     node,
                     "'" + controlGroup->getName() + "' - Watchdog Monitor"},
      ControlGroupRosSubscribedAction{node,
                                      controlGroup,
                                      "power",
                                      ros::Duration{0.01},
                                      1} {}

void WatchdogTimedSubscriberAction::onMessageReceived(const std_msgs::Float64::ConstPtr &msg) {
    lastMessageReceived = ros::Time::now();
}

void WatchdogTimedSubscriberAction::onTimerEvent(const ros::TimerEvent &event) {
    if (ros::Time::now() - lastMessageReceived > WATCHDOG_MAD_TIMEOUT) {
        // ERR
        controlGroup->setPower(0.0);
    }
}

} // namespace RosHandler
