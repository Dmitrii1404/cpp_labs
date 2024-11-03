#include <gtest/gtest.h>
#include "decimal.h"

class testDecimal : public ::testing::Test {
  protected:
    void SetUp() override {
      a = new Decimal("100");
      b = new Decimal("200");
      c = new Decimal("300");
    }
    void TearDown() override{
    }
  Decimal *a;
  Decimal *b;
  Decimal *c;
};

TEST_F(testDecimal, testConstructor){
  ASSERT_EQ(a->toString(), "100");
  ASSERT_EQ(b->toString(), "200");
  ASSERT_EQ(c->toString(), "300");
}

TEST_F(testDecimal, testCopy) {
  Decimal x(*a);
  Decimal y;
  y.prisv(*b);
  Decimal z(std::move(*c));
  ASSERT_EQ(x.toString(), "100");
  ASSERT_EQ(y.toString(), "200");
  ASSERT_EQ(z.toString(), "300");
}

TEST_F(testDecimal, testMath) {
  Decimal x1, x2, y1, y2;
  x1.prisv((*a).plus(*b));
  x2.prisv(x1.plus(*c));
  y1.prisv((*c).minus(*b));
  y2.prisv(y1.minus(*a));
  ASSERT_EQ(x2.toString(), "600");
  ASSERT_EQ(y2.toString(), "0");
}

TEST_F(testDecimal, testBool) {
  ASSERT_FALSE((*a).ravno(*b));
  ASSERT_FALSE((*a).ravno(*c));
  ASSERT_TRUE((*a).not_ravno(*b));
  ASSERT_TRUE((*a).not_ravno(*c));

  ASSERT_FALSE((*a).bolshe(*b));
  ASSERT_FALSE((*a).bolshe(*c));
  ASSERT_TRUE((*a).menshe(*b));
  ASSERT_TRUE((*a).menshe(*c));
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}