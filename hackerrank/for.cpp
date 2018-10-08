/*
A for loop is a programming language statement which allows code to be repeatedly executed.
The syntax for this is
for ( <expression_1> ; <expression_2> ; <expression_3> )
    <statement>

    expression_1 is used for intializing variables which are generally used for controlling terminating flag for the loop.
    expression_2 is used to check for the terminating condition. If this evaluates to false, then the loop is terminated.
    expression_3 is generally used to update the flags/variables.

A sample loop will be

for(int i = 0; i < 10; i++) {
    ...
}

Input Format

You will be given two positive integers, and (), separated by a newline.

Output Format

For each integer in the interval :

    If , then print the English representation of it in lowercase. That is "one" for , "two" for , and so on.
    Else if and it is an even number, then print "even".
    Else if and it is an odd number, then print "odd".

Note:

Sample Input

8
11

Sample Output

eight
nine
even
odd

*/

#include <iostream>
using namespace std;
int main()
{
  int x, y ;
  cin >> x >> y;

  for(int z = x; z <= y; z++)
  {
    if (z == 1)
    {
      cout  << "one" << endl;
    }
  else if(z == 2)
    {
      cout << "two" << endl;
    }
  else if(z == 3)
    {
      cout << "three" << endl;
    }
  else if(z == 4)
    {
      cout << "four" << endl;
    }
  else if(z == 5)
    {
      cout << "five" << endl;
    }
  else if(z == 6)
    {
      cout << "six" << endl;
    }
  else if(z == 7)
    {
      cout << "seven" << endl;
    }
  else if(z == 8)
    {
      cout << "eight" << endl;
    }
  else if(z == 9)
    {
      cout << "nine" << endl;
    }
  }
  
  for(int z = x; z <= y; z++)
    {
      if(z < 10){
      if(z % 2 == 0)
  	{
	  cout << "even" << endl;
	}
      else if (z % 2 != 0)
	{
	  cout << "odd" << endl;
	}
	}
    }
}
