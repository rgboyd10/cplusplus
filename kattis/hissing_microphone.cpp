#include <iostream>
using namespace std;

int main()
{
	string input;
	cin >> input;
	input = input + '.';
	if(input.at(input.find('s') + 1) == 's')
	{
		cout << "hiss" << endl;
	}
	else
	{
		cout << "no hiss" << endl;
	}
}
