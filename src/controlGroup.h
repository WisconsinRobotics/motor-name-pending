#ifndef CONTROL_GROUP_H
#define CONTROL_GROUP_H

#include <iostream>
#include <stdint.h>
#include <string>

using std::string;

namespace MotorLib {
    class ControlGroup {
        public:
            enum class ZeroPowerBehavior {
                BRAKE, COAST
            };
            void setPower(double power);
            const int32_t getEncoder();
            void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior);
            void setReversal(bool inverted);
            const string getName();
            const string getMembers();
    };
}

#endif