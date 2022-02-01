cmake_minimum_required(VERSION 3.2)
project(TalonFX-Controller)

find_package(Threads REQUIRED)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)

add_definitions(-std=c++17)
include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(IMPL_FILES
    ${CMAKE_SOURCE_DIR}/src/group.cpp
    ${CMAKE_SOURCE_DIR}/src/motor.cpp
)

add_executable(TalonFX_test src/test.cpp)
target_link_libraries(TalonFX_test IMPL_FILES)

if (${CMAKE_LIBRARY_ARCHITECTURE} STREQUAL "arm-linux-gnueabihf") # Jetson TK1 / Pi
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/raspberry/libCTRE_Phoenix.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/raspberry/libCTRE_PhoenixCCI.a)
	target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/raspberry/libCTRE_PhoenixDiagnostics.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/raspberry/libCTRE_PhoenixPlatform_socketcan.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/raspberry/libCTRE_PhoenixCanutils.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/raspberry/libCTRE_PhoenixCore.a)
elseif (${CMAKE_LIBRARY_ARCHITECTURE} STREQUAL "aarch64-linux-gnu") # Jetson TX2
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/jetsontx/libCTRE_Phoenix.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/jetsontx/libCTRE_PhoenixCCI.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/jetsontx/libCTRE_PhoenixDiagnostics.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/jetsontx/libCTRE_PhoenixPlatform_socketcan.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/jetsontx/libCTRE_PhoenixCanutils.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/jetsontx/libCTRE_PhoenixCore.a)
else()
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_Phoenix.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixCCI.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixDiagnostics.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixPlatform_socketcan.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixCanutils.a)
    target_link_libraries(TalonFX_test ${CMAKE_SOURCE_DIR}/lib/x86-64/libCTRE_PhoenixCore.a)
endif()

target_link_libraries(TalonFX_test Threads::Threads)