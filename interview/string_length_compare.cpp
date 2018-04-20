#include <iostream>
#include <string>

using namespace std;

int main()
{
  //declare variables
  string guess1;
  string guess2;

  //requests input and reads into variables
  cout << "Please enter the first string: \n";
  getline(cin,guess1);
  cout << "Please enter the second string: \n";
  getline(cin,guess2);

  if(guess1.length() > guess2.length())
    {
      cout << guess1 << " at length " << guess1.length() << " is longer than " << guess2 << " at length " << guess2.length() << ".\n";
    }
  else if (guess1.length() < guess2.length())
    {
      cout << guess1 << " at length " << guess1.length() << " is shorter than " << guess2 << " at length " << guess2.length() << ".\n";
    }
  else
    {
      cout << guess1 << " and " << guess2 << " are the same length at " << guess1.length() << ".\n";  
    }
  return 0;
}
