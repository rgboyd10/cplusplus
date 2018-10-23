/*
Design a class named Box whose dimensions are integers and private to the class. The dimensions are labelled: length , breadth , and height .

The default constructor of the class should initialize , , and to .

The parameterized constructor Box(int length, int breadth, int height) should initialize Box's and to length, breadth and height.

The copy constructor BoxBox ) should set and to 's and , respectively.

Apart from the above, the class should have functions:

    int getLength() - Return box's length
    int getBreadth() - Return box's breadth
    int getHeight() - Return box's height
    long long CalculateVolume() - Return the volume of the box

Overload the operator for the class Box. Box Box if:

    <
    < and ==
    < and == and ==

Overload operator for the class Box().
If is an object of class Box:

should print , and on a single line separated by spaces.

Constraints


Two boxes being compared using the operator will not have all three dimensions equal.
*/

#include <iostream>
using namespace std;

class Box
{

  Box()
  {
    int length = 0;
    int breadth = 0;
    int height = 0;
  };

  Box(int length, int breadth, int height)
  {
    length = l;
    breadth = b;
    height = h;
  }
  
  Box(Box B)
  {
    length = B.length;
    height = B.height;
    breadth = B.breadth;
  }
private:
  int l, b, h;

public:
  int getLength()
  {
    return length;
  }

  int getBreadth()
  {
    return breadth;
  }

  int getHeight()
  {
    return height;
  }

  long long CalculateVolume()
  {
    long long vol;

    
    
    return vol;
  }
};

void check2()
{
  int n;
  cin >> n;
  Box temp;
  for(int i = 0; i < n; i++)
    {
      int type;
      cin >>type;
      if(type == 1)
	{
	  cout << temp < endl;
	}
      if(type == 2)
	{
	  int l, b, h;
	  cin >> l >> b >>h;
	  Box NewBox(l,b,h);
	  temp = NewBox;
	  cout << temp << endl;
	}
      if(type == 3)
	{
	  int l, b, h;
	  cin >> l, b, h;
	  Box NewBox(l, b, h);
	  if(NewBox < temp)
	    {
	      cout << "Lesser\n";
	    }
	  else
	    {
	      cout << "Greater\n";
	    }
	}
      if(type == 4)
	{
	  cout << temp.CalculateVolume() << endl;
	}
      if(type == 5)
	{
	  Box NewBox(temp);
	  cout << NewBox << endl;
	}
    } 
}

int main()
{
  check2();
}
