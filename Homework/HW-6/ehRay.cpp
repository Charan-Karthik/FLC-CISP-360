// Source File Header
// ehRay.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/16/23

#include <algorithm>
#include <ctime>
#include <iomanip>
#include <iostream>

// Function Prototypes
void ProgramGreeting();
void DisplayArray(const int integerArray[], int arraySize);
void DisplayArray(const float floatarrayArray[], int arraySize);
void DisplaySums(int arraySize, const int integerArray[],
                 const float floatArray[]);
void DisplayMinAndMax(int arraySize, const int integerArray[],
                      const float floatArray[]);
void ValueHunt(int arraySize, const int integerArray[],
               const float floatArray[]);
void ReverseArrays(int arraySize, int integerArray[], float floatArray[]);
void ShiftElements(int arraySize, int integerArray[], float floatArray[]);

int main() {
  ProgramGreeting();

  // Create two 10-element arrays
  // one for integers and one for floats
  const int arraySize = 10;
  int integerArray[arraySize] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  float floatArray[arraySize] = {1.1, 2.2, 3.3, 4.4, 5.5,
                                 6.6, 7.7, 8.8, 9.9, 10.10};

  // Speciﬁcation C1 – Display Array Function
  // Display all elements of both arrray
  std::cout << "Integer Array: \n";
  DisplayArray(integerArray, arraySize);

  std::cout << "\n" << std::endl;

  std::cout << "Float Array: \n";
  DisplayArray(floatArray, arraySize);

  // Speciﬁcation C2 – Sum
  // Calculate and display the sums of both arrays
  std::cout << "\n" << std::endl;
  DisplaySums(arraySize, integerArray, floatArray);

  // Specification C3 - Min and Max
  std::cout << std::endl;
  DisplayMinAndMax(arraySize, integerArray, floatArray);

  // Specification B1 - Value Hunt
  std::cout << std::endl;
  ValueHunt(arraySize, integerArray, floatArray);

  // Speciﬁcation B2 – A Ray Reversal
  std::cout << std::endl;
  ReverseArrays(arraySize, integerArray, floatArray);

  std::cout << "Reversed Integer Array: ";
  DisplayArray(integerArray, arraySize);
  std::cout << std::endl;

  std::cout << "Reversed Float Array: ";
  DisplayArray(floatArray, arraySize);
  std::cout << std::endl;

  std::cout << std::endl;
  // Undo Reversal Before Shifting
  ReverseArrays(arraySize, integerArray, floatArray);
  // Speciﬁcation B3 - Element Shift
  ShiftElements(arraySize, integerArray, floatArray);

  return 0;
}

void ProgramGreeting() {
  std::cout << "\n";
  time_t t = time(NULL);
  tm *timePtr = localtime(&t);

  std::cout << "Welcome to ehRay.cpp - a fun array manipulation program!"
            << std::endl;
  std::cout << "My name is Charan Karthik. I created this program in C++! :)"
            << std::endl;
  std::cout << std::setprecision(3) << std::fixed;
  std::cout << "Today's date is: " << std::put_time(timePtr, "%B %d, %Y")
            << std::endl;
  std::cout << std::endl;
}

// Speciﬁcation C1 – Display Array Function
// original function
void DisplayArray(const int integerArray[], int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    std::cout << integerArray[i] << " ";
  }
}

// Speciﬁcation C1 – Display Array Function
// overloaded function
void DisplayArray(const float floatArray[], int arraySize) {
  std::cout << std::setprecision(3) << std::fixed;
  for (int i = 0; i < arraySize; i++) {
    std::cout << floatArray[i] << " ";
  }
}

// Speciﬁcation C2 – Sum
void DisplaySums(int arraySize, const int integerArray[],
                 const float floatArray[]) {
  int integerSum = 0;
  float floatSum = 0;

  // Iterate through both arrays and find the sum of the elements within each
  for (int i = 0; i < arraySize; i++) {
    integerSum += integerArray[i];
    floatSum += floatArray[i];
  }

  std::cout << "Sum of elements in integer array: " << integerSum << std::endl;
  std::cout << "Sum of elements in float array: " << floatSum << std::endl;
}

// Speciﬁcation C3 – Min and Max
void DisplayMinAndMax(int arraySize, int const integerArray[],
                      const float floatArray[]) {
  // Set the min and max values as the first element of the array
  int minInteger = integerArray[0];
  int maxInteger = integerArray[0];
  float minFloat = floatArray[0];
  float maxFloat = floatArray[0];

  // Iterate through the array and update the min and max values
  // Starting at index 1 since index 0 was used to set the max and mins
  for (int i = 1; i < arraySize; i++) {
    if (integerArray[i] < minInteger) {
      minInteger = integerArray[i];
    }
    if (integerArray[i] > maxInteger) {
      maxInteger = integerArray[i];
    }
    if (floatArray[i] < minFloat) {
      minFloat = floatArray[i];
    }
    if (floatArray[i] > maxFloat) {
      maxFloat = floatArray[i];
    }
  }

  // Display the min and max values
  std::cout << "Minimum integer value: " << minInteger << std::endl;
  std::cout << "Maximum integer value: " << maxInteger << std::endl;
  std::cout << "Minimum float value: " << minFloat << std::endl;
  std::cout << "Maximum float value: " << maxFloat << std::endl;
}

