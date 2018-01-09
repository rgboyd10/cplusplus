#include <iostream>
#include <memory>
#include <cassert>
#include <assert.h>

using namespace std;

auto main() -> int
{
  auto sp = make_shared<int>(123);

  auto wp = weak_ptr<int> {sp};

  //often the usage pattern of weak pointer. helps avoid reference loop

  ASSERT(!wp.expired());

  ASSERT(wp.use_count() == 1);

  if(auto locked = wp.lock()) //locked returns a new shared_ptr that holds a strong reference count to the managed object.    
    {
      cout << "locked! %d\n", *locked << endl;
    }

sp = nullptr;

ASSERT(wp.expired());
ASSERT(wp.use_count() ==0);

  if(auto locked = wp.lock())
    {
      cout << "locked! %d\n", *locked << endl;
    }
 else
   {
     wp.reset();
   }


}
