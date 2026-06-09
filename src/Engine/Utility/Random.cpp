/*
    Random.cpp

    Implementation of a random generator.
*/

#include "Utility/Random.hpp"
#include <cmath>

Random::Random(const Seed& seed)
    : SEED_(seed),
      generator_(SEED_.value())
{}

Vector2 Random::nextUnitVector2() {
    auto angle = next<double>(0, 2 * 3.14159265);
    return Vector2(std::cos(angle), std::sin(angle));
}

Seed Random::seed() const {
    return SEED_;
}
