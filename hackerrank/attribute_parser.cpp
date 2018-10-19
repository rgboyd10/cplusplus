/*
We have defined our own markup language HRML. In HRML, each element consists of a starting and ending tag, and there are attributes associated with each tag. Only starting tags can have attributes. We can call an attribute by referencing the tag, followed by a tilde, '~' and the name of the attribute. The tags may also be nested.

The opening tags follow the format:

<tag-name attribute1-name = "value1" attribute2-name = "value2" ...>

The closing tags follow the format:

</tag-name>

For example:

<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>

The attributes are referenced as:

tag1~value  
tag1.tag2~name

You are given the source code in HRML format consisting of lines. You have to answer queries. Each query asks you to print the value of the attribute specified. Print "Not Found!" if there isn't any such attribute.

Input Format

The first line consists of two space separated integers, and . specifies the number of lines in the HRML source program. specifies the number of queries.

The following lines consist of either an opening tag with zero or more attributes or a closing tag.There is a space after the tag-name, attribute-name, '=' and value.There is no space after the last value. If there are no attributes there is no space after tag name.

queries follow. Each query consists of string that references an attribute in the source program.More formally, each query is of the form ~ where and are valid tags in the input.

Constraints

    Each line in the source program contains, at max, characters.
    Every reference to the attributes in the queries contains at max characters.
    All tag names are unique and the HRML source program is logically correct.
    A tag can have no attributes as well.

Output Format

Print the value of the attribute for each query. Print "Not Found!" without quotes if there is no such attribute in the source program.

Sample Input

4 3
<tag1 value = "HelloWorld">
<tag2 name = "Name1">
</tag2>
</tag1>
tag1.tag2~name
tag1~name
tag1~value

Sample Output

Name1
Not Found!
HelloWorld

*/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <array>
using namespace std;
int main()
{
  int number_of_lines, number_of_queries;
  int g = 0;
  int j = 0;
  string stri;
  char x;
  stringstream ss(stri);
  cin >> number_of_lines >> number_of_queries;
  string results[number_of_lines][number_of_lines];
  vector<string> output;
  bool begin_write = false;
  
  //write the first value based on the number of lines
  /*  for(int q = 0; q < number_of_lines; q++)
    {
      results[q][0] = q;
      cout << results[q][0] << endl; //for testing
    }
  *///unncessary because we want to write the actual value and name to index 0
  
  while(ss.good())
    {
      ss >> x;
      if(x == '<')
	{
	  ss >> x;
	  if(x == '/')
	    {
	      break;
	    }
	  while(x != '=')
	    {
	      if(x == ' ')
		{
		  x = '~';
		}
	      stri += x;
     	      ss >> x;
	    }
	  results[g][0] = stri;
	  stri = "";
	}
      cout << results[g][0] << endl; //for testing
      
      if(x == '\"')
	{
	  ss >> x;
	  while(x != '\"')
	    {
	      stri += x;
	      ss >> x;
	    }
	  results[g][1];
	}
      cout << results[g][1] << endl; //for testing
      g++;
      
     }

int u = 0;
while(u < number_of_queries)
  {
    cin >> stri;
    if(results[0][u].find(stri))
      {
	output.push_back(results[1][u]);
      }
    u++;
  }

for(int i = 0; i < output.size(); i++)
  {
    cout  << output[i] << endl;
  }

}
