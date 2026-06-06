/*
    PerlinNoise2D.hpp

    Declaration of a 2D perlin noise generator.
*/

#include "Math/PerlinNoise2D.hpp"

namespace {
    double splitMix64(uint_fast64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        x = x ^ (x >> 31);
        return x;
    }

    double fade(double t) {
        return t * t * t * (t * (t * 6 - 15) + 10);
    }

    double lerp(double start, double target, double alpha) {
        return start + alpha * (target - start);
    }
}

#include "Math/PerlinNoise2D.hpp"
#include "Utility/Random.hpp"

Seed PerlinNoise2D::latticeSeed_(const Vector2i& index) const {
    uint64_t h = SEED_.value();
    h ^= uint64_t(uint32_t(index.x)) * 0x9e3779b97f4a7c15ULL;
    h ^= uint64_t(uint32_t(index.y)) * 0xc2b2ae3d27d4eb4fULL;
    return splitMix64(h);
}

PerlinNoise2D::PerlinNoise2D(const Seed& seed)
    : SEED_(seed) {}

PerlinNoise2D::PerlinNoise2D()
    : SEED_(Seed()) {}

double PerlinNoise2D::value(const Vector2& index) const {
    // Get the integer cell this index is located in
    Vector2i int_index(
        (int)std::floor(index.x),
        (int)std::floor(index.y)
    );

    // Get the offset vector
    Vector2 offset(
        index.x - int_index.x,
        index.y - int_index.y
    );

    // Generate the four unit vectors in the corners of this index.
    auto get_unit = [this](const Vector2i lattice_index) {
        Random random(latticeSeed_(lattice_index));
        return random.nextUnitVector2();
    };
    Vector2 v00 = get_unit(int_index);
    Vector2 v10 = get_unit(int_index + Vector2i::xAxis());
    Vector2 v01 = get_unit(int_index + Vector2i::yAxis());
    Vector2 v11 = get_unit(int_index + Vector2i::one());

    // Calculate the dot products between these unit vectors and the offset vector
    double d00 = v00.dot(offset);
    double d10 = v10.dot(offset);
    double d01 = v01.dot(offset);
    double d11 = v11.dot(offset);

    // Lerp the dot products to get the appropriate value
    double u = fade(offset.x);
    double v = fade(offset.y);
    double left = lerp(d00, d01, v);
    double right = lerp(d10, d11, v);
    return lerp(left, right, u);
}

Seed PerlinNoise2D::seed() const {
    return SEED_;
}
