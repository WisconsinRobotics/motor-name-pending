add_executable(Pigeon2)

target_sources(Pigeon2 PRIVATE main.cpp)

MakeROSTarget(Pigeon2)

MakeTalonTarget(Pigeon2)
