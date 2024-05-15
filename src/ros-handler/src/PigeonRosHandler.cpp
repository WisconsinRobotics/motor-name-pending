#include "PigeonRosHandler.h"
#include "HeadingTimedAction.h"
#include "PigeonIMU.h"
#include "SetHeadingServiceAction.h"
#include <memory>

namespace RosHandler {

PigeonRosHandler::PigeonRosHandler(ros::NodeHandle &node, const std::shared_ptr<Hardware::PigeonIMU> &pigeon)
    : headingAction{std::make_unique<HeadingTimedAction>(node, pigeon)},
      setHeadingAction{std::make_unique<SetHeadingServiceAction>(node, pigeon)} {}

} // namespace RosHandler
