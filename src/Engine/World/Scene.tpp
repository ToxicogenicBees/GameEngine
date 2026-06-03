/*
    Scene.hpp

    Template implementation for a scene class, in charge of storing game objects
*/

#pragma once

#include "World/Scene.hpp"
#include "Events/EngineEventDispatcher.hpp"
#include "World/GameObject.hpp"

template <typename Event_t, typename Func>
void Scene::subscribe(Func&& func) {
    subscriptions_.push_back(EngineEventDispatcher::subscribe<Event_t>(
        std::forward<Func>(func)
    ));
}

template<typename T, typename... Args>
T* Scene::create(Args&&... args) {
    auto obj = std::make_unique<T>(*this, std::forward<Args>(args)...);
    T* raw = obj.get();

    pending_create_.push_back(std::move(obj));
    return raw;
}
