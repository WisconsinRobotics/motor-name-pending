#include "Group.h"

#include <optional>
#include <stdexcept>
#include <utility>

namespace Hardware {
Group::Group(std::string aName) : name{std::move(aName)} {}

void Group::setPrimaryEncoder(std::shared_ptr<ControlGroup> controlGroup) {
    const std::lock_guard lock{mutex};
    encoderRead = std::move(controlGroup);
}

auto Group::getName() const -> std::string {
    const std::lock_guard lock{mutex};
    return name;
}

void Group::addControlGroup(const std::shared_ptr<ControlGroup> &controlGroup) {
    const std::lock_guard lock{mutex};
    members.push_back(controlGroup);
}

void Group::removeControlGroup(ControlGroup &controlGroup) {
    const std::lock_guard lock{mutex};
    for (int i = 0; i < this->members.size(); i++) {
        std::shared_ptr<ControlGroup> member = this->members.at(i);
        if (member->getName() == controlGroup.getName()) {
            this->members.erase(this->members.begin() + i);
            break;
        }
    }
}

auto Group::getMembers() const -> std::string {
    const std::lock_guard lock{mutex};
    std::string membersNames{};
    for (const auto &member : members) {
        membersNames.append(member->getName()).append(" ");
    }
    return membersNames;
}

void Group::setPower(double power) {
    const std::lock_guard lock{mutex};
    for (const auto &member : members) {
        member->setPower(power);
    }
}

void Group::setReversal(bool inverted) {
    const std::lock_guard lock{mutex};
    for (const auto &member : members) {
        member->setReversal(inverted);
    }
}

void Group::setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
    const std::lock_guard lock{mutex};
    for (const auto &member : members) {
        member->setZeroPowerBehavior(inputBehavior);
    }
}

auto Group::getControlGroup(const std::string &aName) -> ControlGroup & {
    const std::lock_guard lock{mutex};
    for (const auto &member : members) {
        if (member->getName() == aName) {
            return *member;
        }
    }
    throw std::invalid_argument{"No member with name " + aName};
}

void Group::clearGroup() {
    const std::lock_guard lock{mutex};
    members.clear();
}

auto Group::getEncoder() const -> std::optional<double> {
    const std::lock_guard lock{mutex};
    if (encoderRead == nullptr) {
        return std::nullopt;
    }
    return encoderRead->getEncoder();
}

void Group::resetSettings() {
    const std::lock_guard lock{mutex};
    for (const auto &member : members) {
        member->resetSettings();
    }
}
} // namespace Hardware