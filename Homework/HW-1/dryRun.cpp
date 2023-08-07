// Speciﬁcation C2 – Source File Header
// dryRun.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 06/11/2023

#include <iostream>
#include <string>

int main() {

  // Speciﬁcation C1 – Program Greeting
  // ProgramGreeting 1
  std::cout << "Hello World! Today is Sunday 06/11/2023. Welcome to "
              "my first ever C++ program (dryRun.cpp) on Replit - "
              "I couldn't get the VM to work on Apple Silicon... rip :(.\n\n";

  std::cout << "My name is Charan and I look forward to coding in the second "
              "fastest (after C) and third most energy efficient (after C and "
              "Rust) programming language!\n\n";

  // Speciﬁcation B1 – Variables
  int age = 22;
  float pi = 3.14f;
  double randomDouble = 123.456;
  bool isStudent = true;
  char commonIterator = 'i';
  std::string bestCompany = "Apple";

  // Speciﬁcation B2 – Output Variables
  std::cout << "My variable's name is 'age' and my value is: " << age;
  std::cout << std::endl;
  std::cout << std::endl;

  std::cout << "Hi, I'm pi (varName) and I am " << pi << " (varValue) \n";
  std::cout << std::endl;

  std::cout << randomDouble
            << " (varValue) is the value for a randomDouble (varName) \n";
  std::cout << std::endl;

  std::cout << "Charan isStudent (varName)? {true: 1, false: 0}: " << isStudent
            << " (varValue) \n";
  std::cout << std::endl;

  std::cout << "The most commonIterator (varName) used in programming is: "
            << commonIterator << " (varValue) \n";
  std::cout << std::endl;

  std::cout << "The bestCompany (varName) in the S&P 500 is: " << bestCompany
            << " (varValue) \n";
  std::cout << std::endl;

  std::cout << "End of Charan's first C++ program on Replit.";

  return 0;
}

// Program Output
/*
Hello World! Today is Sunday 06/11/2023. Welcome to my first ever C++ program (dryRun.cpp) on Replit - I couldn't get the VM to work on Apple Silicon... rip :(.

My name is Charan and I look forward to coding in the second fastest (after C) and third most energy efficient (after C and Rust) programming language!

My variable's name is 'age' and my value is: 22

Hi, I'm pi (varName) and I am 3.14 (varValue) 

123.456 (varValue) is the value for a randomDouble (varName) 

Charan isStudent (varName)? {true: 1, false: 0}: 1 (varValue) 

The most commonIterator (varName) used in programming is: i (varValue) 

The bestCompany (varName) in the S&P 500 is: Apple (varValue) 

End of Charan's first C++ program on Replit.
*/

// Specification A - Reflection
// Word Count (from Google Docs): 450
/*
I was actually kind of surprised by the feedback from ChatGPT - it did a lot better than I had thought it would. It read the comments in addition to the actual code content and provided feedback on that too (it mentioned that the file header and sections marked by the specifications were good practice).

ChatGPT also provided good detail in variable naming convention. I wasn’t aware that the common convention in C++ is to use lowercase letters for variable names. I had just assumed it was because that’s what my prior experience in other programming languages has taught me (except for Python which seems to prefer snake case) and I’m pleased to know that that standard is also applicable for C++. However, the feedback that ChatGPT gave did mention that my variable names could be better (i.e. more descriptive and meaningful). I somewhat disagree with this context as I felt that the variables I included were descriptive of what they represented. That being said this feedback on keeping variable names consistent and descriptive is something that I will keep in mind for the future.

One new thing that I did learn from the feedback was that I could improve my output formatting. Oftentimes in other languages such as Python or JavaScript, I’d usually just print blank lines with an empty ‘print()’ or ‘console.log()’ statement. However, it seems that in C++ I should be using the newline (‘\n’) instead of printing a blank line with “std::cout << std::endl;”. I will need to make sure that I follow this better coding practice for future assignments.

Another new thing I learned from ChatGPT was that C++ programs’ ‘main()’ method needs to ‘return 0;’. I’m not sure if this is something I accidentally deleted from Replit’s boilerplate C++ code or if it wasn’t provided, but ChatGPT caught this error and brought it to my attention. Since receiving the feedback I have gone back to implement it - even though ChatGPT mentioned that the compiler assumes this statement is there if it is omitted on accident, I want to be sure that I’m following best practices.

Overall this was an interesting experience getting assignment feedback from an AI chatbot. To be completely honest, I think I like it. It’s very fast and I can see myself using it to answer quick questions pretty frequently (as opposed to using Google Search to find an answer). I think I need to experiment with it more to determine if I prefer human or machine feedback, but my experience definitely hasn’t been negative. I haven’t used ChatGPT in an educational context before, but I’m very excited about the prospective things that it may be able to do.
*/