using namespace std;

int main()
{
  int i = 10;
  cout << typeid(decltype(i + 1.0)).name() << endl; //outputs "double"

  vector<int> a;
  decltype(a) b;
  b.push_back(10);
  decltype(a)::iterator iter = a.end();

  template<typename X, typename Y>
    auto multiple(X x, Y y) -> decltype(x*y)
  {
    return x * y;
  }

  decltype(a++) b;

  template <int I>
  struct Num
  {
    static const int c = I;
    decltype(I) _member;
    Num() : _member(c) {}
  };

  int i;
  decltype(Num<1>::c, i) var = i; //var is int&

  Class A
  {
  private:
    A();
  };

  cout << typeid(decltype(A())).name() << endl; //doesn't compile: A() is private

  cout << typeid(decltype(declval<A>())).name() << endl; //OK

  template<typename X, typename Y>
  auto multiply(X x, Y y) -> decltype(x * y)
  {
    return x * y;
  }

  template<typename X, typename Y>
    ReturnType multiple(X x, Y y)
  {
    return x * y;
  }

  template<typename X, typename Y>
    decltype(x*y) multiply(X x, Y y) // x and y in decltype aren't in scope yet!
  {
    return x * y;
  }
}
