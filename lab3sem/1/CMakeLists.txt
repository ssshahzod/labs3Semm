cmake_minimum_required(VERSION 3.20)
project(1st)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(1st
        definitions.cpp
        definitions.hpp
        main.cpp)
