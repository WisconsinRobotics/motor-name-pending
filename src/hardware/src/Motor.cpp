#define Phoenix_No_WPI
#include "Motor.h"
#include "ctre/phoenix/motorcontrol/NeutralMode.h"
#include "ctre/phoenix/motorcontrol/can/TalonFX.h"
#include "ctre/phoenix/unmanaged/Unmanaged.h"
#include <optional>
#include <iostream>

#include <memory>

using std::to_string;

namespace Hardware {

using ctre::phoenix::motorcontrol::ControlMode;
using ctre::phoenix::motorcontrol::NeutralMode;

Motor::Motor(uint8_t motorID, std::string friendlyName)
    : motor{std::make_unique<TalonFX>(motorID)},
      deviceID{motorID},
      friendlyName{std::move(friendlyName)} {}

void Motor::setPower(double power) {
    const std::lock_guard lock{mutex};
    ctre::phoenix::unmanaged::FeedEnable(1000);
    motor->Set(ControlMode::PercentOutput, power);
}

auto Motor::getName() const -> std::string {
    const std::lock_guard lock{mutex};
    return friendlyName;
}

auto Motor::getEncoder() const -> std::optional<double> {
    const std::lock_guard lock{mutex};
    return std::make_optional(
        motor->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID));
}

void Motor::setReversal(bool inverted) {
    const std::lock_guard lock{mutex};
    motor->SetInverted(inverted);
}

void Motor::setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
    const std::lock_guard lock{mutex};
    switch (inputBehavior) {
    case ZeroPowerBehavior::BRAKE:
        motor->SetNeutralMode(NeutralMode::Brake);
        break;
    case ZeroPowerBehavior::COAST:
        motor->SetNeutralMode(NeutralMode::Coast);
        break;
    default:
        throw std::invalid_argument("Invalid Argument");
    }
}

void Motor::resetSettings() {
    const std::lock_guard lock{mutex};
    motor->SetInverted(false);
    motor->SetSensorPhase(false);
    motor->SetSelectedSensorPosition(0, PRIMARY_CLOSED_LOOP_PID,
                                     ENCODER_RESET_TIMEOUT_MILLISECONDS);
    motor->SetNeutralMode(NeutralMode::Brake);
}

auto Motor::getMembers() const -> std::string {
    const std::lock_guard lock{mutex};
    return to_string(deviceID) + " is not a Motor Group and has no members!";
}
} // namespace Hardware