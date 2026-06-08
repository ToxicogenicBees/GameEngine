/*
    TextureBatch.hpp

    Declaration of a container of batched sprite data.
*/

#pragma once

#include "Rendering/Batching/Vertex.hpp"
#include "Resources/Types/Texture.hpp"
#include <SDL3/SDL.h>
#include <vector>
#include <concepts>

class TextureBatch {
private:
    Texture* texture_;
    std::vector<Vertex> vertices_;

public:
    using const_iterator = std::vector<Vertex>::const_iterator;

    /**
     * @brief Constructor.
     */
    TextureBatch(Texture* texture);

    /**
     * @brief Adds a range of vertices into the batch.
     * 
     * @param begin An iterator to the beginning of the vertex range.
     * @param end An iterator to the end of the vertex range.
     */
    template<typename Iterator>
    requires std::forward_iterator<Iterator>
    void addVertices(Iterator begin, Iterator end);

    /**
     * @brief Adds a vertex to the batch.
     * 
     * @param vertex The vertex being added.
     */
    void addVertex(const Vertex& vertex);

    /**
     * @brief Clears the vertex list.
     */
    void clear();

    /**
     * @brief Reserves space for vertices.
     * 
     * @param count The amount of space being reserved.
     */
    void reserve(size_t count);

    /**
     * @brief Gets the texture of this batch.
     * 
     * @return The texture of this batch.
     */
    Texture* texture() const;

    /**
     * @brief Gets the vertex list in this batch.
     * 
     * @return The vertex list in this batch.
     */
    const std::vector<Vertex>& vertices() const;

    /**
     * @brief Gets an iterator to the beginning of the vertex list.
     * 
     * @return An iterator to the beginning of the vertex list.
     */
    const_iterator begin() const;

    /**
     * @brief Gets an iterator to the beginning of the vertex list.
     * 
     * @return An iterator to the beginning of the vertex list.
     */
    const_iterator cbegin() const;

    /**
     * @brief Gets an iterator to the end of the vertex list.
     * 
     * @return An iterator to the end of the vertex list.
     */
    const_iterator end() const;

    /**
     * @brief Gets an iterator to the end of the vertex list.
     * 
     * @return An iterator to the end of the vertex list.
     */
    const_iterator cend() const;
};

#include "Rendering/Batching/TextureBatch.tpp"
