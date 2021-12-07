#include "group.h"

using std::find;
using std::swap;


class Group : public ControlGroup {
    public:
        Group(string aName) {
            name = aName;
        }
        const string getName() {
            return name;
        }
        void addControlGroup(ControlGroup cg) {
            members.push_back(cg);
        }
        void removeControlGroup(ControlGroup cg) {
            auto it = find(members.begin(), members.end(), cg);
            if (it != members.end()) {
                swap(*it, members.back());
            }
            members.pop_back();
        }
        const string getMembers() {
            string membersNames = "";
            for (auto i : members) {
                membersNames.append(i.getName()).append(" ");
            }
            return membersNames;
        }
        void setPower(double power) {
            for (auto i : members) {
                i.setPower(power);
            }
        }
        void setReversal(bool inverted) {
            for (auto i : members) {
                i.setReversal(inverted);
            }
        }
        void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
            for (auto i : members) {
                i.setZeroPowerBehavior(inputBehavior);
            }
        }
        ControlGroup getControlGroup(string aName) {
            for (auto i : members) {
                if (i.getName() == aName) {
                    return i;
                }
            }
        }
        void clearGroup() {
            members.clear();
        }
        const int32_t getEncoder() {
            return encoderRead.getEncoder();
        }
        void setEncoder(ControlGroup cg) {
            encoderRead = cg;
        }
    private:
        ControlGroup encoderRead;
        string name;
        vector<ControlGroup> members;
};