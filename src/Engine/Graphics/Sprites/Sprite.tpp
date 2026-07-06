/*
    Sprite.tpp

    Template implementation of a 2D sprite class
*/

#pragma once

#include "Graphics/Sprites/Sprite.hpp"
#include "Resources/Types/Texture.hpp"
#include "Core/Services.hpp"

template<typename string_t>
void Sprite::setTexture(const string_t& texture, Vector2i offset, Size size) {
    setTexture(Services::resources()->load<Texture>(texture), offset, size);
}

template<typename string_t>
void Sprite::setTexture(const string_t& texture) {
    setTexture(Services::resources()->load<Texture>(texture));
}
