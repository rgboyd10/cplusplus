#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Called with empty digit list --> returns no results")
{
  WordsTree emptyTree;
  Engine t9Engine(emptyTree);

  Digits digits;

  auto result = t9Engine.GetWordsByDigits(digits);

  REQUIRE(result.size() == 0);
}

TEST_CASE("When called wth 43556 and known word then return hello")
{
  WordsTree knownWords;
  knownWords.AddWord("hello");

  Engine t9Engine(knownWords);

  Digit digits = {4,3,5,5,6};

  auto result = t9Engine.GetWordsByDigits(digits);

  REQUIRE(result[0] == "hello");
}
