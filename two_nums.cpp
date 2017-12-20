#include <iostream>

using namespace std;

int main()
{
  int x, y;
  cout << "Enter two numbers" << endl;
  cin >> x >> y;

  cout << x << " " ;
  if(x > y)
    {
      cout << "is larger than ";
    }
  else
    {
      cout << "is not larger than ";
    }
  cout << y << endl;

  if(x + y > 10)
    {
      cout << "Thanks for choosing larger numbers!" << endl;
    }
  return 0;
}
