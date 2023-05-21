add_executable(MockMotors)

target_sources(MockMotors PRIVATE main.cpp)

target_link_libraries(MockMotors PRIVATE hardware ros-handler)

MakeROSTarget(MockMotors)

MakeTalonTarget(MockMotors)