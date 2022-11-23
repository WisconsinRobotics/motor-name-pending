add_library(hardware)

target_sources(hardware
    PRIVATE
    src/group.cpp
    src/motor.cpp
)

target_include_directories(hardware PUBLIC include)