#ifndef RESET_SETTINGS_SERVICE_ACTION_H
#define RESET_SETTINGS_SERVICE_ACTION_H

#include "ros-handler-core/ControlGroupRosServiceAction.h"
#include "wrevolution/ResetSettings.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::ControlGroupRosServiceAction;

class ResetSettingsServiceAction : public ControlGroupRosServiceAction<wrevolution::ResetSettings> {
public:
    ResetSettingsServiceAction(ros::NodeHandle &node, const std::shared_ptr<ControlGroup> &controlGroup);

private:
    auto onServiceRequest(const wrevolution::ResetSettings::Request &req, wrevolution::ResetSettings::Response &resp) -> bool override;

    static constexpr double RESET_SETTINGS_MAX_RESPONSE_DELAY_SECONDS{0.5};
};

} // namespace RosHandler

#endif