/*
    Random.tpp

    Template implementation of a random generator.
*/

#pragma once

#include "Utility/Random.hpp"
#include <algorithm>
#include <limits>

template<typename FP_t>
requires std::is_floating_point_v<FP_t>
FP_t Random::next(FP_t min, FP_t max) {
    auto dist = std::uniform_real_distribution<FP_t>(min, max);
    return dist(generator_);
}

template<typename FP_t>
requires std::is_floating_point_v<FP_t>
FP_t Random::next() {
    return next<FP_t>(FP_t{-1}, FP_t{1});
}

template<typename Int_t>
requires std::is_integral_v<Int_t>
Int_t Random::next(Int_t min, Int_t max) {
    auto dist = std::uniform_int_distribution<Int_t>(min, max);
    return dist(generator_);
}

template<typename Int_t>
requires std::is_integral_v<Int_t>
Int_t Random::next() {
    return next<Int_t>(std::numeric_limits<Int_t>::min(), std::numeric_limits<Int_t>::max());
}

template <typename RAIterator>
requires std::random_access_iterator<RAIterator>
void Random::shuffle(RAIterator start, RAIterator end) {
    std::shuffle(start, end, generator_);
}
