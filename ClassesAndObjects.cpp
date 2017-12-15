#include "Person.h"

int main()
{
  Person p1("Kate", "Gregory", 123);
  {
    Person p2("Someone", "Else", 456);
  }
  return 0;
}
