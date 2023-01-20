add_library(config-parsing)

target_sources(config-parsing
    PRIVATE
    src/dummy.cpp
)

target_include_directories(config-parsing PUBLIC include)

target_link_libraries(config-parsing PRIVATE hardware ros-handler)

MakeROSTarget(config-parsing)