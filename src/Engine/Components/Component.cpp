/*
    Component.cpp

    Implementation for modular components to add to game objects
*/

#include "Components/Component.hpp"
#include "World/GameObject.hpp"

Component::Component(GameObject& owner)
    : owner_(&owner) {}

GameObject* Component::owner() const {
    return owner_;
}

Scene* Component::scene() const {
    return owner_->scene();
}

EngineContext& Component::context() {
    return owner_->context();
}

void Component::init() {
    onInit();
}
