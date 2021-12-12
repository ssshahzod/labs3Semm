#include "../definitions.hpp"
#include "gtest/gtest.h"
 //input output
 //empty full sets

TEST(SetConstructor, ConstructorsException){ //put in method
    int ar[] = {1, 3, 4, 5, 6, 5}, arSize = 6;
    ASSERT_THROW(def::Set(-1), std::logic_error);
    ASSERT_THROW(def::Set(200), std::out_of_range); //max set power = 100
    ASSERT_THROW(def::Set(arSize, ar), std::logic_error);
}

TEST(SetMethod, IsinMethod){
    int result = 0, res[] = {1, 2, 3, 5, 6, 7, 43, 235, 523, 13, 125, -1, 0};
    def::Set a(13, res);
    result += (int) a.Isin(5);
    result += (int) a.Isin(-1);
    result += (int) a.Isin(0);
    result += (int) a.Isin(4);
    ASSERT_EQ(3, result);
}

TEST(SetMethod, InputValOperator){
    int arSize = 3, ar[] = {1, 2, 3};
    int result = 0, res[] = {1, 2, 3, 5, 6, 7, 10, -1, 12412};
    def::Set a(arSize, ar);
    a += 5;
    a += 6;
    a += 7;
    ASSERT_EQ(6, a.getPower());
    for(const auto& ar_re : res){
        result += (int) a.Isin(ar_re);
    }
    ASSERT_EQ(6, result);
    a.Add(10);
    a.Add(12412);
    a.Add(-1);
    ASSERT_EQ(9, a.getPower());
    ASSERT_THROW(a += 7, std::logic_error);
    ASSERT_THROW(a.Add(10), std::logic_error);
}

TEST(SetMethod, UnionOperator){
    int arSize = 9, ar[] = {1, 2, 3, 5, 6, 7, 10, 124, 25};
    int ar2Size = 8, ar2[] = {1, 2, 5, 325, 634, 374, 73, 34};
    int ar3Size = 12, ar3[] = {72, 235, 62, 73, -1, 0, 34, 25, 26, 102, -1230, 5231};
    int res = 0, ar_res[] = {1, 2, 3, 5, 6, 7, 10, 124, 25, 325, 634, 374, 73, 34};
    def::Set a(arSize, ar), b(ar2Size, ar2), c(ar3Size, ar3);
    def::Set tmp = a + b;
    ASSERT_EQ(14, tmp.getPower());
    for(const auto& ar_re : ar_res){
        res += tmp.Isin(ar_re);
    }
    ASSERT_EQ(14, res);
    tmp = tmp.Union(c);
    ASSERT_EQ(23, tmp.getPower());
    tmp = a.Union(c);
    ASSERT_EQ(20, tmp.getPower());
}

TEST(SetMethod, SubtrahendOperator){
    int arSize = 10, ar[] = {1, 2, 0, -124, 234, 4, 5, 325, 708, 23};
    int ar2Size = 5, ar2[] = {1, 4, 5, 25, 643};
    int ar3Size = 4, ar3[] = {2, 234, 325, 708};
    int res = 0, ar_res[] = {2, 0, -124, 234, 325, 708, 23};
    def::Set a(arSize, ar), b(ar2Size, ar2), c(ar3Size, ar3);
    def::Set tmp = a - b;
    ASSERT_EQ(7, tmp.getPower());
    for(const auto& ar_re : ar_res)
        res += tmp.Isin(ar_re);
    ASSERT_EQ(7, res);
    tmp = tmp.Diff(c);
    ASSERT_EQ(3, tmp.getPower());
}

TEST(SetMethod, IntersectionOperator){
    int arSize = 10, ar[] = {1, 4, 6, 3215, -1, 3, 2, 0, 42, 124};
    int ar2Size = 6, ar2[] = {1, 4, 6, -1, 110, 1240};
    int ar3Size = 4, ar3[] = {2, 0, -1, 3215};
    int res = 0, ar_res[] = {1, 4, 6, -1};
    def::Set a(arSize, ar), b(ar2Size, ar2), c(ar3Size, ar3);
    def::Set tmp = a * b;
    ASSERT_EQ(4, tmp.getPower());
    for(const auto& ar_re : ar_res)
        res += tmp.Isin(ar_re);
    ASSERT_EQ(4, res);
    tmp = tmp.Intersection(c);
    ASSERT_EQ(1, tmp.getPower());
    tmp = a.Intersection(c);
    ASSERT_EQ(4, tmp.getPower());

}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}