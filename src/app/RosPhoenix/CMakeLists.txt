add_executable(RosPhoenix)

target_sources(RosPhoenix PRIVATE main.cpp)

target_link_libraries(RosPhoenix PRIVATE hardware ros-handler)

MakeROSTarget(RosPhoenix)

MakeTalonTarget(RosPhoenix)
