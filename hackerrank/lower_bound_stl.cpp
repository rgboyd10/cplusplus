/*
You are given integers in sorted order. Also, you are given queries. In each query, you will be given an integer and you have to tell whether that integer is present in the array. If so, you have to tell at which index it is present and if it is not present, you have to tell the index at which the smallest integer that is just greater than the given number is present.

Lower bound is a function that can be used with a sorted vector. Learn how to use lower bound to solve this problem by Clicking Here.

Input Format

The first line of the input contains the number of integers . The next line contains integers in sorted order. The next line contains , the number of queries. Then lines follow each containing a single integer .

Note that if the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.

Constraints


,where is element in the array.


Output Format

For each query you have to print "Yes" (without the quotes) if the number is present and at which index(1-based) it is present separated by a space.

If the number is not present you have to print "No" (without the quotes) followed by the index of the next smallest number just greater than that number.

You have to output each query in a new line.

Sample Input

 8
 1 1 2 2 6 9 9 15
 4
 1
 4
 9
 15

Sample Output

 Yes 1
 No 5
 Yes 6
 Yes 8

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  vector<int> vec;
  int num_int, val, num_queries, yy;

  cin >> num_int;
  for(int x = 0; x < num_int; x++)
    {
      cin >> val;
      vec.push_back(val);
    }
  cin >> num_queries;
  for(int x = 0; x < num_queries; x++)
    {
      cin >> yy;
      for(int y = 1; y < vec.size(); y++)
	{
	  if(yy == vec[y])
	    {
	      if(y == 1 && vec[y] != 2)
		{
		  cout << "Yes " << y << endl;
		  break;
		}
	      else
		{
		  cout << "Yes " << y + 1 << endl;
		  break;
		}
	    }
	  else if(yy < vec[y])
	    {
	      cout << "No ";
	      cout << y + 1 << endl;
	      break;
	    }
	  
	}
    }
}
