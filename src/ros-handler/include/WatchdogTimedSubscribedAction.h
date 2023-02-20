#ifndef WATCHDOG_TIMED_SUBSCRIBED_ACTION_H
#define WATCHDOG_TIMED_SUBSCRIBED_ACTION_H

#include "ros-handler-core/ControlGroupRosSubscribedAction.h"
#include "ros-handler-core/RosTimedAction.h"
#include "std_msgs/Float64.h"

namespace RosHandler {

class WatchdogTimedSubscriberAction : public RosHandlerCore::RosTimedAction,
                                      RosHandlerCore::ControlGroupRosSubscribedAction<std_msgs::Float64> {
public:
    WatchdogTimedSubscriberAction(
        ros::NodeHandle &node,
        const std::shared_ptr<Hardware::ControlGroup> &controlGroup);

private:
    void onMessageReceived(const std_msgs::Float64::ConstPtr &msg) override;
    void onTimerEvent(const ros::TimerEvent &event) override;

    ros::Time lastMessageReceived;
    inline static const ros::Duration WATCHDOG_MAD_TIMEOUT{0.5};
};

} // namespace RosHandler

#endif
