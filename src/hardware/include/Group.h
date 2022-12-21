#ifndef GROUP_H
#define GROUP_H

#include "ControlGroup.h"
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <vector>

namespace Hardware {
class Group : public ControlGroup {
public:
    explicit Group(std::string aName);
    auto getName() const -> std::string override;
    void addControlGroup(const std::shared_ptr<ControlGroup> &controlGroup);
    void removeControlGroup(const ControlGroup &controlGroup);
    auto getMembers() const -> std::string override;
    void setPower(double power) override;
    void setReversal(bool inverted) override;
    void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) override;
    auto getControlGroup(const std::string &aName) -> ControlGroup &;
    void clearGroup();
    auto getEncoder() const -> std::optional<double> override;
    void setPrimaryEncoder(std::shared_ptr<ControlGroup> controlGroup);
    void resetSettings() override;

private:
    std::shared_ptr<ControlGroup> encoderRead;
    std::string name;
    std::vector<std::shared_ptr<ControlGroup>> members;
    mutable std::mutex mutex;
};
} // namespace Hardware

#endif