cmake_minimum_required(VERSION 3.20)
project(2nd)

set(CMAKE_CXX_STANDARD 20)


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

include_directories(.)

add_executable(2nd definitions.cpp definitions.hpp Tests/Tests.cpp)
add_executable(main main.cpp definitions.cpp definitions.hpp)

target_link_libraries(2nd gtest gtest_main)