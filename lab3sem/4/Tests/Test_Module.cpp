//
// Created by cronion on 27.11.2021.
//

#include "Test_Module.h"

TEST(Module_Test, Method_Test){
    Mobile_robots::Module tmp;
    Mobile_robots::Module mPrior(Mobile_robots::middle, 100, 100);
    ASSERT_EQ(tmp.getId(), mPrior.getId());
    ASSERT_EQ(Mobile_robots::middle, mPrior.get_priority());
    ASSERT_EQ(tmp.get_priority(), 0);
    ASSERT_EQ(mPrior.get_power_cons(), 100);
    ASSERT_EQ(false, mPrior.module_stat());
    mPrior.module_switch_on();
    ASSERT_EQ(true, mPrior.module_stat());
}
