//
// Created by cronion on 21.09.2021.
//

#include "../definitions.hpp"
#include "gtest/gtest.h"

////change to double
TEST(BoothLemniscateConstructor, DefaultConstructor){
    Lemniscatus::BoothLemniscate a;
    double err = 0.0001;
    ASSERT_NEAR(1.00000, a.getM(), err);
    ASSERT_NEAR(1.00000, a.getC(), err);
    ASSERT_NEAR(0, a.getP().cordY, err);
    ASSERT_NEAR(0, a.getP().cordX, err);
}

TEST(BoothLemniscateConstructor, InitConstructor){
    double err = 0.0001;
    Lemniscatus::Point p(5.89843, 3.00010);
    Lemniscatus::BoothLemniscate a(p, 3.32423, 6.99999);
    Lemniscatus::BoothLemniscate b(9.14223, 4.01111, 2.12345, 0);
    ASSERT_NEAR(3.32423, a.getM(), err);
    ASSERT_NEAR(6.99999, a.getC(), err);
    ASSERT_NEAR(5.89843, a.getP().cordX, err);
    ASSERT_NEAR(3.00010, a.getP().cordY, err);
    ASSERT_NEAR(9.14223, b.getP().cordX, err);
    ASSERT_NEAR(2.12345, b.getM(), err);
    ASSERT_NEAR(0, b.getC(), err);
}

TEST(BoothLemniscateConstructor, TestException){
    char* str = new char[5];
    Lemniscatus::Point tmp;
    ASSERT_THROW(Lemniscatus::BoothLemniscate(tmp, 0, -2), std::logic_error);
    ASSERT_THROW(Lemniscatus::BoothLemniscate(0,0,-10, 10), std::logic_error);
    ASSERT_THROW(Lemniscatus::BoothLemniscate(0, 20), std::logic_error);
    Lemniscatus::BoothLemniscate a(10, 10);
    ASSERT_THROW(a.setM(0), std::logic_error);
    ASSERT_THROW(a.frml(str, 5), std::length_error);

}

TEST(BoothLemMethods, Setters){
    double err = 0.0001;
    Lemniscatus::BoothLemniscate tmp;
    Lemniscatus::Point p(9.1342, 10.2523);
    tmp.setP(p);
    ASSERT_NEAR(tmp.getP().cordX, p.cordX, err);
    ASSERT_NEAR(tmp.getP().cordY, p.cordY, err);
    tmp.setM(10.14353);
    ASSERT_NEAR(10.14353, tmp.getM(), err);
    tmp.setC(15.75434);
    ASSERT_NEAR(15.75434, tmp.getC(), err);
    ASSERT_THROW(tmp.setM(-1), std::logic_error);
    ASSERT_THROW(tmp.setM(0), std::logic_error);
}

TEST(BoothLemMethods, CenterDistanceTest){
    const double err = 0.0001;
    Lemniscatus::BoothLemniscate a(10, 10);
    ASSERT_NEAR(2.3623, a.centerDistance(150), err);
    ASSERT_NEAR(10.3652, a.centerDistance(100), err);
    ASSERT_NEAR(11.0673, a.centerDistance(145), err);
    ASSERT_NEAR(13.1467, a.centerDistance(60), err);
    ASSERT_NEAR(9.5716, a.centerDistance(10), err);

    Lemniscatus::BoothLemniscate b(1, 0, 5, 60);
    ASSERT_NEAR(10.1546, b.centerDistance(50), err);
    ASSERT_NEAR(5.1627, b.centerDistance(20), err);
    ASSERT_NEAR(5.4842, b.centerDistance(90), err);
    ASSERT_NEAR(10.4881, b.centerDistance(0), err);
    ASSERT_NEAR(7.2612, b.centerDistance(4), err);

    Lemniscatus::BoothLemniscate c(5, 50);
    ASSERT_NEAR(1.1038, c.centerDistance(80), err);
    ASSERT_NEAR(10.0000, c.centerDistance(0), err);
    ASSERT_NEAR(5.2532, c.centerDistance(45), err);
    ASSERT_NEAR(9.9902, c.centerDistance(110), err);
    ASSERT_NEAR(8.3903, c.centerDistance(720), err);

    Lemniscatus::BoothLemniscate d(5, 0);
    ASSERT_NEAR(4.5170, d.centerDistance(10), err);
    ASSERT_NEAR(5.0864, d.centerDistance(2341), err);
    ASSERT_NEAR(4.5170, d.centerDistance(-10), err);
    ASSERT_NEAR(7.0710, d.centerDistance(0), err);
    ASSERT_NEAR(3.4708, d.centerDistance(230), err);

}

TEST(BoothLemMethods, Area){
    const double err = 0.0001, PI = 3.14159;
    Lemniscatus::BoothLemniscate a(10, 10);
    ASSERT_NEAR(107.9790, a.area(), err);
    Lemniscatus::Point tmp(1, 0);
    a.setP(tmp);
    a.setM(5);
    a.setC(60);
    ASSERT_NEAR(PI/2 *120, a.area(), err);
    a.setM(1.1352);
    a.setC(25.2351);
    ASSERT_NEAR(79.2783, a.area(), err);
    a.setC(0);
    ASSERT_NEAR(1.28868, a.area(), err);
    a.setM(5.5689);
    a.setC(2*a.getM()*a.getM());
    ASSERT_NEAR(11.1378, a.area(), err);
}

TEST(BoothLemMethods, Coefs){
    double err = 0.0001;
    Lemniscatus::BoothLemniscate a(10, 10);
    ASSERT_NEAR(14.4914, a.coef().cordX, err);
    ASSERT_NEAR(13.7840, a.coef().cordY, err);
    a.setM(5);
    a.setC(60);
    ASSERT_NEAR(10.4881, a.coef().cordX, err);
    ASSERT_NEAR(3.1623, a.coef().cordY, err);
    a.setC(50);
    ASSERT_NEAR(10.0000, a.coef().cordX, err);
    ASSERT_NEAR(0, a.coef().cordY, err);
    a.setC(0);
    ASSERT_NEAR(50.0000, a.coef().cordX, err);
    ASSERT_NEAR(0, a.coef().cordY, err);


}

TEST(BoothLemMethods, CurveTypeTest){
    Lemniscatus::BoothLemniscate b(9.14223, 4.01111, 2.12345, 0);
    ASSERT_EQ(1, b.curveType());
    b.setM(5);
    b.setC(50);
    ASSERT_EQ(3, b.curveType());
    b.setM(10.5890);
    b.setC(10.9999);
    ASSERT_EQ(2, b.curveType());
    b.setM(5);
    b.setC(60);
    ASSERT_EQ(0, b.curveType());

}

TEST(BoothLemMethods, FrmlMethod){
    char* str = new char[50];
    Lemniscatus::BoothLemniscate a(10, 10); //2M*M > C
    a.frml(str, 50);
    ASSERT_STREQ("r^2 = 210.00(cosA)^2 - 190.00(sinA)^2\n", str);
    Lemniscatus::BoothLemniscate b(1, 0, 5, 60); //C > 2M*M
    b.frml(str, 50);
    ASSERT_STREQ("r^2 = 110.00(cosA)^2 + 10.00(sinA)^2\n", str);
    Lemniscatus::BoothLemniscate c(5, 50); //C == 2M*M
    c.frml(str, 50);
    ASSERT_STREQ("r^2 = 100.00(cosA)^2\n", str);
    Lemniscatus::BoothLemniscate d(5, 0);
    d.frml(str, 50);
    ASSERT_STREQ("r^2 = 50.00(cosA)^2 - 50.00(sinA)^2\n", str);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



