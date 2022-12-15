add_library(ros-handler)

target_sources(ros-handler
    PRIVATE
    src/TimedRosAction.cpp
)

target_link_libraries(ros-handler PRIVATE hardware)

target_include_directories(ros-handler PUBLIC include)

MakeROSTarget(ros-handler)