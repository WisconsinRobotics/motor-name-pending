#ifndef MOTOR_ROS_H
#define MOTOR_ROS_H
#include "communicationHandler.h"
#include "controlGroup.h"
#include "ros/ros.h"

namespace rosLib {
    class motorRos : public communicationHandler {
        public:
            motorRos(MotorLib::ControlGroup &cg);
            void setPower(double power);
            std::optional<double> getEncoder() const;
            void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior);
            void setReverse(bool inverted);
            void resetSettings() const;
        private:
            MotorLib::ControlGroup &aControlGroup;
            ros::NodeHandle node;
            ros::Subscriber motorPower;
            ros::Subscriber encoder:
            motor-name-pending::resetSettings reset;
            motor-name-pending::reverse inverted;
            motor-name-pending::zeroPowerBehavior behavior;
    };
}
#endif