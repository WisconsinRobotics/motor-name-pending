add_library(hardware)

target_sources(hardware
    PRIVATE
    src/Group.cpp
    src/Motor.cpp
    src/MockMotor.cpp
)

target_include_directories(hardware PUBLIC include)

MakeTalonTarget(hardware)