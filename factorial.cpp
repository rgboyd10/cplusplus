#include <iostream>
#include <string>
using namespace std;

int FirstFactorial(int num)
{
	int result = num;
	num = num - 1;	
	while(num > 0)
	{
		result *= num;
		num--;
	}

	return result;
}

int main(void) { 
   
  // keep this function call here
  int num;
  cin >> num;
  cout << FirstFactorial(num) << endl;
  return 0;
    
}
