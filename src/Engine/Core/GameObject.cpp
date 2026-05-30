/*
    GameObject.cpp

    Implementation for a game object that can be rendered on the screen
*/

#include "Core/GameObject.hpp"
#include "Scene/Scene.hpp"

void GameObject::init() {
    onInit();
}

void GameObject::update(double dt) {
    for (auto& component : components_)
        component->update(dt);
    onUpdate(dt);
}

void GameObject::render(Camera& camera) {
    for (auto& component : components_)
        component->render(camera);
    onRender(camera);
}

Scene* GameObject::scene() const {
    return scene_;
}
