#include <iostream>
using namespace std;

int add(double x, double y)
{
  return x+y;
}

int main()
{
  double a = add(3.2, 2.6);
  cout << "3.2 + 2.6 is " << a;
  cout << endl;
  return 0;
}
