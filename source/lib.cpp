#include "lib.hpp"

#include <format>

library::library()
    : name {std::format("{}", "example-vc")}
{
}
