add_library(hardware)

target_sources(hardware
    PRIVATE
    src/Group.cpp
    src/Motor.cpp
    src/MockMotor.cpp
    src/PigeonIMU.cpp
)

target_include_directories(hardware PUBLIC include)

MakeTalonTarget(hardware)
# TODO (@bennowotny ): hardware should not depend on ROS
MakeROSTarget(hardware)
