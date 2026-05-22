/*
    Scene.hpp

    Template implementation for a scene class, in charge of storing game objects
*/

#pragma once

#include "Game/Scene.hpp"
#include "Game/GameObjects/GameObject.hpp"

template<typename T, typename... Args>
T* Scene::create(Args&&... args) {
    auto obj = std::make_unique<T>(std::forward<Args>(args)...);
    T* raw = obj.get();

    raw->scene_ = this;
    objects_.push_back(std::move(obj));

    return raw;
}
