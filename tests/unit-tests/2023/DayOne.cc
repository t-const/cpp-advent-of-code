#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

#include <Advent2023-d1.h>

// Example test case
TEST(Advent2023_Day1, TestExample)
{
  Advent2023D1 advent2023D1(false);

  std::stringstream in;
  in << "1abc2" << std::endl
     << "pqr3stu8vwx" << std::endl
     << "a1b2c3d4e5f" << std::endl
     << "treb7uchet";
  const auto solution = advent2023D1.Solve(in);

  EXPECT_EQ(solution, 142);
}

// Example test case
TEST(Advent2023_Day1, TestSolution)
{
  Advent2023D1 advent2023D1(false);

  const auto solution = advent2023D1.SolveInput("../../res/2023/Day1/input.txt");

  EXPECT_EQ(solution, 54940);
}

TEST(Advent2023_Day1, TestExampleWithLetterDigit)
{
  Advent2023D1 advent2023D1(true);

  std::stringstream in;
  in << "two1nine" << std::endl
     << "eightwothree" << std::endl
     << "abcone2threexyz" << std::endl
     << "xtwone3four" << std::endl
     << "4nineeightseven2" << std::endl
     << "zoneight234" << std::endl
     << "7pqrstsixteen";
  const auto solution = advent2023D1.Solve(in);

  EXPECT_EQ(solution, 281);
}

TEST(Advent2023_Day1, TestSolutionWithLetterDigit)
{
  Advent2023D1 advent2023D1(true);

  const auto solution = advent2023D1.SolveInput("../../res/2023/Day1/input.txt");

  EXPECT_EQ(solution, 54208);
}
