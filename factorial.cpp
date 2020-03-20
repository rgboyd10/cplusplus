#include <iostream>
#include <string>
using namespace std;

int FirstFactorial(int num)
{
	int result;
	for(num; num >= 0; num--)
	{
		result *= num;
	}
	num = result;
	return num;

}

int main(void) { 
   
  // keep this function call here
  cout << FirstFactorial(gets(stdin));
  return 0;
    
}
