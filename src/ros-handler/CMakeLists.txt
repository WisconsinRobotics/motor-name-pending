add_library(ros-handler)

target_sources(ros-handler
    PRIVATE
    src/ros-handler-core/RosTimedAction.cpp
    src/EncoderTimedAction.cpp
)

target_link_libraries(ros-handler PRIVATE hardware)

target_include_directories(ros-handler PUBLIC include)

MakeROSTarget(ros-handler)