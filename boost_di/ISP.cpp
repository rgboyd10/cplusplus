//Interface Segregation Principle
//No client should be forced to depend on methods it does not use
#include <vector>

struct Document;
/*
struct IMachine
{
  virtual void print(vector <Document*> docs) = 0;
  virtual void scan(vector <Document*> docs) = 0;
  virtual void fax(vector <Document*> docs) = 0;
};

struct MFP : IMachine
{
  virtual void print(vector <Document*> docs) override;
  virtual void scan(vector <Document*> docs) override;
  virtual void fax(vector <Document*> docs) override;
};

*/

struct IPrinter
{
     virtual void print(vector <Document*> docs) = 0;
};

struct IScanner
{
  virtual void scan(vector <Document*> docs) = 0;
};

struct {Printer: IPrinter
  {
    void print(std::vector<Document*> docs) override;
  };

  struct Scanner : IScanner
  {
    void scan(std::vector<Document*> docs) override;
  };

  struct IMachine : IPrint, IScanner {};

  struct IMachine : IMachine
  {
    IPrinter& printer;
    IScanner& scanner;

    //constructor
    Machine(IPrinter& printer, IScanner& scanner) : printe{printer},scanner{scanner}
    {}
        void print(std::vector<Document*> docs) override
    {
      printer.print(docs);
    }
        void scan(std::vector<Document*> docs) override
    {
      scanner.scan(docs);
    }
  };
