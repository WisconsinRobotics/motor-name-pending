#ifndef POWER_SUBSCRIBED_ACTION_H
#define POWER_SUBSCRIBED_ACTION_H

#include "ros-handler-core/ControlGroupRosSubscribedAction.h"
#include "ros/node_handle.h"
#include "std_msgs/Float64.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::ControlGroupRosSubscribedAction;

class PowerSubscribedAction : ControlGroupRosSubscribedAction<std_msgs::Float64> {
public:
    PowerSubscribedAction(ros::NodeHandle &node, std::shared_ptr<ControlGroup> controlGroup);

private:
    void onMessageReceived(const std_msgs::Float64::ConstPtr &msg) override;

    static constexpr double POWER_MAX_RESPONSE_DELAY_SECONDS{0.01}; // 10ms
    static constexpr uint32_t POWER_SUBSCRIBER_QUEUE_SIZE{1};
};

} // namespace RosHandler

#endif