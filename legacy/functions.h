#include "Utility.h"
#include <iostream>
using namespace std;

int doubler(int i)
{
  return i * 2;
}

int tripler(int i)
{
  return i * 3;
}

typedef int (*CHANGER )(int i);

int Change(int i)
{
  CHANGER f;
  if(i>5)
    {
      f = tripler;
    }
  else
    {
      f = doubler;
    }
  return f(i);

  typedef int(Utility::* UF)();
  int ManipulateUtility(int i)
  {
    Utility u(i);
    UF action;
    if(i>3)
      {
	action = &Utility::triplex;
      }
    else
      {
	action = &Utility::doublex;
      }
    return (u.*action)();
  }

  void UseSomething(void* something)
  {
    //cout << *something << endl;
    int* s = (int*) something;
    cout << *s << endl;
  }

  void arrays()
  {
    int ints[3];
    ints[0] = 0;
    ints[1] = 1;
    *(ints+2) = 2;
    *(ints+3) = 3;

    float floats[] = {1.0,2.0,3.0};

    int* aI = new int[4];
    aI[0] = 4;
    aI[1] = 3;
    aI[2] = 2;
    *(aI+3) = 1;

    for(int i = 0; i < 4; i++)
      {
	aI[i] = i;
      }

    int localsize = sizeof(ints)/sizeof(ints[0]);
    int freestoresize = sizeof(aI)/sizeof(aI[0]);

    delete[] aI;

    int matrix[2][3];
    matrix[0][0] = 1;
    matrix[0][1] 2;
    
  }
  
}
