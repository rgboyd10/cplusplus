#include "Person.h"
#include <string>

using namespace std;

int main()
{
  Person Kate("Kate", "Gregory", 345);
  Kate.AddResource();
  Kate.SetFirstName("Kate2");
  Kate.AddResource();
  Person Kate2 = Kate;
  Kate = Kate2;
  return 0;
}
