/*
    Sprite.cpp

    Implementation of a 2D sprite class
*/

#include "Graphics/Sprites/Sprite.hpp"

Sprite::Sprite(std::shared_ptr<Texture> texture, const Vector2i& offset, const Size& size)
    : offset_(offset),
      size_(size),
      texture_(texture)
{}

Sprite::Sprite(std::shared_ptr<Texture> texture)
    : offset_(Vector2i::zero()),
      size_(texture ? texture->size() : Size{0, 0}),
      texture_(texture)
{}

std::shared_ptr<Texture> Sprite::texture() const {
    return texture_;
}

void Sprite::setTexture(std::shared_ptr<Texture> texture, const Vector2i& offset, const Size& size) {
    texture_ = texture;
    offset_ = offset;
    size_ = size;
}

void Sprite::setTexture(std::shared_ptr<Texture> texture) {
    texture_ = texture;
    offset_ = Vector2i::zero();
    size_ = texture ? texture->size() : Size{0, 0};
}

Vector2i Sprite::offset() const {
    return offset_;
}

Size Sprite::size() const {
    return size_;
}
