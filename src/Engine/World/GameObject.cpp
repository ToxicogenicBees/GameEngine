/*
    GameObject.cpp

    Implementation for a game object that can be rendered on the screen
*/

#include "World/GameObject.hpp"
#include "World/Scene.hpp"

GameObject::GameObject(Scene& scene)
    : scene_(&scene) {}

void GameObject::init() {
    for (auto& component : components_)
        component->init();
    onInit();
}

Scene* GameObject::scene() const {
    return scene_;
}

EngineContext& GameObject::context() {
    return scene_->context();
}
