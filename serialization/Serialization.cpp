#include <string>
#include <iostream>
#include <memory>
#include <functional>
#include <sstream>
#include <boost/serialization/serialization.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
using namespace std;

struct Address
{
  string street, city;
  int suite;

  friend ostream& operator<<(std::ostream& os, const Address& obj)
  {
    return os
      << "street: " << obj.street
      << " city: " << obj.city
      << " suite: " << obj.suite;
  }

private:
  friend class boost::serialization::access;

  template<class Ar> void serialize(Ar& ar, const unsigned int version)
  {
    ar & street;
    ar & city;
    ar & suite;
  }
};

struct Contact
{
  string name;
  Address address;

  friend ostream& operator<<(std::ostream& os, const Contact& obj)
  {
    return os
      << "name: " << obj.name
      << "address: " << obj.address;
  }

private:
  friend class boost::serialization::access;

  template<class Ar> void serialize(Ar& ar, const unsigned int version)
  {
    ar & name;
    ar & address;
  }


};

int main()
{
  Contact john;
  john.name = "John Doe";
  john.address = Address{"123 East Dr", "London", 123};

  auto clone = [](Contact c)
    {
      ostringstream oss;
      boost::archive::text_oarchive oa(oss);
      oa << c; // serializes John into a string

      string s = oss.str();

      Contact result;
      istringstream iss(s);
      boost::archive::text_iarchive ia(iss);
      ia >> result; //deserializes John string into result
      return result;
      
    };

  Contact jane = clone(john);
  jane.name = "Jane";
  jane.address.street = "123B West Dr";

  cout << john << endl << jane << endl;
  
  getchar();
  return 0;
}
