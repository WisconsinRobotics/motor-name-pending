#define Phoenix_No_WPI
#include "motor.h"

using std::to_string;

namespace MotorLib{
    Motor::Motor(uint8_t ID) {
        this->motor = std::unique_ptr<TalonFX>(new TalonFX{ID});
        deviceID = ID;
    }
    void Motor::setPower(double power) {
        motor->Set(ControlMode::PercentOutput, power);
    }
    string Motor::getName() const {
        return to_string(deviceID);
    }
    double Motor::getEncoder() const {
        return motor->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID);
    }
    void Motor::setReversal(bool inverted) {
        motor->SetInverted(inverted);
    }
    void Motor::setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
        switch(inputBehavior) {
            case ZeroPowerBehavior::BRAKE :
                motor->SetNeutralMode(Brake);
                break;
            case ZeroPowerBehavior::COAST :
                motor->SetNeutralMode(Coast);
                break;
            default : 
            throw std::invalid_argument("Invalid Argument");
        }
    }
    string Motor::getMembers() const {
        return to_string(deviceID) + " is not a Motor Group and has no members!";
    }
}