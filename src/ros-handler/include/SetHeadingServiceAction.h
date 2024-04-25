#ifndef SET_HEADING_SERVICE_ACTION_H
#define SET_HEADING_SERVICE_ACTION_H

#include "PigeonIMU.h"
#include "ros-handler-core/PigeonRosServiceAction.h"
#include "wrevolution/SetHeading.h"

namespace RosHandler {

using Hardware::PigeonIMU;
using RosHandlerCore::PigeonRosServiceAction;

class SetHeadingServiceAction : public PigeonRosServiceAction<wrevolution::SetHeading> {
public:
    SetHeadingServiceAction(ros::NodeHandle &node, const std::shared_ptr<PigeonIMU> &pigeon);

private:
    auto onServiceRequest(const wrevolution::SetHeading::Request &req, wrevolution::SetHeading::Response &resp) -> bool override;

    static constexpr double SET_HEADING_MAX_RESPONSE_DELAY_SECONDS{0.5};
};

} // namespace RosHandler

#endif
