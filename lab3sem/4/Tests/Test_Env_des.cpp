//
// Created by cronion on 26.11.2021.
//

#include "Test_Env_des.h"
#include "gtest/gtest.h"

TEST(Env_constructor, Constructor_Test){
    int h = 5, w = 5;
    Mobile_robots::Component t(1, 1,Mobile_robots::observation_center);
    Mobile_robots::Env_descriptor tmp(h, w);
    ASSERT_EQ(h, tmp.get_map_height());
    ASSERT_EQ(w, tmp.get_map_weight());
    int res = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            res += tmp.get_cell_info(i, j).component_type;
        }
    }
    ASSERT_EQ(0, res);
    tmp.change_component(1, 1, t);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            res += tmp.get_cell_info(i, j).component_type;
        }
    }
    ASSERT_EQ(Mobile_robots::observation_center, res);
    ASSERT_EQ(&t, tmp.get_cell_link(1, 1));
    ASSERT_THROW(Mobile_robots::Env_descriptor(-5, 2), std::logic_error);
}