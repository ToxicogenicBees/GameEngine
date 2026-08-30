/*
    PerlinNoise.hpp

    Declaration of a perlin noise generator.
*/

#pragma once

#include "foundation/utility/fp_type.hpp"
#include "foundation/math/Vector.hpp"
#include "core/utility/Seed.hpp"

namespace toxico {
    template<std::size_t N>
    class PerlinNoise {
    private:
        const Seed SEED_;

        /**
         * @brief Gets a deterministic seed at a specified lattice index.
         * 
         * @param index The desired lattice index.
         * @return A deterministic seed for this index.
         */
        Seed latticeSeed_(const Vector<int, N>& index) const;

    public:
        /**
         * @brief Constructor.
         * 
         * @param seed The desired noise seed.
         */
        PerlinNoise(const Seed& seed);

        /**
         * @brief Constructor.
         */
        PerlinNoise();

        /**
         * @brief Gets the perlin noise value at the specified index.
         * 
         * @param index The desired index.
         * @return The noise value at this index.
         */
        fp_type value(const Vector<fp_type, N>& index) const;

        /**
         * @brief Gets the perlin noise value at the specified index.
         * 
         * @param index The desired index.
         * @return The noise value at this index.
         */
        fp_type operator()(const Vector<fp_type, N>& index) const;

        /**
         * @brief Gets the seed of this noise generator.
         * 
         * @return The seed of the generator.
         */
        Seed seed() const;
    };
}

#include "foundation/math/PerlinNoise.tpp"
