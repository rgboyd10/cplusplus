using namespace std;

class Token
{
public:
  char kind;
  double value;
};

/*implement with

Token t;
t.kind = '+';
Token t2; //t2 is another Token
t2.kind = '8'; //we use the digit 8 as the "kind" for numbers
t2.value = 3.14;

Token tt = t; //copy initialization
if(tt.kind != t.kind)
throw("impossible!");
t = t2;
cout << t.value;

//constructors for Token objects
Token t1{'+'}; // t1.kind = '+'
Token t2{'8',11.5}; t2.kind = '8' and t2.value = 11.5

//usage in a main file
Token get_token(); //function to read a token from cin
vector<Token> tok; //we'll put the tokens here
int main()
{
while(cin)
{
Token t = get_token();
tok.push_back(t);
}
//...

for(int i = 0; i < tok.size(); i++)
{
if(tok[i].kind == '*') //we found a multiple!
 {
double d = tok[i-1].value*tok[i+1].value;
//now what?
 }
}
}
*/


