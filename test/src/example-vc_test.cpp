#include <gtest/gtest.h>

#include "example/lib.hpp"

TEST(ExampleTest, simpleTest)
{
  auto const lib = example::library {};
  ASSERT_EQ(lib.name, "example-vc");
}
