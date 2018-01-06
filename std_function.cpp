#include <functional>

class LambdaStore
{
  function<bool(double)> _stored_lambda;

public:
  function<int(int)> get_abs() const
  {
    return [](int i) {return abs(i);};
  }

  void set_lambda(const function<bool(double)>& lambda)
  {
    _stored_lambda = lambda;
  }
};

int main()
{
  LambdaStore ls;
  ls.set_lambda([](double d) {return d > 0.0;});

  auto abs_lambda = ls.get_abs();
  abs_lambda(-10); // return 10;
}
