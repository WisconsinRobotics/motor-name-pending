#ifndef MOTOR_H
#define MOTOR_H

#define Phoenix_No_WPI
#include <stdexcept>
#include "ctre/Phoenix.h"
#include "ctre/phoenix/platform/Platform.h"
#include "ctre/phoenix/unmanaged/Unmanaged.h"
#include "ctre/phoenix/cci/Unmanaged_CCI.h"
#include "controlGroup.h"

using namespace ctre::phoenix;
using namespace ctre::phoenix::platform;
using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;
using MotorLib::ControlGroup;

namespace MotorLib {
    class Motor : public ControlGroup {
        public:
            Motor(uint8_t ID);
            void setPower(double power);
            const int32_t getEncoder();
            void setReversal(bool inverted);
            void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior);
            const string getName();
            const string getMembers();
            ~Motor();

        private:
            TalonSRX *motor;
            uint8_t deviceID;
            static constexpr int8_t PRIMARY_CLOSED_LOOP_PID = 0;
    };
}

#endif