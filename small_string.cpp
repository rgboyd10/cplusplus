#include <iostream>
#include <string>

using namspace std;

int main()
{
  string name;
  cout << "Who are you ? ";
  cin >> name;
  string greeting = "Hello, " + name;
  if(name == "Kate")
    {
      greeting += ", I know you!";
    }
  cout << greeting << endl;
  return 0;
}
