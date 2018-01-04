#include <string>
#ifndef _Person_H
#define _Person_H
#include <memory>

class Person
{
 private:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;

 public:
  Person(std::string first,
	 std::string last,
	 int arbitrary);
  Person();
  ~Person();
  std::string GetName() {return firstname + " " + lastname;}
  int GetNum() {return arbitrarynumber;}
};
#endif
