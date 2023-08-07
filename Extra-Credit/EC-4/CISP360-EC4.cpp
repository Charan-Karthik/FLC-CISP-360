// Source File Header
// CISP360-EC4.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/28/23

#include <iomanip>
#include <iostream>

int main() {
  const double PI = 3.14;
  const int MAX_RADIUS = 8;

  std::cout << "Circle Areas\n";
  std::cout << "============\n" << std::endl;
  std::cout << std::setw(5) << "Radius" << std::setw(10) << "Area \n";
  std::cout << std::setw(5) << "------" << std::setw(10) << "---- \n";

  for (int radius = 1; radius <= MAX_RADIUS; radius *= 2) {
    double area = PI * radius * radius;
    std::cout << std::setw(3) << radius << std::setw(13) << std::fixed
              << std::setprecision(2) << area << "\n";
  }

  return 0;
}

// Short Reflection
/*
Not really much to comment on here. This was another quick, easy, and fun
program. It kind of reminded me of when I was first getting started with
practicing algorithms for coding interviews and I had to do math questions
similar to this using loops, conditionals, and data strucutes like hashmaps and
arrays.

The formatting wasn't too bad, but for whatever reason I couldn't get all the
numbers in the 'Area' column to properly align with the start of the column or
even be centered with the column. Maybe I needed to experiment more with the
'right' and 'left' display properties?

One quick note: I did change the 'PI' column name to 'Area' since I thought that
was more descriptive of the data in that column.
*/
