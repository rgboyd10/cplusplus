#include <cstdio>
#include <ostream>
#include <iostream>
#include <memory>
using namespace std;

struct BankAccount
{
  virtual ~BankAccount() = default;
  virtual void deposit(int amount) = 0;
  virtual void withdraw(int amount) = 0;
};

struct CurrentAccount : BankAccount
{
  explicit CurrentAccount(const int balance) : balance(balance)
  {}

  void deposit(int amount) override
  {
    balance += amount;
  };

  void withdraw(int amount) override
  {
    if(amount <= balance) balance -= amount;
  }

  friend ostream& operator<<(ostream& os, const CurrentAccount& obj)
  {
    return os << "balance: " << obj.balance;
  }

private:
  int balance;
};

void smart_pointers()
{
  BankAccount* a = new CurrentAccount{123};
  a->deposit(321);
  delete a;

  shared_ptr<CurrentAccount> b = make_shared<CurrentAccount>(123);
  b->deposit(321);

  CurrentAccount* underlying = b.get();

  cout << *b << endl;
}

int main()
{
  smart_pointers();
  getchar();
  return 0;
}
