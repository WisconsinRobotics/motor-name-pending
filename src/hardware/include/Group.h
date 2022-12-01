#ifndef GROUP_H
#define GROUP_H

#include "ControlGroup.h"
#include <memory>
#include <mutex>
#include <optional>
#include <string>
#include <vector>

using Hardware::ControlGroup;
using std::string;
using std::vector;

namespace Hardware {
class Group : public ControlGroup {
public:
    explicit Group(string aName);
    auto getName() const -> string override;
    void addControlGroup(std::shared_ptr<ControlGroup> controlGroup);
    void removeControlGroup(std::shared_ptr<ControlGroup> controlGroup);
    auto getMembers() const -> string override;
    void setPower(double power) override;
    void setReversal(bool inverted) override;
    void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) override;
    auto getControlGroup(string aName) -> std::shared_ptr<ControlGroup>;
    void clearGroup();
    auto getEncoder() const -> std::optional<double> override;
    void setPrimaryEncoder(std::shared_ptr<ControlGroup> controlGroup);
    void resetSettings() const override;

private:
    std::shared_ptr<ControlGroup> encoderRead;
    string name;
    vector<std::shared_ptr<ControlGroup>> members;
    mutable std::mutex mutex;
};
} // namespace Hardware

#endif