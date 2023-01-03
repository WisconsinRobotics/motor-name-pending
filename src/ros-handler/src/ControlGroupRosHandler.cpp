#include "ControlGroupRosHandler.h"
#include "ControlGroup.h"
#include "EncoderTimedAction.h"
#include "PowerSubscribedAction.h"
#include "ZeroPowerBehaviorServiceAction.h"
#include <memory>

namespace RosHandler {

ControlGroupRosHandler::ControlGroupRosHandler(const std::shared_ptr<Hardware::ControlGroup> &controlGroup, ros::NodeHandle &node)
    : encoderAction{std::make_unique<EncoderTimedAction>(node, controlGroup)},
      powerAction{std::make_unique<PowerSubscribedAction>(node, controlGroup)},
      zeroPowerBehaviorAction{std::make_unique<ZeroPowerBehaviorServiceAction>(node, controlGroup)} {}

} // namespace RosHandler