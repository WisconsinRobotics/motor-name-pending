cmake_minimum_required(VERSION 3.2)
project(TalonFX-Controller)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(MotorControl 
    src/group.cpp
    src/motor.cpp
)

target_include_directories (MotorControl PUBLIC include)