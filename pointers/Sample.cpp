#include <memory>
#include <iostream>

using namespace std;


struct Hen
{
  unsigned id;
  float eggs;
  
  Hen(unsigned id_, float eggs_) : id {id_}, eggs{eggs_}
  {};

  ~Hen()
  {
    cout << "Chicken soup!\n" << endl;
  };
};

auto GetHen() -> unique_ptr<Hen>
{

  return make_unique<Hen>(2, 3.9f);
  
}

auto UpdateHen(unique_ptr<Hen> hen) -> unique_ptr <Hen>
{
  hen -> eggs += 1.8f;
  return hen;
}

auto main() -> int
{

  auto hen = GetHen();
  
  Hen copy = *hen;

  Hen & ref = *hen;

  Hen * ptr = hen.release();

  hen.reset(ptr);

  
}
