#define Phoenix_No_WPI
#include "motor.h"

using std::to_string;

namespace MotorLib{
    Motor::Motor(uint8_t ID) {
        this->motor = std::unique_ptr<TalonFX>(new TalonFX{ID});
        deviceID = ID;
    }
    void Motor::setPower(double power) {
        const std::lock_guard lock{this->m};
        motor->Set(ControlMode::PercentOutput, power);
    }
    string Motor::getName() const {
        const std::lock_guard lock{this->m};
        return to_string(deviceID);
    }
    std::optional<double> Motor::getEncoder() const {
        const std::lock_guard lock{this->m};
        return motor->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID);
    }
    void Motor::setReversal(bool inverted) {
        const std::lock_guard lock{this->m};
        motor->SetInverted(inverted);
    }
    void Motor::setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
        const std::lock_guard lock{this->m};
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
    void Motor::resetSettings() const {
        const std::lock_guard lock{this->m};
        motor->SetInverted(false);
        motor->SetSensorPhase(false);
        motor->SetSelectedSensorPosition(0, PRIMARY_CLOSED_LOOP_PID, 100);
        motor->SetNeutralMode(Brake);
    }
    string Motor::getMembers() const {
        const std::lock_guard lock{this->m};
        return to_string(deviceID) + " is not a Motor Group and has no members!";
    }
}