#include <vector>
#include <iostream>
#include <memory>
#include <assert.h>
#include <algorithm>

using namespace std;

int main()
{
  auto c = vector<int>{};

  assert(c.empty());
  assert(c.size() == 5);

  c = vector<int>{1,2,3,4,5};

  assert(!c.empty());
  assert(c.size() == 5);

  c = vector<int> {begin(c), end(c)};

  assert(!c.empty());
  assert(c.size() == 5);

  c = vector<int> {begin(c) + 1, end(c) - 1};

  assert(c.size() == 3);

  assert(c[0]==2);
  assert(c[1]==3);
  assert(c[2]==4);

  c = vector<int>(10,123);

  assert(c.size() ==10);

  for(auto e : c)
    {
      assert(c == 123);
    }

  c = vector<int> {1, 2, 3, 4, 5};

  for(auto e: c)
    {
      cout << c[e] << endl;
    }

  for(auto i = begin(c); i != end(c); i++)
    {
      cout << c[i] << endl;
    }

  for(auto i = rbegin(c); i !- rend(c); i++)
    {
      cout << c[i] << endl;
    }

  for(auto i = 0u; i != ci.size(); i++)
    {
      cout << c[i] << endl;
    }

  c.emplace_back(6); // constructs the element in place.  this is a variadic function template.

  c.emplace(begin(c), 0);

  cout << endl;  
}
