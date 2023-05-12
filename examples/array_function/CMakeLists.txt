cmake_minimum_required(VERSION 3.24)
project(array_function C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(array_function
        arrayFunction.c
        arrayFunction.h
        ArrayFunctionMain.c arrayFunction.c arrayFunction.c)
