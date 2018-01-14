#include <algorithm>

using namespace std;

int main()
{
  vector <int> v{2, 4, 6, 6, 1, 3, -2, 0, 11, 2, 3, 2, 4, 4, 2, 4};
  string s {"Hello I am a sentence."};

  //find the first zero in the collection
  auto result = find(begin(v), end(v), 0);
  int weLookedFor = *result;

  //find the first 2 after that zero
  result = find(result, end(v), 2);
  if(result != end(v))
    {
      weLookedFor = *result;
    }
  
}
