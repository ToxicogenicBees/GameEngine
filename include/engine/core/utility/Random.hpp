/*
    Random.hpp

    Declaration of a random generator.
*/

#pragma once

#include "core/math/Vector.hpp"
#include "core/utility/Seed.hpp"
#include <concepts>
#include <cstdint>
#include <random>

namespace toxico {
    class Random {
    private:
        const Seed SEED_;
        std::mt19937 generator_;

    public:
        /**
         * @brief Constructor.
         * 
         * @param seed The seed for this random generator.
         */
        Random(const Seed& seed = Seed());

        /**
         * @brief Generates the next value of the specified type from this generator.
         * 
         * @param min The minimum bound of generation.
         * @param max The maximum bound of generation.
         * @return The next value from the generator.
         */
        template<typename FP_t>
        requires std::is_floating_point_v<FP_t>
        FP_t next(FP_t min, FP_t max);

        /**
         * @brief Generates the next value of the specified type from this generator.
         *        Defaults to the range [-1.0, 1.0)
         * 
         * @return The next value from the generator.
         */
        template<typename FP_t>
        requires std::is_floating_point_v<FP_t>
        FP_t next();
        
        /**
         * @brief Generates the next value of the specified type from this generator.
         * 
         * @param min The minimum bound of generation.
         * @param max The maximum bound of generation.
         * @return The next value from the generator.
         */
        template<typename Int_t>
        requires std::is_integral_v<Int_t>
        Int_t next(Int_t min, Int_t max);

        /**
         * @brief Generates the next value of the specified type from this generator.
         *        Default range is the std::numeric_limit<Int_t>::min/max()
         * 
         * @return The next value from the generator.
         */
        template<typename Int_t>
        requires std::is_integral_v<Int_t>
        Int_t next();

        /**
         * @brief Generates the next value from a normal distribution
         * 
         * @param mean The mean of the distribution.
         * @param deviation The standard devation of the distribution.
         */
        double nextNormal(double mean, double deviation);

        /**
         * @brief Gets the next unit vector from this generator.
         * 
         * @return A randomly generated unit vector.
         */
        template<size_t N>
        Vector<double, N> nextUnitVector();

        /**
         * @brief Shuffles the provided container.
         * 
         * @param start The start of the range being shuffled.
         * @param end The end of the range being shuffled.
         */
        template <typename RAIterator>
        requires std::random_access_iterator<RAIterator>
        void shuffle(RAIterator start, RAIterator end);

        /**
         * @brief Gets the seed of this generator.
         * 
         * @return The seed of this generator.
         */
        Seed seed() const;
    };
}

#include "core/utility/Random.tpp"
