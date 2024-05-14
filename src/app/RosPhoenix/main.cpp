#include "ControlGroup.h"
#include "ControlGroupRosHandler.h"
#include "Group.h"
#include "Motor.h"
#include "PigeonIMU.h"
#include "PigeonRosHandler.h"
#include "ros/node_handle.h"
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>


#include "ctre/phoenix/platform/Platform.h"
#include "ctre/phoenix/platform/can/PlatformCAN.h"
#include "ctre/phoenix/unmanaged/Unmanaged.h"

auto main(int32_t argc, char **argv) -> int32_t {

    // TODO (@Tzanccc): currently a magic string, consider changing it use command line arguments or some other equivalent
    ctre::phoenix::platform::can::PlatformCAN::SetCANInterface("can0");

    std::cout << "wrevolution ROS test start..." << std::endl;

    // Simple motor setup
    auto motor1{std::make_shared<Hardware::Motor>(1, "frontLeft")};
    auto motor2{std::make_shared<Hardware::Motor>(2, "midLeft")};
    auto motor3{std::make_shared<Hardware::Motor>(3, "backLeft")};

    auto motor4{std::make_shared<Hardware::Motor>(4, "frontRight")};
    auto motor5{std::make_shared<Hardware::Motor>(5, "midRight")};
    auto motor6{std::make_shared<Hardware::Motor>(6, "backRight")};

    auto leftGroup{std::make_shared<Hardware::Group>("left")};
    auto rightGroup{std::make_shared<Hardware::Group>("right")};

    leftGroup->addControlGroup(motor1);
    leftGroup->addControlGroup(motor2);
    leftGroup->addControlGroup(motor3);

    rightGroup->addControlGroup(motor4);
    rightGroup->addControlGroup(motor5);
    rightGroup->addControlGroup(motor6);

    leftGroup->setZeroPowerBehavior(Hardware::ZeroPowerBehavior::COAST);
    rightGroup->setZeroPowerBehavior(Hardware::ZeroPowerBehavior::COAST);

    auto pigeonIMU{std::make_shared<Hardware::PigeonIMU>(10, "pigeon")};
    pigeonIMU->enableCompass(true);

    std::cout << "Motor setup complete!" << std::endl;

    // Setup ROS Interface
    ros::init(argc, argv, "RosControlTest");
    ros::NodeHandle node{};

    // auto timer = node.createTimer(ros::Duration{0.01}, [](const ros::TimerEvent& event)->void {
    // });

    auto leftHandler{std::make_unique<RosHandler::ControlGroupRosHandler>(node, leftGroup)};
    auto rightHandler{std::make_unique<RosHandler::ControlGroupRosHandler>(node, rightGroup)};
    auto pigeonHandler{std::make_shared<RosHandler::PigeonRosHandler>(node, pigeonIMU)};

    std::cout << "ROS Setup complete!" << std::endl;

    // Spin ROS comms
    ros::spin();

    std::cout << "Shutting down..." << std::endl;

    return 0;
}
