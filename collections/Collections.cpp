#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include "Person.h"
using namespace std;

void print(int i)
{
  cout << i << " ";
}

bool odd(int i)
{
  return i%2;
}

int main()
{
  vector<int> v;
  v.push_back(3);
  v.push_back(6);
  v.push_back(9);
  v.push_back(2);

  for(auto i = v.begin(); i != v.end(); i++)
    {
      cout << *i << " ";
    }

  cout << endl;

  for(auto i = v.rbegin(); i != v.rend(); i++)
    {
      cout << *i << " ";
    }

  cout << endl;

  int j = v[2];

  cout << j << endl;

  vector<Person> vp;
  Person Kate("Kate", "Gregory", 123);
  Person Someone("Someone", "Else", 456);

  vp.push_back(Kate);
  vp.push_back(Someone);

  for(auto ip = vp.begin(); ip != vp.end(); ip++)
    {
      cout << ip->GetName() << " ";
    }
  
  cout << endl << "----------------" << endl;

  map<int, Person> people;
  people[Kate.GetNum()] = Kate;
  people[Someone.GetNum()] = Someone;

  Person third("Third", "Fiction", 124);
  pair<int, Person> p(third.GetNum(), third);
  people.insert(p);

  for(auto ip = people.begin(); ip != people.end(); ip++)
    {
      cout << ip->first << " " << ip->second.GetName() << endl;
    }

  cout << endl;

  auto found = people.find(123);
  cout << found->first << " " << found -> second.GetName() << endl;

  string who = people[123].GetName();
  cout << "person at 124 is " << who << ". ";

  cout << endl << "----------------" << endl;

  cout << "contents of v: ";
  for_each(v.begin(), v.end(), print);

  cout << endl;

  cout << "odd elements of v: ";
  auto o = find_if(v.begin(), v.end(), odd);
  while(o != v.end())
    {
      cout << *o << " ";
      o = find_if(o++, v.end(), odd);
    }

  cout << endl;
  cout << "contents of v: ";
  sort(v.begin(), v.end());
  for_each(v.begin(), v.end(), print);

  cout << endl << "-------------------------" << endl;

  int length = third.GetName().size();
  string firstfour = third.GetName().substr(0,4);
  cout << length << " " << firstfour;

  cout << endl;

  return 0;
}
