#include "Person.h"
#include "Tweeter.h"
#include <iostream>

using namespace std;

int main()
{
  Person* Kate = new Person("Kate", "Gregory", 456);
  Tweeter* KateGregcons = new Tweeter("Kate", "Gregory", 567, "Kgregs");

  Person* pKateGregcons = KateGregcons;

  cout << Kate->GetName() << endl;
  cout << KateGregcons->GetName() << endl;
  cout << pKateGregcons->GetName() << endl;

  delete KateGregcons;
}
