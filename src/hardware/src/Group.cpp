#include "Group.h"

namespace Hardware{
    Group::Group(string aName) {
        name = aName;
    }

    void Group::setPrimaryEncoder(std::shared_ptr<ControlGroup> cg) {
        const std::lock_guard lock{mutex};
        encoderRead = cg;
    }
    
    string Group::getName() const {
        const std::lock_guard lock{mutex};
        return name;
    }

    void Group::addControlGroup(std::shared_ptr<ControlGroup> cg) {
        const std::lock_guard lock{mutex};
        members.push_back(cg);
    }

    void Group::removeControlGroup(std::shared_ptr<ControlGroup> cg) {
        const std::lock_guard lock{mutex};
        for(int i = 0; i < this->members.size(); i++){
            std::shared_ptr<ControlGroup> member = this->members.at(i);
            if(member->getName() == cg->getName()){
                this->members.erase(this->members.begin()+i);
                break;
            }
        }
    }
    
    string Group::getMembers() const {
        const std::lock_guard lock{mutex};
        string membersNames = "";
        for (auto i : members) {
            membersNames.append(i->getName()).append(" ");
        }
        return membersNames;
    }

    void Group::setPower(double power) {
        const std::lock_guard lock{mutex};
        for (auto i : members) {
            i->setPower(power);
        }
    }

    void Group::setReversal(bool inverted) {
        const std::lock_guard lock{mutex};
        for (auto i : members) {
            i->setReversal(inverted);
        }
    }

    void Group::setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
        const std::lock_guard lock{mutex};
        for (auto i : members) {
            i->setZeroPowerBehavior(inputBehavior);
        }
    }

    std::shared_ptr<ControlGroup> Group::getControlGroup(string aName) {
        const std::lock_guard lock{mutex};
        for (auto i : members) {
            if (i->getName() == aName) {
                return i;
            }
        }
        return nullptr;
    }

    void Group::clearGroup() {
        const std::lock_guard lock{mutex};
        members.clear();
    }

    std::optional<double> Group::getEncoder() const {
        const std::lock_guard lock{mutex};
        if(encoderRead == nullptr) {
            return {};
        } else {
            return encoderRead->getEncoder();
        }
    }

    void Group::resetSettings() const {
        const std::lock_guard lock{mutex};
        for (auto i : members) {
            i->resetSettings();
        }
    }
}