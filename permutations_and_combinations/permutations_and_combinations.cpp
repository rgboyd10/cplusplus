//A program that calculates the permutations and combinations for two different numbers, and prints the result.

#include <iostream>
#include <vector>
using namespace std;

int factorial(int x)
{
  int result;
  int iterator = 1;

  while(iterator > 0)
    {
      result = x;
      iterator = x;
      result *= iterator;
      iterator--;
    }

  return result;
}

int main()
{
  //declare variables
  int num1, num2, result;
  char computation;

  //request numbers and desired computation from the user and read into variables
  cout << "Please enter two numbers, each followed by RET." << endl;
  cin >> num1 >> num2;
  cout << "Which calculation would you like to perform? Enter 'p' for permutation or 'c' for combinations." << endl;
  cin >> computation;

  //perform calculations and display result
  if(computation == 'p')
    {
      result = factorial(num1) / factorial((num1-num2));
      cout << "For the permutation of " << num1 << " & " << num2 << "the answer is " << result << "." << endl;
    }
  else if(computation == 'c')
    {
      result = (factorial(num1) / factorial((num1-num2))) / factorial(num2);
      cout << "For the combination of " << num1 << " & " << num2 << "the answer is " << result << "." << endl;
    }
  else //TODO:figure out how to allow them to try again.
    {
      cout << "You've entered an incorrect value, goodbye." << endl;
    }

    return 0;
}
