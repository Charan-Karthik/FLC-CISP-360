// Source File Header
// revengeOfAlGore.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 06/25/23

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

// Global Constant Variables
// Speciﬁcation B1 - Mixed length output
const double MM2IN = 0.03937; // Millimeter to Inch Conversion
// Speciﬁcation B2 - Mixed temperature output
const double F2C = 5.0 / 9.0; // Fahrenheit to Celsius Conversion Constant

const double YEARLY_SEA_LEVEL_RISE = 3.1; // forecasted 3.1 mm per year rise
const double YEARLY_TEMP_RISE =
    2.0 / 15.0; // forecasted 2.0 degrees increase over 15 years

// Mean July Temperature Constants (in Fahrenheit) by City
const double NYC_JULY = 85.0;  // New York City
const double DEN_JULY = 88.0;  // Denver
const double PHX_JULY = 106.0; // Phoenix
const double SAC_JULY = 92.0;  // Sacramento

// Function Prototypes
void ProgramGreeting();
void autoHeader(std::string title);
double fahrenheitToCelsius(double fahrenheit);
void yearlyTempRiseTable();
void coutAll(double rise, double temp);
void coutMax(double rise_mm, double rise_in, double temp_F, double temp_C);
void yearlyTempAndSeaLevelRiseTable();

