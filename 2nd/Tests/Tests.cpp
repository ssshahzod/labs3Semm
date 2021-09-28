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
    Lemniscatus::BoothLemniscate b(9, 4, 2, 0);
    ASSERT_EQ(3, a.getM());
    ASSERT_EQ(6, a.getC());
    ASSERT_EQ(5, a.getP().cordX);
    ASSERT_EQ(3, a.getP().cordY);
    ASSERT_EQ(9, b.getP().cordX);
    ASSERT_EQ(2, b.getM());
    ASSERT_EQ(0, b.getC());
    ASSERT_EQ(1, b.curveType());
}

TEST(BoothLemniscateConstructor, TestException){
    Lemniscatus::Point tmp;
    ASSERT_ANY_THROW(Lemniscatus::BoothLemniscate(tmp, 0, -2));
    ASSERT_ANY_THROW(Lemniscatus::BoothLemniscate(0,0,-10, 10));
}

TEST(BoothLemMethods, Setters){
    Lemniscatus::BoothLemniscate tmp;
    Lemniscatus::Point p(9, 10);
    tmp.setP(p);
    ASSERT_EQ(tmp.getP().cordX, p.cordX);
    ASSERT_EQ(tmp.getP().cordY, p.cordY);
    tmp.setM(10);
    ASSERT_EQ(10, tmp.getM());
    tmp.setC(15);
    ASSERT_EQ(15, tmp.getC());
    ASSERT_ANY_THROW(tmp.setM(-1));
}

TEST(BoothLemMethods, Parameters){
    Lemniscatus::BoothLemniscate a(10, 10);
    const double err = 0.0001, PI = 3.14159;
    ASSERT_NEAR(107.9790, a.area(), err);
    ASSERT_EQ(2, a.curveType());
    ASSERT_NEAR(14.4914, a.coef().cordX, err);
    ASSERT_NEAR(13.7840, a.coef().cordY, err);
    ASSERT_NEAR(2.3623, a.centerDistance(150), err);
    ASSERT_NEAR(10.3652, a.centerDistance(100), err);
    ASSERT_STREQ("r^2 = 210.00(cosA)^2 - 190.00(sinA)^2\n", a.frml());

    Lemniscatus::BoothLemniscate b(1, 0, 5, 60);
    ASSERT_NEAR(PI/2 *120, b.area(), err);
    ASSERT_EQ(0, b.curveType());
    ASSERT_NEAR(10.4881, b.coef().cordX, err);
    ASSERT_NEAR(3.1623, b.coef().cordY, err);
    ASSERT_NEAR(10.1546, b.centerDistance(50), err);
    ASSERT_NEAR(5.1627, b.centerDistance(20), err);
    ASSERT_STREQ("r^2 = 110.00(cosA)^2 + 10.00(sinA)^2\n", b.frml());
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



