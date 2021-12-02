#ifndef GROUP_H
#define GROUP_H

#include <iostream>
#include <vector>
#include <string>
#include "controlGroup.h"
#include "motor.h"

using std::string;
using std::vector;
using MotorLib::ControlGroup;

namespace MotorLib {
    class Group : ControlGroup {
        public:
            Group(string aName);
            string getName();
            void addControlGroup(ControlGroup cg);
            void removeControlGroup(ControlGroup cg);
            string getMembers();
            void setPower(double power);
            void setReversal(bool inverted);
            void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior);
            ControlGroup getControlGroup (string aName);
            void clearGroup();
            int32_t getEncoder();
            void setEncoder(ControlGroup cg);

        private:
            ControlGroup encoderRead;
            string name;
            vector<ControlGroup> members;
    };
}

#endif