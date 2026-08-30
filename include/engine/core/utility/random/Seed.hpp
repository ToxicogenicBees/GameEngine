/*
    Seed.hpp

    Declaration of a simple seed class for random generation.
*/

#pragma once

#include <cstdint>
#include <string>

namespace toxico {
    class Seed {
    private:
        const uint_fast64_t VALUE_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param value The desired value for this seed
         */
        Seed(uint_fast64_t value);

        /**
         * @brief Constructor.
         */
        Seed();

        /**
         * @brief Gets the value of this seed.
         */
        uint_fast64_t value() const;

        /**
         * @brief Gets this seed as a string.
         * 
         * @return The seed as a string.
         */
        std::string toString() const noexcept;
    };
}
