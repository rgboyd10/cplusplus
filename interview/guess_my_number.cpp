//Guess the Number game

#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
  int answer = rand() % 11 + 1;
  int userin;
  bool isWrong = true;

  cout << "I'm thinking of a number between 1 and 10. Enter your guess: \n";
  cin >> userin;

  while(isWrong)
    {
  if(answer > userin)
    {
      cout << "Your number is too low. Try again.\n";
      cin >> userin;
    }
  else if(userin > answer)
    {
      cout << "Your number is too high. Try again.\n";
      cin >> userin;
    }
  else
    isWrong = false;
    }
      cout << "You got it!\n";
}
