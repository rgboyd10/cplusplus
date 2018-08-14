/*
A common problem in mathematics is to determine which quadrant a given point lies in.  There are four quadrants, numbered from 1 to 4. For example, the point A, which is at coordinates (12,5) lies in quadrant 1 since both its x and y values are positive, and point B lies in quadrant 2 since its x value is negative and its y value is positive. Your job is to take a point and determine the quadrant it is in. You can assume that neither of the two coordinates will be 0.
*/

#include <iostream>
using namespace std;
int main()
{
  int x;
  int y;
  int quadrant;

  cin >> x >> y;

  if(x > 0 && y > 0) quadrant = 1;
  else if(x < 0 && y < 0) quadrant = 3;
  else if(x < 0 && y > 0) quadrant = 2;
  else if(x > 0 && y < 0) quadrant = 4;

  cout << quadrant << endl;
}
