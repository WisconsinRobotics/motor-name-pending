add_executable(TalonFX_test)

target_sources(TalonFX_test PRIVATE test.cpp)

target_link_libraries(TalonFX_test PRIVATE hardware)

MakeTalonExecutable(TalonFX_test)