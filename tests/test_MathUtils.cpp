#include <gtest/gtest.h>
#include "WarGame/MathUtils.h"

TEST(MathUtilsTest, Add) {
    EXPECT_EQ(WarGame::MathUtils::Add(2, 3), 5);
    EXPECT_EQ(WarGame::MathUtils::Add(-1, 1), 0);
    EXPECT_EQ(WarGame::MathUtils::Add(0, 0), 0);
}
