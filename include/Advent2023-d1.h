#pragma once

#include <string>

class Advent2023D1
{
  public:
  Advent2023D1(bool useLetterDigits) : mUseLetterDigits(useLetterDigits) {}

  ~Advent2023D1() = default;

  int SolveInput(const std::string& inputFile);
  int Solve(std::istream& input);

  private:
  int GetNumberLineValue(const std::string& line) const;
  int GetLetterDigitsLineValue(const std::string& line) const;

  bool mUseLetterDigits = false;
};