int main() {
  // Speciﬁcation C1 - ProgramGreeting
  std::cout << std::endl;
  autoHeader("Greetings!");
  ProgramGreeting();

  autoHeader("Climate Analysis");
  std::cout << std::endl;

  // Speciﬁcation C2 - 5 year rise
  autoHeader("5 Year Sea Level Rise");
  for (int year = 1; year <= 5; year++) {
    double seaLevelIncrease = year * YEARLY_SEA_LEVEL_RISE; // in inches
    std::cout << "Year " << year << " Rise: " << std::fixed
              << std::setprecision(3) << seaLevelIncrease << " mm or "
              << seaLevelIncrease * MM2IN << " inches" << std::endl;
  }

  std::cout << std::endl;

  // Specification C3 - 5 year temp (in general)
  autoHeader("General 5 Year Temperature Rise");
  for (int year = 1; year <= 5; year++) {
    double tempIncrease = year * YEARLY_TEMP_RISE; // in F
    std::cout << "Year " << year << " Temperature Rise: " << std::fixed
              << std::setprecision(3) << tempIncrease << " F or "
              << (tempIncrease * F2C) << " C" << std::endl;
  }
  std::cout << std::endl;

  // Specification C3 - 5 year temp (specific values for cities)
  autoHeader("5 Year Temperature Rise By City (Table View)");
  // Also kind of touches on the 'output table' of Specification C4
  // though I didn't use the coutAll function for the table's values
  yearlyTempRiseTable();
  std::cout << std::endl;

  // Specification C4 - coutAll function
  // The for loop for each city passes each year's specific temp rise value
  // and specific temperature value to the coutAll function for years 1-5
  autoHeader("5 Year Temperature Rise by City (List View)");

  autoHeader("New York");
  for (int year = 1; year <= 5; year++) {
    double specificYearRiseValue = year * YEARLY_TEMP_RISE;
    double specificYearTempValue = NYC_JULY + specificYearRiseValue;
    std::cout << "Year " << year << ": ";
    coutAll(specificYearRiseValue, specificYearTempValue);
  }
  std::cout << std::endl;

  autoHeader("Denver");
  for (int year = 1; year <= 5; year++) {
    double specificYearRiseValue = year * YEARLY_TEMP_RISE;
    double specificYearTempValue = DEN_JULY + specificYearRiseValue;
    std::cout << "Year " << year << ": ";
    coutAll(specificYearRiseValue, specificYearTempValue);
  }
  std::cout << std::endl;

  autoHeader("Phoenix");
  for (int year = 1; year <= 5; year++) {
    double specificYearRiseValue = year * YEARLY_TEMP_RISE;
    double specificYearTempValue = PHX_JULY + specificYearRiseValue;
    std::cout << "Year " << year << ": ";
    coutAll(specificYearRiseValue, specificYearTempValue);
  }
  std::cout << std::endl;

  autoHeader("Sacramento");
  for (int year = 1; year <= 5; year++) {
    double specificYearRiseValue = year * YEARLY_TEMP_RISE;
    double specificYearTempValue = SAC_JULY + specificYearRiseValue;
    std::cout << "Year " << year << ": ";
    coutAll(specificYearRiseValue, specificYearTempValue);
  }
  std::cout << std::endl;

  // Specification B4 - coutMax function
  // The for loop for each city passes each year's specific sea level rise
  // values and specific temperature values to the coutMax function
  // for years 1-5
  autoHeader("5 Year Sea Level and Temperature Rise - List View");
  autoHeader("New York");
  for (int year = 1; year <= 5; year++) {
    std::cout << "Year " << year << ": ";
    double seaLevelIncrease = year * YEARLY_SEA_LEVEL_RISE; // in inches
    double tempIncrease = year * YEARLY_TEMP_RISE;          // in F
    double newJulyTemp = (NYC_JULY + tempIncrease);
    coutMax(seaLevelIncrease, seaLevelIncrease * MM2IN, newJulyTemp,
            fahrenheitToCelsius(newJulyTemp));
  }
  std::cout << std::endl;

  autoHeader("Denver");
  for (int year = 1; year <= 5; year++) {
    std::cout << "Year " << year << ": ";
    double seaLevelIncrease = year * YEARLY_SEA_LEVEL_RISE; // in inches
    double tempIncrease = year * YEARLY_TEMP_RISE;          // in F
    double newJulyTemp = (DEN_JULY + tempIncrease);
    coutMax(seaLevelIncrease, seaLevelIncrease * MM2IN, newJulyTemp,
            fahrenheitToCelsius(newJulyTemp));
  }
  std::cout << std::endl;

  autoHeader("Phoenix");
  for (int year = 1; year <= 5; year++) {
    std::cout << "Year " << year << ": ";
    double seaLevelIncrease = year * YEARLY_SEA_LEVEL_RISE; // in inches
    double tempIncrease = year * YEARLY_TEMP_RISE;          // in F
    double newJulyTemp = (PHX_JULY + tempIncrease);
    coutMax(seaLevelIncrease, seaLevelIncrease * MM2IN, newJulyTemp,
            fahrenheitToCelsius(newJulyTemp));
  }
  std::cout << std::endl;

  autoHeader("Sacramento");
  for (int year = 1; year <= 5; year++) {
    std::cout << "Year " << year << ": ";
    double seaLevelIncrease = year * YEARLY_SEA_LEVEL_RISE; // in inches
    double tempIncrease = year * YEARLY_TEMP_RISE;          // in F
    double newJulyTemp = (SAC_JULY + tempIncrease);
    coutMax(seaLevelIncrease, seaLevelIncrease * MM2IN, newJulyTemp,
            fahrenheitToCelsius(newJulyTemp));
  }
  std::cout << std::endl;

  // Although this doesn't use the coutMax function, I thought
  // it would be nice to include as a way to visualize the data better
  autoHeader("5 Year Sea Level and Temperature Rise - Table View");
  yearlyTempAndSeaLevelRiseTable();

  return 0;
}

// Speciﬁcation C1 - ProgramGreeting
void ProgramGreeting() {
  std::cout << "Hello World - my name is Charan Karthik. Today is Sunday "
               "06/25/23. Welcome to my third ever C++ program. Today we will "
               "be doing some computations and climate analysis. I hope you "
               "enjoy what I've created! \n"
            << std::endl;
}

// Specification C4 - coutAll function
void coutAll(double rise, double temp) {
  std::cout << std::fixed << std::setprecision(3) << "Rise by " << rise
            << " F or " << (rise * F2C) << " C. New avg. July Temp: " << temp
            << " F or " << (fahrenheitToCelsius(temp)) << " C." << std::endl;
}

// Specification B3 - Auto Heading Function
void autoHeader(std::string title) {
  transform(title.begin(), title.end(), title.begin(), ::toupper);
  std::cout << title << "\n";
  std::cout << std::string(title.size(), '=') << "\n";
}

