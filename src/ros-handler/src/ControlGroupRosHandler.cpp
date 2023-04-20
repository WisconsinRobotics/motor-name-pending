#include "ControlGroupRosHandler.h"
#include "ControlGroup.h"
#include "EncoderTimedAction.h"
#include "PowerSubscribedAction.h"
#include "ResetEncoderServiceAction.h"
#include "ResetSettingsServiceAction.h"
#include "ReverseServiceAction.h"
#include "ZeroPowerBehaviorServiceAction.h"
#include <memory>

namespace RosHandler {

ControlGroupRosHandler::ControlGroupRosHandler(ros::NodeHandle &node, const std::shared_ptr<Hardware::ControlGroup> &controlGroup)
    : encoderAction{std::make_unique<EncoderTimedAction>(node, controlGroup)},
      powerAction{std::make_unique<PowerSubscribedAction>(node, controlGroup)},
      zeroPowerBehaviorAction{std::make_unique<ZeroPowerBehaviorServiceAction>(node, controlGroup)},
      resetSettingsAction{std::make_unique<ResetSettingsServiceAction>(node, controlGroup)},
      reverseAction{std::make_unique<ReverseServiceAction>(node, controlGroup)},
      resetEncoderAction(std::make_unique<ResetEncoderServiceAction>(node, controlGroup)) {}

} // namespace RosHandler