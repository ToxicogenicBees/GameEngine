/*
    GameObject.cpp

    Implementation for a game object that can be rendered on the screen
*/

#include "GameObject/GameObject.hpp"
#include "Scene/Scene.hpp"

void GameObject::render() {
    for (auto& component : components_)
        component->render();
}

bool GameObject::isAlive() const {
    return alive_;
}

Scene* GameObject::scene() const {
    return scene_;
}
