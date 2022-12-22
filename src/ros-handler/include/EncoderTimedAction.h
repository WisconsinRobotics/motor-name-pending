#ifndef ENCODER_TIMED_ACTION_H
#define ENCODER_TIMED_ACTION_H

#include "ControlGroup.h"
#include "ros-handler-core/ControlGroupRosTimedAction.h"
#include "ros/node_handle.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::ControlGroupRosTimedAction;

class EncoderTimedAction : public ControlGroupRosTimedAction {
public:
    EncoderTimedAction(ros::NodeHandle &node, const std::shared_ptr<ControlGroup> &controlGroup);

private:
    void onTimerEvent(const ros::TimerEvent &event) override;

    const ros::Publisher publisher;
    static constexpr double ENCODER_PUBLISHING_RATE_HZ{50};
    static constexpr uint32_t ENCODER_PUBLISHING_BUFFER_SIZE{1};
};

} // namespace RosHandler

#endif