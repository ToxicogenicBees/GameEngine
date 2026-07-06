/*
    AdjacencyMask.cpp

    Implementation for an adjacency mask, representing a mask of adjacent tiles around a given tile.
*/

#include "Minesweeper/Core/AdjacencyMask.hpp"
#include <iostream>

AdjacencyMask::AdjacencyMask(const std::vector<Vector2i>& mask)
    : mask_(mask) {}

AdjacencyMask::AdjacencyMask()
    : mask_({{-1, -1}, {0, -1}, {1, -1}, {-1, 0}, {1, 0}, {-1, 1}, {0, 1}, {1, 1}}) {}

std::vector<Vector2i> AdjacencyMask::apply(Vector2i index) const {
    std::vector<Vector2i> neighbors;
    for (const auto& offset : mask_)
        neighbors.emplace_back(index + offset);
    return neighbors;
}
