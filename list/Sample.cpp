#include <list>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  auto c = list<int> {};

  c = lst<list> {1,2,3,4,5};

  cout << c.empty();
  cout << c.size();

  c = list<int> {begin(c), end(c)};

  c = list<int> {++begin(c), --end(c)};

  auto v = vector<int> {1,2,3};
  c = list<int> {begin(v) + 1, begin(v) - 1};

  c = list<int> (10);

  for(auto e : c)
    {
      cout << e;
    }

  c = list<int> (10, 123);

}
