cmake_minimum_required(VERSION 3.18)
project(dynamicOp)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

include_directories(.)

add_executable(dynamicOp definitions.cpp definitions.hpp Tests/Tests.cpp)
add_executable(dynamicOpMain definitions.cpp definitions.hpp main.cpp task.cpp)

target_link_libraries(dynamicOp gtest gtest_main)