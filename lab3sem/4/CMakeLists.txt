cmake_minimum_required(VERSION 3.20)
project(4th)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

include_directories(.)

add_executable(4th Tests/Tests.cpp
        src/Env_descriptor.cpp src/Env_descriptor.h
        src/Component.cpp src/Component.h
        src/Module.cpp src/Module.h src/Coord.cpp src/Coord.h
        src/Module_sensor.cpp src/Module_sensor.h
        src/AI.cpp src/AI.h
        src/Power_generator.cpp src/Power_generator.h
        src/Robot_commander.cpp src/Robot_commander.h
        src/Managing_module.cpp src/Managing_module.h
        src/Util.cpp src/Util.h
        src/Mobile_robot.cpp src/Mobile_robot.h
        src/Observation_center.cpp src/Observation_center.h
        Tests/Test_Env_des.cpp Tests/Test_Env_des.h Tests/Test_Comp.cpp Tests/Test_Comp.h Tests/Test_Module.cpp Tests/Test_Module.h Tests/Test_power_generator.cpp Tests/Test_power_generator.h)

add_executable(4thMain src/main.cpp
        src/Env_descriptor.cpp src/Env_descriptor.h
        src/Component.cpp src/Component.h
        src/Module.cpp src/Module.h src/Coord.cpp src/Coord.h
        src/Module_sensor.cpp src/Module_sensor.h
        src/AI.cpp src/AI.h
        src/Power_generator.cpp src/Power_generator.h
        src/Robot_commander.cpp src/Robot_commander.h
        src/Managing_module.cpp src/Managing_module.h
        src/Util.cpp src/Util.h
        src/Mobile_robot.cpp src/Mobile_robot.h
        src/Observation_center.cpp src/Observation_center.h)

target_link_libraries(4th gtest gtest_main)