// Source File Header
// CISP360-EC6.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/28/23

#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>

const int MONKEYS = 3;
const int DAYS = 7;

// Function prototypes
void EnterData(double[MONKEYS][DAYS]);
double CalculateAverage(const double[MONKEYS][DAYS]);
double FindLeastAmountOfFood(const double food[MONKEYS][DAYS]);
double FindGreatestAmountOfFood(const double food[MONKEYS][DAYS]);
void DisplayFoodDataAsATable(const double food[MONKEYS][DAYS]);

int main() {
  double monkeyFoodDataByDay[MONKEYS][DAYS];

  EnterData(monkeyFoodDataByDay);

  std::cout << "Monkey Business" << std::endl;
  std::cout << "===============\n" << std::endl;

  DisplayFoodDataAsATable(monkeyFoodDataByDay);

  std::cout << "Least amount of food eaten: "
            << FindLeastAmountOfFood(monkeyFoodDataByDay);
  std::cout << "\nGreatest amount of food eaten: "
            << FindGreatestAmountOfFood(monkeyFoodDataByDay);

  return 0;
}

void EnterData(double food[MONKEYS][DAYS]) {
  for (int monkey = 0; monkey < MONKEYS; monkey++) {
    for (int day = 0; day < DAYS; day++) {
      std::cout << "Enter food for monkey " << monkey + 1 << ", for day "
                << day + 1 << ": ";
      std::cin >> food[monkey][day];

      while (food[monkey][day] < 0) {
        std::cout << "Food amount cannot be negative. Please enter again: ";
        std::cin >> food[monkey][day];
      }
    }
  }
}

double CalculateAverage(const double food[MONKEYS][DAYS]) {
  double total = 0.0;
  for (int monkey = 0; monkey < MONKEYS; monkey++) {
    for (int day = 0; day < DAYS; day++) {
      total += food[monkey][day];
    }
  }
  return total / (MONKEYS * DAYS);
}

double FindLeastAmountOfFood(const double food[MONKEYS][DAYS]) {
  double least = std::numeric_limits<double>::max();
  for (int monkey = 0; monkey < MONKEYS; monkey++) {
    for (int day = 0; day < DAYS; day++) {
      if (food[monkey][day] < least) {
        least = food[monkey][day];
      }
    }
  }
  return least;
}

double FindGreatestAmountOfFood(const double food[MONKEYS][DAYS]) {
  double greatest = std::numeric_limits<double>::min();
  for (int monkey = 0; monkey < MONKEYS; monkey++) {
    for (int day = 0; day < DAYS; day++) {
      if (food[monkey][day] > greatest) {
        greatest = food[monkey][day];
      }
    }
  }
  return greatest;
}

void DisplayFoodDataAsATable(const double food[MONKEYS][DAYS]) {
  // Column Headers
  std::cout << std::setw(5) << "M";
  for (int day = 1; day <= DAYS; day++) {
    std::cout << std::setw(8) << "D" << day;
  }
  std::cout << std::endl;

  // Monkey Food Data By Day
  for (int monkey = 0; monkey < MONKEYS; monkey++) {
    std::cout << std::setw(5) << monkey + 1;
    for (int day = 0; day < DAYS; day++) {
      std::cout << std::setw(9) << food[monkey][day];
    }
    std::cout << std::endl;
  }

  // Row for Averages
  std::cout << std::setw(5) << "Avg";
  for (int day = 0; day < DAYS; day++) {
    double dailyAverage = 0.0;
    for (int monkey = 0; monkey < MONKEYS; monkey++) {
      dailyAverage += food[monkey][day];
    }
    std::cout << std::setw(9)
              << static_cast<int>(std::round(dailyAverage / MONKEYS));
  }
  std::cout << std::endl;
}

// Short Reflection
/*
This was a pretty fun program to compose. I've always struggled with working
with 2D arrays so this was really good practice. Hopefully DSA challenges
involving 2D arrays will be easier for me now!

One thing I noticed is that the code I wrote here probably isn't optimal. There's
a lot of nested loops being called and although I'd love to simplify that, I'm
not sure how to do that. I'm sure there's a better way to do this, but I can't
think of a method that doesn't involve taking away from making each function
single-purpose. I feel like it's something worth thinking about for future
improvements of this program, but I'm also not sure if I'm spending time
stressing over something of minor relevance.

Outside of that though, it was a very straightforward program with clear
requirements. All things considered, I'm happy with the way it turned out,
especially the fact that I was able to get the table formatted nearly.
 */