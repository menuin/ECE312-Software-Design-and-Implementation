cmake_minimum_required(VERSION 3.24)
project(project_6)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project_6
        main.cpp
        MazeParams.h
        Project6.cpp
        Recursion.h)
