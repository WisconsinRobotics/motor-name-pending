#include "HeadingTimedAction.h"
#include "ros/forwards.h"
#include "std_msgs/Float64.h"

namespace RosHandler {
using Hardware::PigeonIMU;

HeadingTimedAction::HeadingTimedAction(ros::NodeHandle &node, const std::shared_ptr<PigeonIMU> &pigeon)
    : PigeonRosTimedAction(node,
                           pigeon,
                           "Heading Publisher",
                           ros::Rate{HEADING_PUBLISHER_RATE_HZ}),
      publisher{node.advertise<std_msgs::Float64>("/heading", HEADING_PUBLISHER_BUFFER_SIZE)} {}


void HeadingTimedAction::onTimerEvent(const ros::TimerEvent &event) {
    std_msgs::Float64 msg;
    
    auto compass = pigeon->GetAbsoluteCompassHeading();
    auto yaw = pigeon->getYaw();
    if (yaw.has_value()) {
        msg.data = *yaw;
        publisher.publish(msg);
    }
}

} // namespace RosHandler
