//#include "Person.h"
#include "Tweeter.h"
#include <iostream>

int main()
{
  Person p1("Kate", "Gregory", 123);
  {
    Tweeter t1("Someone", "Else", 456, "@whoever");
  }
  std::cout << "after innermost block" <<  std::endl;
  return 0;
}
