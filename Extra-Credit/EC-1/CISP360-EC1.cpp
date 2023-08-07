// Source File Header
// CISP360-EC1.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/28/23

#include <iomanip>
#include <iostream>

int main() {

  std::cout << std::endl;
  std::cout << "Hello World! Welcome to my first Extra Credit assignment "
              "submission for CISP 360 w/ Professor Fowler in Summer 2023. "
              "This is a quick program to calculate some sales number based "
              "on a division's performance. Enjoy! \n"
            << std::endl;

  double totalSales = 8.6; // in millions
  const double EAST_COAST_SALES_PERCENTAGE = 0.58;
  double eastCoastSales = totalSales * EAST_COAST_SALES_PERCENTAGE;

  std::cout << "Sales Prediction" << std::endl;
  std::cout << "=============" << std::endl;
  std::cout << "Total Sales: " << totalSales << "mm" << std::endl;
  std::cout << "East Coast Div: " << std::fixed << std::setprecision(3)
            << eastCoastSales << "mm" << std::endl;

  std::cout << "\nmm = millions";

  return 0;
}

// Short Reflection
/*
This truly was a short and easy program! I kinda approached it spaghetti code
style, but I think if I were to extend this program I'd choose to prompt the
user for the total sales number and maybe even the east coast division's sales
percentage. That being said, it's way out of the scope for what we were asked
for.

Seeing that this week's lesson was about functions though, I probably should've
put some of the code above into a function. *cough* program greeting and
calculation (and maybe even the display) *cough*
*/