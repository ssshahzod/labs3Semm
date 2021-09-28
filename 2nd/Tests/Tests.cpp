//
// Created by cronion on 21.09.2021.
//

#include "../definitions.hpp"
#include "gtest/gtest.h"


TEST(BoothLemniscateConstructor, DefaultConstructor){
    Lemniscatus::BoothLemniscate a;
    ASSERT_EQ(1, a.getM());
    ASSERT_EQ(1, a.getC());
    ASSERT_EQ(0, a.getP().cordY);
    ASSERT_EQ(0, a.getP().cordX);
}

TEST(BoothLemniscateConstructor, InitConstructor){
    Lemniscatus::Point p(5, 3);
    Lemniscatus::BoothLemniscate a(p, 3, 6);
    ASSERT_EQ(3, a.getM());
    ASSERT_EQ(6, a.getC());
    ASSERT_EQ(5, a.getP().cordX);
    ASSERT_EQ(3, a.getP().cordY);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



