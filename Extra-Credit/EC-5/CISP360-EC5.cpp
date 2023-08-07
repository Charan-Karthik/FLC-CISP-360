// Source File Header
// CISP360-EC5.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/28/23

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

// Function Prototypes
void getJudgeData(double &score, int judgeNumber);
double calcScore(const std::vector<double> &scores);
double findLowest(const std::vector<double> &scores);
double findHighest(const std::vector<double> &scores);

int main() {
  std::cout << "Star Search" << std::endl;
  std::cout << "===========\n" << std::endl;

  std::vector<double> scores(5);

  for (int i = 0; i < 5; ++i) {
    getJudgeData(scores[i], i + 1);
  }

  for (double score : scores) {
    std::cout << score << std::endl;
  }

  std::cout << "Average score is " << calcScore(scores) << std::endl;

  double lowestScore = findLowest(scores);
  double highestScore = findHighest(scores);

  for (double score : scores) {
    if (score == lowestScore || score == highestScore) {
      std::cout << "0" << std::endl;
      if (score == lowestScore)
        lowestScore = -1;
      if (score == highestScore)
        highestScore = 11;
    } else {
      std::cout << score << std::endl;
    }
  }

  return 0;
}

void getJudgeData(double &score, int judgeNumber) {
  std::cout << "Enter judge " << judgeNumber << " score (1-10): ";
  do {
    std::cin >> score;

    if (score < 1 || score > 10) {
      std::cout << "Enter a number between 1 and 10" << std::endl;
    }
  } while (score < 1 || score > 10);
}

double calcScore(const std::vector<double> &scores) {
  double total = std::accumulate(scores.begin(), scores.end(), 0.0);
  total = total - findLowest(scores) - findHighest(scores);
  return total / 3.0;
}

double findLowest(const std::vector<double> &scores) {
  return *std::min_element(scores.begin(), scores.end());
}

double findHighest(const std::vector<double> &scores) {
  return *std::max_element(scores.begin(), scores.end());
}

// Short Reflection
/*
This was a fun program to write - especially because it got to take advantage of
the dynamic sizing that vectors provide. Although I could've used a fixed size
array, I chose to use a vector for additional practice with vectors.

Otherwise this was a very straightforward program. Some minor improvements could
be done by removing magic numbers and using constants/global constants instead
and improving input validation to make sure that numbers are actually entered.
I also would've liked to use different function names to be more specific (and
keep function names in PascalCase whereas variables are camelCase).) Outside of
that though it was fun to research and experiment with additional functions like
min_element, max_element, and accumulate (getting to use these functions is
another reason why I opted to use a vector instead of an array - really makes
life easier!).
*/

// Side Note
/*
I noticed that the professor's example output didn't quite match what the
question asked for (e.g. the question mentioned that a valid score range is
0-10, but in the professor's example the c:out statements indicate that vallid
scores are actually 1-10). Just wanted to mention this discrepancy since I made
the program to match the example output as close as possible while still being
able to handle other test cases.
*/