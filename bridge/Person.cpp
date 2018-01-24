#include "Person.h"
#include <iostream>
using namespace std;
struct Person::PersonImpl
{
  void greet(Person *p);
};

void Person::PersonImpl::greet(Person *p)
{
  cout << "Hello, my name is " << p->name.c_str() << endl;
}
  void greet();
  Person::Person() : impl(new PersonImpl)
  {

  }

  Person::~Person()
  {
    delete impl;
  }

void Person::greet()
{
  impl->greet(this);
}
