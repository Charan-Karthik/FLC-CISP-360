// Source File Header
// CISP360-EC2.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/28/23

#include <iostream>

int main() {
  int rent, utilities, phone, cable;
  const int MONTHS_IN_A_YEAR = 12;

  std::cout << "Enter the following expenses (without decimal points)\n";
  std::cout << "Enter monthly cost for rent: ";
  std::cin >> rent;

  std::cout << "Enter monthly cost for utilities: ";
  std::cin >> utilities;

  std::cout << "Enter monthly cost for phone: ";
  std::cin >> phone;

  std::cout << "Enter monthly cost for cable: ";
  std::cin >> cable;

  std::cout << "\n" << std::endl;

  int totalMonthlyCosts = rent + utilities + phone + cable;
  int totalAnnualCost = totalMonthlyCosts * MONTHS_IN_A_YEAR;

  std::cout << "Total Monthly Costs: " << totalMonthlyCosts << "\n";
  std::cout << "Total Annual Cost: " << totalAnnualCost << "\n\n";

  return 0;
}

// Short Reflection
/*
Not much to really comment on here. A pretty short and fun program that allowed
me to practice more with user input. If I were to take this assignment to the
next level I'd probably try and tackle input validation and keep looping the
prompt until a valid input is provided.

Otherwise there's not much else I'd change, it's pretty straightforward and the
spaghetti code implementation can't be improved by much (at least that I can
think of).

RE-SUBMISSION NOTE
The addition I made was removing the 'magic number' 12 and assigning that value
to a constant variable (to follow best programming practices).
*/