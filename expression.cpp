double expression()
{
  double left = expression(); //read and evaluate an expression
  Token t = get_token(); //get the next token
  switch(t.kind) //see which kind of token it is
    {
    case '+':
      return left + term(); //read and evaluate a term, then do an add

    case '-':
      return left-term(); // read and evaluate a Term, then do a subtraction

    default:
      return left; //return the value of expression
    }
}
