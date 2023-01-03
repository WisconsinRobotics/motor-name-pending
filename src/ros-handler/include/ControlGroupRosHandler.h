#ifndef CONTROL_GROUP_ROS_HANDLER_H
#define CONTROL_GROUP_ROS_HANDLER_H

#include "ControlGroup.h"
#include "EncoderTimedAction.h"
#include "PowerSubscribedAction.h"
#include "ZeroPowerBehaviorServiceAction.h"
#include "ros/node_handle.h"
#include <memory>

namespace RosHandler {

class ControlGroupRosHandler {
public:
    ControlGroupRosHandler(const std::shared_ptr<Hardware::ControlGroup> &controlGroup, ros::NodeHandle &node);

private:
    const std::unique_ptr<EncoderTimedAction> encoderAction;
    const std::unique_ptr<PowerSubscribedAction> powerAction;
    const std::unique_ptr<ZeroPowerBehaviorServiceAction> zeroPowerBehaviorAction;
};

} // namespace RosHandler

#endif