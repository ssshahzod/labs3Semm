#include "gtest/gtest.h"
#include "Test_Env_des.h"
#include "Test_Comp.h"
#include "Test_Module.h"
#include "Test_power_generator.h"

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
