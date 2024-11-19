#include "example/lib.hpp"

#include <format>

using example::library;

library::library()
    : name {std::format("{}", "example-vc")}
{
}
