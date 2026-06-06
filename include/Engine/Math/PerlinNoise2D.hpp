/*
    PerlinNoise2D.hpp

    Declaration of a 2D perlin noise generator.
*/

#pragma once

#include "Math/Vector2.hpp"
#include "Utility/Seed.hpp"

class PerlinNoise2D {
private:
    const Seed SEED_;

    /**
     * @brief Gets a deterministic seed at a specified lattice index.
     * 
     * @param index The desired lattice index.
     * @return A deterministic seed for this index.
     */
    Seed latticeSeed_(const Vector2i& index) const;

public:
    /**
     * @brief Constructor.
     * 
     * @param seed The desired noise seed.
     */
    PerlinNoise2D(const Seed& seed);

    /**
     * @brief Constructor.
     */
    PerlinNoise2D();

    /**
     * @brief Gets the perlin noise value at the specified index.
     * 
     * @param index The desired index.
     * @return The noise value at this index
     */
    double value(const Vector2& index) const;

    /**
     * @brief Gets the seed of this noise generator.
     * 
     * @return The seed of the generator.
     */
    Seed seed() const;
};
