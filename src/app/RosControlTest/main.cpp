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

    // Simple motor setup
    auto motor1{std::make_shared<Hardware::MockMotor>("MOTOR_1")};
    auto motor2{std::make_shared<Hardware::MockMotor>("MOTOR_2")};

    // Complex motor setup
    auto motor3{std::make_shared<Hardware::MockMotor>("MOTOR_3")};
    auto motor4{std::make_shared<Hardware::MockMotor>("MOTOR_4")};

    auto motorGroup{std::make_shared<Hardware::Group>("MOCK_GROUP")};
    motorGroup->addControlGroup(motor3);
    motorGroup->addControlGroup(motor4);

    const std::vector<std::shared_ptr<Hardware::ControlGroup>> testingGroups{
        motor1,
        motor2,
        motorGroup};

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