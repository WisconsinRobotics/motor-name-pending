#include "motorRos.h"


namespace rosLib {
    void motorRos::motorRos(MotorLib::ControlGroup &cg, int argc, char** argv) {
        aControlGroup = cg;
        ros::init(argc, argv, *cg.getName);
        motorPower = node.subscribe("/control/motor_system/cmd", 1000);
        encoder = n.advertise<std::optional<double>>(getEncoder(), 1000);
        setPower(motorPower);
        setZeroPowerBehavior(<call>(zeroPowerBehavior));
        setReverse(<call>(reverse));
        if(<call>(resetSettings)) {
            resetSettings();
        }
        while(ros::ok()) {
            ros::spinOnce();
        }
    }
    void motorRos::spin(bool set) {
        while(set) {
            ros::spinOnce();
    }
    void motorRos::spinOnce() {
        ros::spinOnce();
    }
    void motorRos::setPower(double power) {
        aControlGroup.setPower(power);
    }
    std::optional<double> motorRos::getEncoder() const {
        return aControlGroup.getEncoder();
    }
    void motorRos::setZeroPowerBehavior(ZeroPowerBehavior inputBehavior) {
        aControlGroup.setZeroPowerBehavior(inputBehavior);
    }
    void motorRos::setReverse(bool inverted) {
        aControlGroup.setReverse(inverted);
    }
    void motorRos::resetSettings() const {
        aControlGroup.resetSettings();
    }