#include <iostream>
#include "math.h"
using namespace std;

int main()
{
  //declare variables
  double plusx, minusx, a, b, c;

  //get values from the user
  cout << "The quadratic equation is x = (-b +- sqrt(b^2 - 4ac)) / 2a. Please enter your values for each variable below." << endl;
  cout << "a: "; cin >> a;
  cout << "b: "; cin >> b;
  cout << "c: "; cin >> c;

  //calculate and present the result
  plusx = (-b + sqrt(pow(b,2.0) - 4.0*a*c)) / (2.0*a);
  minusx = (-b - sqrt(pow(b,2.0) - 4.0*a*c)) / (2.0*a);
  cout << "\nThe answers are " << plusx << " and " << minusx << "." << endl;

}
