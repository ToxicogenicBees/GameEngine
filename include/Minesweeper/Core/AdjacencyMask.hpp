/*
    AdjacencyMask.hpp

    Declaration for an adjacency mask, representing a mask of adjacent tiles around a given tile.
*/


#pragma once

#include <Math/Vector2.hpp>
#include <vector>

class AdjacencyMask {
private:
    std::vector<Vector2i> mask_;

public:
    /**
     * @brief Constructor.
     * 
     * @param mask The vector of relative positions representing the adjacency mask.
     */
    AdjacencyMask(const std::vector<Vector2i>& mask);

    /**
     * @brief Constructor.
     *        Defaults to the standard 8-neighbor adjacency mask.
     */
    AdjacencyMask();

    /**
     * @brief Gets the neighbors of a given index, filtered by the adjacency mask.
     * 
     * @param index The index to get the neighbors of.
     * @return A vector of neighboring indices that are within the adjacency mask.
     */
    std::vector<Vector2i> apply(const Vector2i& index) const;
};
