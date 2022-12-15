#ifndef __CONTROL_GROUP_ROS_HANDLER__
#define __CONTROL_GROUP_ROS_HANDLER__

#include "ControlGroup.h"
#include <memory>

namespace RosHandler {

using Hardware::ControlGroup;

class ControlGroupRosHandler {
public:
private:
    std::shared_ptr<ControlGroup> controlGroup;
};
} // namespace RosHandler

#endif