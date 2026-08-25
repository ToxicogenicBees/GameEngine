/*
    Random.cpp

    Implementation of a random generator.
*/

#include "core/utility/random/Random.hpp"
#include <cmath>

namespace toxico {
    Random::Random(const Seed& seed)
        : SEED_(seed),
        generator_(SEED_.value())
    {}

    double Random::nextNormal(double mean, double deviation) {
        std::normal_distribution<double> normal(mean, deviation);
        return normal(generator_);
    }

    Seed Random::seed() const {
        return SEED_;
    }
}
