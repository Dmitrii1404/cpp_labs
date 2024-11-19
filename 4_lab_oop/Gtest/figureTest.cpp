#include <gtest/gtest.h>
#include "dinFig.hpp"
#include "rectangle.hpp"
#include "rhombus.hpp"
#include "trapezoid.hpp"

class testFigure : public ::testing::Test {
protected:
    void SetUp() override {
        a = Rectangle<double> ({{0,5},{0,15},{15,15},{15,5}});
        b = Rectangle<double> ({{0,0}, {0,-5}, {-5,-5}, {-5,0}});
        c = Rhombus<double>  ({{1,4},{3,6},{5,4},{3,2}});
        d = Rhombus<double>  ({{-2,-5},{-4,-7},{-6,-5},{-4,-3}});
        e = Trapezoid<double> ({{1,2},{3,5},{7,5}, {9,2}});
        f = Trapezoid<double> ({{-2,-3},{-4,-6},{-8,-6}, {-10,-3}});
        F.push_back(std::make_shared<Rectangle<double>>(a));
        F.push_back(std::make_shared<Rectangle<double>>(b));
        F.push_back(std::make_shared<Rhombus<double>>(c));
        F.push_back(std::make_shared<Rhombus<double>>(d));
        F.push_back(std::make_shared<Trapezoid<double>>(e));
        F.push_back(std::make_shared<Trapezoid<double>>(f));
    }
    void TearDown() override{}
    Rectangle<double> a;
    Rectangle<double> b;
    Rhombus<double> c;
    Rhombus<double> d;
    Trapezoid<double> e;
    Trapezoid<double> f;
    DinFig<std::shared_ptr<Figure<double>>> F;

};

TEST_F(testFigure, testSquare){
    ASSERT_EQ(a.square(), 150);
    ASSERT_EQ(b.square(), 25);
    ASSERT_EQ(c.square(), 16);
    ASSERT_EQ(d.square(), 16);
    ASSERT_EQ(e.square(), 18);
    ASSERT_EQ(f.square(), 18);
}

TEST_F(testFigure, testCenter){
    ASSERT_EQ(a.center().getX(), 7.5);
    ASSERT_EQ(a.center().getY(), 10);
    ASSERT_EQ(b.center().getX(), -2.5);
    ASSERT_EQ(b.center().getY(), -2.5);
    ASSERT_EQ(c.center().getX(), 3);
    ASSERT_EQ(c.center().getY(), 4);
    ASSERT_EQ(d.center().getX(), -4);
    ASSERT_EQ(d.center().getY(), -5);
    ASSERT_EQ(e.center().getX(), 5);
    ASSERT_EQ(e.center().getY(), 3.5);
    ASSERT_EQ(f.center().getX(), -6);
    ASSERT_EQ(f.center().getY(), -4.5);
}

TEST_F(testFigure, testAllSquare) {
    ASSERT_EQ(F.getAllSquare(), 243);
}

TEST_F(testFigure, deleteByIndex) {
    ASSERT_EQ(F.getAllSquare(), 243);
    F.remove_ind(2);
    ASSERT_EQ(F.getAllSquare(), 227);
    F.remove_ind(0);
    ASSERT_EQ(F.getAllSquare(), 77);
}

int main(int argc, char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}