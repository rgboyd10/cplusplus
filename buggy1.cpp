#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main(int arg, char* argv[])
{
  if(strcmp("",argv[1]))
    {
      cout << "You figured it out!\n" << endl;
    }
 else
   {
     cout << "Sorry :-(\n" << endl;
   }
}
