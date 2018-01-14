#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{

vector<int> v {2,7,1,6,2,-2,4,0};
int twos = 0;
int const target = 2;

//count how many entries have tha target value (2)
for (size_t i = 0; i < v.size(); i++)
  {
    if(v[i] == target)
      {
	twos++;
      }
    
  }

 twos = count(v.begin(),v.end(),target);
 twos = count(begin(v),end(v),target);

 //count how many entries are odd
 int odds = 0;
 for(auto elem: v)
   {
     if(elem % 2 != 0)
       {
	 odd++;
       }
   }

 odds = count_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0;});

 map<int, int> monthlengths{{1,31}, {2, 28}, {3,31}, {4, 30}, {5, 31},{6,30},{7,31},{8,30},{9,31},{10,31},{11,30},{12,31}};
 int longmonths = count_if(begin(monthlengths),end(monthlengths), [](auto elem) {return elem.second == 31;});

  //are all any or non of the values odd?
  bool allof, noneof, anyof;
  allof = (odds == v.size());
  noneof = (odds == 0);
  anyof = (odds > 0);

  allof = all_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0;});
  noneof = non_of(begin(v), end(v), [](auto elem) {return elem % 2 != 0;});
  anyof = any_of(begin(v), end(v), [](auto elem){return elem % 2 != 0;});

  return 0;
}
