//mutable lambdas
using namepsace std;

int main()
{
  vector<pair<int, int>> flight_hours;
  //...flight hours are populated with values...

  auto running_total = 100; // from previous month

  for_each(flight_hours.begin(), flight_hours.end(), [running_total](pair<int, int>& x) mutable // causes it no longer to be const
	   {running_total += x.first; x.second = running_total;});
}

template <class Func>
void by _const_ref(const Func& f) {f();}
by_const_ref([] {}); // ok
by_const_ref([] () mutable {}); //ok

string s("executing mutable lambda");
by_const_ref([s]() mutable {cout << s << endl;}); // error
