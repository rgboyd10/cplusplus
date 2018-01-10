#include <set>
#include <cassert>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  set<int> c = {1,2,4,5,3};
 
  assert(!c.empty());
  assert(c.size() == 5);

  for (auto x : c)
    {
      cout << c << endl;
    }

  c.insert(0);
  auto result = c.emplace(6);

  assert(*result.first ==6);
  assert(result.second);

  result = c.emplace(6);

  assert(*result.first ==6);
  assert(!result.second);

  auto next = c.erase(begin(c));

  assert(*next ==1);

  assert(1 == c.erase(6));
  assert(0 == c.erase(123));

  auto i = c.find(3);
  assert(*i == 3);
  assert(end(c) == c.find(123));

  auto upper = c.upper_bound(3);
  assert(*upper == 4);

  auto lower = c.lower_bound(3);
  assert(*lower == 3);

  auto range = c.equal_range(3);

  assert(range.first == lower);
  assert(range.second == upper);

  for(auto i = begin(c); i != lower; i++)
    {
      cout << "lower is " << c << endl;
    }

  for(auto i = lower; i != upper; i++)
    {
      cout << "key is " << c << endl;
    }

  for(auto i = upper; i != end(c); i++)
    {
      cout << "upper is " << c << endl;
    }
}

