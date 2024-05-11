#include <cmath>
#include <memory>
#include <optional>
#include <string>

#include "PigeonIMU.h"

#define Phoenix_No_WPI
#include "ctre/phoenix/sensors/Pigeon2.h"

namespace Hardware {

PigeonIMU::PigeonIMU(uint8_t canID, std::string friendlyName) :
    imu(std::make_unique<Pigeon2>(canID)),
    deviceID(canID),
    friendlyName(std::move(friendlyName)) {}

auto PigeonIMU::getName() const -> std::string{
    const std::lock_guard lock{mutex};
    return friendlyName;
}

auto PigeonIMU::getYaw() const -> std::optional<double> {
    const std::lock_guard lock{mutex};
    double angle = std::fmod(imu->GetYaw(), 360);
    angle = angle >= 0 ? angle : angle + 360;
    return std::make_optional(angle);
}

void PigeonIMU::setYaw(double angleDeg) {
    const std::lock_guard lock{mutex};
    imu->SetYaw(angleDeg);
}

}
