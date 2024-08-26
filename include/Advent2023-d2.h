#pragma once

#include <string>
#include <sstream>
#include <vector>

struct GameSet
{
  int redCount = 0;
  int greenCount = 0;
  int blueCount = 0;
};

struct GameResult
{
  int id {};
  std::vector<GameSet> Sets {{}, {}, {}};
};

class Advent2023D2
{
  public:
  Advent2023D2() = default;
  ~Advent2023D2() = default;

  int SolveInput(const std::string& inputFile);
  int Solve(std::istream& input);

  private:
  int ParseInputLine(std::string& line) const;
};