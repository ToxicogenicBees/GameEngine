/*
    Seed.cpp

    Implementation of a simple seed class for random generation.
*/

#include "core/utility/Seed.hpp"
#include <random>

namespace toxico {
    Seed::Seed(uint_fast64_t value)
        : VALUE_(value) {}

    Seed::Seed()
        : VALUE_(std::random_device{}()) {}

    uint_fast64_t Seed::value() const {
        return VALUE_;
    }
}
