#include <iostream>

#include <Advent2023-d1.h>

int main()
{
  std::clog << "Executing advent 2023 day 1..." << std::endl;
  Advent2023D1 advent2023D1(SOLUTION_TYPE::UNOPTIMIZED);
  advent2023D1.Solve("../../res/2023/Day1/input.txt");

  return 0;
}