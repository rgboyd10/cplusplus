#include <iostream>
using namespace std;

double add(double x, double y)
{
  return x + y;
}

double add(double a, double b, double c)
{
  return a + b + c;
  //or return add(add(a,b),c);
}

bool test(bool x)
{
  return x;
}

bool test(double x)
{
  return x > 0;
}

void test(int y)
{
  return;
}

int main()
{
  double a = add(3, 4);
  cout << "3 + 4 is " << a;
  double b = add(1.2, 3.4);
  cout << endl;
  cout << "1.2 + 3.4 is " << b;

  cout << endl;
  double c = add(1.1, 2.2, 3.3);
  cout << "1.1 + 2.2 + 3.3 is " << c << endl;

  add(0,0);
  add(0,0,0);

  if(test(true))
    {
      cout << "true passes the test" << endl;
    }
  if(test(3.2))
    {
      cout << "3.2 passes the test" << endl;
    }
  /*  if(test(3))
    {
      cout << "3 passes the test" << endl;
      }*/

  return 0;
}
