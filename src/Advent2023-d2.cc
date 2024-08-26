#include <Advent2023-d2.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

int Advent2023D2::SolveInput(const std::string& inputFile)
{
  if(inputFile.empty())
  {
    std::cerr << "No input file, can't solve solution." << std::endl;
    return -1;
  }

  std::ifstream input(inputFile);
  if(!input.is_open())
  {
    std::cerr << "Could not open file." << std::endl;
    return -1;
  }

  const auto solution = Solve(input);
  input.close();
  return solution;
}

int Advent2023D2::Solve(std::istream& input)
{
  int gameId = 0;
  return gameId;
}

int Advent2023D2::ParseInputLine(const std::string& line) const
{
  std::regex pattern("(\\d+)(?= red)");

    // Create an iterator for the matches
    std::sregex_iterator redIter(line.begin(), line.end(), pattern);
    std::sregex_iterator end;

    // Iterate over all matches and print them
    for (; redIter != end; ++redIter) {
        std::smatch match = *redIter;
        std::cout << match.str() << std::endl;
    }
}
