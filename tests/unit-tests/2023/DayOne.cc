#include <gtest/gtest.h>

#include <Advent2023-d1.h>

// Example test case
TEST(Advent2023_Day1, TestUnoptimized)
{
  Advent2023D1 advent2023D1(SOLUTION_TYPE::UNOPTIMIZED);
  
  const auto solution = advent2023D1.Solve("../../res/2023/Day1/input.txt");

  EXPECT_EQ(solution, 54940);
}
