#ifndef __TIMED_ROS_ACTION__
#define __TIMED_ROS_ACTION__

#include "ros/forwards.h"
#include "ros/node_handle.h"
#include "ros/rate.h"
namespace RosHandler {
class TimedRosAction {
public:
    explicit TimedRosAction(const ros::Rate &rate, const ros::NodeHandle &node, std::string_view actionName);

    virtual ~TimedRosAction() = default;
    TimedRosAction(const TimedRosAction &) = delete;
    auto operator=(const TimedRosAction &) -> TimedRosAction & = delete;
    TimedRosAction(TimedRosAction &&) = delete;
    auto operator=(TimedRosAction &&) -> TimedRosAction & = delete;

private:
    void timerCallback(const ros::TimerEvent &event);
    virtual void onTimerEvent(const ros::TimerEvent &event);

    static constexpr double TIMER_TOLERANCE_RATIO{0.1}; // Alert on timers more than 10% out of tol.

    const ros::Timer timer;
    const ros::Rate expectedRate;
    const std::string_view actionName;
};
} // namespace RosHandler

#endif