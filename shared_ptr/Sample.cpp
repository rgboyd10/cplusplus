using namespace std;

auto main() -> int
{
  auto sp = shared_ptr<int> {};

  ASSERT(!sp);

  ASSERT(sp.use_count() == 0);
  sp = make_shared<int>(123);
  ASSERT(!sp.unique());
  
  ASSERT(sp);
  ASSERT(sp.use_count() == 1);
  ASSERT(sp.unique());

  auto  sp2 = sp;
  
  ASSERT(sp.use_count() == 2);
  ASSERT(!sp.unique());

  ASSERT(sp2.use_count() == 2);
  ASSERT(sp2.unique());

  int copy = *sp;

  int & ref = *sp;

  int * ptr = sp.get();

  ASSERT(sp.get() == sp2.get());
  ASSERT(sp == sp2);

  
}
