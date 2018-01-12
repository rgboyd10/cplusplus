#include <iostream>

using namespace std;

void f()
{
  cout << "Hello, world!\n" << endl;
}

int main(void)
{
  cout << "Please enter a number: \n" << endl;
  int num;
  cin >> num;
  
  cout << "DEBUG before: " << "\n" << num << endl;

  num = num/2 + 1;

  cout << "DEBUG after: " << "\n" << num << endl;
  
  for(int i = 0; i < num; i++)
    {
      cout << i << "\n" << endl;
    }

  return 0;
}
