// Source File Header
// CISP360-EC3.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/28/23

#include <iostream>

int main() {
int month, day, year;

std::cout << "Magic Dates" << std::endl;
std::cout << "===========" << std::endl;
std::cout << "Enter the month: ";
std::cin >> month;

std::cout << "Enter the day: ";
std::cin >> day;

std::cout << "Enter the year: ";
std::cin >> year;

if (day < 1 || day > 31 || month < 1 || month > 12 || year < 10 ||
    year > 99) {
    std::cout << "Something's wrong with month, day, or year." << std::endl;
    return 1;
}

std::cout << "Candidate date: " << month << "/" << day << "/" << year
            << std::endl;

if (month * day == year) {
    std::cout << "You have a magic date!" << std::endl;
} else {
    std::cout << "Not a magic date." << std::endl;
}

return 0;
}

// Short Reflection
/*
Would've liked to add more validation using a hashmap or something similar to
make sure that valid dates are entered (i.e. making sure someone doesn't enter
February 30th or something like that).

Also adding a validation to the year to make sure that the user enters a two
digit ending for the year and not a four digit full year would be a useful
feature to include in an improved version.

One more addition I could think of would be adding some cout statements to
direct the user what kind of inputs to provide (especially around inputting a
two digit year and not a four digit one). Another approach to this would be to
enhance the detail in error handling to describe what specifically went wrong
and how to fix it.
 */