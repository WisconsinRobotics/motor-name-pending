#ifndef CONTROL_GROUP_H
#define CONTROL_GROUP_H

#include <stdint.h>
#include <string>
#include <optional>

using std::string;

namespace Hardware {
    enum class ZeroPowerBehavior {
        BRAKE, COAST
    };
    class ControlGroup {
        public:
            virtual void setPower(double power) = 0;
            virtual std::optional<double> getEncoder() const = 0;
            virtual void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) = 0;
            virtual void setReversal(bool inverted) = 0;
            virtual string getName() const = 0;
            virtual string getMembers() const = 0;
            virtual void resetSettings() const = 0;
    };
}

#endif