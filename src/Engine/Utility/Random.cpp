/*
    Random.cpp

    Implementation of a random generator.
*/

#include "Utility/Random.hpp"
#include <cmath>
#include <iostream>

Random::Random(std::optional<uint_fast32_t> seed)
    : SEED_(seed ? seed.value() : std::random_device{}()),
      generator_(SEED_)
{}

Vector2 Random::nextUnitVector2() {
    auto angle = next<double>(0, 2 * 3.14159265);
    std::clog << angle << "\n";
    return Vector2(std::cos(angle), std::sin(angle));
}
