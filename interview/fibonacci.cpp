#include <iostream>
using namespace std;

int main()
{
  int num = 1;
  int start = 1;
  while(num<= 100)
    {
      
      start = num + start;
      num += start;
      cout << start << "\n" << num << "\n";
      
    }
}
