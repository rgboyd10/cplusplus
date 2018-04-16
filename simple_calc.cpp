#include <iostream>
using namespace std;

int main()
{
  cout << "Please enter expression (we can handle +, -, *, and /)\n";
  int lval = 0;
  int rval;
  cin >> lval; //read leftmost operand
  if(!cin) throw("No first operand");
  for(char op; cin >> op;)
    {
      //read operator and right-hand operand repeatedly
      if(op!='x') cin >> rval;
      if(!cin) throw("no second operand");
      switch(op)
        {
        case '+':
          lval += rval;
          break;
        case '-':
          lval -= rval;
          break;
        case '*':
          lval *= rval;
          break;
        case '/':
          lval /= rval;
          break;
        default:
          cout << "Result: " << lval << '\n';

          return 0;
        }
    }
  throw("bad expression");

}
