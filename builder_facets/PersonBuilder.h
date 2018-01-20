//works as a convenience builder, we only use it to present builders of the different facets

//lets us switch from one Builder to another
class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilder
{
  Person p;

 protected:
  Person& person;

  explicit PersonBuilder(Person& person) : person{person}
  {

  }
  public:
 PersonBuilder() : person{p} {}

  operator Person()
  {
    return move(person);
  }
  
  PersonAddressBuilder lives();
  PersonJobBuilder works();

};
