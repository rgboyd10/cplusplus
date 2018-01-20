#include <string>
#include "PersonBuilder.h"

using namesace std;

class PersonAddressBuilder : public PersonBuilder
{
  typedef PersonAddressBuilder Self;
 public: 
  explicit PersonAddressBuilder(Person& person) : PersonBuilder{person}
  {}

  Self& at(string street_address)
    {
      person.street_address = street_address;
      return *this;
    }

  Self& with_postcode(std::string post_code)
    {
      person.post_code = post_code;
      return *this;
    }

  Self& in(std::string city)
    {
      person.city = city;
      return *this; // returns a reference to the current object
    }
    
};
