// Source File Header
// currencyConverter.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/02/23

#include <iomanip>
#include <iostream>

// Function Prototypes
void ProgramGreeting();
int MainMenu();
int ReverseMenu();
void InvalidInput();
double ConvertCurrency(double conversionRate, double amount);
void DisplayConvertedAmount(double convertedAmount);

// Constant Global Variables - Converstion Rates
// Rates are accurate as of 06/24/23, 10:35 PST
const double USD_TO_YEN = 143.71;
const double USD_TO_EURO = 0.91;
const double USD_TO_POUND = 0.79;

const double YEN_TO_USD = 1 / USD_TO_YEN;
const double EURO_TO_USD = 1 / USD_TO_EURO;
const double POUND_TO_USD = 1 / USD_TO_POUND;

int main() {
  ProgramGreeting();

  // Speciﬁcation C1 - Main Menu
  int reverseMenuChoice;
  int mainMenuChoice = MainMenu();
  double amount, convertedAmount;

  // Speciﬁcation B1 - Menu Logic (Main Menu, siwtch statement)
  switch (mainMenuChoice) {
  case 1:
    std::cout << "Enter Amount in USD: ";
    // Speciﬁcation C3 - Input
    std::cin >> amount;
    // Speciﬁcation B2 - Option Functions
    convertedAmount = ConvertCurrency(USD_TO_YEN, amount);
    // Speciﬁcation B3 - Pass Arguments
    DisplayConvertedAmount(convertedAmount);
    break;
  case 2:
    std::cout << "Enter Amount in USD: ";
    // Speciﬁcation C3 - Input
    std::cin >> amount;
    // Speciﬁcation B2 - Option Functions
    convertedAmount = ConvertCurrency(USD_TO_EURO, amount);
    // Speciﬁcation B3 - Pass Arguments
    DisplayConvertedAmount(convertedAmount);
    break;
  case 3:
    std::cout << "Enter Amount in USD: ";
    // Speciﬁcation C3 - Input
    std::cin >> amount;
    // Speciﬁcation B2 - Option Functions
    convertedAmount = ConvertCurrency(USD_TO_POUND, amount);
    // Speciﬁcation B3 - Pass Arguments
    DisplayConvertedAmount(convertedAmount);
    break;
  case 4:
    // Speciﬁcation C2 - Reverse Menu
    reverseMenuChoice = ReverseMenu();

    bool isReverseMenuChoiceValid;
    if (reverseMenuChoice < 1 || reverseMenuChoice > 4) {
      isReverseMenuChoiceValid = false;
    } else {
      isReverseMenuChoiceValid = true;
    }

    if (isReverseMenuChoiceValid && reverseMenuChoice != 4) {
      // Speciﬁcation C3 - Input
      std::cout << "Enter Amount: ";
      std::cin >> amount;
    }

    // Speciﬁcation B1 - Menu Logic (Reverse Menu, else-if else ladder)
    if (reverseMenuChoice == 1) {
      // Speciﬁcation B2 - Option Functions
      convertedAmount = ConvertCurrency(YEN_TO_USD, amount);
      // Speciﬁcation B3 - Pass Arguments
      DisplayConvertedAmount(convertedAmount);
    } else if (reverseMenuChoice == 2) {
      // Speciﬁcation B2 - Option Functions
      convertedAmount = ConvertCurrency(EURO_TO_USD, amount);
      // Speciﬁcation B3 - Pass Arguments
      DisplayConvertedAmount(convertedAmount);
    } else if (reverseMenuChoice == 3) {
      // Speciﬁcation B2 - Option Functions
      convertedAmount = ConvertCurrency(POUND_TO_USD, amount);
      // Speciﬁcation B3 - Pass Arguments
      DisplayConvertedAmount(convertedAmount);
    } else if (reverseMenuChoice == 4) {
      std::cout << "Exiting Program..." << std::endl;
      return 0;
    } else {
      InvalidInput();
      return 0;
    }
    break;
  default:
    InvalidInput();
    break;
  }

  return 0;
}

void ProgramGreeting() {
  std::cout << std::endl;
  std::cout << "Hello World - my name is Charan Karthik. Today is Sunday "
               "07/02/23. Welcome to Currency Converter! This program enables "
               "you to convert value in one currency to another. I hope you "
               "find this useful! \n"
            << std::endl;
}

