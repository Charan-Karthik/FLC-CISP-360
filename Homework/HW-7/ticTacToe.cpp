// Source File Header
// ticTacToe.cpp
// Charan Karthik, CISP 360 - Prof. Fowler
// 07/24/23

#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>

// Function Prototypes
void ProgramGreeting();
int StartMenu();
void GameInstructions();
void DisplayBoard(const std::vector<std::vector<char> > &board);
bool CheckForWinner(const std::vector<std::vector<char> > &board);
bool CheckForTie(const std::vector<std::vector<char> > &board);
void HumanTurn(std::vector<std::vector<char> > &board);
void ComputerTurn(std::vector<std::vector<char> > &board);

int main() {
  ProgramGreeting();

  while (true) {
    while (true) {
      int userMenuSelection = StartMenu();

      if (userMenuSelection == 3) {
        std::cout << "Thank you for playing! Goodbye!" << std::endl;
        return 0;
      }

      if (userMenuSelection == 1) {
        GameInstructions();
        continue;
      }

      if (userMenuSelection == 2) {
        break;
      }
    }

    std::vector<std::vector<char> > board(3, std::vector<char>(3, ' '));
    std::cout << std::endl;

    DisplayBoard(board);
    std::cout << std::endl;

    // Speciﬁcation C1 - Random Start
    bool isHumanMove = rand() % 2;
    if (isHumanMove) {
      std::cout << "Human starts the game!" << std::endl;
    } else {
      std::cout << "Computer starts the game!" << std::endl;
    }

    while (!CheckForWinner(board) && !CheckForTie(board)) {
      if (isHumanMove) {
        HumanTurn(board);
      } else {
        ComputerTurn(board);
      }

      std::cout << std::endl;
      DisplayBoard(board);
      std::cout << std::endl;

      isHumanMove = !isHumanMove;
    }

    if (CheckForWinner(board)) {
      if (isHumanMove) {
        std::cout << "\nCOMPUTER WINS!\n" << std::endl;
      } else {
        std::cout << "\nHUMAN WINS!\n" << std::endl;
      }
    } else {
      std::cout << "\nIT'S A TIE!\n" << std::endl;
    }

    char replayChoice;
    do {
      std::cout << "Do you want to play again? (Y/N): ";
      std::cin >> replayChoice;
      replayChoice = toupper(replayChoice);
    } while (replayChoice != 'Y' && replayChoice != 'N');

    if (replayChoice == 'N') {
      std::cout << "Thank you for playing! Goodbye!" << std::endl;
      return 0;
    }
  }
  return 0;
}

void ProgramGreeting() {
  std::cout << "\n";
  time_t t = time(NULL);
  tm *timePtr = localtime(&t);

  std::cout << "Welcome! Are you ready to play some Tic Tac Toe?\n"
            << std::endl;
  std::cout << "My name is Charan Karthik and I made this Tic Tac Toe game in "
               "C++. I hope you enoy what I've created! :)"
            << std::endl;
  std::cout << "Today's date is: " << std::put_time(timePtr, "%B %d, %Y")
            << std::endl;
  std::cout << std::endl;
}

// Speciﬁcation B1 - Start Menu
int StartMenu() {
  int choice;

  do {
    std::cout << "\nMENU\n";
    std::cout << "1 - Explain Game\n";
    std::cout << "2 - Play\n";
    std::cout << "3 - Quit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    // Speciﬁcation B2 - Valid Menu Choices
    if (choice < 1 || choice > 3) {
      std::cout << "Invalid choice. Please choose a valid option.\n";
    }

  } while (choice < 1 || choice > 3);

  return choice;
}

void GameInstructions() {
  std::cout
      << "\nTic Tac Toe is a game played between two players on a 3x3 board.\n";
  std::cout << "The goal is to get three of your symbols (X or O) in a row.\n";
}

// Specification C2 - Simple Display
void DisplayBoard(const std::vector<std::vector<char> > &board) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      std::cout << board[i][j];
      if (j != 2)
        std::cout << " | ";
    }
    if (i != 2)
      std::cout << "\n---------\n";
  }
  std::cout << std::endl;
}

bool CheckForWinner(const std::vector<std::vector<char> > &board) {
  for (int i = 0; i < 3; i++) {
    if (board[i][0] != ' ' && board[i][0] == board[i][1] &&
        board[i][1] == board[i][2])
      return true;
    if (board[0][i] != ' ' && board[0][i] == board[1][i] &&
        board[1][i] == board[2][i])
      return true;
  }

  if (board[0][0] != ' ' && board[0][0] == board[1][1] &&
      board[1][1] == board[2][2])
    return true;
  if (board[0][2] != ' ' && board[0][2] == board[1][1] &&
      board[1][1] == board[2][0])
    return true;

  return false;
}

bool CheckForTie(const std::vector<std::vector<char> > &board) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (board[i][j] == ' ')
        return false;
    }
  }
  return true;
}

