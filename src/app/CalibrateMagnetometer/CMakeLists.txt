add_executable(CalibrateMagnetometer)

target_sources(CalibrateMagnetometer PRIVATE main.cpp)

target_link_libraries(CalibrateMagnetometer PRIVATE hardware)

MakeTalonTarget(CalibrateMagnetometer)
