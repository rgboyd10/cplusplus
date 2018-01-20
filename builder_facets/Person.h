#include <string>
using namespace std;

class PersonBuilder;

class Person
{
  //address
  string street_address, post_code, city;

  //employment
  string company_name, position;
  int annual_income = 0;

  Person(){}
 public:

 Person(Person&& other) :
  street_address(std::move(other.street_address)),
    post_code(std::move(other.post_code)),
    city(std::move(other.city)),
    company_name(std::move(other.company_name)),
    position(std::move(other.position)),
    annual_income(std::move(other.annual_income))
      {
      }

  Person& operator=(Person&& other)
    {
      if(this == &other)
	return == &other;

      street_address = std::move(other.street_address);
      post_code = std::move(other.post_code);
      city = std::move(other.city);
      company_name = std::move(other.company_name);
      position = std::move(other.position);
      annual_income = std::move(other.annual_income);
      return *this;
    }

  friend std::ostream& operator<<(std::ostream& os, const Person& obj)
  {
    return os
      << "street_address: " << obj.street_address
      << "post_code: " << obj.post_code
      << "city: " << obj.city
      << "company_name: " << obj.company_name
      << "position: " << obj.position
      << "annual_income: " << obj.annual_income
  }


  
  static PersonBuilder create();

  friend class PersonBuilder;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
};
