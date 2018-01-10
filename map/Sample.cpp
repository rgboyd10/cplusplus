#include <map>
#include <cassert>
#include <iostream>

using namespace std;

int main()
{
  auto c = map<int, double> {};
  assert(c.empty());
  c = map<int, double>
    {
      {1,1.1},
      {4,4.1},
      {2,2.1},
      {3,3.1},
      {5,5.1}
    };
  assert(!c.empty());
  assert(c.size() == 5);
  assert(c[4] == 4.1);
  c[6] = 6.1;

  auto v = c[7];

  assert(v==0.0);
  assert(c.size() == 7);
  auto result = c.insert(make_pair(8,8.1));
  assert(result.second);

  result = c.emplace(9,9.1);

  auto i = c.find(6);

  assert(i->first == 6);
  assert(i->second == 6.1);

  c.erase(i);
  c.erase(7);

  for(auto v: c)
    {
      cout << v.first << "\t" << v.second << endl;
    }
}
