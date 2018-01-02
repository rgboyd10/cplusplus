#include <string>
class BankAccount
{
 public:
  BankAccount(void);
  ~BankAccount(void);

 private:
  int BalanceInPennies;
  //TODO: finish writing this class
 public:
  std::string GetHolderName() {return "Not Implemented";}
};
