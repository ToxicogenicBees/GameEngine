/*
    Sprite.cpp

    Implementation of a 2D sprite class
*/

#include "Graphics/Sprites/Sprite.hpp"
#include "Core/Services.hpp"

Sprite::Sprite(TextureHandle texture, Vector2i offset, Size size) {
    setTexture(texture, offset, size);
}

Sprite::Sprite(TextureHandle texture)  {
    setTexture(texture);
}

TextureHandle Sprite::texture() const {
    return texture_;
}

void Sprite::setTexture(TextureHandle texture, Vector2i offset, Size size) {
    texture_ = texture;
    offset_ = offset;
    size_ = size;
}

void Sprite::setTexture(TextureHandle texture) {
    texture_ = texture;
    offset_ = Vector2i::zero();

    auto* tex = Services::resources()->resolve(texture);
    size_ = tex ? tex->size() : Size{0, 0};
}

Vector2i Sprite::offset() const {
    return offset_;
}

Size Sprite::size() const {
    return size_;
}
