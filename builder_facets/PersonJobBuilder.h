#include <string>
#include "PersonBuilder.h"
using namesace std;

class PersonJobBuilder : public PersonBuilder
{
  typedef PersonJobBuilder Self;
 public: 
  explicit PersonJobBuilder(Person& person) : PersonBuilder{person}
  {}

  Self& at(string company_name)
    {
      person.company_name = company_name;
      return *this;
    }

  Self& with_postcode(std::string position)
    {
      person.position = position;
      return *this;
    }

  Self& in(std::string annual_income)
    {
      person.annual_income = annual_income;
      return *this; // returns a reference to the current object
    }
    
};
