#include "ros-handler-core/RosTimedAction.h"

namespace RosHandler::RosHandlerCore {

RosTimedAction::RosTimedAction(const ros::Rate &rate,
                               const ros::NodeHandle &node,
                               std::string_view actionName)
    : timer{node.createTimer(rate, &RosTimedAction::timerCallback, this)},
      expectedRate{rate},
      actionName{actionName} {}

void RosTimedAction::timerCallback(const ros::TimerEvent &event) {
    // Timer monitor code
    const auto timingDifference{event.current_expected - event.current_real};
    const auto relativeDifference{std::abs((timingDifference - expectedRate.expectedCycleTime()).toSec() / expectedRate.expectedCycleTime().toSec())};

    if (relativeDifference > TIMER_TOLERANCE_RATIO) {
        ROS_WARN_STREAM( // NOLINT(hicpp-no-array-decay,cppcoreguidelines-pro-bounds-array-to-pointer-decay); Req'd for ROS logging
            "Timer '" << actionName << "' is out of tolerance: Exp " << expectedRate.expectedCycleTime() << " Act " << timingDifference);
    }

    // Run inheritance-defined callback
    onTimerEvent(event);
}

} // namespace RosHandler::RosHandlerCore
