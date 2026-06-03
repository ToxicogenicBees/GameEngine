/*
    GameObject.tpp

    Template implementation for a game object that can be rendered on the screen
*/

#pragma once

#include "World/GameObject.hpp"

template<typename Component_t, typename... Args>
Component_t* GameObject::addComponent(Args&&... args) {
    auto comp = std::make_unique<Component_t>(*this, std::forward<Args>(args)...);

    Component_t* raw = comp.get();
    components_.push_back(std::move(comp));

    return raw;
}

template<typename Component_t>
Component_t* GameObject::getComponent() {
    for (auto& comp : components_) {
        if (auto* casted = dynamic_cast<Component_t*>(comp.get()))
            return casted;
    }
    return nullptr;
}
