#include "Person.h"
#include <iostream>
#include "Noise.h"

using namespace std;

int Person::ratio()
{
  string fullname = GetName();
  int lengthwithoutspace = fullname.length()-1;
  return arbitrarynumber/lengthwithoutspace;
}

Person::Person() : firstname(""), lastname(""), arbitrarynumber("")
{
}

Person::Person(string first, string last, int arbitrary) : firstname(first), lastname(last), arbitrarynumber(arbitrary)
{
  Noise np("Speaking");
  if(arbitrarynumber == 0)
    {
      throw invalid_argument("Arbitrary number for a Person cannot be zero.");
    }
}

Person::~Person()
{
}
