#include <gtest/gtest.h>

#include "lib.hpp"

TEST(ExampleTest, simpleTest)
{
  auto const lib = library {};
  ASSERT_EQ(lib.name, "example-vc");
}

