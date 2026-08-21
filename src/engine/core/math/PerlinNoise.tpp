/*
    PerlinNoise.tpp

    Template implementation of a perlin noise generator.
*/

#include "core/utility/Random.hpp"
#include <vector>
#include <cmath>

namespace {
    double fade(double t) {
        // 6t^5 - 15t^4 + 10t^3
        return t * t * t * (t * (t * 6 - 15) + 10);
    }
}

namespace toxico {
    template <size_t N>
    Seed PerlinNoise<N>::latticeSeed_(const Vector<int, N>& index) const {
        uint_fast64_t h = SEED_.value();

        for (size_t i = 0; i < N; ++i) {
            auto x = static_cast<uint64_t>(index[i]);

            h ^= x + 0x9e3779b97f4a7c15ULL
                + (h << 6)
                + (h >> 2);
        }

        // SplitMix64 finalizer.
        h = (h ^ (h >> 30)) * 0xbf58476d1ce4e5b9ULL;
        h = (h ^ (h >> 27)) * 0x94d049bb133111ebULL;
        h ^= h >> 31;

        return h;
    }

    template<size_t N>
    PerlinNoise<N>::PerlinNoise(const Seed& seed)
        : SEED_(seed) {}

    template<size_t N>
    PerlinNoise<N>::PerlinNoise()
        : SEED_(Seed()) {}

    template <size_t N>
    double PerlinNoise<N>::value(const Vector<double, N>& index) const {
        // Find the integer lattice cell.
        Vector<int, N> cell_index;

        for (size_t i = 0; i < N; ++i)
            cell_index[i] = static_cast<int>(std::floor(index[i]));

        // Position within the cell, in [0, 1).
        Vector<double, N> cell_offset = index - cell_index;

        // Fade each interpolation coordinate.
        Vector<double, N> t;
        for (size_t i = 0; i < N; ++i)
            t[i] = fade(cell_offset[i]);

        // Number of corners in an N-dimensional hypercube.
        const size_t vertices = size_t(1) << N;

        std::vector<double> dot_products;
        dot_products.reserve(vertices);
        for (size_t c = 0; c < vertices; ++c) {
            // Convert corner bit pattern into an N-dimensional offset.
            Vector<int, N> corner;

            for (size_t dim = 0; dim < N; ++dim)
                corner[dim] = (c & (size_t(1) << dim)) ? 1 : 0;

            // Absolute lattice position.
            Vector<int, N> lattice_index = cell_index + corner;

            // Deterministically generate this corner's gradient.
            Random random(latticeSeed_(lattice_index));
            auto gradient = random.template nextUnitVector<N>();

            // Vector from the corner to the sample point.
            Vector<double, N> displacement = cell_offset - corner;

            // Perlin contribution from this corner.
            dot_products.push_back(gradient.dot(displacement));
        }

        // Interpolate all 2^N corner contributions.
        double result = 0.0;
        for (size_t c = 0; c < vertices; ++c) {
            double weight = 1.0;
            for (size_t dim = 0; dim < N; ++dim) {
                if (c & (size_t(1) << dim))
                    weight *= t[dim];
                else
                    weight *= (1.0 - t[dim]);
            }
            result += dot_products[c] * weight;
        }
        return result;
    }

    template<size_t N>
    double PerlinNoise<N>::operator()(const Vector<double, N>& index) const {
        return value(index);
    }

    template<size_t N>
    Seed PerlinNoise<N>::seed() const {
        return SEED_;
    }
}
