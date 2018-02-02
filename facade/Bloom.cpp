#include "StdAfx.h"
#include "Window.h"
#include "TextBuffer.h"
#include "Console.h"
using namespace std;

int main()
{
  auto window = Console::instance().multicolumn("Test",
    2, 40, 40);

  for (size_t i = 0; i < 40; i++)
  {
    window->buffers[1]->add_string("This is line " +
      boost::lexical_cast<string>(i));
  }

  window->Show();
  return 0;
}