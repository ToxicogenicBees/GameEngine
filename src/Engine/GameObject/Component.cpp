/*
    Component.cpp

    Implementation for modular components to add to game objects
*/

#include "GameObject/Component.hpp"

void Component::init() {
    onInit();
}

void Component::update(double dt) {
    onUpdate(dt);
}

void Component::render(Camera& camera) {
    onRender(camera);
}
