#include "ControlGroup.h"
#include "ControlGroupRosHandler.h"
#include "Group.h"
#include "MockMotor.h"
#include "ros/node_handle.h"
#include <cstdint>
#include <iostream>
#include <memory>
#include <vector>

auto main(int32_t argc, char **argv) -> int32_t {
    std::cout << "wrevolution ROS test start..." << std::endl;

    // motors 1 - 3
    auto motor1{std::make_shared<Hardware::Motor>(1, "LeftBackMotor_1")};
    auto motor2{std::make_shared<Hardware::Motor>(2, "LeftMiddleMotor_2")};
    auto motor3{std::make_shared<Hardware::Motor>(3, "LeftFrontMotor_3")};

    // motors 4 - 6
    auto motor4{std::make_shared<Hardware::Motor>(4, "RightBackMotor_4")};
    auto motor5{std::make_shared<Hardware::Motor>(5, "RightMiddleMotor_5")};
    auto motor6{std::make_shared<Hardware::Motor>(6, "RightFrontMotor_6")};

    // motor group 1
    auto motorGroup1{std::make_shared<Hardware::Group>("LeftGroupMotors")};
    motorGroup1->addControlGroup(motor1);
    motorGroup1->addControlGroup(motor2);
    motorGroup1->addControlGroup(motor3);

    // motor group 2
    auto motorGroup1{std::make_shared<Hardware::Group>("RightGroupMotors")};
    motorGroup2->addControlGroup(motor4);
    motorGroup2->addControlGroup(motor5);
    motorGroup2->addControlGroup(motor6);

    std::cout << "Motor setup complete!" << std::endl;

    // Setup ROS Interface
    ros::init(argc, argv, "RosControlTest");
    ros::NodeHandle node{};

    std::vector<std::unique_ptr<RosHandler::ControlGroupRosHandler>> controlGroupHandlers{};

    controlGroupHandlers.reserve(testingGroups.size());

    for (const auto &controlGroup : testingGroups) {
        controlGroupHandlers.push_back(std::make_unique<RosHandler::ControlGroupRosHandler>(node, controlGroup));
    }

    std::cout << "ROS Setup complete!" << std::endl;

    // Spin ROS comms
    ros::spin();

    std::cout << "Shutting down..." << std::endl;

    return 0;
}
