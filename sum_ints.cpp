//A program that reads and stores a series of integers and then computes the sum of the first  N integers that the user wants to sum.
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  //declare variables
  vector<int> values;
  int userin_values;
  int userin;
  int sum = 0;
  ostringstream strs;
  string input;

  //requesting the number of values to sum
  cout << "How many values would you like to sum? " << endl;
  cin >> userin;

  //requesting the numbers to sum
  cout << "Please enter some integers (press '|' to stop)." << endl;
  while(cin >> userin_values)
    {
      
      strs << userin_values;
      input = strs.str();
      if(input == "|")
      {
      break;
      }
      values.push_back(userin_values);
    }
        for(int x = 0; x < userin; x++)
          {
            sum += values[x];
          }

        cout << "The sum of the first " << userin << " numbers ( ";

        for(int x = 0; x < userin; x++)
            {
              cout << values[x] << " ";
            }
        cout << ") is " << sum << "." << endl; 
        
}
