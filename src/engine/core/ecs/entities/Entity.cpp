/*
    Entity.cpp

    Implementation of an ECS entity wrapper.
*/

#include "core/ecs/entities/Entity.hpp"

namespace toxico {
    Entity::Entity(ECS& ecs, EntityHandle handle) noexcept
        : handle_(handle),
          ecs_(ecs)
    {}

    void Entity::destroy() noexcept {
        return ecs_.destroy(handle_);
    }

    bool Entity::isValid() const noexcept {
        return ecs_.isValid(handle_);
    }

    EntityHandle Entity::handle() const noexcept {
        return handle_;
    }
}
