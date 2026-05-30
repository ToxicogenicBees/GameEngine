/*
    Entity.hpp

    Declaration of an abstract engine entity class
*/

#include "Core/Entity.hpp"

const Transform& Entity::transform() const {
    return transform_;
}

Transform& Entity::transform() {
    return transform_;
}

bool Entity::isActive() {
    return active_;
}

void Entity::setActive(bool active) {
    active_ = active;
}
