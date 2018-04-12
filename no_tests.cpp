#include <iostream>
#include <cmath>
using namespace std;


int area(int length, int width)
{
  return length * width;
}

int main()
{
 int x, y;
   cout << "Enter a length followed by enter and width followed by enter to calculate an area." << endl;
   cin >> x >> y;
   int area1 = area(x,y);
   cout << area1 << endl;
}

int f(int x, int y, int z)
{
  int area1 = area(x,y);
  if(area1 <= 0)
    {
      throw ("Non-positive area");
       int area2 = framed_area(1, z);
      int area3 = framed_area(y, z);
      double ratio = double(area1)/area3;
      //..
    }
}
