#include <gtest/gtest.h>
#include "dinFig.h"
#include "rectangle.h"
#include "rhombus.h"
#include "trapezoid.h"

class testFigure : public ::testing::Test {
protected:
    void SetUp() override {
        a = new Rectangle({0,5},{0,15},{15,15},{15,5});
        b = new Rectangle({0,0}, {0,-5}, {-5,-5}, {-5,0});
        c = new Rhombus({1,4},{3,6},{5,4},{3,2});
        d = new Rhombus({-2,-5},{-4,-7},{-6,-5},{-4,-3});
        e = new Trapezoid({1,2},{3,5},{7,5}, {9,2});
        f = new Trapezoid({-2,-3},{-4,-6},{-8,-6}, {-10,-3});
    }
    void TearDown() override{}
    Figure *a;
    Figure *b;
    Figure *c;
    Figure *d;
    Figure *e;
    Figure *f;
};

TEST_F(testFigure, testSquare){
    ASSERT_EQ(a->square(), 150);
    ASSERT_EQ(b->square(), 25);
    ASSERT_EQ(c->square(), 16);
    ASSERT_EQ(d->square(), 16);
    ASSERT_EQ(e->square(), 18);
    ASSERT_EQ(f->square(), 18);
}

TEST_F(testFigure, testCenter){
    ASSERT_EQ(a->center().first, 7.5);
    ASSERT_EQ(a->center().second, 10);
    ASSERT_EQ(b->center().first, -2.5);
    ASSERT_EQ(b->center().second, -2.5);
    ASSERT_EQ(c->center().first, 3);
    ASSERT_EQ(c->center().second, 4);
    ASSERT_EQ(d->center().first, -4);
    ASSERT_EQ(d->center().second, -5);
    ASSERT_EQ(e->center().first, 5);
    ASSERT_EQ(e->center().second, 3.5);
    ASSERT_EQ(f->center().first, -6);
    ASSERT_EQ(f->center().second, -4.5);
}

TEST_F(testFigure, testAllSquare) {
    DinFig<Figure*> F;
    F.push_back(a);
    F.push_back(b);
    F.push_back(c);
    F.push_back(d);
    F.push_back(e);
    F.push_back(f);
    ASSERT_EQ(F.getAllSquare(), 243);
}

TEST_F(testFigure, deleteByIndex) {
    DinFig<Figure*> F;
    F.push_back(a);
    F.push_back(b);
    F.push_back(c);
    F.push_back(d);
    F.push_back(e);
    F.push_back(f);
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