#include <gtest/gtest.h>
#include <stdexcept>
#include "Task1.h"
#include <sstream>

TEST(Matrix, Construct) {
    Matrix m;
    Matrix m1(4,10);
    EXPECT_EQ(4,m1.GetNumRows());
    EXPECT_EQ(10,m1.GetNumColumns());
}
TEST(Matrix, Reset)
{
    Matrix m1(7,5);
    m1.Reset(10,12);
    EXPECT_EQ(10,m1.GetNumRows());
    EXPECT_EQ(12,m1.GetNumColumns());
}

TEST(Matrix , At)
{
    Matrix m1;
    std::stringstream ss;
    ss<<"1 2 1 2";
    ss>>m1;
    EXPECT_EQ(1,m1.GetNumRows());
    EXPECT_EQ(2,m1.GetNumColumns());
    EXPECT_EQ(1,m1.At(0,0));
    int k = m1.At(0,1);
    EXPECT_EQ(2,k);
}
TEST(Matrix,Operators)
{
    Matrix m1;
    std::stringstream ss;
    ss<<"1 2 1 2";
    ss>>m1;
    Matrix m2;
    std::stringstream ss2;
    ss2<<"1 2 1 2";
    ss2>>m2;
    Matrix m3 =m1+m2;
    EXPECT_EQ(m3.At(0,0) , 2);
    EXPECT_EQ(m3.At(0,1), 4);
    bool equal = m1 == m2;
    EXPECT_EQ(equal,true);
    bool not_equal = m1==m3;
    EXPECT_EQ(not_equal,false);
}

TEST(Matrix, Errors)
{
    EXPECT_THROW(Matrix m1(-1,2) , std::out_of_range);
    Matrix m2(1,2);
    EXPECT_THROW(m2.At(1,2),std::out_of_range);
    Matrix m3(3,2);
    EXPECT_THROW(m3.At(-1,0),std::out_of_range);
    EXPECT_THROW(m3.Reset(-1,2),std::out_of_range);
    EXPECT_THROW(m3+m2,std::logic_error);
}

