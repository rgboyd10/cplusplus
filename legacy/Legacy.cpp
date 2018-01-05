#include <iostream>
#include "Point.h"
#include "functions.h"

using namespace std;
typedef unsigned long DWORD;

int main()
{
  int i1 = 7;
  long l1 = 3;
  DWORD d1 = 13;
  //d1 = "hello";
  cout << i1 << " " << l1 << " " << d1 << endl;
  KPoint p;
  p.x = 2;
  p.y = 3;
  int i2 = Change(i1);
  int i3 = Change((int)l1);
  int i4 = ManipulateUtility(5);

  UseSomething(&i1);
  UseSomething(&(p.x));
  UseSomething(&p);
  UseSomething(Change);

  arrays();

  stringdemo();

  
}
