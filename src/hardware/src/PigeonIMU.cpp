#include <cmath>
#include <memory>
#include <optional>
#include <string>

#include "PigeonIMU.h"
#include "ctre/phoenix/paramEnum.h"

#define Phoenix_No_WPI
#include "ctre/phoenix/sensors/Pigeon2.h"

namespace Hardware {

PigeonIMU::PigeonIMU(uint8_t canID, std::string friendlyName) :
    imu{std::make_unique<Pigeon2>(canID)},
    deviceID{canID},
    friendlyName{std::move(friendlyName)} {

    }

auto PigeonIMU::getName() const -> std::string{
    const std::lock_guard lock{mutex};
    return friendlyName;
}

void PigeonIMU::setOrientation(AxisDirection forward, AxisDirection up) {
    imu->ConfigMountPose(forward, up);
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

void PigeonIMU::startMagCal() {
    imu->ConfigSetParameter(ctre::phoenix::eMagCalRunning, 1, 0, 0);
}

void PigeonIMU::endMagCal(bool saveMagCal) {
    // Apply calibration
    if (saveMagCal) {
        imu->ConfigSetParameter(ctre::phoenix::eMagCal, 0, 0, 0);
    }
    imu->ConfigSetParameter(ctre::phoenix::eMagCalRunning, 0, 0, 0);
}

void PigeonIMU::enableCompass(bool enable) {
    imu->ConfigEnableCompass(enable);
    if (enable) {
        imu->SetYawToCompass();
    }
}

}
