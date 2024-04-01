#include "ros/init.h"
#include "ros/node_handle.h"
#include "ros/rate.h"
#include "std_msgs/Float64.h"
#define Phoenix_No_WPI
#include "ctre/phoenix/sensors/Pigeon2.h"
#include "ctre/phoenix/platform/can/PlatformCAN.h"

auto main(int32_t argc, char **argv) -> int32_t {

    ctre::phoenix::platform::can::PlatformCAN::SetCANInterface("can0");
    ctre::phoenix::sensors::Pigeon2 pigeon = ctre::phoenix::sensors::Pigeon2(1);

    ros::init(argc, argv, "PigeonIMU");
    ros::NodeHandle nHandle;

    auto headingPub{nHandle.advertise<std_msgs::Float64>("/heading", 10)};

    ros::Rate rate(10);

    while (ros::ok()) {
        std_msgs::Float64 headingMsg;
        headingMsg.data = pigeon.GetYaw();

        headingPub.publish(headingMsg);

        rate.sleep();
    }

    return 0;
}