// Speciﬁcation C1 - Main Menu
int MainMenu() {
  int choice;
  std::cout << "Currency Converter Main Menu - Please Select an Option: \n 1. "
               "USD -> Yen \n 2. USD -> Euro \n 3. USD -> British Pound \n "
               "4. Flip Conversion \n"
            << std::endl;

  std::cout << "Enter Choice: ";
  std::cin >> choice;
  return choice;
}

// Speciﬁcation C2 - Reverse Menu
int ReverseMenu() {
  int choice;
  std::cout
      << "\n Currency Converter Reverse Menu - Please Select an Option: \n "
         "1. Yen -> USD \n 2. Euro -> USD \n 3. British Pound -> USD \n "
         "4. Quit w/o Conversion \n"
      << std::endl;
  std::cout << "Enter Choice: ";
  std::cin >> choice;
  return choice;
}

// Speciﬁcation B2 - Option Functions
double ConvertCurrency(double conversionRate, double amount) {
  return conversionRate * amount;
}

// Speciﬁcation B3 - Pass Arguments
void DisplayConvertedAmount(double convertedAmount) {
  std::cout << std::fixed << std::setprecision(3)
            << "Converted Amount: " << convertedAmount << "\n";
}

void InvalidInput() {
  std::cout << "Invalid Input. Please only enter 1, 2, 3, or 4. Please "
               "restart the program and try again. Exiting Program..."
            << std::endl;
}

// Specification A - Reflection
// Word Count (from Google Docs): 529
/*
This week was an interesting experience with AI feedback. GPT-4 seemed to make a
few mistakes in the code feedback. For instance, it mentioned that I didn’t
include function declarations for the functions I provided function prototypes
for and used in the main() function. At first, I thought that maybe I just
didn’t copy and paste the code into ChatGPT correctly, but it was all there.
Another error it made was in highlighting good C++ programming practices - it
mentioned that my variable names and function names were in ‘camelCase’, but the
reality was that my variable names were in ‘camelCase’ and my function names
were in ‘PascalCase’. These two mistakes were really strange to me.

Out of curiosity, I compared the GPT-4 results with GPT 3.5 and Bard. GPT 3.5
hallucinated slightly and said that I had inconsistent spelling for
‘Specification’. However, when I prompted it again and asked where this
happened, it apologized for the mistake and said that ‘Specification’ was
spelled correctly and consistently in all areas. Bard on the other hand provided
super vague and general feedback (not of the same quality as either GPT-3.5 or
GPT-4 with the same prompts).

Overall the feedback was the same as any previous week/homework. I had good
formatting, good use of functions for modularity, descriptive variable and
function names, proper definition of global constant variables, and decent error
handling (which is good practice). One suggestion for improvement was to add
additional error handling - specifically for the case when the user may not
enter a double value for the amount to convert. This is something I wanted to
do, but I realized after checking the textbook and HW 5 that error handling was
a bit out of scope for this assignment (HW 4) - though I couldn’t help it and
added some minimal error handling for the menu inputs at least. Another unique
suggestion from GPT-3.5 was to actually have the menu options come from an enum
instead of being hardcoded - I hadn’t even paused to think about this! I really
thought that piece of feedback was eye-opening and will definitely be
experimenting with it later. One last good
piece of advice for improving the program was to extend the modularization into
additional files/classes instead of just through functions. This is another
piece of advice that I want to try implementing!

Overall the TL;DR of this week would be: surprised AI made some seemingly simple
mistakes in providing feedback, intrigued by altering the program to use enums
and further modularizing it into separate files/classes, and excited to go into
next week and explore error handling (after all, a developer should always
assume: never trust the user)


Addition:
After re-submitting to fix a typo I realized that my similarity went up from
green to yellow. This was likely due to my re-submitting after many other
students had submitted their assignments. However, upon inspection of the areas
marked for similarity, it seemed to mostly be the specifications, constant
variables, and cout statements for the menus and their options. Otherwise, I’d
say the other logic aspects of my code were unique and not marked for
similarity.
*/