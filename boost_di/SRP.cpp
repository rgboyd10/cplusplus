//shows the Single Responsibility Principle

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct Journal
{
  std::string title;
  std::vector<string> entries;

  explicit Journal(const std::string& title)
    : title{title}
  {
   
  }

  void add(const std::string& entry)
  {
    entries.push_back(entry);
  }

  
  
};

struct PersistenceManager
{
void save(const string& filename)
  {
    std::ofstream ofs(filename);
    for(auto&s : entries)
      {
	ofs << s << std::endl;
      }
  }
};
