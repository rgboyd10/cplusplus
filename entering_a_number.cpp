#include <iostream>

using namespace std;

int main()
{
  int i;
  int j;
  cout << "Enter a number: ";
  cin >> i;
  cout << "You entered " << i << ". Enter another: ";
  cin >> j;
  bool keepgoing = true;
  int answer;

  for(int loop=0; loop < 10; loop++)
    {
      cout << loop << " ";
    }

  while(keepgoing)
    {
  if(i < j)
    {
      cout << "The first number, " << i << ", is less than the second number " << j << ".\n";
    }
  else
    {
      cout << "The first number, " << i << ", is greater than the second number " << j << ".\n";
    }
  if(i==j)
    {
      cout << "The first number, " << i << ", is the same as the second number " << j << ".\n"; 
    }
  if(i>j)
    {
      cout << "The first number, " << i << ", is greater than the second number " << j << ".\n";
    }

  cout << "Compare another? 0 for no: ";
  cin >> answer;
  if(answer == 0)
    {
      keepgoing = false;
    }
    }

}
