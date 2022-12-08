add_executable(TalonFX_test)

target_sources(TalonFX_test PRIVATE test.cpp)

target_link_libraries(TalonFX_test PRIVATE hardware)

MakeROSTarget(TalonFX_test)
MakeTalonTarget(TalonFX_test)