//
// Created by cronion on 26.11.2021.
//

#include "Test_Comp.h"


TEST(Component_test, Methods_test){
    Mobile_robots::Component tmp(1, 1, Mobile_robots::observation_center, 800, 5, 100);
    ASSERT_EQ(tmp.get_comp_string().coordX, 1);
    ASSERT_EQ(tmp.get_comp_string().coordY, 1);
    ASSERT_EQ(tmp.get_comp_string().component_type, Mobile_robots::observation_center);
    ASSERT_EQ(tmp.get_modules_slots(), 5);
    ASSERT_EQ(tmp.getType(), Mobile_robots::observation_center);
    ASSERT_EQ(tmp.get_power_cons(), 100);
    ASSERT_EQ(tmp.get_comp_cost(), 800);
    ASSERT_EQ(tmp.get_modules_num(), 0);
    Mobile_robots::Module t;
    tmp.install_module(t);
    ASSERT_EQ(tmp.get_modules_num(), 1);
    ASSERT_EQ(true, tmp.module_is_in(t.getId()));
    tmp.delete_module(t.getId());
    ASSERT_EQ(0, tmp.get_modules_num());
}