#include "Person.h"
#include "Tweeter.h"
#include <iostream>
#include "Resource.h"
using namespace std;

int main()
{
  Tweeter t("Kate", "Gregory", 123, "@gregcons");
  Person* p = &t;
  Tweeter* pt = static_cast<Tweeter*>(p); //casting
  cout << pt->GetName() << endl;

  Resource f("local");
 Tweeter* pi = dynamic_cast<Tweeter*>(&f); // won't work because i doesn't have a first name, last name, twitter handle, or GetName function
 if(pi)
   {
     cout << pi->GetName() << endl;
}
 else
   {
     cout << "resource can't be cast to tweeter" << endl;
}
  cout << "resource can't be cast to tweeter"  << endl;
  

  return 0;
}
