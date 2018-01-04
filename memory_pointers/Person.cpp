#include "Person.h"
#include <iostream>

using namespace std;

Person::Person(string first, string last, int arbitrary) : firstname(first), lastname(last), arbitrarynumber(arbitrary)
{
  cout << "Constructing" << firstname << " " << lastname << endl;
}

string Person::GetName() const
{
  return firstname + " " + lastname;
}

bool Person::operator<(Person& p)
{
  return arbitrarynumber < p.arbitrarynumber;
}

bool Person::operator<(int i)
{
  return arbitrarynumber < i;
}

bool operator<(int i, Person& p)
{
  return i < p.arbitrarynumber;
}

void Person::AddResource()
{
  pResource.reset();
  pResource = std::make_shared<Resource>("Resource for " + GetName());
}
