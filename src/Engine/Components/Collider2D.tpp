/*
    Collider2D.tpp

    Template implementation for an abstract 2D collider component
*/

#pragma once

#include "Components/Collider2D.hpp"

template<typename BoundingBox_t, typename... Args>
Collider2D::Collider2D(std::type_identity<BoundingBox_t>, Args&&... args)
    : bounds_(std::make_unique<BoundingBox_t>(std::forward<Args>(args)...)) {}
