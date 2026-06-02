/*
    Random.hpp

    Declaration of a random generator.
*/

#pragma once

#include "Math/Vector2.hpp"
#include <concepts>
#include <optional>
#include <stdint.h>
#include <random>

class Random {
private:
    const uint_fast64_t SEED_;
    std::mt19937 generator_;

public:
    /**
     * @brief Constructor.
     * 
     * @param seed The (optional) seed for this random generator.
     */
    Random(std::optional<uint_fast32_t> seed = std::nullopt);

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
     * @brief Gets the next 2D unit vector from this generator.
     * 
     * @return A randomly generated 2D unit vector.
     */
    Vector2 nextUnitVector2();

    /**
     * @brief Shuffles the provided container.
     * 
     * @param start The start of the range being shuffled.
     * @param end The end of the range being shuffled.
     */
    template <typename RAIterator>
    requires std::random_access_iterator<RAIterator>
    void shuffle(RAIterator start, RAIterator end);
};

#include "Utility/Random.tpp"
