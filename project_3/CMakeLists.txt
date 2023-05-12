cmake_minimum_required(VERSION 3.24)
project(project_3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(__MACOSX)

add_executable(project_3
        __MACOSX/._main.cpp
        __MACOSX/._Project3.cpp
        __MACOSX/._UTString.h
        main.cpp
        Project3.cpp
        UTString.h Project3.cpp Project3.cpp)
