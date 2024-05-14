#ifndef PIGEON_H
#define PIGEON_H

#include <mutex>
#include <optional>

#define Phoenix_No_WPI
#include "ctre/phoenix/sensors/Pigeon2.h"

using ctre::phoenix::sensors::Pigeon2;

namespace Hardware {
class PigeonIMU {
public:
    explicit PigeonIMU(uint8_t canID, std::string friendlyName);
    auto getName() const -> std::string;
    [[nodiscard]] auto getYaw() const -> std::optional<double>;
    void setYaw(double angleDeg);
    void startMagCal();
    void endMagCal(bool saveMagCal);
    void enableCompass(bool enable);

private:
    mutable std::mutex mutex;
    std::unique_ptr<Pigeon2> imu;
    uint8_t deviceID;
    const std::string friendlyName;
};
} // namespace Hardware

#endif
