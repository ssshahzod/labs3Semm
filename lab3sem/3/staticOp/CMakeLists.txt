cmake_minimum_required(VERSION 3.20)
project(staticOp)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

include_directories(.)

add_executable(staticOp definitions.cpp definitions.hpp Tests/Tests.cpp)
add_executable(main definitions.cpp definitions.hpp main.cpp)

target_link_libraries(staticOp gtest gtest_main)