/*
    GameObject.cpp

    Implementation for a game object that can be rendered on the screen
*/

#include "World/GameObject.hpp"
#include "World/Scene.hpp"

void GameObject::init() {
    for (auto& component : components_)
        component->onInit();
    onInit();
}

Scene* GameObject::scene() const {
    return scene_;
}
