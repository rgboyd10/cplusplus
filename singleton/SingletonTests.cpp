#include "Singleton.hpp"
#include <gtest/gtest.h>

TEST(DatabaseTests, IsSingleTonTest)
{
  auto& db = SingletonDatabase::get();
  auto& db = SingletonDatabase::get();
  ASSERT_EQ(1, db.instance_count);
  ASSERT_EQ(1, db.instance_count);
}

TEST(RecordFinderTests,SingletonTotalPopulationTest)
{
  SingletonRecordFinder rf;
  std::vector<std::string> names {"Seoul", "Mexico City"};
  int tp = rf.total_population(names);
  EXPECT_EQ(17500000 + 17400000, tp);
}


TEST(RecordFinderTests, DependantTotalPopulationTest)
{
  DummyDatabase db{};
  ConfigurableRecordFinder rf{db};
  EXPECT_EQ(4,rf.total_population(std::vector<std::string>{"alpha", "gamma"}));
}

int main(int ac, char* av[])
{
  //  SingletonDatabase db;
  //auto db2(...);
  //auto db3 = ...;

  testing::InitGoogleTest(&ac, av);  
  return RUN_ALL_TESTS();
  

  return 0;
}
