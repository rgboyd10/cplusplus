#include <vector>
#include <iostream>
using namespace std;

int main()
{
vector<double> temps; //temperatures

 for(double temp; cin>>temp;) // read and put into temps
  {
    temps.push_back(temp);
  }

 double sum = 0;
 double high_temp = -1000;
 double low_temp = 1000;
 int no_of_temps;

 for(double temp : cin >> temps)
   {
     ++no_of_temps; //count the temperatures
     sum+=temp; // compute the sum
     if(x > high_temp) high_temp = temp; // find high
     if(x < low_temp) low_temp = temp; //find low
   }

 cout << "High temperature: " << high_temp << '\n';
 cout << "Low temperature: " << low_temp << '\n';
 cout << "Average temperature: " << sum/temps.size() << '\n';
}
