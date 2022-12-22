add_executable(RosControlTest)

target_sources(RosControlTest PRIVATE main.cpp)

target_link_libraries(RosControlTest PRIVATE hardware ros-handler)

MakeROSTarget(RosControlTest)