#include <cstring>
#include <string>

void stringdemo()
{
  char* s1 = "Hello";
  int i = strlen(s1);
  char* s2 = new char[strlen(s1) + strlen(" Kate")];
  strcpy(s2,s1);
  strcat(s2, " Kate");
  char hello[] = {' ', 'w','o','r','l','d'};
  int j = strlen(hello);
  char better[] = "better";
  int k = strlen(better);

  std::string s(s1);
  s+= " modern c++";
  char* s3 = new char[s.length() + 1];
  //s3 = s;
  //s3 = s.c_str();
  strcpy(s3,s.c_str());

  delete[] s2;
  delete[] s3;
}
