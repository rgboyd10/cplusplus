#include "Complex.h"
using namespace std;

Complex::Complex(ostream& o, set<int> c) : ostream(ostream& o, set<int> c), istream(ostream& o, set<int> c){}

Complex::~Complex()
{}

ostream& Complex::ostream& operator << (ostream& o, set<int> c)
{
  return o;
}

istream& Complex::istream& operator >> (istream& i, set<int> c)
{
  return i;
}
