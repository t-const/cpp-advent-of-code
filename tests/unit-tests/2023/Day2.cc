#include <gtest/gtest.h>

#include <Advent2023-d2.h>

TEST(Advent2023_Day2, Example)
{
    Advent2023D2 advent2023D2;

    std::stringstream in;
    in << "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green\n"
       << "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue\n"
       << "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red\n"
       << "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red\n"
       << "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green";
    const auto solution = advent2023D2.Solve(in);

    EXPECT_EQ(solution, 0);
}

// Example test case
TEST(Advent2023_Day2, TestSolution)
{
  Advent2023D2 advent2023D2;

  const auto solution = advent2023D2.SolveInput("../../res/2023/Day2/input.txt");

  EXPECT_EQ(solution, 0);
}