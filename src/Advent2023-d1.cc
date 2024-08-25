#include <Advent2023-d1.h>

#include <fstream>
#include <iostream>
#include <vector>

int Advent2023D1::Solve(const std::string& inputFile)
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

  int sum = 0;
  std::string line;

  while(std::getline(input, line))
  {
    std::clog << "\rEvaluating: " << line << " ===> ";
    int lineNumber;
    switch(mSolutionType)
    {
    case SOLUTION_TYPE::UNOPTIMIZED:
      lineNumber = GetUnoptimizedLineValue(line);
      break;

    default:
      break;
    }

    std::clog << std::to_string(lineNumber) << std::endl;
    sum += lineNumber;
  }

  std::clog << "Solution is: " << sum << std::endl;
  return sum;
}

int Advent2023D1::GetUnoptimizedLineValue(const std::string& line) const
{
  if(line.empty())
  {
    return 0;
  }

  // could be optimized by searching both start/end in a loop
  std::vector<char> numberInLines;
  for(const auto c : line)
  {
    if(std::isdigit(c))
    {
      numberInLines.emplace_back(c);
    }
  }

  std::string numberStr {numberInLines.front(), numberInLines.back()};
  return std::stoi(numberStr);
}
