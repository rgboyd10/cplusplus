//this is pointless but displays the value of pointers

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
  
  Person Kate("Kate", "Gregory", 234);
  Person* pKate = &Kate;
  (*pKate).SetNumber(235);
  cout << "Kate: " << Kate.GetName() << " " << Kate.GetNumber() << endl;
  cout << "pKate: " << pKate->GetName() << " " << pKate->GetNumber() << endl;

  int& rA = a;
  rA = 5;
  cout << "a is " << a << endl;

  Person& rKate = Kate;
  rKate.SetNumber(345);
  cout << "rKate: " << rKate.GetName() << " " << rKate.GetNumber() << endl;

  //int* badPointer;
  //*badPointer = 3;
  //cout << *badPointer << endl;

  //int& badReference;
  //badReference = 3;
  //cout << badReference;

}
