#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector <int> v;
	for(int i = 0; i < 10; i++)
	  {
	    v.push_back(i);
	  }
	
	for_each(v.begin(), v.end(), [](int i) {cout << i << " ";}); //lambda
	cout << endl;
	cout << endl << "--------------" << endl;
	for_each(v.begin(),
		 v.end(),
		 [](int n)
		 {
		   cout << n << " ";
		 }
		 );
	cout << endl;
	cout << endl << "------------" << endl;

	//multiple statements in a lambda
	for_each(v.begin(), v.end(),
		 [](int n)
		 {
		   cout << n;
		   if(n % 2 == 0)
		     {
		       cout << " even " << endl;
		     }
		   else
		     {
		       cout << " odd " << endl;
		     }
		 });

	cout << endl << "-------------------" << endl;

	//deducing the return type frm the code
	vector<int> v2;
	transform(v.begin(), v.end(), back_inserter(v2), [](int n) {return n * n * n;});
        for_each(v2.begin(), v2.end(), [](int n){cout << n << " ";});
	cout << endl;
	cout << endl << "-------------" << endl;

	//explicitly specifying the return type
	vector<double> dv;
	transform(v.begin(), v.end(), back_inserter(dv),
		  [](int n) -> double {
		    if(n%2 ==0)
		      {
			return n * n * n;
		      }
		    else
		      {
			return n/2.0;
		      }
		  });

	for_each(dv.begin(), dv.end(),
		 [](double x)
		 {
		   cout << x << " ";
		 });
		 
cout << endl;

//capturing by value explicity [x,y]
 int x = 3;
 int y = 7;
 cout << "print elements between " << x << " and " << y << " inclusive";
 for_each(v.begin(), v.end(), [x,y](int n)
	  {
	    if(n >= x && n <= y)
	      {
		cout << n << " ";
	      }
	  });
 cout << endl;
 for_each(v.begin(), v.end(), [](int n){cout << n << " ";});
 cout << endl;
 cout << endl << "--------------------------" << endl;

 //capturing by value implicitly [=]
 x = 2;
 y = 9;
 cout << "printing elements between " << x << " and " << y << " inclusive ";
 for_each(v.begin(), v.end(), [=](int n)
	  {
	    if(n >= x && n <= y)
	      {
		cout << n << " ";
	      }
	  });
 cout << endl;
 for_each(v.begin(), v.end(), [](int n) {cout << n << " ";});
 cout << endl;
 cout << endl << "--------------------------" << endl;

 //capturing by value and changing locally [=] mutable - also changing the value
 x = 1;
 y = 1;
 for_each(v.begin(), v.end(), [=](int& r) mutable
	  {
	    const int old = r;
	    r *= 2;
	    x = y;
	    y = old;
	  });

 cout << "doubling " << endl;
 for_each(v.begin(), v.end(),
	  [](int n)
	  {
	    cout << n << " ";
	  });
 cout << endl;
 cout << endl << "-----------------" << endl;

 //capturing by reference [&x, &y] - also changing the param (int&)
 v.clear();
 for(int i = 0; i < 10; i++)
   {
     v.push_back(i);
   }
 for_each(v.begin(), v.end(),
	  [&x, &y](int& r)
	  {
	    const int old = r;
	    r *= 2;
	    x = y;
	    y = old;
	  });

 for_each(v.begin(),v.end(),[](int n) {cout << n << " ";});
 cout << endl;
 cout << "x,y: " << x << ", " << y << endl;
 cout << endl;
 cout << endl << "-----------------------" << endl;

 //capturing whole stack by reference (and a neater way to keep initializing)
 v.clear();
 int i = 0;
 generate_n(back_inserter(v), 10, [&] {return i++;}); // [&]() {return i}
 cout << "initializing" << endl;
 for_each(v.begin(), v.end(), [](int n) {cout << n << " ";});
 cout << endl;
 cout << "i: " << i << endl;

 cout << endl << "---------------" << endl;

 return 0;
}
