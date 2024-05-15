add_library(ros-handler)

target_sources(ros-handler
    PRIVATE
    src/ros-handler-core/RosTimedAction.cpp
    src/ros-handler-core/ControlGroupRosTimedAction.cpp
    src/ros-handler-core/PigeonRosTimedAction.cpp
    src/EncoderTimedAction.cpp
    src/ZeroPowerBehaviorServiceAction.cpp
    src/PowerSubscribedAction.cpp
    src/ControlGroupRosHandler.cpp
    src/ResetSettingsServiceAction.cpp
    src/ResetEncoderServiceAction.cpp
    src/ReverseServiceAction.cpp
    src/PigeonRosHandler.cpp
    src/HeadingTimedAction.cpp
    src/SetHeadingServiceAction.cpp
)

target_link_libraries(ros-handler PRIVATE hardware)

target_include_directories(ros-handler PUBLIC include)

MakeROSTarget(ros-handler)
