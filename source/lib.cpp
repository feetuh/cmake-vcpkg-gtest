#include "lib.hpp"

#include <fmt/format.h>

library::library()
    : name {fmt::format("{}", "example-vc")}
{
}
