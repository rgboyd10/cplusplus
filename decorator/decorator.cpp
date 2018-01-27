
struct Logger
{
  function<void()> func;
  string name;

  Logger(const function<void()>& func, const string& name)
    : func{func},
      name{name}
  {}

  void operator()() const
  {
    cout << "Entering "  << name << endl;
    func();
    cout << "Exiting " << name << endl;
  }
};

template <typename Func>
struct Logger2
{
  function<void()> func;
  string name;

  Logger2(Func func
	  , const string& name)
    : func{func},
      name{name}
  {}

  void operator()() const
  {
    cout << "Entering "  << name << endl;
    func();
    cout << "Exiting " << name << endl;
  }
};

template <typename Func> auto make_logger2(Func func, const string& name)
{
  retunr Logger2<Func>{func, name};
}

double add(double a, double b) {return a + b;} 
int main()
{
  auto logged_add = make_logger3(add, "add");
  auto result = logged_add(2, 3);
  
  getchar();
  return 0;
};
