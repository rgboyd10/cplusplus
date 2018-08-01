/*
Pero has negotiated a Very Good data plan with his internet provider. The provider will let Pero use up X megabytes to surf the internet per month. Each megabyte that he doesn¡¯t spend in that month gets transferred to the next month and can still be spent. Of course, Pero can only spend the megabytes he actually has.

If we know how much megabytes Pero has spent in each of the first N months of using the plan, determine how many megabytes Pero will have available in the N+1 month of using the plan.

Input
The first line of input contains the integer X(1¡ÜX¡Ü100). The second line of input contains the integer N (1¡ÜN¡Ü100). Each of the following N lines contains an integer Pi (0¡ÜPi¡Ü10000), the number of megabytes spent in each of the first N months of using the plan. Numbers Pi will be such that Pero will never use more megabytes than he actually has.

Output
The first and only line of output must contain the required value from the task.
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
  //declare vars
  int megabyte_limit = 0;
  int mb_values = 0;
  int result = 0;
  int month_counter;
  vector <int> megabytes_used_history;
  int total_mb_used = 0;
  int total_mb_available = 0;
  
  //read in values
  cin >> megabyte_limit;
  while(cin >> mb_values)
    {
      if(mb_values >= megabyte_limit) mb_values = 0;
      megabytes_used_history.push_back(mb_values);
      month_counter++;
    }

  //calculate output and print
  for(int x = 0; x < megabytes_used_history.size(); x++)
    {
      total_mb_used += megabytes_used_history[x];
    }

  //other method
  total_mb_available = megabyte_limit * month_counter;
  cout << total_mb_available << endl;
  result = total_mb_available - total_mb_used;
  cout << result << endl;
}
