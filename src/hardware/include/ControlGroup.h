#ifndef CONTROL_GROUP_H
#define CONTROL_GROUP_H

#include <cstdint>
#include <optional>
#include <string>

namespace Hardware {
enum class ZeroPowerBehavior {
    BRAKE,
    COAST
};

class ControlGroup {
public:
    virtual void setPower(double power) = 0;
    [[nodiscard]] virtual auto getEncoder() const -> std::optional<double> = 0;
    virtual void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) = 0;
    virtual void setReversal(bool inverted) = 0;
    [[nodiscard]] virtual auto getName() const -> std::string = 0;
    [[nodiscard]] virtual auto getMembers() const
        -> std::string = 0; // TODO: Is this necessary?
    virtual void resetSettings() = 0;

    ControlGroup() = default;
    virtual ~ControlGroup() = default;
    ControlGroup(const ControlGroup &) = delete;
    auto operator=(const ControlGroup &) -> ControlGroup & = delete;
    ControlGroup(ControlGroup &&) = delete;
    auto operator=(ControlGroup &&) -> ControlGroup & = delete;
};
} // namespace Hardware

#endif