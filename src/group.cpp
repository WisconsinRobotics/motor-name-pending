#include "group.h"

// using std::find;
using std::swap;

namespace MotorLib{
    Group::Group(string aName) {
        name = aName;
    }
    void Group::setPrimaryEncoder(std::shared_ptr<ControlGroup> cg) {
        encoderRead = cg;
    }
    string Group::getName() const {
        return name;
    }
    void Group::addControlGroup(std::shared_ptr<ControlGroup> cg) {
        members.push_back(cg);
    }
    void Group::removeControlGroup(std::shared_ptr<ControlGroup> cg) {
        for(int i = 0; i < this->members.size(); i++){
            std::shared_ptr<ControlGroup> member = this->members.at(i);
            if(member->getName() == cg->getName()){
                this->members.erase(this->members.begin()+i);
                break;
            }
        }
    }
    string Group::getMembers() const {
        string membersNames = "";
        for (auto i : members) {
            membersNames.append(i->getName()).append(" ");
        }
        return membersNames;
    }
    void Group::setPower(double power) {
        for (auto i : members) {
            i->setPower(power);
        }
    }
    void Group::setReversal(bool inverted) {
        for (auto i : members) {
            i->setReversal(inverted);
        }
    }
    void Group::setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
        for (auto i : members) {
            i->setZeroPowerBehavior(inputBehavior);
        }
    }
    std::shared_ptr<ControlGroup> Group::getControlGroup(string aName) {
        for (auto i : members) {
            if (i->getName() == aName) {
                return i;
            }
        }
        return nullptr;
    }
    void Group::clearGroup() {
        members.clear();
    }
    std::optional<double> Group::getEncoder() const {
        if(encoderRead == nullptr) {
            return {};
        } else {
            return encoderRead->getEncoder();
        }
    }
    void Group::resetSettings() const {
        for (auto i : members) {
            i->resetSettings();
        }
    }
}