#ifndef CONTROL_GROUP_ROS_HANDLER_H
#define CONTROL_GROUP_ROS_HANDLER_H

#include "ControlGroup.h"
#include "EncoderTimedAction.h"
#include "PowerSubscribedAction.h"
#include "ResetSettingsServiceAction.h"
#include "ReverseServiceAction.h"
#include "WatchdogTimedSubscribedAction.h"
#include "ZeroPowerBehaviorServiceAction.h"
#include "ros/node_handle.h"
#include <memory>

namespace RosHandler {

class ControlGroupRosHandler {
public:
    ControlGroupRosHandler(ros::NodeHandle &node, const std::shared_ptr<Hardware::ControlGroup> &controlGroup);

private:
    const std::unique_ptr<EncoderTimedAction> encoderAction;
    const std::unique_ptr<PowerSubscribedAction> powerAction;
    const std::unique_ptr<ZeroPowerBehaviorServiceAction> zeroPowerBehaviorAction;
    const std::unique_ptr<ResetSettingsServiceAction> resetSettingsAction;
    const std::unique_ptr<ReverseServiceAction> reverseAction;
    const std::unique_ptr<WatchdogTimedSubscriberAction> watchdogAction;
};

} // namespace RosHandler

#endif