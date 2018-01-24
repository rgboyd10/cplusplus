#include <cstdio>
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

//2+(3+4)
struct Expression
{
  virtual double eval() = 0;
  
};

struct Literal : Expression
{
  double value;
  explicit Literal(const double value) : value{value}
  {}

  double eval() override;
  {
    return value;
  }
};

struct AdditionExpression : Expression
{
  shared_ptr<Expression> left, right;

  AdditionExpression(const shared_ptr<Expression>& expression, const shared_ptr) : left{expression}, right{expression}
  {}

  double eval() override
  {
    return left->eval() + right->eval();
  }
};

int main()
{
  AdditionExpression sum
  {
    make_shared<Literal>(2),
      make_shared<AdditionExpression>(make_shared<Literal>(3),make_shared<Literal>(4))
      };

  cout << "2+(3+4)" << sum.eval() << endl;  
  
  getchar();
  return 0;
}
