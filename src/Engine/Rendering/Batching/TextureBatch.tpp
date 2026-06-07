/*
    TextureBatch.tpp

    Template implementation of a container of batched sprite data.
*/

#pragma once

#include "Rendering/Batching/TextureBatch.hpp"

template<typename Iterator>
requires std::forward_iterator<Iterator>
void TextureBatch::addVertices(Iterator begin, Iterator end) {
    vertices_.insert(
        vertices_.end(),
        begin,
        end
    );
}
