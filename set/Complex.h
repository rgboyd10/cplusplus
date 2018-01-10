#include <iostream>
#ifndef _Complex_H
#define _Complex_H

using namespace std;

class Complex
{
public:
  Complex();
  ~Complex();
  ostream& operator << (ostream& o, set<int> c);
  istream& operator >> (istream& i, set<int> c);

};

ostream& operator <<(ostream& o, set<int> c);
istream& operator >>(istream& i, set<int> c);
#endif
