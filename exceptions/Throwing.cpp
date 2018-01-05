#include "Person.h"
#include "Noise.h"
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
  Noise n1("beep 1");
  try
    {
      vector<int> v;
      v.push_back(1);
      Noise n2("bloop2");
      Person Kate("Kate", "Gregory", 0);
      int j = v.at(99); // accessing an element out of range of the vector std::out_of_range exception
    }
  catch(exception& e)
    {
      cout << e.what() << endl;
    }
  catch(out_of_range& e)
    {
      cout << "out of range exception" << e.what() << endl;
    }
  
  return 0;
  
}
