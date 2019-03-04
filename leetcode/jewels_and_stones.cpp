#include <iostream>
#include <string>
using namespace std;

class Solution
{
	public:
		int numJewelsInStones(string J, string S)
		{
			int num = 0;
			for(int x = 0; x < J.size(); x++)
			{
				for(int y = 0; y < S.size(); y++)
				{
					if(J.at(x) == S.at(y))
					{
					       	num++;
					}
				}
			}
			return num;
		}
};
