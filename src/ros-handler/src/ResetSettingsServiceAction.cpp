#include "ResetSettingsServiceAction.h"
#include "ControlGroup.h"
#include "wrevolution/ResetSettings.h"

namespace RosHandler {

using Hardware::ControlGroup;
using RosHandlerCore::ControlGroupRosServiceAction;
using wrevolution::ResetSettings;

ResetSettingsServiceAction::ResetSettingsServiceAction(ros::NodeHandle &node, const std::shared_ptr<ControlGroup> &controlGroup)
    : ControlGroupRosServiceAction<ResetSettings>(node,
                                                  controlGroup,
                                                  "reset_settings",
                                                  ros::Duration{RESET_SETTINGS_MAX_RESPONSE_DELAY_SECONDS}) {}

auto ResetSettingsServiceAction::onServiceRequest(const ResetSettings::Request &req,
                                                  ResetSettings::Response &resp) -> bool {
    controlGroup->resetSettings();
    return true;
}

} // namespace RosHandler
