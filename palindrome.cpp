#include <iostream>

bool is_palindrome(string s2)
{
	
}

class Solution
{
public:
	string breakPalindrom(string s){
		int n = s.length();
		string answer = "";
		for(int i = 0; i < n; i++){
			for(char ch = 'a'; ch <= 'z'; ch++){
				if(s[i] != ch)
				{
					string s2 = s;
					s2[i] = ch;
					if(!is_palindrome(s2)){
						if(answer.empty()){
							answer = s2;
						}
					else {
						answer = min(answer, s2);
					}						
					}	
				}
			}
		}
		return answer;	
	}
};

int main()
{

}
