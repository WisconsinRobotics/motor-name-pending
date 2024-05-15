#ifndef PIGEON_ROS_TIMED_ACTION_H
#define PIGEON_ROS_TIMED_ACTION_H

#include <memory>
#include "PigeonIMU.h"
#include "RosTimedAction.h"

namespace RosHandler::RosHandlerCore {

using Hardware::PigeonIMU;

class PigeonRosTimedAction : public RosTimedAction {
public:
    PigeonRosTimedAction(
        const ros::NodeHandle &node,
        const std::shared_ptr<PigeonIMU> &pigeon,
        const std::string &actionDescription,
        const ros::Rate &rate);

protected:
    const std::shared_ptr<PigeonIMU> pigeon;
};

} // namespace RosHandler::RosHandlerCore

#endif
