#ifndef MOCK_MOTOR_H
#define MOCK_MOTOR_H

#include "ControlGroup.h"
#include <chrono>
#include <mutex>

namespace Hardware {

class MockMotor : public ControlGroup {

public:
    explicit MockMotor(std::string_view name);

    [[nodiscard]] auto getEncoder() const -> std::optional<double> override;
    [[nodiscard]] auto getMembers() const -> std::string override;
    [[nodiscard]] auto getName() const -> std::string override;
    void resetSettings() override;
    void setPower(double power) override;
    void setReversal(bool inverted) override;
    void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) override;

private:
    void updateEncoder() const;

    mutable std::mutex mutex;
    const std::string_view name;
    mutable double encoder{0};
    const int32_t ENC_PER_SECOND_MAX_SPEED{200};
    int32_t speed{0};
    int32_t inversion{1};
    mutable std::chrono::time_point<std::chrono::steady_clock> lastEncoderCalculation;
};
} // namespace Hardware

#endif