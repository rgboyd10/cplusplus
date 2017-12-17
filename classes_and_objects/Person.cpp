#include "Person.h"
#include <iostream>

Person::Person(std::string first, std::string last, int arbitrary) : firstname(first), lastname(last), arbitrarynumber(arbitrary)
{
  std::cout << "Constructing" << firstname << " " << lastname << std::endl;
}

Person::~Person()
{
std::cout << "Destructing" << firstname << " " << lastname << std::endl;
  
}
