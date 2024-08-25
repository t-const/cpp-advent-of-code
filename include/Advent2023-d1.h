#pragma once

#include <string>

enum class SOLUTION_TYPE : int
{
  UNOPTIMIZED = 0
};

class Advent2023D1
{
  public:
  Advent2023D1(SOLUTION_TYPE solutionType)
	: mSolutionType(solutionType)
  {
  }

  ~Advent2023D1() = default;

  int Solve(const std::string& inputFile);

  private:
  int GetUnoptimizedLineValue(const std::string& line) const;

  SOLUTION_TYPE mSolutionType;
};