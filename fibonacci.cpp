#include <iostream>
using namespace std;

int main()
{
  int num = 1;
  int start = 1;
  while(start <= 34)
    {
      
      start = num + start;
      num += start;
      cout << start << " " << num << " ";
    }
}
