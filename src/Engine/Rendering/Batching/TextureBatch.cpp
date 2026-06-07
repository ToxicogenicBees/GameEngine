/*
    TextureBatch.cpp

    Implementation of a container of batched sprite data.
*/

#include "Rendering/Batching/TextureBatch.hpp"

TextureBatch::TextureBatch(Texture* texture)
    : texture_(texture) {}

void TextureBatch::addVertex(const Vertex& vertex) {
    vertices_.push_back(vertex);
}

void TextureBatch::clear() {
    vertices_.clear();
}

void TextureBatch::reserve(size_t count) {
    vertices_.reserve(count);
}

Texture* TextureBatch::texture() const {
    return texture_;
}

const std::vector<Vertex>& TextureBatch::vertices() const {
    return vertices_;
}

TextureBatch::const_iterator TextureBatch::begin() const {
    return vertices_.begin();
}

TextureBatch::const_iterator TextureBatch::cbegin() const {
    return vertices_.cbegin();
}

TextureBatch::const_iterator TextureBatch::end() const {
    return vertices_.end();
}

TextureBatch::const_iterator TextureBatch::cend() const {
    return vertices_.cend();
}
