// Source File Header
// tempCalc.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/09/23

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

// Function Prototypes
void ProgramGreeting();
int Prompt();
bool ValFlo(int objectCode, float userTempInF, bool runValidation);
float Prompt(int objectCode);
void PromptTemperatureConversion(float objectTempInF);
void ConvertTemperature(int scale, float tempToConvert);
float FahrenheitToCelsius(float tempInF);

int main() {
  ProgramGreeting();
  int objectCode = Prompt();
  float objectTemp = Prompt(objectCode);
  PromptTemperatureConversion(objectTemp);
  return 0;
}

// Specification C1 – Only Valid Words
int Prompt() {
  std::string object;
  int objCode;
  do {
    std::cout << "Enter the object (cat, cot, cap, car): ";
    std::cin >> object;
    std::transform(object.begin(), object.end(), object.begin(), ::tolower);

    if (object == "cat") {
      objCode = 1;
    } else if (object == "cot") {
      objCode = 2;
    } else if (object == "cap") {
      objCode = 3;
    } else if (object == "car") { // Specification C3 – Another Thing
      objCode = 4;
    } else {
      objCode = 0;
      std::cout << "Invalid object. Please enter again.\n";
    }
  } while (objCode == 0);
  return objCode;
}

// Specification B1 – Floats for Temps
// Speciﬁcation B3 - Prompt Function
/*
IMPORTANT NOTE: This function satisfies both Specifications B1 and B3.

This function satisfies Speficiation B3 because it is an overloading method
(overloading the Prompt() function that returns an int). Although I
would've liked to name this function 'PromptObjectTemp' (it's more specific that
way), in order to satisfy Specification B3, I used the same function name to
demonstrate my understanding of overloading.

This function satisfies Specification B1 because it prompts the client to enter
a decimal temperature.
*/
float Prompt(int objectCode) {
  float tempIn;
  bool runValidation = true;
  do {
    runValidation = true;
    std::cout << "\nEnter the temperature in Fahrenheit: ";
    std::cin >> tempIn;
    // make sure that the user enters a number
    if (std::cin.fail()) {
      std::cout << "Invalid input. Please enter a number.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      runValidation = false;
      continue;
    }
  } while (!ValFlo(objectCode, tempIn, runValidation));
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  return tempIn;
}

// Specification B2 - Valid Temps Only
bool ValFlo(int objectCode, float userTempInF, bool runValidation) {
  float low, high;
  if (!runValidation) {
    return false;
  }

  if (objectCode == 1) { // cat
    low = 86.0 - 0.2;
    high = 102.0 + 0.2;
  } else if (objectCode == 2) { // cot
    low = 54.0 - 0.2;
    high = 80.0 + 0.2;
  } else if (objectCode == 3) { // cap
    low = 72.0 - 0.2;
    high = 88.0 + 0.2;
  } else if (objectCode == 4) { // car
    low = 0.0 - 0.2;
    high = 100.0 + 0.2;
  }
  if (userTempInF < low) {
    std::cout << "Temperature is out of range (too low). Please enter again.\n";
    return false;
  } else if (userTempInF > high) {
    std::cout
        << "Temperature is out of range (too high). Please enter again.\n";
    return false;
  }
  return true;
}

// Specification C2 – Select Temp Scale Menu
void PromptTemperatureConversion(float objectTempInF) {
  int scale;
  float convertedTemp;

  bool validInput = false;

  while (!validInput) {
    std::cout << "\nWould you like to convert the temperature?\n"
              << "1. Celsius\n"
              << "2. Kelvin\n"
              << "3. Rankine\n"
              << "4. All\n"
              << "5. Exit Program\n";
    std::cout << "Enter Selection: ";
    std::cin >> scale;

    // make sure that the user enters a number
    if (std::cin.fail()) {
      std::cout << "Invalid input. Please enter a number.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    } else if (scale < 1 || scale > 5) {
      std::cout << "Invalid input. Please enter a number between 1 and 5 "
                   "(inclusive).\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    } else {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      validInput = true;
      break;
    }
  }
  std::cout << std::endl;
  ConvertTemperature(scale, objectTempInF);
}

