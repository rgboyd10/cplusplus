//a program that reads digits and composes them into integers.  
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  char a, b, c, d;
  int e, f, g, h;

  cout << "Please enter a number with four or less digits." << endl;
  cin >> a >> b >> c >> d;
  e = a-'0';
  f = b-'0';
  g = c-'0';
  h = d-'0';

  cout << e << f << g << h << endl;
}
