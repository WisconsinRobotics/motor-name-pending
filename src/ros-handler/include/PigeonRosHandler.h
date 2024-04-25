#ifndef PIGEON_ROS_HANDLER_H
#define PIGEON_ROS_HANDLER_H

#include "HeadingTimedAction.h"
#include "PigeonIMU.h"
#include "SetHeadingServiceAction.h"
#include "ros/node_handle.h"

namespace RosHandler {

class PigeonRosHandler {
public:
    PigeonRosHandler(ros::NodeHandle &node, const std::shared_ptr<Hardware::PigeonIMU> &pigeon);

private:
    const std::unique_ptr<HeadingTimedAction> headingAction;
    const std::unique_ptr<SetHeadingServiceAction> setHeadingAction;
};

} // namespace RosHandler

#endif
