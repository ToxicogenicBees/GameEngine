/*
    Seed.cpp

    Implementation of a simple seed class for random generation.
*/

#include "core/utility/random/Seed.hpp"
#include <random>

namespace toxico {
    Seed::Seed(uint_fast64_t value)
        : VALUE_(value) {}

    Seed::Seed()
        : VALUE_(std::random_device{}()) {}

    uint_fast64_t Seed::value() const {
        return VALUE_;
    }

    /**
     * @brief Gets this seed as a string.
     * 
     * @return The seed as a string.
     */
    std::string Seed::toString() const noexcept {
        return std::to_string(VALUE_);
    }
}