// Specification B4 - coutMax function
void coutMax(double mmRise, double inRise, double tempF, double tempC) {
  std::cout << std::fixed << std::setprecision(3)
            << "Sea Level Rise: " << mmRise << " mm or " << inRise
            << " in; Avg. July Temperature: " << tempF << " F or " << tempC
            << " C\n";
}

// Function to convert Fahrenheit to Celsius
// This function is used as a helper function to satisfy Speciﬁcation B2 - Mixed
// temperature output
double fahrenheitToCelsius(double fahrenheit) {
  return (fahrenheit - 32) * F2C;
}

// Function to display table of temperature increase over year for cities
void yearlyTempRiseTable() {
  std::cout << std::setw(17) << "Year" << std::setw(25) << "New York"
            << std::setw(33) << "Denver" << std::setw(32) << "Phoenix"
            << std::setw(35) << "Sacramento" << std::endl;

  for (int year = 0; year <= 5; year++) {
    std::cout << std::setw(15) << year;

    double tempNYC = NYC_JULY + year * YEARLY_TEMP_RISE;
    std::cout << std::setw(20) << std::fixed << std::setprecision(3) << tempNYC
              << " F | " << fahrenheitToCelsius(tempNYC) << " C";

    double tempDEN = DEN_JULY + year * YEARLY_TEMP_RISE;
    std::cout << std::setw(20) << std::fixed << std::setprecision(3) << tempDEN
              << " F | " << fahrenheitToCelsius(tempDEN) << " C";

    double tempPHX = PHX_JULY + year * YEARLY_TEMP_RISE;
    std::cout << std::setw(20) << std::fixed << std::setprecision(3) << tempPHX
              << " F | " << fahrenheitToCelsius(tempPHX) << " C";

    double tempSAC = SAC_JULY + year * YEARLY_TEMP_RISE;
    std::cout << std::setw(20) << std::fixed << std::setprecision(3) << tempSAC
              << " F | " << fahrenheitToCelsius(tempSAC) << " C";

    std::cout << std::endl;
  }
}

// Function to display table of temperature increase over year for cities
// and to display the sea level rise over year
void yearlyTempAndSeaLevelRiseTable() {
  std::cout << std::setw(17) << "Year" << std::setw(25) << "New York"
            << std::setw(33) << "Denver" << std::setw(32) << "Phoenix"
            << std::setw(35) << "Sacramento" << std::setw(34) << "Sea Level"
            << std::endl;

  for (int year = 0; year <= 5; year++) {
    std::cout << std::setw(15) << year;

    double tempNYC = NYC_JULY + year * YEARLY_TEMP_RISE;
    std::cout << std::setw(20) << std::fixed << std::setprecision(3) << tempNYC
              << " F | " << fahrenheitToCelsius(tempNYC) << " C";

    double tempDEN = DEN_JULY + year * YEARLY_TEMP_RISE;
    std::cout << std::setw(20) << std::fixed << std::setprecision(3) << tempDEN
              << " F | " << fahrenheitToCelsius(tempDEN) << " C";

    double tempPHX = PHX_JULY + year * YEARLY_TEMP_RISE;
    std::cout << std::setw(20) << std::fixed << std::setprecision(3) << tempPHX
              << " F | " << fahrenheitToCelsius(tempPHX) << " C";

    double tempSAC = SAC_JULY + year * YEARLY_TEMP_RISE;
    std::cout << std::setw(20) << std::fixed << std::setprecision(3) << tempSAC
              << " F | " << fahrenheitToCelsius(tempSAC) << " C";

    double specificYearSeaLevelRise = year * YEARLY_SEA_LEVEL_RISE;
    std::cout << std::setw(20) << std::fixed << std::setprecision(3)
              << specificYearSeaLevelRise << " mm | "
              << specificYearSeaLevelRise * MM2IN << " in";

    std::cout << std::endl;
  }
}

