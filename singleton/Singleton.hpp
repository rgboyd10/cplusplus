#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <boost/lexical_cast.hpp>
#include <vector>

class Database
{
 public:
  virtual int get_population(const std::string& name) = 0;
};

class SingletonDatabase : public Database
{
  SingletonDatabase()
  {
  std::cout << "Initializing database" << std::endl;

  std::ifstream ifs("capitals.txt");

  std::string s, s2;

  while(getline(ifs, s))
    {
      getline(ifs, s2);
      int pop = boost::lexical_cast<int>(s2);
      capitals[s] = pop;
    }
  instance_count++;
  }
  std::map<std::string,int> capitals;


  
  
public:

  static int instance_count;

  SingletonDatabase(SingletonDatabase const&) = delete;
  void operator = (SingletonDatabase const&) = delete;

  static SingletonDatabase& get()
  {
    //c++ can allocate static objects right inside functions
    static SingletonDatabase db; // provides a certain measure of thread safety
    return db;
  }

  int get_population(const std::string& name)
  {
    return capitals[name];
  }
  /*
  static SingletonDatabase* get_instance()
  {
    if(!instance)
      {
      instance = new SingletonDatabase;
      }
    return instance; //could use atexit
    }*/
};

class DummyDatabase : public Database
{
public:
  std::map<std::string, int> capitals;
  DummyDatabase()
  {
    capitals["alpha"] =1;
    capitals["beta"] =1;
    capitals["gamma"] =1;
  }
  
  int get_population(const std::string& name) override
  {
    return capitals[name];
  }
};

struct SingletonRecordFinder
{
  int total_population(std::vector<std::string> names)
  {
    int result = 0;
    for(auto&name : names)
      {
      result += SingletonDatabase:get().get_population(name);
      }
    return result;
  }
};

struct ConfigurableRecordFinder
{
  explicit ConfigurableRecordFider(Database& db) : db{db}
  {

  }
  
  Database& db;
};
