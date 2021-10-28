cmake_minimum_required(VERSION 3.20)
project(FischerDavis)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(FischerDavis
        main.cpp
        NumConverter.cpp
        NumConverter.h)