// Specification A - Reflection
// Word Count (from Google Docs): 457
/*
The feedback from ChatGPT this week is as expected - the code I provided is said
to compile (expected since it did compile on Replit). I also got the usual
feedback regarding the naming convention, use of comments, code structure,
headers, etc. - AI has deemed these all good (except the program’s name
‘revengeOfAlGore.cpp’ didn’t match what the program actually did). The one
suggestion for improvement it had for me this week was that I should be careful
with function naming (specifically the ‘coutAll’ and ‘coutMax’ functions) and be
sure that the functions I write don’t conflict with pre-existing C++ reserved
keywords. I also got some useful information regarding documenting code -
ChatGPT mentioned that including comments above functions is good practice (one
suggestion for improvement was that I actually do it for ALL my functions).

Moving on, another week means another fun AI experiment! This week I chose to
compare feedback from GPT 3.5 and GPT 4. The first thing I noticed was that
GPT 3.5’s response speed was much faster than GPT 4’s. That being said, GPT 4
provided more nuanced feedback. For example, it mentioned that my use of global
constants and lack of global variables was good - however, it also mentioned
that I was overusing these constants and that I should consider creating a
‘std::map’ or ‘std::unordered_map’ to store the temperature values for each
city. It also caught some redundancy in calculations that were similar across
the different specifications/functions and mentioned that I should consider
making these calculations their own functions. Last, it mentioned that my
‘autoHeader’ function could use some improvement. Since I opted to do it using
the <algorithm> file header, the function I created is transforming the input in
place. GPT 4 suggested that I don’t modify the argument directly, but rather
that I create a new string for the uppercase conversion. This feedback suggests
that maybe I should’ve gone with the method that Specification B3 hinted at
(converting each letter in a string to a char to uppercase and then putting the
string back together). Oddly, GPT 4 didn’t mention that the program name should
match what the program does (even though GPT 3.5 did).

Overall it was a fun experience comparing the different feedback from the two
LLM models (same model, but one having many more parameters). The difference
wasn’t as big as I would’ve thought it would be, but at least it wasn’t exactly
the same. This whole getting feedback from AI is pretty nice, but it oddly feels
repetitive and not very personal. Though for the level and complexity of the
program that kinda makes sense (I can’t see how a human would provide
meaningfully different feedback from what the AI did).
*/

// Reflection Addendum
// Word Count (from Google Docs): 412
/*
I noticed an oddly high similarity score (first yellow warning percentage). Upon
further inspection, the areas marked for similarity are mostly specifications,
for loop setup, formatting, and constant variables. Though the percentage was
higher than I expected it to be (especially after including the reflection
piece), the marked similarity items make sense. In fact, if those situations
where similarity was marked were not to be included, the similarity score is
super low.

I’m coming back to add a few thoughts to this reflection as I had some
realizations I wanted to comment on. First, the ambiguity of instructions in
this assignment caused a lot of discourse between my classmates and me. A lot of
us interpreted the discussions quite differently but in the end, this reminded
me that programming is really just problem-solving and that problem-solving is
collaborative and includes the perspectives of many. For example, when it came
to storing the calculation in a variable, I talked to some classmates on Discord
that manually typed out 60+ variables whereas I used a loop to temporarily store
values for each iteration. In the end, we all came to realize the importance of
being able to articulate our thought processes when solving a problem. Though we
approached the problem in different ways, we all were able to discuss our
thoughts thoroughly and solve it in a method that yielded similar results
(though the program output format was quite unique amongst us all, despite
having the same temperature and sea level rise values).

Also, another comment I wanted to make is regarding the function prototypes. I
thought this was an interesting piece in C++ programming as I’d never
encountered it before. In JavaScript function hoisting took care of what the
prototypes are effectively doing and in Java I never really stopped to think
about it, but the Spring Tools Suite IDE kinda did it all automatically with the
MVC framework (kinda took it for granted until now). Just thought this was cool
and wanted to briefly write about it.

Oh and one last thing I noticed as an area for improvement: my code was very
much spaghetti code and included a lot of very similar/repeating lines. I
could’ve added more functions to make the code better. And my function naming
convention was a little off - I should’ve stuck with PascalCase, but after
seeing coutAll and coutMax I kinda defaulted to camelCase (note to self to be
more wary of this in future programs).
*/