#include "catch.hpp"

TEST_CASE("Encode uppercase letter --> return digit")
{
  StringToDigitsEncoder encoder;

  Digits expected({2});

  REQUIRE(encoder.Encode("A") == expected);
  REQUIRE(encoder.Encode("B") == expected);
  REQUIRE(encoder.Encode("C") == expected);
  
}

TEST_CASE("Tree has other word that begins with the same letter")
{
  WordsTree tree;
  tree.AddWord("ab",{2,2});
  tree.AddWord("ad",{2,3});

  auto result = tree.GetWords(Digits{2,3});

  REQUIRE(result.size() == 1);
  REQUIRE(result[0] == "ad");
}
