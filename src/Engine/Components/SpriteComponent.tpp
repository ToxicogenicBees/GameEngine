/*
    SpriteComponent.tpp

    Template implementation for a component containing a 2D sprite
*/

#pragma once

#include "Components/SpriteComponent.hpp"
#include "Core/Services.hpp"

template<typename string_t>
SpriteComponent::SpriteComponent(const string_t& texture)
    : texture_(Services::assets()->loadTexture(texture)) {}

template<typename string_t>
void SpriteComponent::setTexture(const string_t& texture) {
    texture_ = Services::assets()->loadTexture(texture);
}
