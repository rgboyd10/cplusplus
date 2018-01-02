#include <string>
#include <iostream>
#include "Person.h"

using namespace std;

int main()
{
  int a = 3;
  cout << "a is " << a << endl;
  int *pA = &a;
  *pA = 4;
  cout << "a is " << a << endl;
  int b = 100;
  pA = &b;
  (*pA)++;
  cout << "a " << a << ", *pA " << *pA << endl;

}
