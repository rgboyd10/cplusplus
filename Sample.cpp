#include "Precompiled.h"
#include "assert.h"
#ifndef _DEBUG
#define VERIFY ASSERT
#else
#define VERIFY(expression)(expression)
#endif

auto main() ->int
{
  static_assert(sizeof(float) == 4, "can't serialize floats!");  

  
  
}
