#include <gtest/gtest.h>
#include "solution.h"

class Test : public ::testing::TestWithParam<std::tuple<int, int, int>>{
};

TEST_P(Test, CheckTest) {
    auto [divider, border, expected] = GetParam();
    EXPECT_EQ(findAnswer(divider, border), expected)
                        << "Divider: " << divider << ", Border: " << border << ", Expected: " << expected;
}

INSTANTIATE_TEST_SUITE_P(
        TestTrueCases,
        Test,
        ::testing::Values(
                std::make_tuple(1, 12, 12),
                std::make_tuple(11, 12, 11),
                std::make_tuple(13, 12, 0),
                std::make_tuple(12, 12, 12),
                std::make_tuple(3, 12, 12),
                std::make_tuple(1, 12, 12),
                std::make_tuple(1, 12, 12)
        )
);

INSTANTIATE_TEST_SUITE_P(
        TestFalseCases,
        Test,
        ::testing::Values(
                std::make_tuple(0, 12, -1),
                std::make_tuple(1, 0, -1),
                std::make_tuple(-10, -10, -1),
                std::make_tuple(0, 0, -1)
        )
);

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}