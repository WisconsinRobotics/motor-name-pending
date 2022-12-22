add_executable(RawTalonTest)

target_sources(RawTalonTest PRIVATE test.cpp)

target_link_libraries(RawTalonTest PRIVATE hardware)

MakeTalonTarget(RawTalonTest)