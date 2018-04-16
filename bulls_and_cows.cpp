//A guessing game program that has a vector with 4  numbers ranging from 0 to 9. The user must discover those numbers by repeated guesses. If the number to be guessed is 1234 and the user guesses 1359; the response should be "1 bull and 1 cow" becaues the user got one digit right and in the right position (a bull) and one digit(3) right but in the wrong position (a cow).  The guessing continue until the user gets four bulls, that is, has the four digits correct and in the correct order.

#include <vector>
#include <iostream>
using namespace std;

int main()
{
  //declare variables
  vector<int> vec {8, 6, 7, 5};
  int guess1, guess2, guess3, guess4;
  string animal1, animal2, animal3, animal4;

  while(guess1 != vec[0] && guess2 != vec[1] && guess3 != vec[2] && guess4 != vec[3])
    {
  cout << "What is the first number? ";
  cin >> guess1;
  if(guess1 == vec[0]) animal1 = "bull";
  else if(guess1 == vec[1] || guess1 == vec[2] || guess1 == vec[3]) animal1 = "cow";
  else animal1 = "wrong, try again.";
  cout << "animal1 is " << animal1 << endl;

  cout << "What is the second number? ";
  cin >> guess2;
  if(guess2 == vec[1]) animal2 = "bull";
  else if(guess2 == vec[1] || guess2 == vec[2] || guess2 == vec[3]) animal2 = "cow";
  else animal2 = "wrong, try again.";
  cout << "animal2 is " << animal2 << endl;

  cout << "What is the third number? ";
  cin >> guess3;
  if(guess3 == vec[2]) animal3 = "bull";
  else if(guess3 == vec[1] || guess3 == vec[2] || guess3 == vec[3]) animal3 = "cow";
  else animal3 = "wrong, try again.";
  cout << "animal3 is " << animal3 << endl;

  cout << "What is the fourth number? ";
  cin >> guess4;
  if(guess4 == vec[3]) animal4 = "bull";
  else if(guess4 == vec[1] || guess4 == vec[2] || guess4 == vec[3]) animal4 = "cow";
  else animal4 = "wrong, try again.";
  cout << "animal4 is " << animal4 << endl;

  if(animal1 == "bull" && animal2 == "bull" && animal3 == "bull" && animal4 == "bull")
    {
      cout << "Congrats, you win.";
      break;
    }
    }
}
