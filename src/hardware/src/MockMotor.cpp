#include "MockMotor.h"
#include <chrono>
#include <mutex>

#include <iostream>

namespace Hardware {

MockMotor::MockMotor(std::string_view name)
    : name{name},
      lastEncoderCalculation{std::chrono::steady_clock::now()} {}

auto MockMotor::getEncoder() const -> std::optional<double> {
    std::lock_guard lock{mutex};
    updateEncoder();
    return std::make_optional(encoder);
}

auto MockMotor::getMembers() const -> std::string {
    std::lock_guard lock{mutex};
    return "";
}

auto MockMotor::getName() const -> std::string {
    std::lock_guard lock{mutex};
    return std::string{name};
}

void MockMotor::resetSettings() {
    std::lock_guard lock{mutex};
    encoder = 0;
    speed = 0;
}

void MockMotor::setPower(double power) {
    std::lock_guard lock{mutex};
    speed = static_cast<int32_t>(inversion * ENC_PER_SECOND_MAX_SPEED * power);
}

void MockMotor::setReversal(bool inverted) {
    std::lock_guard lock{mutex};
    if ((inverted && inversion == 1) || (!inverted && inversion == -1)) {
        inversion *= -1;
        speed *= -1;
        updateEncoder();
        // TODO: Does the encoder flop as well in hardware?  If so, it should be replicated here
    }
}

void MockMotor::setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
    std::lock_guard lock{mutex};
    // Mock motors currently do not support ZeroPowerBehavior
    // TODO: Simulate ZeroPowerBehavior in the mock
}

// DO NOT LOCK THE MUTEX!
// Trust the caller to have acquired the mutex prior to modifying the encoder
// else deadlock
void MockMotor::updateEncoder() const {
    const auto currentCalculationTime = std::chrono::steady_clock::now();
    const auto deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(currentCalculationTime - lastEncoderCalculation);
    const auto encoderDelta = speed * deltaTime.count();
    encoder += encoderDelta;
    lastEncoderCalculation = currentCalculationTime;
}

} // namespace Hardware