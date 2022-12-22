#ifndef __TIMED_ROS_ACTION__
#define __TIMED_ROS_ACTION__

#include "ros/forwards.h"
#include "ros/node_handle.h"
#include "ros/rate.h"

namespace RosHandler::RosHandlerCore {

class RosTimedAction {
public:
    RosTimedAction(const ros::Rate &rate, const ros::NodeHandle &node, std::string actionName);

    virtual ~RosTimedAction() = default;
    RosTimedAction(const RosTimedAction &) = delete;
    auto operator=(const RosTimedAction &) -> RosTimedAction & = delete;
    RosTimedAction(RosTimedAction &&) = delete;
    auto operator=(RosTimedAction &&) -> RosTimedAction & = delete;

private:
    void timerCallback(const ros::TimerEvent &event);
    virtual void onTimerEvent(const ros::TimerEvent &event) = 0;

    static constexpr double TIMER_TOLERANCE_RATIO{0.5}; // Alert on timers more than 10% out of tol.

    const ros::Timer timer;
    const ros::Rate expectedRate;
    const std::string actionName;
};

} // namespace RosHandler::RosHandlerCore

#endif