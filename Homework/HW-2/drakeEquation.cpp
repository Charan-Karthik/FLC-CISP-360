// Speciﬁcation C3 - Source File Header
// drakeEquation.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 06/18/23

#include <iomanip>
#include <iostream>

int main() {
  // Speciﬁcation C2 - Program Greeting
  // ProgramGreeting
  std::cout
      << "Hello. Today is 06/18/23. My name is Charan, welcome to my second "
        "C++ program. This program will use the Drake Equation to calculate "
        "how many potential alien civilizations there are in the universe. \n";

  // Speciﬁcation C1 - Variable Declaration
  float avgPercentPotentiallySupportingLife; // % stars w/ planets that can
                                             // potentially support life

  /* the following floating point variable numbers
  reference information about Planets */
  float percentDevelopingIntelligentLife;
  float percentAbleAndWillingToCommunicate;
  float civilizationExpectedLifetime; // measured in years

  // Speciﬁcation C4 - Variable Initialization
  avgPercentPotentiallySupportingLife = 0.9;
  percentDevelopingIntelligentLife = 0.5;
  percentAbleAndWillingToCommunicate = 0.8;
  civilizationExpectedLifetime = 10000;

  // Speciﬁcation B4 - Constant Variables
  const int RATE_OF_STAR_CREATION = 7;
  const float PERCENT_STARS_WITH_PLANETS = 0.4;
  const float PERCENT_PLANETS_DEVELOPING_LIFE = 0.13;

  // Speciﬁcation B1 - Calculation
  // etCiv represents the number of potential alien civilizations
  const float etCiv =
      RATE_OF_STAR_CREATION * PERCENT_STARS_WITH_PLANETS *
      avgPercentPotentiallySupportingLife * PERCENT_PLANETS_DEVELOPING_LIFE *
      percentDevelopingIntelligentLife * percentAbleAndWillingToCommunicate *
      civilizationExpectedLifetime;

  // Speciﬁcation B2 - Drake Equation Heading
  std::cout << std::endl;
  std::cout << "CHANCE OF INTELLIGENT LIFE \n";
  std::cout << "========================== \n";
  std::cout << std::fixed << std::setprecision(3) << etCiv << std::endl;

  // Speciﬁcation B3 - Double and Half Output and Headings
  std::cout << std::endl;
  std::cout << "SENSITIVITY ANALYSIS \n";
  std::cout << "=================== \n";
  std::cout << std::fixed << std::setprecision(3)
            << "Double Results: " << etCiv * 2 << std::endl;
  std::cout << std::fixed << std::setprecision(3)
            << "Half Results: " << etCiv / 2 << std::endl;

  return 0;
}

// Specification A - Reflection
// Word Count (from Google Docs): 628
/*
This week I had quite a lot of fun with generative AI using both ChatGPT and Bard. Starting with the feedback from the provided prompt, both platforms provided feedback that was pretty generalized and expected. The feedback highlighted good formatting, good variable naming convention, proper use of const, proper inclusion of the standard C++ libraries, and good use of comments. One nitpicky piece of advice I got was to be more consistent with my use of comments - ChatGPT recognized that I was using both [slash* *slash] and [double slash] suggested that I stick to one kind in the future. I agree with this feedback. Bard’s nitpicky suggestion was to provide more whitespace to distinguish code blocks (it mentioned that I did it well but that I could use more - which I found interesting because when I try that, Replit formats it back to what it thinks is the best use of whitespace for separation).

One fun and useful use case for generative AI that I tried differently this week was to copy and paste my code alongside the specifications and requirements to make sure I didn’t miss anything. I found this to be SUPER helpful because oftentimes I find myself looking back and forth between multiple windows to make sure I didn’t miss anything (which can often take a few minutes), but ChatGPT and Bard are able to do this checking in a matter of seconds.

One prompt I used this week was to suggest any additional improvements to the program. Common feedback I got from both ChatGPT and Bard was to use input validation if I were to change the program and prompt the user to provide values for some of the non-constant variables. Another piece of feedback I got was to use comments to explain the code relating to calculation (although I believe that the specification comment takes care of this, I do understand Bard’s point). The last two pieces of suggestions for improvement that Bard provided were to use functions (we haven’t quite gotten to that point in the class yet, but a function for the calculation would be a good idea - though one limitation would be that it takes quite a lot of inputs that can be easily mixed up, even though multiplication is commutative, this is still an issue we’d want to avoid) and a unit testing framework (or even unit testing to make sure calculations with predetermined numbers are as expected).

To quickly comment on plagiarism detection, this assignment did get a high percentage of similarity. However, upon closer examination of the report, the similarity mostly highlighted the file header and output statements with Specifications B2 and B3. This was likely due to a lot of students currently in this class and from this class in the past submitting the same required information in the specifications. Additionally, there was some overlap in variable naming conventions. Although I tried to be unique with my variable names, there are only so many different ways to create a constant for ‘RATE_OF_STAR_CREATION’. Additionally, the formatting to three decimal places has a pretty standard method to follow using the standard C++ libraries. Thus to conclude my reflection on plagiarism, it makes sense that the percentage is high due to the nature and requirements of the assignment; removing these contingencies, the percentage of similarity is quite low.

One last piece of reflection that I wanted to include this week was about the use of the ‘const’ keyword. Bard suggested that I label every variable with ‘const’ since this program isn’t prompting the user for any input. Though I understood where Bard was coming from with that suggestion I found my use of ‘const’ to be more ‘acceptable’ because I only attributed the ‘const’ keyword to variables that have generally accepted values.
 */