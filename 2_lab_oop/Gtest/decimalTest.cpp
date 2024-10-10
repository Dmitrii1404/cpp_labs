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
      delete a;
      delete b;
      delete c;
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
  Decimal y = *b;
  Decimal z(std::move(*c));
  ASSERT_EQ(x.toString(), "100");
  ASSERT_EQ(y.toString(), "200");
  ASSERT_EQ(z.toString(), "300");
}

TEST_F(testDecimal, testMath) {
  Decimal x1 = *a + *b;
  Decimal x2 = x1 + *c;
  Decimal y1 = *c - *b;
  Decimal y2 = y1 - *a;
  ASSERT_EQ(x2.toString(), "600");
  ASSERT_EQ(y2.toString(), "0");
}

TEST_F(testDecimal, testBool) {
  ASSERT_FALSE(*a == *b);
  ASSERT_FALSE(*a == *c);
  ASSERT_TRUE(*a != *b);
  ASSERT_TRUE(*a != *c);

  ASSERT_FALSE(*a > *b);
  ASSERT_FALSE(*a > *c);
  ASSERT_TRUE(*a < *b);
  ASSERT_TRUE(*a < *c);
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}