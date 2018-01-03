#include <string>

class Resource
{
 private:
  std::string name;
 public:
  Resource(std::string n);
  ~Resource(void);
  std::stringGetName() const {return name;}
};
