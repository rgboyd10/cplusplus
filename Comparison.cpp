#include <iostream>
#include <string>
#include "Utility.cpp"

using namespace std;

int foo(string s)
{}

int something()
{}

int main()
{
  int i = 2;
  if(i == 3)
    {
      cout << "i is 3" << endl;
    }
  cout << "i " << i << endl;
  if(i = 3)
    {
      cout << "is is 3" << endl;
    }
  cout << "i " << i << endl;
  i = 4;
  if(3 == i)
    {
      cout << "i is 3" << endl;
    }
  cout << "i " << i << endl;

  cout << i << " is ";

  int p;
  if(p = foo("whatever")) 
    {
      something();
    }

  cout << "Enter a number " << endl;
  cin >> i;

  cout << i << " is ";
  if(!IsPrime(i))
    {
      cout << "not ";
    }
  cout << "prime." << endl;
  int j;
  cout << "Enter a second number " << endl;
  cin >> j;

  cout << i << "is ";
  if(j && (i % j))
    {
      cout << "not ";
    }
  
  cout << "a multiple of " << j << endl;

  return 0;
}
