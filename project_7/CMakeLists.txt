cmake_minimum_required(VERSION 3.24)
project(project_7)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(__MACOSX)

add_executable(project_7
        __MACOSX/._Customer.h
        __MACOSX/._CustomerDB.cpp
        __MACOSX/._CustomerDB.h
        __MACOSX/._main.cpp
        __MACOSX/._Project7.cpp
        __MACOSX/._UTString.h
        Customer.h
        CustomerDB.cpp
        CustomerDB.h
        main.cpp
        Project7.cpp
        UTString.h Project7.cpp)
