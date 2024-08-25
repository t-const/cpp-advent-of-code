#include <Advent2023-d1.h>

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

int Advent2023D1::SolveInput(const std::string& inputFile)
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

int Advent2023D1::Solve(std::istream& input)
{
	int totalExecutionTime = 0;
  int sum = 0;
  std::string line;

  while(std::getline(input, line))
  {
    std::clog << "\rEvaluating: " << line << " ===> ";
    int lineNumber;

    // Start time measurement
    auto start = std::chrono::high_resolution_clock::now();

    lineNumber = mUseLetterDigits ? GetLetterDigitsLineValue(line)
				  : GetNumberLineValue(line);

    // End time measurement
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the elapsed time in different units
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::clog << std::to_string(lineNumber) << std::endl;
    sum += lineNumber;
    totalExecutionTime += duration.count();
  }
	std::clog << "Solution is: " << sum << std::endl;
  std::clog << "Execution time: " << totalExecutionTime << "(ms)" << std::endl;

	return sum;
}

int Advent2023D1::GetNumberLineValue(const std::string& line) const
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

int Advent2023D1::GetLetterDigitsLineValue(const std::string& line) const
{
  if(line.empty())
	{
		return 0;
	}

	const std::map<std::string, int> DIGITS = {
		{"one", 1},
	  {"two", 2},
	  {"three", 3},
	  {"four", 4},
	  {"five", 5},
	  {"six", 6},
	  {"seven", 7},
	  {"eight", 8},
	  {"nine", 9}
	};

	std::vector<int> numbersInLine;
	auto strToCompute = line;
	while(!strToCompute.empty())
	{
		if(std::isdigit(strToCompute.at(0)))
		{
			numbersInLine.emplace_back(strToCompute.at(0) - '0'); // - 0 will remove the character code offset
			strToCompute = strToCompute.substr(1, strToCompute.length() - 1);
			continue;
		}

		bool foundDigit = false;
		for(const auto [spelled, digit] : DIGITS)
		{
			if(!strToCompute.starts_with(spelled))
			{
				continue;
			}

			numbersInLine.emplace_back(digit);
			const auto digitCharCount = spelled.length();
			strToCompute = strToCompute.substr(digitCharCount, strToCompute.length() - digitCharCount);
			foundDigit = true;
			break;
		}

		if(foundDigit)
		{
			continue;
		}

		strToCompute = strToCompute.substr(1, strToCompute.length() - 1);
	}
	
	return 10 * numbersInLine.front() + numbersInLine.back();
}
