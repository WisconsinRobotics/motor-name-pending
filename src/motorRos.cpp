#include "motorRos.h"


namespace rosLib {
    motorRos(std::unordered_set<std::shared_ptr<MotorLib::ControlGroup>> &cgList) {
        for(auto x : cgList) {
            std::unordered_set<boost::function> temp;
            temp.insert(boost::bind(motorRos::setPower, _1, x)(power));
            temp.insert(boost::bind(motorRos::getEncoder, x);
            aMap[x] = temp;
        }
    }
    void motorRos::spin(bool set) {
        if(!ros::ok()) {
            return;
        }
        do {
        } while(ros::ok() && set);
    }
    void motorRos::spinOnce() {
        spin(false);
    }
    void motorRos::setPower(double power, std::shared_ptr<MotorLib::ControlGroup> ptr) {
        ptr->setPower(power);
    }
    std::optional<double> motorRos::getEncoder(std::shared_ptr<MotorLib::ControlGroup> ptr) const {
        return ptr->getEncoder();
    }
    void motorRos::setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
        aControlGroup.setZeroPowerBehavior(inputBehavior);
    }
    void motorRos::setReverse(std_srvs::SetBool inverted, std::shared_ptr<MotorLib::ControlGroup> ptr) {
        ptr->setReverse(inverted);
    }
    void motorRos::resetSettings() const {
        aControlGroup.resetSettings();
    }
}