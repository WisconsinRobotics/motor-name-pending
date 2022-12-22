#include "ros-handler-core/RosTimedAction.h"

namespace RosHandler::RosHandlerCore {

RosTimedAction::RosTimedAction(const ros::Rate &rate,
                               const ros::NodeHandle &node,
                               std::string actionName)
    : timer{node.createTimer(rate, &RosTimedAction::timerCallback, this)},
      expectedRate{rate},
      actionName{std::move(actionName)} {}

void RosTimedAction::timerCallback(const ros::TimerEvent &event) {
    // Run inheritance-defined callback
    onTimerEvent(event);
}

} // namespace RosHandler::RosHandlerCore
