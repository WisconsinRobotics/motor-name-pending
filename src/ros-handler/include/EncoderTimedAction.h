#ifndef ENCODER_TIMED_ACTION_H
#define ENCODER_TIMED_ACTION_H

#include "ControlGroup.h"
#include "ros-handler-core/RosTimedAction.h"
#include "ros/node_handle.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::RosTimedAction;

class EncoderTimedAction : public RosTimedAction {
public:
    EncoderTimedAction(ros::NodeHandle &node, std::shared_ptr<ControlGroup> controlGroup);

private:
    void onTimerEvent(const ros::TimerEvent &event) override;

    const ros::Publisher publisher;
    const std::shared_ptr<ControlGroup> controlGroup;
    static constexpr double ENCODER_PUBLISHING_RATE_HZ{100};
    static constexpr uint32_t ENCODER_PUBLISHING_BUFFER_SIZE{1};
};

} // namespace RosHandler

#endif