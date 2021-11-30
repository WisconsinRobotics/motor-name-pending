#define Phoenix_No_WPI
#include <stdint.h>
#include <iostream>
#include <stdexcept>
#include "controlgroup.cpp"
#include "ctre/Phoenix.h"
#include "ctre/phoenix/platform/Platform.h"
#include "ctre/phoenix/unmanaged/Unmanaged.h"
#include "ctre/phoenix/cci/Unmanaged_CCI.h"

using namespace ctre::phoenix;
using namespace ctre::phoenix::platform;
using namespace ctre::phoenix::motorcontrol;
using namespace ctre::phoenix::motorcontrol::can;

class Motor: ControlGroup {
    public:
        TalonSRX *motor;

        Motor(uint8_t id) {
            this->motor = new TalonSRX(id);
            deviceid = id;
        };
        void setPower(double power) {
            motor->Set(ControlMode::PercentOutput, power);
        };
        int32_t getEncoder() {
           return motor->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID);
        }
        void setReversal(bool inverted) {
            motor->SetInverted(inverted);
        };
        void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
            switch(inputBehavior) {
                case BRAKE :
                    motor->SetNeutralMode(Brake);
                    break;
                case COAST :
                    motor->SetNeutralMode(Coast);
                    break;
                default : 
                throw std::invalid_argument("Invalid Argument");
            }
        }
        ~Motor(){
            delete motor;
        }
    private:
        uint8_t deviceid;
        static constexpr int8_t PRIMARY_CLOSED_LOOP_PID = 0;
};