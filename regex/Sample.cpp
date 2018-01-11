#include <regex>
#include <cassert>
#include <string>
#include <iostream>

using namespace std;

int main()
{
  auto s = string{"Call 877-808-2321 to reach Amelia the hen!"};

  auto r = regex {R"((\d{3})-(\d{3})-(\d{4}))"};

  auto m = smatch {};
  //m = match_results<string::const_iterator>{};

  assert(m.empty());
	 
  assert(regex_search(s, m , r));

  assert(!m.empty());

  for(auto & sub : m)
    {
      //auto str = sub.str();

      cout << sub.length() << &*sub.first << endl;
    }

  auto output = m.format(R"($'<a href="link..."> $1 $2 $3</a>$')");

  cout << output.c_str() << endl;
}
