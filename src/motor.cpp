#define Phoenix_No_WPI
#include "motor.h"

using std::to_string;

class Motor: public ControlGroup {
    public:
        Motor(uint8_t ID) {
            this->motor = new TalonSRX(ID);
            deviceID = ID;
        }
        void setPower(double power) {
            motor->Set(ControlMode::PercentOutput, power);
        }
        string getName() const {
            return to_string(deviceID);
        }
        int32_t getEncoder() const {
           return motor->GetSelectedSensorPosition(PRIMARY_CLOSED_LOOP_PID);
        }
        void setReversal(bool inverted) {
            motor->SetInverted(inverted);
        }
        void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
            switch(inputBehavior) {
                case ControlGroup::ZeroPowerBehavior::BRAKE :
                    motor->SetNeutralMode(Brake);
                    break;
                case ControlGroup::ZeroPowerBehavior::COAST :
                    motor->SetNeutralMode(Coast);
                    break;
                default : 
                throw std::invalid_argument("Invalid Argument");
            }
        }
        ~Motor(){
            delete motor;
        }
        string getMembers() const {
            return to_string(deviceID) + " is not a Motor Group and has no members!";
        }

    private:
        TalonSRX *motor;
        uint8_t deviceID;
        static constexpr int8_t PRIMARY_CLOSED_LOOP_PID = 0;
};