#include <string>
#ifndef _Person_H
#define _Person_H
class Person
{
 protected:
  std::string firstname;
  std::string lastname;
  int arbitrarynumber;

 public:
  Person(std::string first,
	 std::string last,
	 int arbitrary);
  ~Person();

  virtual std::string GetName() const;
  int GetNumber() const {return arbitrarynumber;}
  void SetNumber(int number) {arbitrarynumber = number;}
  void SetFirstName(std::string first) {firstname = first;}
};
#endif
