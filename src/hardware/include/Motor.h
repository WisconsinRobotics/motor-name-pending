#ifndef MOTOR_H
#define MOTOR_H

#include "ControlGroup.h"
#define Phoenix_No_WPI
#include "ctre/phoenix/motorcontrol/can/TalonFX.h"
#include <memory>
#include <mutex>
#include <stdexcept>

using ctre::phoenix::motorcontrol::can::TalonFX;
namespace Hardware {
class Motor : public ControlGroup {
public:
    explicit Motor(uint8_t motorID);
    void setPower(double power) override;
    auto getEncoder() const -> std::optional<double> override;
    void setReversal(bool inverted) override;
    void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) override;
    auto getName() const -> std::string override;
    auto getMembers() const -> std::string override;
    void resetSettings() const override;

private:
    mutable std::mutex mutex;
    std::unique_ptr<TalonFX> motor;
    uint8_t deviceID;
    static constexpr int8_t PRIMARY_CLOSED_LOOP_PID{0};
    static constexpr int32_t ENCODER_RESET_TIMEOUT_MILLISECONDS{100};
};
} // namespace Hardware

#endif