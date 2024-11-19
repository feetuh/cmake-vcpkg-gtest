#include <iostream>

#include "example/lib.hpp"

auto main() -> int
{
  auto const lib = example::library {};
  auto const message = "Hello from " + lib.name + "!";
  std::cout << message << '\n';
  return 0;
}

