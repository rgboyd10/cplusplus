//#include "Person.h"
#include "Tweeter.h"
#include "status.h"
#include <iostream>

using namespace std;

int main()
{
  Person p1("Kate", "Gregory", 123);
  {
    Tweeter t1("Someone", "Else", 456, "@whoever");
  }

  cout << "after innermost block" <<  std::endl;
  Status s = Pending;
  s = Approved;
  return 0;
}
