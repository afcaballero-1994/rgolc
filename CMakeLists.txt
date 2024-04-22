cmake_minimum_required(VERSION 3.28)
project(rgolc)

set(CMAKE_CXX_STANDARD 26)

add_executable(rgolc src/main.cpp
        src/Grid.cpp
        src/Grid.h
        src/Simulation.cpp
        src/Simulation.h)
target_link_libraries(rgolc PRIVATE raylib m)