void HumanTurn(std::vector<std::vector<char> > &board) {
  int x, y;
  do {
    std::cout << "\nNOTE: \n";
    std::cout << "The COLUMNS, from left to right, are 0, 1, and 2.\n";
    std::cout << "The ROWS, from top to bottom, are 0, 1, and 2.\n";
    std::cout << std::endl;

    std::cout << "Enter the row number: ";
    std::cin >> x;
    std::cout << "Enter the column number: ";
    std::cin >> y;

    // Specification B3 – Valid Move
    if (x < 0 || x > 2 || y < 0 || y > 2 || board[x][y] != ' ') {
      std::cout << "Invalid move. Please try again.\n";
    } else {
      board[x][y] = 'X';
      break;
    }
  } while (true);
}

// Specification C3 - AI
void ComputerTurn(std::vector<std::vector<char> > &board) {
  int x, y;
  do {
    /* The computer will generate potential coordinates until a valid coordinate
     * is generated. The check for validation checks to see if the generated
     * coordinate is an empty space (see the if statement below). */
    x = rand() % 3;
    y = rand() % 3;

    // Specification B3 – Valid Move
    if (board[x][y] == ' ') {
      board[x][y] = 'O';
      break;
    }
  } while (true);
}

// Specification A - Reflection
// Word Count (from Google Docs): 825
/*
Another week of pretty standard feedback: good formatting, good function and
variable naming, good program structure, and good use of comments. One thing
I’ve come to really appreciate (especially as these programs have gotten longer
and longer) is how fast the feedback from the LLMs is. I’d imagine it would take
human professors and/or TAs quite a while to read through students’ code and
provide the same feedback (and it would also probably be very boring for them).

A few new pieces of feedback did stand out to me this week though. The first is
the identification of potential compilation errors. ChatGPT identified that my
program might not actually run on Ubuntu because I was missing some file headers
(specifically <cstdlib>, <ctime>, and <cctype>). This really stood out to me
because my program had absolutely no issues compiling on replit. I opted to
include these headers after reading the feedback just in case my code decided to
not compile on the professor’s system. Either way, I thought that this was
interesting and I’m glad that ChatGPT caught this (may have saved me from
getting a 0! Haha).

The next piece of feedback this week was with respect to code logic. ChatGPT
commented on how my code logic was done and implemented correctly (especially
around the methods that check for ties and wins). That being said, it did bring
to light some edge cases that I hadn’t stopped to consider. For example, ChatGPT
opened my eyes to the very very slim possibility of the computer turn not being
able to find an empty spot when the game hasn’t been declared a tie. This
totally slipped my mind! Despite memorializing and understanding this feedback
though, I opted to not add the fix for this edge case as even ChatGPT mentioned
that this was very unlikely to happen (still interesting to me that it caught
this though! I wonder what would’ve been the outcome if this code was in Python
and I had put it through the code interpreter feature that everyone seems to be
talking about these days…).

Adding onto the logic piece, ChatGPT mentioned that my use of double ‘while
(true)’ loops may be confusing. I 100% agree here. This was actually a
last-minute change that I had to make because I almost missed the requirement
that mentioned that the program should prompt the user to play again. Although
it was a messy implementation (and I’m not proud that I had to do it), I’m glad
I was able to get a fix in despite being short on time (traveling this weekend
so that’s why I had to ‘rush’ a bit to submit on the Friday before).

Other sorts of niche pieces of feedback had to do with improving the AI
decision-making to make the game a bit harder (e.g. make the AI actively try to
win and block the human), enhancing input validation (i.e. clearing invalid
input), and using ‘srand(time(NULL))’ instead of just ‘rand()’. Definitely, all
valid pieces of advice that I’d explore and implement given more time, but, for
now, I’m mostly happy with the program I was able to create).

One additional small item to mention is that ChatGPT caught my use of magic
numbers! Specifically around the use of ‘3’ to denote the dimensions of the
tic-tac-toe square. This totally slipped my mind. I should’ve considered making
this a constant global integer variable and using that variable downstream
instead - especially considering the fact that I did program a game explanation
into the code… Oh well, something to keep in mind for next time. NO. MAGIC.
NUMBERS!

The absolute last thing I want to mention is something that ChatGPT actually
didn’t pick up on and that’s with respect to code optimization. I intentionally
used a vector for this assignment when an array would’ve worked just fine. The
reason for that is that I wanted to practice more with vectors since that’s an
actual new topic for me (although it ended up not really being all that
different from lists in Python/arrays in JavaScript). Anyway, my weird choice to
use vectors instead of arrays aside, I’m surprised that ChatGPT didn’t pick up
on the fact that the use of an array would’ve been more appropriate for this
particular program. Since the tic-tac-toe board is fixed in size and I’m not
allowing the user to change that, performance-wise, it would’ve made more sense
to allocate a fixed amount of memory with a 2D 3x3 array instead of allowing for
a dynamic 3x3 vector. Just something small I noticed because my brain is in
leetcode/DSA/algo grind mode right now trying to find the optimal solutions in
both time and space complexities. That being said, the difference in using an
array for this particular program would’ve been negligible so maybe that’s why
ChatGPT left it out. Regardless, I’m glad I finally got a chance to practice and
use vectors.

 */