void ConvertTemperature(int scale, float tempToConvert) {
  float convertedTemp;
  std::cout << std::fixed << std::setprecision(3);

  switch (scale) {
  case 1: // Celsius
    convertedTemp = FahrenheitToCelsius(tempToConvert);
    std::cout << "Temperature in Celsius: " << convertedTemp << "\n";
    break;
  case 2: // Kelvin
    convertedTemp = FahrenheitToCelsius(tempToConvert) + 273.15;
    std::cout << "Temperature in Kelvin: " << convertedTemp << "\n";
    break;
  case 3: // Rankine
    convertedTemp = tempToConvert + 459.67;
    std::cout << "Temperature in Rankine: " << convertedTemp << "\n";
    break;
  case 4: // All
    ConvertTemperature(1, tempToConvert);
    ConvertTemperature(2, tempToConvert);
    ConvertTemperature(3, tempToConvert);
    break;
  case 5: // Exit Program
    break;
  default:
    // technically this should never print to the console
    // due to the error handling in the
    // 'PromptTemperatureConversion' function
    std::cout << "Invalid option. Please select 1, 2, 3, or 4.\n";
  }
}

float FahrenheitToCelsius(float tempInF) {
  float tempInC;
  tempInC = (tempInF - 32) * (5.0 / 9.0);
  return tempInC;
}

void ProgramGreeting() {
  std::cout << "Hello World! It's Charan Karthik." << std::endl;
  std::cout << "Today's I'm back at it again with another "
               "C++ Program. This program will work with some fun temperature "
               "conversions. I hope you enjoy :) \n"
            << std::endl;

  time_t currentTime = time(NULL);
  tm *tm_local = localtime(&currentTime);
  std::string monthName;
  switch (tm_local->tm_mon) {
  case 0:
    monthName = "January";
    break;
  case 1:
    monthName = "February";
    break;
  case 2:
    monthName = "March";
    break;
  case 3:
    monthName = "April";
    break;
  case 4:
    monthName = "May";
    break;
  case 5:
    monthName = "June";
    break;
  case 6:
    monthName = "July";
    break;
  case 7:
    monthName = "August";
    break;
  case 8:
    monthName = "September";
    break;
  case 9:
    monthName = "October";
    break;
  case 10:
    monthName = "November";
    break;
  case 11:
    monthName = "December";
    break;
  }
  std::cout << "The first new feature of this program will be getting the "
               "current date. Here is the current date: "
            << monthName << " " << tm_local->tm_mday << ", "
            << 1900 + tm_local->tm_year << "\n"
            << std::endl;
}

// Specification A - Reflection
// Word Count (from Google Docs): 454
/*
This week’s AI feedback was pretty good because it wasn’t just the usual
feedback I received. Though that being said, I did get some of the same general
feedback as always: good formatting and organization, good use of whitespace,
good variable and function names (for the most part - it was a little picky
about the Promtp() and ValFlo() functions), etc. The new content this week had
to do with none other than error handling. It actually made me quite happy when
ChatGPT described my code as having ‘robust error handling’ (especially because
I probably spent more time than I needed to cover all different kinds of edge
cases). Outside of that, it once again mentioned that I should consider creating
an enum for the object input instead of having a switch case to map ‘cat’ to
‘1’, etc. Again, I don’t know why I didn’t think of this - I use enums that
others have created at work, but I never think to create one myself… Really
gotta work on that part I suppose.

Other small pieces of feedback included advising me against using recursive
behavior in my ConvertTemperature() function and instead just having the
conversions for all the temperatures be hard coded for case ‘4’. I’m not sure
how I feel about that advice - I get where it’s coming from in that what I did
isn’t really necessary, but it seems that to have the cleanest code recursion
would be the best option. Another comment it made on this function was to break
it up into smaller pieces - since ConvertTemperature() is doing the converting
and displaying, ChatGPT advised that I break this function up into two parts (a
convert portion and a display portion). This advice stood out to me because
ChatGPT also mentioned that my other functions were well done in the sense that
they were all single-purpose functions.

The last piece of feedback I got was with some redundant code. I added error
handling for every c:in statement so a lot of the checks to see whether c:in
failed and clearing it made some parts of my code very repetitive. I really
should’ve made that it’s own function… Otherwise it was very cool and
interesting to see the main() function having so few lines of code. Abstracting
things out to the smaller functions was a really fun and enlightening
programming experience and made me want to forever leave spaghetti code behind.
Also, I’m super excited for Homework 6 and to work with the array data structure
(it’ll really make coding certain things a lot easier - for example, having all
the months to display the current date be of an array index instead of using a
switch case ladder for it)!
*/