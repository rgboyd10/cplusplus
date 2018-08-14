/*
Young Mirko threw matches all over the floor of his room.

His mom did not like that and ordered him to put all the matches in a box. Mirko soon noticed that not all of the matches on the floor fit in the box, so he decided to take the matches that don¡¯t fit and throw them in the neighbour¡¯s garbage, where his mom (hopefully) won¡¯t find them.

Help Mirko determine which of the matches fit in the box his mom gave him. A match fits in the box if its entire length can lie on the bottom of the box. Mirko examines the matches one by one.
Input

The first line of input contains an integer N(1¡ÜN¡Ü50), the number of matches on the floor, and two integers W and H, the dimensions of the box (1¡ÜW¡Ü100, 1¡ÜH¡Ü100).

Each of the following N lines contains a single integer between 1 and 1000 (inclusive), the length of one match.
Output

For each match, in the order they were given in the input, output on a separate line ¡°DA¡± if the match fits in the box or ¡°NE¡± if it does not.
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
  //declare vars
  vector <int> match_length;
  int lengths;
  int number_of_matches = 0;
  int width;
  int height;
  int x = 0;
  //read in values
  cin >> number_of_matches >> width >> height;

  while(x < number_of_matches)
    {
      cin >> lengths;
      match_length.push_back(lengths);
      x++;
    }

  //compute and write the lengths and DA or NE
  for(int x = 0; x < match_length.size(); x++)
    {
      if(sqrt(pow(width,2) + pow(height,2)) >= match_length[x])
	{
	  cout << "DA" << endl;
	}
      else
	cout << "NE" << endl;
    }
}
