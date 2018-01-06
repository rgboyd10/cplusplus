using namespace std;

int main()
{
  auto a = 5.0, b = 10.0;
  auto i = 1.0, *ptr = &a, &ref = b;
  auto j = 10, str = "error"; //compile error

  map<string, int> index;
  auto& ref = index;
  auto* ptr = &index;
  const auto j = inex;
  const auto& cref = index;

  const vector<int> values;
  auto a = values; // type of a is vector<int>
  auto& b = value; // type of b is const vector<int>&

  volatile long clock = 0;
  auto c = clock; // c is not volatile

  JetPlane fleet[10];
  auto e = fleet; // type of e is JetPlane*
  auto& f = fleet; //type of f is JetPlane(&)[10] - a reference

  int func(double){return 10;}
  auto g = func; //type of g is int(*)(double)
  auto& h = func; // type of h is int(&)(double)

  template <typename T>
  void f(T t)
  {}
  
  f(expr); // T is deduced from expr

  auto var = expr; //type of var is deduced from expr, same as above
  
}
