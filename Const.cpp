#include "Person.h"

int DoubleIt(int x)
{
  return x * 2;
}

int main()
{
  int i = 3;
  const int ci = 3;
  i = 4;
  //ci = 4;

  int j = 10;
  int DoubleJ = DoubleIt(j);
  int DoubleTen = DoubleIt(10);

  Person Kate("Kate", "Gregory", 234);
  Kate.SetNumber(235);
  const Person cKate = Kate;
  //cKate.SetNumber(236);
  int KateNumber = cKate.GetNumber();
  
  int* pI = &i;
  //int* pII = &ii;

  Person* pKate = &Kate;
  Person Someone("Someone", "Else", 345);

  const int * pcI = pI; //pointer to a const
  //*pcI = 4;
  pcI = &j;

  int* const cpI = pI; // const pointer
  *cpI = 4;
  //cpI = &j;
}
