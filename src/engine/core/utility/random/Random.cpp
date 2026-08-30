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

    fp_type Random::nextNormal(fp_type mean, fp_type deviation) {
        std::normal_distribution<fp_type> normal(mean, deviation);
        return normal(generator_);
    }

    Seed Random::seed() const {
        return SEED_;
    }
}