// Speciﬁcation B1 – Value Hunt
void ValueHunt(int arraySize, const int integerArray[],
               const float floatArray[]) {
  int integerToFind;
  float floatToFind;

  bool integerFound = false;
  bool floatFound = false;

  std::cout << "Enter an integer value to search for: ";
  std::cin >> integerToFind;

  std::cout << "Enter a float value to search for: ";
  std::cin >> floatToFind;

  for (int i = 0; i < arraySize; ++i) {
    if (integerArray[i] == integerToFind) {
      integerFound = true;
    }
    if (std::abs(floatArray[i] - floatToFind) <= 0.05) {
      floatFound = true;
    }
  }

  std::cout << "Integer value was " << (integerFound ? "found" : "not found")
            << " in the array." << std::endl;
  std::cout << "Float value was " << (floatFound ? "found" : "not found")
            << " in the array." << std::endl;
}

// Speciﬁcation B2 – A Ray Reversal
void ReverseArrays(int arraySize, int integerArray[], float floatArray[]) {
  for (int i = 0; i < arraySize / 2; i++) {
    std::swap(integerArray[i], integerArray[arraySize - i - 1]);
    std::swap(floatArray[i], floatArray[arraySize - i - 1]);
  }
}

// Speciﬁcation B3 - Element Shift
void ShiftElements(int arraySize, int integerArray[], float floatArray[]) {
  int lastInteger = integerArray[arraySize - 1];
  float firstFloat = floatArray[0];

  for (int i = arraySize - 1; i > 0; i--) {
    integerArray[i] = integerArray[i - 1];
  }
  integerArray[0] = lastInteger;

  for (int i = 0; i < arraySize - 1; i++) {
    floatArray[i] = floatArray[i + 1];
  }
  floatArray[arraySize - 1] = firstFloat;

  std::cout << "Shifted Integer Array: ";
  DisplayArray(integerArray, arraySize);
  std::cout << std::endl;

  std::cout << "Shifted Float Array: ";
  DisplayArray(floatArray, arraySize);
  std::cout << std::endl;
}

// Specification A - Reflection
/*
Another week of pretty standard feedback. I got the usual: good naming
convention, good code structure, good use of comments, etc. A new piece of
positive feedback this week came with good use of the ‘const’ keyword in
function parameters - the AI feedback picked up on the fact that ‘const’ was
only used when the function wouldn’t be changing the input array(s). Another
piece of positive feedback I received was about creating functions that have a
clear purpose and being single purpose. Although I agree with the former half of
the feedback, I do believe that proper single-purpose functions should be split
into a ‘do something’ portion and then the ‘display portion’.  Although it’s a
bad habit of mine to code a function that does something and then display it
within that same function, I need to try and be more aware of this when actually
programming (and not just realizing this in hindsight).

One major piece of feedback for improvement that I can’t believe I missed was
with respect to error handling. I included no error handling whatsoever… This
didn’t stand out to me during the development process at all (which is really
strange because I’m usually on top of that) so I’ll need to be more aware of
this while creating programs in the future.

Another piece of interesting feedback I got was to use template functions to
handle arrays of any type instead of overloading the display function to handle
an integer array and a float array. That was definitely some good feedback that
I need to look into (especially because passing in arrays of any type is what
I’m most used to when developing in non-strictly-types languages). On a
different note, a smaller suggestion for improvement was to include the
‘arraySize’ variable as a global constant variable instead of declaring it in
the main function (on a side note, it’s interesting that the feedback didn’t
pick up on the fact that this naming convention should’ve also been in all caps
since it’s a constant variable).

The last thing I want to comment on is the similarity score. I submitted my
program as a .txt file without this reflection just to see what I’d be working
with with respect to the similarity score and I got a whopping 49%! That’s the
highest I’d ever seen in one of my submissions… Upon closer inspection of the
areas marked for similarity, it’s the usual suspects: specification comments,
function names, some variable names, a lot of the ‘std::cout’, comments
indicating the source file header/function prototypes, etc.

It’s really interesting to see how much was flagged and also how much the score
will drop after including this reflection. (I was actually pretty happy to see
that my logic for calculating the absolute value of the difference between the
user-inputted float and the floats in the area and comparing that to the 0.05
margin was not flagged because at first, I had done it with ranges and I was
pretty happy with myself for thinking of this different approach)

*/