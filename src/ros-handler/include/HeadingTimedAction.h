#ifndef HEADING_TIMED_ACTION_H
#define HEADING_TIMED_ACTION_H

#include "PigeonIMU.h"
#include "ros-handler-core/PigeonRosTimedAction.h"
#include "ros-handler-core/RosTimedAction.h"

namespace RosHandler {

using Hardware::PigeonIMU;
using RosHandlerCore::PigeonRosTimedAction;

class HeadingTimedAction : public PigeonRosTimedAction {
public:
    HeadingTimedAction(ros::NodeHandle &node, const std::shared_ptr<PigeonIMU> &pigeon);

private:
    void onTimerEvent(const ros::TimerEvent &event) override;

    const ros::Publisher publisher;
    static constexpr double HEADING_PUBLISHER_RATE_HZ{50};
    static constexpr uint32_t HEADING_PUBLISHER_BUFFER_SIZE{1};
};

} // namespace RosHandler

#endif
