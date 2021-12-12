//
// Created by cronion on 27.11.2021.
//

#include "Test_power_generator.h"

TEST(Power_Generator_test, Method_test){
    Mobile_robots::Power_generator tmp(800);
    ASSERT_EQ(100, tmp.getId());
    ASSERT_EQ(800, tmp.get_power_cons());
    ASSERT_EQ(false, tmp.module_stat());
    tmp.set_cost(900);
    ASSERT_EQ(900, tmp.get_cost());

}

TEST(Power_generator, Constructor_exceptions){
    ASSERT_THROW(Mobile_robots::Power_generator t(-100), std::logic_error);
}