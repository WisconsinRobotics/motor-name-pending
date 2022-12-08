add_executable(TalonFX_test)

target_sources(TalonFX_test PRIVATE test.cpp)

target_link_libraries(TalonFX_test PRIVATE hardware ${catkin_LIBRARIES})
add_dependencies(TalonFX_test ${catkin_EXPORTED_TARGETS})

MakeTalonExecutable(TalonFX_test)