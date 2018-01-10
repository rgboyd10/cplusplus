#include <map>
#include <cassert>
#include <iostream>


namespace std
{
  template <typename T>
  auto begin(pair<T, T> const & range) -> T
  {
    return range.first;
  }

  auto end(pair<T, T> const & range) -> T
  {
    return range.second;
  }

}
using namespace std;

int main()
{
  auto c = multimap<int, double>
    {
      {1,1.1},
      {2,2.1},
      {2,2.2},
      {3,3.1}
    };

  assert(!c.empty());
  assert(c.size() ==4);

  auto result = c.emplace(2, 2.3);
  assert(result->first == 2);
  assert(result->second == 2.3);

  for(auto& v : c)
    {
      cout << v.first << v.second << endl;    
    }

auto range = c.equal_range(2);

for(auto i = range.first; i != range.second; i++)
  {
    cout << i->first << i->second << endl;
  }

for(auto & v : c.equal_range(2))
  {
    cout << v.first << v.second << endl;
  }
}
