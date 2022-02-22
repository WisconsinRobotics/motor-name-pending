#ifndef MOTOR_ROS_H
#define MOTOR_ROS_H
#include <unordered_set>
#include <unordered_map>
#include <memory>
#include "communicationHandler.h"
#include "controlGroup.h"
#include "ros/ros.h"


namespace rosLib {
    class motorRos : public communicationHandler {
        public:
            motorRos(std::unordered_set<std::shared_ptr<MotorLib::ControlGroup>> &cgList);
        private:
            void setPower(double power, std::shared_ptr<MotorLib::ControlGroup> ptr);
            std::optional<double> getEncoder(std::shared_ptr<MotorLib::ControlGroup> ptr) const;
            void setZeroPowerBehavior(ZeroPowerBehavior inputBehavior, std::shared_ptr<MotorLib::ControlGroup> ptr);
            void setReverse(bool inverted, std::shared_ptr<MotorLib::ControlGroup> ptr);
            void resetSettings(std::shared_ptr<MotorLib::ControlGroup> ptr) const;
            std::unordered_map<std::shared_ptr<MotorLib::ControlGroup>, std::unordered_set<boost::function>> aMap;
            ros::NodeHandle node;
    };
}
#endif